#include <stdio.h>

// Uma unica variavel que representa multipos tipos de dados
union Data {
    int   intN;
    float floatF;
} data; 

int main() {
    union Data data;

    data.intN = 5;
    data.floatF = 3.4;

    printf("%d\n", data.intN);
    printf("%f\n", data.floatF);

    return(0);
}

