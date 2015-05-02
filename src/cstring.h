#ifndef CSTRING_H
#define CSTRING_H

#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct String {
	uint8_t length;
	uint8_t string[UINT8_MAX];
} String;

char *cstr_from_string(const String *);
bool strcmp_s(const char *src, size_t src_len, const char *dst, size_t dst_len);

#endif
