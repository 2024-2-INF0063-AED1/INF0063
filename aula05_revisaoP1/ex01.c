#include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define VMAX 
# define VMIN 

void somaVetor(int *p, int *q, int tamanho) {
}

void mostraVetor(int *p, int tamanho) {
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int N; // tamanho do vetor \
              (inferir a partir dos dados de entrada)

    N = ...;
    int v1[N]; // dado
    int v2[N]; // aleatorio

    // Vetor dado
    

    // Vetor aleatorio


    printf("Vetor 1: ");
    mostraVetor(v1, N);
    
    printf("Vetor 2: ");
    mostraVetor(v2, N);
    
    somaVetor(v1, v2, N);
    
    printf("Soma   : ");
    mostraVetor(v1, N);

    return 0;
}
