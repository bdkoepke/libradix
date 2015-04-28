#include <assert.h>
#include <stdlib.h>
#include "maybe.h"

int main() {
	Maybe *m = maybe_nothing();
	assert (maybe_is_nothing(m));
	maybe_free(m);
	size_t test = 100;
	m = maybe_new_just((void *)test);
	assert (maybe_is_just(m));
	size_t ref = maybe_from_just(m);
	maybe_free(m);
}
