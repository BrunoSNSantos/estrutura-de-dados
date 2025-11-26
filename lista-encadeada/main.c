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
   return;
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
    return;
}

void inserir_meio(struct no **l, int valor, int novo_valor) {
    if (*l == NULL) return;

    struct no *auxp = *l;
    while (auxp != NULL && auxp->valor != valor) {
        auxp = auxp->prox;
    }

    if (auxp == NULL) return;

    struct no *novo_no = malloc(sizeof(struct no));
    novo_no->valor = novo_valor;

    novo_no->prox = auxp->prox;
    auxp->prox = novo_no;

    return;
}

struct no* remover_inicio(struct no **l) {
    if (*l == NULL) return *l;
    
    struct no *aux = *l;
    *l = aux->prox;
    free(aux);
    
    return *l;
}

void remover_fim(struct no **l) {
    if (*l == NULL) return;

    if ((*l)->prox == NULL) {
        free(*l);
        *l = NULL;
        return;
    }

    struct no *auxp = *l;
    struct no *ant = NULL;

    while (auxp->prox != NULL) {
        ant = auxp;
        auxp = auxp->prox;
    }
    ant->prox = NULL;
    free(auxp);
    return;
}

void remover_valor(struct no **l, int valor) {
    if (*l == NULL) return;

    struct no *auxp = *l;
    struct no *ant = NULL;
    
    while (auxp != NULL && auxp->valor != valor) {
        ant = auxp;
        auxp = auxp->prox;
    }

    if (auxp == NULL) return;

    if (ant == NULL) {
        *l = auxp->prox;
        free(auxp);
        return;
    }

    ant->prox = auxp->prox;
    free(auxp);

    return;
}

void alterar(struct no **l, int valor, int novo_valor) {
    if (*l == NULL) return;

    struct no *auxp = *l;

    while (auxp != NULL && auxp->valor != valor) {
        auxp = auxp->prox;
    } 
    if (auxp == NULL) return;

    auxp->valor = novo_valor;
    return;
}

struct no* copiar(struct no **l) {
    struct no *nova_lista = NULL;
    struct no *aux = *l;

    while (aux != NULL) {
        inserir_fim(&nova_lista, aux->valor);
        aux = aux->prox;
    }

    return nova_lista;
}

struct no** ordenar(struct no **l) 
{
    struct no *nl = NULL;

    while (*l != NULL) {

        struct no *aux = *l;
        *l = (*l)->prox;

        struct no *aux_p = nl;  
        struct no *ant = NULL;

        while (aux_p != NULL && aux->valor > aux_p->valor) {
            ant = aux_p;
            aux_p = aux_p->prox;
        }

        // insere no começo
        if (ant == NULL) {
            aux->prox = nl;
            nl = aux;
        }
        // insere no meio ou fim
        else {
            ant->prox = aux;
            aux->prox = aux_p;   // aux_p pode ser NULL → insere no fim
        }
    }

    *l = nl;
    return l;
}

struct no *buscar(struct no **l, int valor) {
    if (*l == NULL ) return NULL;

    struct no *auxp = *l;
    while(auxp != NULL) {
        if (auxp->valor == valor) {
            return auxp;
        } 
        auxp = auxp->prox;
    }

    return NULL;
}

void liberar(struct no **l) {
    struct no *auxp;

    while (*l != NULL) {
        auxp = *l;
        *l = (*l)->prox;
        free(auxp);
    }
}

int main() {
    struct no *lista = NULL;

    inserir_inicio(&lista, 3);
    inserir_inicio(&lista, 5);
    inserir_inicio(&lista, 7);

    imprimir(lista);

    inserir_fim(&lista, 9);
    imprimir(lista);

    ordenar(&lista);
    imprimir(lista);

    buscar(&lista, 1);

    remover_inicio(&lista);
    imprimir(lista);

    remover_fim(&lista);
    imprimir(lista);

    remover_valor(&lista, 5);
    imprimir(lista);

    remover_valor(&lista, 10);
    imprimir(lista);

    alterar(&lista, 7, 10);
    imprimir(lista);

    alterar(&lista, 2, 4);
    imprimir(lista);

    inserir_meio(&lista, 10, 7);
    imprimir(lista);

    return 0;
}