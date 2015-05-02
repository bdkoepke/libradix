#include "cstring.h"
#include <string.h>

char *cstr_from_string(const String *this) {
  char *c = malloc(sizeof(char) * (this->length + 1));
  memcpy(c, this->string, this->length);
  c[this->length] = '\0';
  return c;
}

bool strcmp_s(const char *src, size_t src_len, const char *dst,
              size_t dst_len) {
  if (src_len != dst_len)
    return false;
  size_t i;
  for (i = 0; i < src_len; i++)
    if (src[i] != dst[i])
      return false;
  return true;
}
