#include <stdio.h>
#include <stdlib.h>

//Criando a estrutura...
typedef struct no {
    int valor;
    struct no *proximo;
} No;

typedef struct {
    No *inicio;
    int tam;
} Lista;

void criar_lista(Lista *lista) {
    lista->inicio = NULL;
    lista->tam = 0;
}

void inserir_inicio(Lista *lista, int num) {
    No *nova = malloc(sizeof(No));
    if(nova) {
        nova->valor = num;
        nova->proximo = lista->inicio;
        lista->inicio = nova;
        lista->tam++;
    } else {
        printf("Erro ao alocar");
    }
}

void inserir_fim(Lista *lista, int num) {
    No *aux,*nova = malloc(sizeof(No));
    if(nova) {
        nova->valor = num;
        nova->proximo = NULL;
        if(lista->inicio == NULL) {
            lista->inicio = nova;
        } else {
            aux = lista->inicio;
            while(aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = nova;
        }
        lista->tam++;
    } else {
        printf("Erro ao alocar");
    }
}

void inserir_meio(Lista *lista, int num, int ant) {
    No *aux, *nova = malloc(sizeof(No));
    if(nova) {
        nova->valor = num;
        if(lista->inicio == NULL) {
            nova->proximo = NULL;
            lista->inicio = nova;
        } else {
            aux = lista->inicio;
            while(aux->valor != ant && aux->proximo) {
                aux = aux->proximo;
            }
            nova->proximo = aux->proximo;
            aux->proximo = nova;
        }
        lista->tam++;
    } else {
        printf("Erro ao alocar.");
    }
}

void imprime(Lista lista) {
    No *no = lista.inicio;
    printf("\nTamanho da lista: %d",lista.tam);
    printf("\nLista: ");
    while(no) {
        printf("%d ",no->valor);
        no = no->proximo;

    }
    printf("\n\n");
}



int main() {
    int opcao, valor, anterior;
    //No *lista = NULL;
    Lista lista;
    criar_lista(&lista);
    do {
        printf("\n========Lista Encadeada=========");
        printf("\n0 - Sair\n1 - InserirI\n2 - InserirF\n3 - InserirM\n4 - Imprimir\n");
        printf("Qual opcao? ");
        scanf("%d",&opcao);
        switch(opcao) {
        case 1:
            printf("Digite um valor: ");
            scanf("%d",&valor);
            inserir_inicio(&lista,valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d",&valor);
            inserir_fim(&lista,valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d%d",&valor,&anterior);
            inserir_meio(&lista,valor,anterior);
            break;
        case 4:
            imprime(lista);
            break;
        default:
            if(opcao!=0)
                printf("Opcao Invalida!\n");
        }
    } while(opcao!=0);
    return 0;
}
