#include "radix.h"
#include "cstring.h"
#include <stdio.h>

int main() {
  Radix *r = radix_new();
  radix_insert(r, "this is a key", "this is a value");
  char *v = cstr_from_string(maybe_from_just(radix_lookup(r, "this is a key")));
  puts(v);
  radix_dump(r);
  radix_free(r);
  free(v);
}
