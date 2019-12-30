#include "libmx.h"

char * mx_nbr_to_hex(unsigned long nbr) {
    unsigned long nb = nbr;
    int i = 1;
    int temp = 0;

    if (!nbr) return "0";
    while (nb /= (unsigned long)16) 
        i++;
    char * new = (char *)malloc(sizeof(char) * (i + 1));
    
    new[i] = '\0';
    while (nbr != 0) {
        i--;
        temp = 0;
        temp = nbr % (unsigned long)16;
        if (temp < 10) new[i] = temp + 48;
        else new[i] = temp + 87;
        nbr = nbr / (unsigned long)16;
    }
    return new;
}
