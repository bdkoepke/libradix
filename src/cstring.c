#include "cstring.h"
#include "math.h"

#include <string.h>

char *cstr_from_string(const String *this) {
  char *c = malloc(sizeof(char) * (this->length + 1));
  memcpy(c, this->string, this->length);
  c[this->length] = '\0';
  return c;
}

Compare strcmp_s(const char *src, size_t src_len, const char *dst,
              size_t dst_len) {
	size_t len = min(src_len, dst_len);
  size_t i;
  for (i = 0; i < len; i++)
    if (src[i] < dst[i])
			return LessThan;
		else if (src[i] > dst[i])
			return GreaterThan;
  return EqualTo;
}
