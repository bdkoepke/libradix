#include <assert.h>
#include <stdlib.h>
#include "maybe.h"

struct _Maybe {
  void *just;
};

Maybe *maybe_new_just(void *this) { return this; }

Maybe *maybe_nothing() { return NULL; }

bool maybe_is_just(Maybe *this) { return this != NULL; }

bool maybe_is_nothing(Maybe *this) { return this == NULL; }

void *maybe_from_just(Maybe *this) {
  assert(maybe_is_just(this));
  return this;
}

void *maybe_from_maybe(Maybe *this, void *default_value) {
  return maybe_is_just(this) ? this : default_value;
}

void maybe_free(Maybe *this) {}
