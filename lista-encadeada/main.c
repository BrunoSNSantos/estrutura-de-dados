#include <stdio.h> 
#include <stdlib.h>

struct no {
    int valor;
    struct no *prox;
};

void inserir_inicio(struct no **l, int valor) {
    struct no *aux = malloc(sizeof(struct no));
    aux->valor = valor;
    aux->prox = *l;
    *l = aux;
}

void imprimir(struct no *l) {
    while (l != NULL) {
        printf("%d -> ", l->valor);
        l = l->prox;
    }
    printf("NULL\n");
}


int main() {
    struct no *lista = NULL;

    inserir_inicio(&lista, 3);
    inserir_inicio(&lista, 5);
    inserir_inicio(&lista, 7);

    imprimir(lista);

    return 0;
}