#include "contract.h"
#include "cstring.h"
#include "hexdump.h"
#include "radix.h"
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#pragma pack(push) /* push current alignment to stack */
#pragma pack(1)    /* set alignment to 1 byte boundary */

typedef enum { Value = UINT8_MAX } Tag;

typedef struct {
  Tag tag : CHAR_BIT;
  String s;
} TagString;

typedef struct {
  uint8_t count;
  union {
    String s;
    TagString t;
  };
} Node;

struct _Radix {
  uint16_t length;
  uint8_t *tree;
};

#pragma pack(pop) /* restore original alignment from stack */

Radix *radix_new() {
  size_t DEFAULT_LENGTH = 32 * 1024;

  Radix *r = malloc(sizeof(Radix));
  r->length = DEFAULT_LENGTH;
  r->tree = malloc(sizeof(uint8_t) * (r->length));
  r->tree[0] = 0;
  return r;
}

Maybe *radix_lookup(const Radix *this, const char *key) {
  Node *n = (Node *)this->tree;
  if (n->count == 0)
    return maybe_nothing();
  if (n->count == 1)
    return (strcmp_s(key, strlen(key), n->s.string, n->s.length))
               ? maybe_new_just(n->s.string + n->s.length)
               : maybe_nothing();
  return maybe_nothing();
}

void _radix_insert_empty(Radix *this, const char *key, const char *value) {
  String *k;
  {
    Node *n = (Node *)this->tree;
    k = &(n->s);
    n->count++;
  }

  k->length = strlen(key);
  memcpy(k->string, key, k->length);

  String *v = (String *)(k->string + k->length);
  v->length = strlen(value);
  memcpy(v->string, value, v->length);
}

void _radix_insert(Radix *this, const char *key, const char *value) {}

void radix_insert(Radix *this, const char *key, const char *value) {
  contract_requires(strlen(key) < UINT8_MAX && strlen(value) < UINT8_MAX);
  Node *n = (Node *)this->tree;
  (n->count == 0 ? _radix_insert_empty : _radix_insert)(this, key, value);
}

void radix_dump(const Radix *this) { hexdump("radix", this->tree, UINT8_MAX); }

void radix_free(Radix *this) {
  free(this->tree);
  free(this);
}
