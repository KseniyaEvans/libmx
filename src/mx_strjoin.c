#include "libmx.h"

char * mx_strjoin(const char * s1, const char * s2) {
    if (s1 == NULL && s2 != NULL)
        return mx_strdup(s2);
    if (s1 != NULL && s2 == NULL)
        return mx_strdup(s1);
    if (s1 == NULL && s2 == NULL)
        return NULL;

    char * new = mx_strnew(mx_strlen(s1) + mx_strlen(s2));

    if (!new)
        return NULL;
    mx_strcpy(new, s1);
    mx_strcat(new, s2);
    return new;
}
