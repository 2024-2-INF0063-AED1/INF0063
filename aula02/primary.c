#include <stdio.h>

int main(){
    unsigned char;
    signed char; 
    double;
    long double;
    unsigned int;
    signed int;
    short;
    long;
    long long;
    void;

    /* Tamanho do tipo de dado
       %lu: usado para valores 'unsigned long'
       %zu: usado para valores 'size_t' (unsigned long)
    */ 
    printf("Tamanho do uchar    : bytes\n", ...);
    printf("Tamanho do schar    : bytes\n", ...);
    printf("Tamanho do double   : bytes\n", ...);
    printf("Tamanho do ldouble  : bytes\n", ...);
    printf("Tamanho do uint     : bytes\n", ...);
    printf("Tamanho do sint     : bytes\n", ...);
    printf("Tamanho do short    : bytes\n", ...);
    printf("Tamanho do long     : bytes\n", ...);
    printf("Tamanho do long long: bytes\n", ...);
    printf("Tamanho do void     : bytes\n", ...);
    printf("Tamanho do size_t   : bytes\n", ...);

    return 0;
}
