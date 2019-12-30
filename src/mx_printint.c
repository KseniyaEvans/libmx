#include "libmx.h"

void mx_printint(int n) {
    long long int new = (long long int)n;

    if (new < 0) {
        new = -new;
        mx_printchar('-');
    }
    if (new > 9)
        mx_printint(new / 10);
    if (new < 10)
        mx_printchar('0' + new);
    if (new >= 10) {
        int k = new - (new / 10) * 10;

        mx_printchar('0' + k);
    }
}
