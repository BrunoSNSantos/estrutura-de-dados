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

void inserir_fim(struct no **l, int valor) {
    struct no *novo_no = malloc(sizeof(struct no));
    novo_no->valor = valor;
    novo_no->prox = NULL;

    if (*l == NULL) {
        novo_no->ant = NULL;
        *l = novo_no;

        return;
    }

    struct no *auxp = *l;
    while(auxp->prox != NULL) {
        auxp = auxp->prox;
    }
    auxp->prox = novo_no;
    novo_no->ant = auxp;
    
    return;
}

struct no* buscar(struct no **l, int valor) {
    if (*l == NULL) return NULL;

    struct no *auxp = *l;
    while (auxp && auxp->valor != valor) {
        auxp = auxp->prox;
    }
    return auxp; 
}

void remover (struct no **l, int valor) {
    if (*l == NULL) return;

    struct no *auxp = *l;

    while (auxp && auxp->valor != valor) {
        auxp = auxp->prox;
    }

    if (auxp == NULL) return;

    if (auxp->ant == NULL) {
        *l = auxp->prox;
        if (auxp->prox != NULL) {
            auxp->prox->ant = NULL;
        }
        free(auxp);

        return;
    }

    if (auxp->prox == NULL) {
        auxp->ant->prox = NULL;
        free(auxp);

        return;
    }
    
    auxp->ant->prox = auxp->prox;
    auxp->prox->ant = auxp->ant;
    free(auxp);

    return;
}