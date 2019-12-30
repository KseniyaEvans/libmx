#include "libmx.h"

static int count_spaces(const char *str) {
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i]))
            res++;
    }
    return res;
}

static int count_words_ver2(const char *str) {
    int res = -1;
    int flag = 0;
    int i = 0;

    if (str) {
        int len = mx_strlen(str);

        res = 0;
        for (i = 0; mx_isspace(str[i]); i++)
            continue; // Skiping whitespaces at the beginning
        for ( ; i <= len; i++) {
            if ((mx_isspace(str[i]) || str[i] == '\0') && flag == 1) { // If we were inside the word
                flag = 0; // Out of the word
                res++;
            }
            else if (!mx_isspace(str[i]))
                flag = 1; // In the word
        }
    }
    return res;
}

char *mx_del_extra_spaces(const char *str) {
    if (!str)
        return NULL;

    char *tr_str = NULL;
    int spaces = count_spaces(str);
    int words = count_words_ver2(str);
    int new_size = mx_strlen(str) - spaces + words - 1;

    tr_str = mx_strnew(new_size);
    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        if (mx_isspace(str[i])) // skiping space symbols
            continue;
        else {
            while (!mx_isspace(str[i]))
                tr_str[j++] = str[i++];
            tr_str[j++] = ' '; // separating words with space
        }
    }
    tr_str[new_size] = '\0'; // deleting extra space at the end
    return tr_str;
}
