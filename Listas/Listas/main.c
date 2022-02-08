/*
    Estrutura basica da Lista Encadeada
    com inserção aletoria
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void inserir_ordenado(Lista *lista, int num) {
    No *aux,*nova = malloc(sizeof(No));
    if(nova) {
        nova->valor = num;
        if(lista->inicio == NULL) {
            nova->proximo = NULL;
            lista->inicio = nova;
        } else if(nova->valor < lista->inicio->valor) {
            nova->proximo = lista->inicio;
            lista->inicio = nova;
        } else {
            aux = lista->inicio;
            while(aux->proximo && nova->valor > aux->proximo->valor) {
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

No* remover(Lista *lista, int num) {
    No *aux, *remover = NULL;
    if(lista->inicio) {
        if(lista->inicio->valor == num) {
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->tam--;
        } else {
            aux = lista->inicio;
            while(aux->proximo && aux->proximo->valor != num) {
                aux = aux->proximo;
                if(aux->proximo) {
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    lista->tam--;
                }
            }
        }
    }

    return remover;
}

No* buscar(Lista *lista, int num) {
    No *aux, *no = NULL;
    aux = lista->inicio;
    while(aux && aux->valor != num) {
        aux = aux->proximo;
    }
    if(aux) {
        no = aux;
    }

    return no;
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
    srand(time(NULL));
    int opcao, anterior;
    //No *lista = NULL;
    Lista lista;
    No *auxiliar;
    criar_lista(&lista);
    do {
        int valor=1+rand()%100;
        printf("\n========Lista Encadeada=========");
        printf("\n0 - Sair\n1 - Inserir no Inicio\n2 - Inserir no Fum\n3 - Inserir no Meio");
        printf("\n4 - Inserir Ordenado\n5 - Remover\n6 - Imprimir\n7 - Buscar\n");
        printf("Qual opcao? ");
        scanf("%d",&opcao);
        switch(opcao) {
        case 1:
            /*printf("Digite um valor: ");
            scanf("%d",&valor);*/
            inserir_inicio(&lista,valor);
            break;
        case 2:
            /*printf("Digite um valor: ");
            scanf("%d",&valor)*/
            inserir_fim(&lista,valor);
            break;
        case 3:
            printf("Digite o valor de referencia: ");
            scanf("%d",&anterior);
            inserir_meio(&lista,valor,anterior);
            break;
        case 4:
            /*printf("Digite um valor: ");
            scanf("%d",&valor);*/
            inserir_ordenado(&lista, valor);
            break;
        case 5:
            printf("Digite um valor a ser removido: ");
            scanf("%d",&valor);
            auxiliar = remover(&lista, valor);
            if(auxiliar) {
                printf("\nElemento removido: %d\n",auxiliar->valor);
                free(auxiliar);
            } else {
                printf("\nElemento inesistente!\n");
            }
            break;
        case 6:
            imprime(lista);
            break;
        case 7:
            printf("Digite um valor a ser buscado: ");
            scanf("%d",&valor);
            auxiliar = buscar(&lista, valor);
            if(auxiliar) {
                printf("\nValor encontrado: %d\n",auxiliar->valor);
            } else {
                printf("\nValor nao encontrado!\n");
            }
            break;
        default:
            if(opcao!=0)
                printf("Opcao Invalida!\n");
        }
    } while(opcao!=0);
    return 0;
}
