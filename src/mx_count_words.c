#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int res = -1;
    int flag = 0;
    int i = 0;

    if (str) {
        int len = mx_strlen(str);

        res = 0;
        for (i = 0; str[i] == c; i++)
            continue; // Skiping delims at the beginning
        for ( ; i <= len; i++) {
            if ((str[i] == c || str[i] == '\0') && flag == 1) { // If we were inside the word
                flag = 0; // Out of the word
                res++;
            }
            else if (!(str[i] == c))
                flag = 1; // In the word
        }
    }
    return res;
}
