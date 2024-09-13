#include <stdio.h>

#define N 3

void main()
{
    int numeros[N];
    
    for(int i=0; i<N; i++){
        printf("Digite o %dº número: ", i+1);
        scanf("%d", &numeros[i]);
    }
    
    for(int i=0; i<N; i++){
        printf("%d \n", numeros[N-i-1]);
    }
}

