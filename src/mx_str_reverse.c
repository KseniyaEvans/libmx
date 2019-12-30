#include "libmx.h"

void mx_str_reverse(char *s) {
    int length = mx_strlen(s);
    int j = 0;
    int i = 0;

    for (i = length - 1; i >= length/2; i--) {
        mx_swap_char(&s[i], &s[j]);
        j++;
    }
}
