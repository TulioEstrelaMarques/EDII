#include <stdio.h>
#include <stdlib.h>

//Criando a estrutura...
typedef struct no {
    int valor;
    struct no *proximo;
} No;

void inserir_inicio(No **lista, int num) {
    No *nova = malloc(sizeof(No));
    if(nova) {
        nova->valor = num;
        nova->proximo = *lista;
        *lista = nova;
    } else {
        printf("Erro ao alocar");
    }
}

void inserir_fim(No **lista, int num) {
    No *aux,*nova = malloc(sizeof(No));
    if(nova) {
        nova->valor = num;
        nova->proximo = NULL;
        if(*lista == NULL) {
            *lista = nova;
        } else {
            aux = *lista;
            while(aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = nova;
        }
    } else {
        printf("Erro ao alocar");
    }
}

void inserir_meio(No **lista, int num, int ant) {
    No *aux, *nova = malloc(sizeof(No));
    if(nova) {
        nova->valor = num;
        if(*lista == NULL) {
            nova->proximo = NULL;
            *lista = nova;
        } else {
            aux = *lista;
            while(aux->valor != ant && aux->proximo) {
                aux = aux->proximo;
            }
            nova->proximo = aux->proximo;
            aux->proximo = nova;
        }
    } else {
        printf("Erro ao alocar.");
    }
}




int main() {

}
