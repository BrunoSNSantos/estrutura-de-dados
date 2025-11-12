#include <stdio.h> 
#include <stdlib.h>

struct no {
    int valor;
    struct no *prox;
};

int main() {
    struct no *lista = NULL;
    struct no *e1;

    e1=malloc(sizeof(struct no));
    e1->valor = 3;
    e1->prox = NULL;
    lista = e1;

    struct no *aux;
    aux=malloc(sizeof(struct no));
    aux->valor=5;
    aux->prox=e1;
    lista=aux;

    free(e1);
    free(aux);

    return 0;
}