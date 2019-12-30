#include "libmx.h"

int mx_sqrt(int x) {
    float new = x;

    for (int i = 1; i <= x/2 + 1; i++) {
        if (new / (float)i == (float)i) {
            return i;
        }
    }
    return 0;
}
