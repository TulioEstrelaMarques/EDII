#include<stdio.h>
#include<stdlib.h>

struct NoLis
{
    int val;
    struct NoLis *prox;
};
typedef struct NoLis No;

void inic_fil(No *p)
{
    p->prox=NULL;
}

int lista_vazia(No *p)
{
    if(p->prox==NULL)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}

void no_insere_fim(No *p, int x)
{
    No *q,*pos;
    q=(No*) malloc(sizeof(No));


    q->val=x;
    q->prox=NULL;
    pos=p;
    while(pos->prox!=NULL)
    {
        pos=pos->prox;
    }
    pos->prox=q;
}

void imprimi(No *p)
{
    No *q;
    q=p->prox;
    printf("\n");
    while(q!=NULL)
    {
        printf("[%i]-->",q->val);
        q=q->prox;
    }
    printf("NULL");
}

int main()
{
    struct No *p;
    int i,tam=0;
    int valor, op,y;

    inic_fil(&p);
    while( 1 )
    {
        printf("\n\nLista Linear Simplesmente Encadeada:\n");
        printf( "0 - Sair\n");
        printf( "2 - Inserir elemento no fim da lista\n" );
        printf( "5 - Mostrar lista\n" );
        printf( "Opcao?  " );
        scanf( "%d",&op);
        switch( op )
        {
        case 0:
            exit(0);
            break;
        case 2:
            printf( "Valor? " );
            scanf("%d",&valor);
            no_insere_fim(&p,valor);
            break;
        case 5:
            if (lista_vazia(&p))
            {
                printf("Lista vazia!!\n");
            }
            else
            {
                imprimi(&p);
            }
        }

    }
    return 0;
}
