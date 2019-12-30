#include "libmx.h"

static size_t	mx_wcharlen(wchar_t wc) {
	if (wc < 0x80)
		return (1);
	else if (wc < 0x800)
		return (2);
	else if (wc < 0x10000)
		return (3);
	return (4);
}

void mx_print_unicode(wchar_t c) {
	char tmp[4];
    size_t nb_bytes = mx_wcharlen(c);

    if (nb_bytes == 1) tmp[0] = c;
    else {
        if (nb_bytes == 2) 
            tmp[0] = ((c & (0x1f << 6)) >> 6) | 0xC0;
        else {
            if (nb_bytes == 3)
                tmp[0] = (( c >> 12) & 0xf) | 0xE0;
            else {
                tmp[0] = (( c >> 18) & 7) | 0xF0;
                tmp[1] = (( c >> 12) & 0x3f) | 0x80;
            }
            tmp[nb_bytes - 2] = (( c >> 6) & 0x3f) | 0x80;
        }
        tmp[nb_bytes - 1] = ( c & 0x3f) | 0x80;
    }
    write(1, tmp, nb_bytes);
}
