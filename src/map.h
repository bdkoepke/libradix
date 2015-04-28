typedef struct _Map Map;

bool map_null();
size_t map_size();
bool map_member(void *key);
bool map_not_member(void *key);
void *map_lookup(void *key);

