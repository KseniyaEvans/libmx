#include "libmx.h"

static void neg(int * n, int * sign) {
    if (*n < 0) {
		*n *= -1;
		*sign = 1;
	}
}

char * mx_itoa(int number) {
    int tmp = number;
	int l = 2;
	int sign = 0;
	char *ret;

	if (number == -2147483648)
        return (mx_strdup("-2147483648"));
	neg(&number, &sign);
	while (tmp /= 10)
        l++;
	l += sign;
	if ((ret = (char*)malloc(l)) == NULL)
        return (NULL);
	ret[--l] = '\0';
	while (l--) {
		ret[l] = number % 10 + '0';
		number /= 10;
	}
	if (sign)
        ret[0] = '-';
	return (ret);
}
