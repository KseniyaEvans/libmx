#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    int i = -1;
    
    if (arr && delim) {
        while (arr[++i]) {
            mx_printstr(arr[i]);
            if (arr[i + 1])
                mx_printstr(delim);
        }
        mx_printchar('\n');
    }
}
