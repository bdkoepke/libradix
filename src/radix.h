#ifndef RADIX_H
#define RADIX_H

#include "maybe.h"

typedef struct _Radix Radix;

Radix *radix_new();
Maybe *radix_lookup(const Radix *, const char *key);
void radix_insert(Radix *, const char *key, const char *value);
void radix_dump(const Radix *);
void radix_free(Radix *);

#endif
