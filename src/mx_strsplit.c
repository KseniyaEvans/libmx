#include "libmx.h"

static void my_count_sub_size(int *i, int *sub_size, const char *s, char c) {
    while (s[(*i)++] == c)
        continue; // Skipping delims at the beginning
    while (s[*i] != c) {
        (*i)++; // Counting size of the next word
        (*sub_size)++;
    }
}

char **mx_strsplit(const char *s, char c) {
    if (s) {
        int size = mx_count_words(s, c);
        int sub_size = 0; // Size of each el of array
        int i = 0;
        
        if (size > 0) {
            char **arr = (char **)malloc(size * sizeof(char *) + 1);
            
            for (int j = 0; j < size; j++) {
                my_count_sub_size(&i, &sub_size, s, c);
                arr[j] = mx_strnew(sub_size);
                i = i - sub_size - 1; // Moving counter to the start of the word
                for (int f = 0; f <= sub_size; f++)
                    arr[j][f] = s[i++];
                i++;
                sub_size = 0;
            }
            arr[size] = NULL;
            return arr;
        }
    }
    return NULL;
}
