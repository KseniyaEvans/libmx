#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (!str || !sub)
        return -2;
    int index = -1;
    char *temp = mx_strstr(str, sub);
    
    if (temp) { 
        index = temp - str;
    }
    return index;
}
