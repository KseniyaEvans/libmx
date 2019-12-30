#include "libmx.h"

void * mx_memcpy(void * restrict dst, const void * restrict src, size_t n) {
    char *pszDest = (char *)dst;
    const char *pszSource =( const char*)src;
    
    while (n) {
        *(pszDest++)= *(pszSource++); 
        --n;
    }
    return dst;
}
