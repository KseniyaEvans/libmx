#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int min = 0; 
    int max = size - 1; 
    int mid = (min + max) / 2;

    *count = 0;
    if (arr == NULL || s == NULL || size < 0) {
        *count = 0;
        return -1;
    }
    while (min <= max) { 
        *count = *count + 1;
        if (mx_strcmp(s, (arr[mid])) == 0)
            return mid;
        else if (mx_strcmp(arr[mid], s) < 0)
            min = mid + 1;
        else if (mx_strcmp(arr[mid], s) > 0)
            max = mid - 1;
        mid = (min + max) / 2;
    } 
    *count = 0;
    return -1;
}
