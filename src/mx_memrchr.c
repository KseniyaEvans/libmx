#include "libmx.h"

void * mx_memrchr(const void * s, int c, size_t n) {
    int i = 0;
	const unsigned char * ss = s;

	for (i = n - 1; i >= 0; i--) {
	    if (ss[i] == (unsigned char)c)
			return (void *)(ss + i);
	}
	return NULL;
}
