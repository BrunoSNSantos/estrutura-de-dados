#include <stdio.h> 
#define capacidade 10

struct fila {
    int vetor[capacidade];
    int tam;
};

void inicializar_fila(struct fila *fila) {
    fila -> tam = 0;
}

void finalizar_fila(struct fila *fila) {
}

int inserir(struct fila *fila, int valor)
{
if(fila->tam >= capacidade)
    return 0;

fila->vetor[fila->tam] = valor;
fila->tam++;
    return 1;
}

int tamanho(struct fila *fila) {
    return fila->tam;
}

int remover(struct fila *fila) {
    if (tamanho(fila)<=0) {
        return 0;
    }
    for (int i = 0; i < fila->tam; i++) {
        fila->vetor[i] = fila->vetor[i+1];
    }
    fila->tam--;
    return 1;
}

void imprimir_fila(struct fila *fila)
{
printf("[ ");
for(int i = 0; i < fila->tam; i++){
printf("%d ", fila->vetor[i]);
}
printf("]\n");
}

int obter_primeiro(struct fila *fila) {
    int primeiro = fila->vetor[0];
    printf("%d\n", primeiro);
    return primeiro;
}

int esta_vazia(struct fila *fila) {
    if(fila->tam!=0) {
        return 0;
    }
    printf("Verdadeiro");
    return 1;
}

int esta_cheia(struct fila *fila) {
    if(fila->tam<=capacidade) {
        return 0;
    }
    printf("Verdadeiro");
    return 1;
}


int main() {
    struct fila fila1, fila2;
    inicializar_fila(&fila1);

    puts("Testando inserir e imprimir_fila para a fila 1");
    inserir(&fila1, 2);
    imprimir_fila(&fila1);
    inserir(&fila1, 4);
    imprimir_fila(&fila1);
    inserir(&fila1, 6);
    imprimir_fila(&fila1);

    puts("Testando remover para a lista 1");
    remover(&fila1);
    imprimir_fila(&fila1);

    puts("Testando obter_primeiro para a fila 1");
    obter_primeiro(&fila1);

    puts("Testando esta_vazia para a fila 1");
    esta_vazia(&fila1);

    puts("Testando esta_cheia para a fila 1");
    esta_cheia(&fila1);

    puts("Testando tamanho para fila 1");
    tamanho(&fila1);

    return 0;
}