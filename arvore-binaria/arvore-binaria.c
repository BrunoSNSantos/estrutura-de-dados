#include <stdio.h>
#include <stdlib.h>

struct no_a {
    int valor;
    struct no_a *esq;
    struct no_a *dir;
}; 

void inserir(struct no_a **a, int valor) {
    struct no_a *aux = malloc(sizeof(struct no_a));
    aux->valor = valor;
    aux->esq = NULL;
    aux->dir = NULL;

    if (*a == NULL) {
        *a = aux;
    }
}

int main () {
    struct no_a *arvore = NULL;

    return 0;
}