#include <stdio.h>
#include <stdlib.h>

// Elementos da pilha
struct Node {
    int value;
    struct Node* next;
};
typedef struct Node Node;

// Fila contendo ponteiros para o inicio e fim da fila
struct Queue {
    struct Node* start;
    struct Node* end;
};
typedef struct Queue Queue;

// Ponteiro auxiliar
Node* aux;

Queue* create();
void push(Queue* x);
void pop(Queue* x);
void clean(Queue* x);
void show(Queue* x);

int main() {
    Queue* x = create();

    push(x);
    push(x);
    push(x);
    show(x);
    pop(x);
    clean(x);
    show(x);

    return 0;
}

// Criar pilha
Queue* create() {
    Queue* x = (Queue*) malloc(sizeof(Queue));
    if(x != NULL) {
        x->start = NULL;  // Inicio da fila (vazia)
        x->end = NULL;  // Fim da fila (vazia)
    }
    
    return x;
}

// Insercao de elementos
void push(Queue* x) {
    // Alocamos espaco para um novo elemento
    Node* new = (Node*) malloc(sizeof(Node));
    
    printf("Insera um numero: ");
    scanf("%d", &new->value);

    // Atualizamos o topo
    new->next = NULL;
    // Caso a fila esteja vazia
    if(x->start == NULL) {
        x->start = new;
        x->end = new;
    }
    // Caso a fila contenha algum elemento, inserir no final
    else {
        x->end->next = new;
        x->end = new;
    }
    printf("Numero %d inserido na fila!\n", new->value);
}

// Remover elemento (FILO)
void pop(Queue* x) {
    if(x->start == NULL)
        printf("\nFila vazia!");
    else {
        aux = x->start;
        printf("Numero %d removido!\n", x->start->value);
        x->start = x->start->next;
        free(aux);
    }
}

// Esvaziar fila
void clean(Queue* x) {
    if(x->start == NULL)
        printf("Fila vazia!\n");
    else {
        aux = x->start;
        do {
            x->start = x->start->next;
            free(aux);
            aux = x->start;
        } while(aux != NULL);
        printf("Fila esvaziada!\n");
    }
}

// Mostra fila (FIFO)
void show(Queue* x) {
    // Caso a pilha esteja vazia
    if(x->start == NULL)
        printf("Estado da fila: Fila vazia!\n");
    // Caso nao esteja
    else {
        aux = x->start;
        printf("Estado da pilha: |");
        do {
            printf(" %d |", aux->value);
            aux = aux->next;
        } while(aux != NULL);
        printf("\n");
    }
}

