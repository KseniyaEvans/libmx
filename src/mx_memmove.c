#include "libmx.h"

void * mx_memmove(void * dst, const void * src, size_t len) {
    register char *dp = dst;
	register char const *sp = src;

	if (dp < sp) {
		while (len-- > 0) 
			*dp++ = *sp++;
	} else {
		dp += len;
		sp += len;
		while (len-- > 0) 
			*--dp = *--sp;
	}
	return dst;
}
