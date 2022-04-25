#include <stdio.h>
#include <stdlib.h>

// tamanho da tabela
#define M 41

// tipo cidade
typedef struct {
    char nome[50];
} Cidade;

// tipo nó usado na lista encadeada
typedef struct no {
    Cidade cidade;
    struct no *proximo;
} No;

// tipo lista com um ponteiro para o primeiro nó
typedef struct {
    No *inicio;
    int tam;
} Lista;

// nossa tabela (vetor de ponteiros para listas)
Lista *tabela[M];

//--------------------------------- fim definições variáveis --------------------

//--------------------------------- funções meus tipos --------------------------

// cria e retorna um tipo cidade
Cidade criarCidade() {
    Cidade sp;
    printf("Digite o nome da cidade: ");
    scanf("%*c");
    fgets(sp.nome, 50, stdin);
    return sp;
}

// imprime uma cidade
void imprimirCidade(Cidade sp) {
    printf("\tNome: %s\n", sp.nome);
}

//-------------------------------- início funções lista -------------------------
// cria uma lista vazia e retorna seu endereço na memória
Lista* criarLista() {
    Lista *l = malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tam = 0;
    return l;
}

/*
    inserir no início da lista
    PARÂMETROS
    sp - nova cidade a ser inserida
    *lista - endereço de uma lista encadeada.
*/
void inserirInicio(Cidade sp, Lista *lista) {
    No *no = malloc(sizeof(No));
    no->cidade = sp;
    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tam++;
}

// busca um elemento na lista
No* buscarNo(char *nome, No *inicio) {

    while(inicio != NULL) {
        if(inicio->cidade.nome == nome)
            return inicio;
        else
            inicio = inicio->proximo;
    }
    return NULL;// matricula não encontrada
}

void imprimirLista(No *inicio) {
    while(inicio != NULL) {
        imprimirCidade(inicio->cidade);
        inicio = inicio->proximo;
    }
}
//---------------------------------- fim funções lista -------------------------

//--------------------------- início funções tabela hash -----------------------
// inicializa a tabela com uma lista vazia em cada posição do vetor
void inicializar(){
    int i;
    for(i = 0; i < M; i++)
        tabela[i] = criarLista();
}

// função de espalhamento funcaoEspalhamento

unsigned long funcaoEspalhamento(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
// cria uma cidade e a insere na tabela
void inserTabela(){
    Cidade sao = criarCidade();
    int indice = funcaoEspalhamento(sao.nome);
    inserirInicio(sao, tabela[indice]);
}

// busca uma cidade. Seu retorno é um endereço ou NULL
Cidade* buscarcidadeTabela(char *nome){
    int indice = funcaoEspalhamento(*nome);
    No *no = buscarNo(*nome, tabela[indice]->inicio);
    if(no)
        return &no->cidade;
    else
        return NULL;
}

// imprimir tabela
void imprimirTabela(){
    int i;
    printf("\n---------------------TABELA-------------------------\n");
    for(i = 0; i < M; i++){
        printf("%d Lista tamanho: %d\n", i, tabela[i]->tam);
        imprimirLista(tabela[i]->inicio);
    }
    printf("---------------------FIM TABELA-----------------------\n");
}

int main() {
    int op;
    char nome[50];
    Cidade *sp;

    inicializar();

    do {
        printf("\n0 - Sair\n1 - Inserir\n2 - Buscar\n3 - Imprimir tabela\n");
        scanf("%d", &op);
        switch(op) {
        case 0:
            printf("saindo...\n");
            break;
        case 1:
            inserTabela();
            break;
        case 2:
            printf("Qual a matricula a ser buscada? ");
            scanf("%s", nome);
            sp = buscarcidadeTabela(*nome);
            if(sp) {
                printf("Cidade encontrada: \tNome: %s", sp->nome);
            } else
                printf("Cidade nao contrada!\n");
            break;
        case 3:
            imprimirTabela();
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while(op != 0);

    return 0;
}
