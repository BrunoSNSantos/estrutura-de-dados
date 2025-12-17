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

void mostrar(struct no **l) {
    struct no *aux = *l;
    printf("[ ");
    while(aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }

    printf("] ");
}

void liberar(struct no **l) {
    if (*l == NULL) return;

    struct no *auxp = *l;
    struct no *prox = *l;

    while(auxp != NULL) {
        prox = auxp->prox;
        free(auxp);
        auxp = prox;
    }

    *l = NULL;
}

struct tabela_hashing {
    void **p;
    int tamanho;
};

void th_iniciar(struct tabela_hashing *th, int tamanho) {
    th->tamanho = tamanho;
    th->p = malloc(th->tamanho * sizeof(int *));

    for(int i; i < th->tamanho; i++) {
        th->p[i] = NULL;
    }
}

void th_inserir(struct tabela_hashing *th, int valor) {
    int pos = valor % th->tamanho;
    struct no **l = (struct no **)&th->p[pos];
    inserir_comeco(l, valor);
}


void th_remover(struct tabela_hashing *th, int valor) { 
    int pos = valor % th->tamanho;
    struct no **l = (struct no **)&th->p[pos];
    remover(l, valor);
}

void *th_pegar(struct tabela_hashing *th, int valor) {
    int pos = valor % th->tamanho;
    struct no **l = (struct no **)&th->p[pos];
    return buscar(l, valor);
}

void th_mostrar(struct tabela_hashing *th) {
    printf("{ tabela hashing:\n");
    for (int i = 0; i < th->tamanho; i++) {
        printf(" [%d]: ", i);
        mostrar((struct no **)&th->p[i]);
        printf("\n");
    }
    printf("}\n");
}

void th_finalizar(struct tabela_hashing *th) {
    for (int i = 0; i < th->tamanho; i++) {
        struct no **l = (struct no **)&th->p[i];
        liberar(l);
    }
    free(th->p);
}