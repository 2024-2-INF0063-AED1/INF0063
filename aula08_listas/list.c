#include <stdio.h>
#include <stdlib.h>

// Elementos da pilha
struct Node {
    int value;
    struct Node* next;
};
typedef struct Node Node;

// Lista contendo ponteiros para o inicio e fim da lista
struct List {
    struct Node* start;
    struct Node* end;
};
typedef struct List List;

// Ponteiro auxiliar
Node* aux;
Node* prev;

List* create();
void insertStart(List* x);
void insertEnd(List* x);
void delete(List* x);
void clean(List* x);
void show(List* x);

int main() {
    List* x = create();

    insertStart(x);
    insertStart(x);
    insertEnd(x);
    show(x);
    delete(x);
    show(x);
    clean(x);
    show(x);

    return 0;
}

// Criar lista
List* create() {
    List* x = (List*) malloc(sizeof(List));
    if(x != NULL) {
        x->start = NULL;  // Inicio da lista (vazia)
        x->end = NULL;  // Fim da lista (vazia)
    }
    
    return x;
}

// Insercao de elementos no inicio
void insertStart(List* x) {
    // Alocamos espaco para um novo elemento
    Node* new = (Node*) malloc(sizeof(Node));
    
    printf("Insera um numero: ");
    scanf("%d", &new->value);

    // Caso a lista esteja vazia
    if(x->start == NULL) {
        x->start = new;
        new->next = NULL;
        x->end = new;
    }
    // Caso nao esteja
    else {
        new->next = x->start;
        x->start = new;
    }
    printf("Numero %d inserido no inicio da lista!\n", new->value);
}

// Insercao de elementos no final
void insertEnd(List* x) {
    // Alocamos espaco para um novo elemento
    Node* new = (Node*) malloc(sizeof(Node));
    
    printf("Insera um numero: ");
    scanf("%d", &new->value);

    // Caso a lista esteja vazia
    if(x->start == NULL) {
        x->start = new;
        new->next = NULL;
        x->end = new;
    }
    // Caso nao esteja
    else {
        x->end->next = new;
        x->end = new;
        x->end->next = NULL;
    }
    printf("Numero %d inserido no final da lista!\n", new->value);
}

// Remover elemento
void delete(List* x) {
    int number;
    int found; // contador de numeros removidos

    // Caso a lista esteja vazia
    if(x->start == NULL)
        printf("Lista vazia!\n");
    // Caso nao esteja
    else {
        printf("Digite o elemento a ser removido: ");
        scanf("%d", &number);
        // Fazemos aux apontar para o endereco que inicio aponta
        aux = x->start;
        // Fazemos prev apontar para NULL
        prev = NULL;
        found = 0;
        do {
            // caso aux->value seja igual ao numero a ser removido
            if(aux->value == number) {
                found++; // Incrementa o contador
                // Se for o primeiro da lista
                if(aux == x->start) {
                    // inicio apontara para o segundo elemento da lista ou para NULL
                    // caso o elemento removido seja o unico elemento da lista
                    x->start = aux->next;
                    // desalocamos o espaco para onde aux apontava
                    free(aux);
                    // aux aponta para o inicio da lista
                    aux = x->start;
                }
                // Se for o ultimo da lista
                else if (aux == x->end) {
                    // o elemento anterior a fim, no atributo prox apontará para NULL
                    prev->next = NULL;
                    // fim aponta para o elemento apontado por anterior
                    x->end = prev;
                    // Desalocamos o espaco para onde aux apontava
                    free(aux);
                    // Como era o ultmo elemento da lista, aux recebe NULL
                    aux = NULL;
                }
                // Se nao for nem o primeiro nem o ultimo da lista
                else {
                    // o elemento anterior ao elemento a ser removido, no atributo prox apontará para o elemento
                    // para qual aux->next apontava
                    prev->next = aux->next;
                    // Desalocamos o espaco para onde aux apontava
                    free(aux);
                    // aux aponta para o proximo elemento da lista, aquele que era o seguinte ao numero removido
                    aux = prev->next;
                }
            }
            // caso aux->value nao seja igual ao numero a ser removido
            else {
                prev = aux;
                aux = aux->next;
            }
        // Essa operacao sera feita ate aux ser diferente de NULL, ou seja, nao houverem mais elementos a serem pesquisados
        } while(aux != NULL);

        // Impressao do resultado
        if(found == 0)
            printf("Numero nao encontrado!\n");
        else
            printf("Numero %d removido %d vez(es)\n", number, found);
    }
}

// Esvaziar lista
void clean(List* x) {
    if(x->start == NULL)
        printf("Lista vazia!\n");
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
void show(List* x) {
    // Caso a pilha esteja vazia
    if(x->start == NULL)
        printf("Estado da lista: Lista vazia!\n");
    // Caso nao esteja
    else {
        aux = x->start;
        printf("Estado da lista: |");
        do {
            printf(" %d |", aux->value);
            aux = aux->next;
        } while(aux != NULL);
        printf("\n");
    }
}

