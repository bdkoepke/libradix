#include <stdbool.h>
typedef struct _Maybe Maybe;

Maybe *maybe_new_just(void *);
Maybe *maybe_nothing();
bool maybe_is_just(Maybe *);
bool maybe_is_nothing(Maybe *);
void *maybe_from_just(Maybe *);
void *maybe_from_maybe(Maybe *, void *default_value);
void maybe_free(Maybe *);
