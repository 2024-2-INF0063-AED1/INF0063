#include <stdio.h>

// Redefinindo os tipos float e int
typedef float nota;
typedef int   inteiro;

struct tAluno {
    inteiro matricula;
    nota prova1;
    nota prova2;
};

// Redefinindo uma struct (encurta o comando na declaracao)
typedef struct tAluno tAluno;

int main(void) {
    tAluno aluno;
    nota media = 0;
  
    printf("Informe o numero de matricula: ");
    scanf("%d", ...);
    printf("Informe a nota da primeira prova: ");
    scanf("%f", ...);
    printf("Informe a nota da segunda prova: ");
    scanf("%f", ...);

    media = (...  + ...) / 2;

    printf("\nMatricula.....: %d\n", );
    printf("Media do aluno: %.1f\n", );
    getchar();

    return(0);
}
