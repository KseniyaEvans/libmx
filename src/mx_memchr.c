#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const char * ptr = (const char *)s;
	
	for (size_t i = 0; i < n; i++) {
		if (ptr[i] == c)
			return (void *)&ptr[i];
    }
	return NULL;
}
