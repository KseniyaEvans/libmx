#include "libmx.h"

bool mx_isspace(char c) {
    return (c == ' ' 
    || c == '\n' 
    || c == '\f' 
    || c == '\r' 
    || c == '\t' 
    || c == '\v');
}
