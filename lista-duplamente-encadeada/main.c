#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    struct no *ant;
    struct no *prox;
};

void inserir_comeco(struct no **l, int valor) {
    struct no *aux = malloc(sizeof(struct no));
    aux->valor = valor;
    aux->ant = NULL;

    if (*l == NULL) {
        aux->prox = NULL;
        *l = aux;
        return;
    }
    aux->prox = *l;
    (*l)->ant = aux;
    *l = aux;
    return;
}
