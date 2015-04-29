#include "radix.h"
#include <stdint.h>
#include <stdlib.h>

struct _Radix {
	int16_t length;
	int8_t *tree;
};

Radix *radix_new() {
	size_t DEFAULT_LENGTH = 32 * 1024;
	Radix *r = malloc(sizeof(Radix));
	r->length = DEFAULT_LENGTH;
	r->tree = malloc(sizeof(int8_t) * r->length);
	return r;
}

bool radix_member(Radix *this, int8_t *key) {
}

Maybe *radix_lookup(Radix *this, int8_t *key) {
}

void radix_free(Radix *this) {
	free(this->tree);
	free(this);
}
