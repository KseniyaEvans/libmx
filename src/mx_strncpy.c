char *mx_strncpy(char *dst, const char *src, int len) {
    char *d = dst;
    
    while (*src != '\0' && len-- != 0) {
        *dst = *src;
        src++;
        dst++;
    }
    return d;
}
