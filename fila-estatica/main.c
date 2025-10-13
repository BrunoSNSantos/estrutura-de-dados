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

int *obter_primeiro(struct fila *fila) {
    if (fila->tam==0) {
        return NULL;
    }
    return fila->vetor;
}

int esta_vazia(struct fila *fila) {
    if(fila->tam!=0) {
        return 0;
    }
    return 1;
}

int esta_cheia(struct fila *fila) {
    if(fila->tam<capacidade) {
        return 0;
    }
    return 1;
}

int limpa (struct fila *fila) {
    if(fila->tam==0) {
        return 0;
    }
    for(int i = 0; i<fila->tam; i++) {
        fila->vetor[i] = NULL;
    }
    fila->tam=0;
    return 1;
}

int contem(struct fila *fila, int valor) {
    for(int i = 0; i < fila->tam; i++) {
        if(fila->vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct fila fila1, fila2;
    inicializar_fila(&fila1);
    inicializar_fila(&fila2);

    puts("Testando inserir e imprimir_fila para a fila 1");
    inserir(&fila1, 2);
    imprimir_fila(&fila1);
    inserir(&fila1, 4);
    imprimir_fila(&fila1);
    inserir(&fila1, 6);
    imprimir_fila(&fila1);

    puts("Testando remover para a fila 1");
    remover(&fila1);
    imprimir_fila(&fila1);

    puts("Testando contem para fila 1");
    int pos = contem(&fila1, 6);

    if(pos!=-1) {
        printf("O valor está na posição %d\n", pos);
    } else {
        printf("O valor não está na fila\n");
    }

    puts("Testando esta_cheia para fila 1");
    inserir(&fila1, 1);
    inserir(&fila1, 2);
    inserir(&fila1, 3);
    inserir(&fila1, 4);
    inserir(&fila1, 5);
    inserir(&fila1, 6);
    inserir(&fila1, 7);
    inserir(&fila1, 8);
    imprimir_fila(&fila1);

    if(esta_cheia(&fila1)){
        printf("Fila está cheia\n");
    }

    puts("Testando esta_vazia para a fila 2");
    if(esta_vazia(&fila2)){
        printf("Fila está vazia\n");
    }

    puts("Testando limpa para fila 1");
    limpa(&fila1);
    imprimir_fila(&fila1);
    //perguntar o problema do = NULL para o Ajalmar

    return 0;
}