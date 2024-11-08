#include <stdio.h>
#include <stdlib.h>

// Elementos da pilha
struct Node {
    int value;
    struct Node* next;
};
typedef struct Node Node;

// Pilha contendo um ponteiro para o topo da pilha
struct Stack {
    struct Node* top;
};
typedef struct Stack Stack;

// Ponteiro auxiliar
Node* aux;

Stack* create();
void push(Stack* x);
void pop(Stack* x);
void clean(Stack* x);
void show(Stack* x);

int main() {
    Stack* x = create();

    push(x);
    push(x);
    push(x);
    show(x);
    pop(x);
    show(x);
    clean(x);
    show(x);

    return 0;
}

// Criar pilha
Stack* create() {
    Stack* x = (Stack*) malloc(sizeof(Stack));
    if(x != NULL)
        x->top = NULL;  // Inicio da pilha (vazia)
    
    return x;
}

// Insercao de elementos
void push(Stack* x) {
    // Alocamos espaco para um novo elemento
    Node* new = (Node*) malloc(sizeof(Node));

    printf("Insera um numero: ");
    scanf("%d", &new->value);

    // Atualizamos o topo
    new->next = x->top;
    // Topo aponta para o endereço de novo
    x->top = new;
    printf("Numero %d inserido na pilha!\n", new->value);
}

// Remover elemento (FILO)
void pop(Stack* x) {
    if(x->top == NULL)
        printf("\nPilha vazia!");
    else {
        aux = x->top;
        printf("Numero %d removido!\n", x->top->value);
        x->top = x->top->next;
        free(aux);
    }
}

// Esvaziar pilha
void clean(Stack* x) {
    if(x->top == NULL)
        printf("Pilha vazia!\n");
    else {
        aux = x->top;
        do {
            x->top = x->top->next;
            free(aux);
            aux = x->top;
        } while(aux != NULL);
        printf("Pilha esvaziada!\n");
    }
}

// Mostra pilha (LIFO)
void show(Stack* x) {
    // Caso a pilha esteja vazia
    if(x->top == NULL)
        printf("Estado da pilha: Pilha vazia!\n");
    // Caso nao esteja
    else {
        aux = x->top;
        printf("Estado da pilha: |");
        do {
            printf(" %d |", aux->value);
            aux = aux->next;
        } while(aux != NULL);
        printf("\n");
    }
}

