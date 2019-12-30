char *mx_strcpy(char *dst, const char *src) {
    char *d = dst;
    int i = 0;
    
    while ( (dst[i] = src[i]) != '\0') {
        i++;
    }
    return d;
}
