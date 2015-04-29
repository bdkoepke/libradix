#ifndef RADIX_H
#define RADIX_H

#include "maybe.h"

typedef struct _Radix Radix;

Radix *radix_new();
bool radix_member(Radix *, int8_t *key);
Maybe *radix_lookup(Radix *, int8_t *key);
void radix_insert(Radix *, int8_t *key, int8_t *value);
void radix_delete(Radix *, int8_t *key);
void radix_free(Radix *);

#endif
