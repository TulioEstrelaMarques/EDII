#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int key;
    struct no *prox;
}No;

typedef struct{
    No *inicio;
    int tam;
}Lista;

void inicializarLista(Lista *l){
    l->inicio = NULL;
    l->tam = 0;
}

void inserirLista(Lista *l, int num){
    No *nova = malloc(sizeof(No));
    if(nova){
        nova->key = num;
        nova->prox = l->inicio;
        l->inicio = nova;
    }else{
        printf("\nErro ao alocar");
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
