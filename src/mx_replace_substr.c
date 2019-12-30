#include "libmx.h"

static void counters(int * cnt, int * i, char * str, char * sub, int oldWlen) {
    for (*i = 0; str[*i] != '\0'; *i += 1) {
        if (mx_strstr(&str[*i], sub) == &str[*i]) { 
            *cnt += 1;
            *i += oldWlen - 1;
        }
    }
}

char * mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace)
        return NULL;
    char *result;
    int i = 0;
    int cnt = 0;
    int newWlen = mx_strlen(replace);
    int oldWlen = mx_strlen(sub);
    
    counters(&cnt, &i, (char *)str, (char *)sub, oldWlen);
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);
    i = 0;
    while (*str) {
        if (mx_strstr(str, sub) == str) {
            mx_strcpy(&result[i], replace);
            i += newWlen;
            str += oldWlen;
        } else result[i++] = *str++; 
    }
    result[i] = '\0';
    return result;
}
