#include <stdio.h> 
#include <stdlib.h>

struct no {
    int valor;
    struct no *prox;
};

void imprimir(struct no *l) {
    while (l != NULL) {
        printf("%d -> ", l->valor);
        l = l->prox;
    }
    printf("NULL\n");
}

void inserir_inicio(struct no **l, int valor) {
    struct no *aux = malloc(sizeof(struct no));
    aux->valor = valor;
    aux->prox = *l;
    *l = aux;
}

void inserir_fim(struct no **l, int valor) {
    struct no *nvalor = malloc(sizeof(struct no));
    nvalor->valor = valor;
    nvalor->prox = NULL;

    struct no *auxp;
    auxp=*l;

    while(auxp->prox!=NULL) {
        auxp=auxp->prox;
    }
    auxp->prox=nvalor;
}

struct no *buscar(struct no **l, int valor) {
    struct no *auxp;
    auxp = *l;

    while(auxp != NULL) {
        if (auxp->valor == valor) {
            return auxp;
        } 
        auxp = auxp->prox;
    }

    return NULL;
}


int main() {
    struct no *lista = NULL;

    inserir_inicio(&lista, 3);
    inserir_inicio(&lista, 5);
    inserir_inicio(&lista, 7);

    imprimir(lista);

    inserir_fim(&lista, 9);

    imprimir(lista);

    buscar(&lista, 1);

    return 0;
}