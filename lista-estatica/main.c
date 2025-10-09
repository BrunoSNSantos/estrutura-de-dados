#include <stdio.h>
#define capacidade 10

struct lista {
    int vetor[capacidade];
    int tam;
};

void inicializar_lista(struct lista *l) {
    l -> tam = 0;
}

int inserir_comeco(struct lista *l, int valor)
{
    if (l->tam >= capacidade) {
        return 0;
    } 
    for (int i = l->tam; i > 0; i--){
        l->vetor[i] = l->vetor[i-1];
    } 
    l->vetor[0] = valor;
    l->tam++;
    return 1;
}

int inserir_fim(struct lista *l, int valor)
{
if(l->tam >= capacidade)
return 0;

l->vetor[l->tam] = valor;
l->tam++;
return 1;
}

void imprimir_vetor(struct lista *l)
{
printf("[ ");
for(int i = 0; i < l->tam; i++){
printf("%d ", l->vetor[i]);
}
printf("]\n");
}

int buscar(struct lista *l, int valor) {
    for(int i = 0; i < l->tam; i++) {
        if(l->vetor[i] == valor) {
            return i;
        }
    }
    return -1;
}

int alterar (struct lista *l, int valor, int novo_valor) {
    int pos = buscar(l, valor);
    if (pos == -1) {
        return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
    } else {
        l->vetor[pos] = novo_valor;
        return 1;
    }
}

int deletar (struct lista *l, int valor) {
    int pos = buscar(l, valor);
    if (pos == -1) {
        return 0;
    } else {
        for (int i = pos; i < l->tam - 1; i++) {
            l->vetor[i] = l->vetor[i+1];
        }
    }
    l->tam--;
    return 1;
}

int deletar_comeco (struct lista *l) {
    if (l->tam==0) {
        return 0;
    } 
    for (int i = 0; i < l->tam - 1; i++) {
        l->vetor[i] = l->vetor[i+1];
    }
    l->tam--;
    return 1;
}

int main()
{
struct lista l1, l2;
inicializar_lista(&l1);
inicializar_lista(&l2);

puts("inserir_fim para lista l1:");
imprimir_vetor(&l1);
inserir_fim(&l1, 3);
imprimir_vetor(&l1);
inserir_fim(&l1, 2);
imprimir_vetor(&l1);
inserir_fim(&l1, 5);
imprimir_vetor(&l1);

puts("inserir_fim para lista l2:");
imprimir_vetor(&l2);
inserir_fim(&l2, 4);
imprimir_vetor(&l2);
inserir_fim(&l2, 3);
imprimir_vetor(&l2);
inserir_fim(&l2, 7);
imprimir_vetor(&l2);

puts("inserir_comeco para lista 1:");
inserir_comeco(&l1, 1);
imprimir_vetor(&l1);
inserir_comeco(&l1, 4);
imprimir_vetor(&l1);
inserir_comeco(&l1, 6);
imprimir_vetor(&l1);

puts("inserir_comeco para lista 2:");
inserir_comeco(&l2, 4);
imprimir_vetor(&l2);
inserir_comeco(&l2, 3);
imprimir_vetor(&l2);
inserir_comeco(&l2, 9);
imprimir_vetor(&l2);

puts("alterar e deletar para lista 1:");
imprimir_vetor(&l1);
alterar(&l1, 3, 7);
imprimir_vetor(&l1);
deletar(&l1, 5);
imprimir_vetor(&l1);

puts("alterar e deketar para lista 2: ");
imprimir_vetor(&l2);
alterar(&l2, 9, 1);
imprimir_vetor(&l2);
deletar(&l2, 7);
imprimir_vetor(&l2);

puts("deletar_comeco para lista 1:");
deletar_comeco(&l1);
imprimir_vetor(&l1);

puts("deletar comeco para lista 2:");
deletar_comeco(&l2);
imprimir_vetor(&l2);

return 0;
}