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

void no_insere(No *p, int x)
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

void imprime(No *p)
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

void imprime_separado(No *p)
{
    No *r,*s;
    r=p->prox;
    s=p->prox;

    printf("\nLista de Pares\n");
    while(r!=NULL)
    {
        if(r->val%2==0)
        {
            printf("[%i]-->",r->val);
        }
        r=r->prox;
    }
    printf("NULL");

    printf("\n\nLista de Impares\n");
    while(s!=NULL)
    {
        if(s->val%2!=0)
        {
            printf("[%i]-->",s->val);
        }
        s=s->prox;
    }
    printf("NULL");
}


int main()
{
    struct No *p;
    int valor, op;

    inic_fil(&p);
    while( 1 )
    {
        printf("\n\nLista Linear Simplesmente Encadeada:\n");
        printf( "0 - Sair\n");
        printf( "1 - Inserir elemento na lista\n" );
        printf( "2 - Mostrar lista\n" );
        printf( "3 - Mostrar lista separada\n" );
        printf( "Opcao?  " );
        scanf( "%d",&op);
        switch( op )
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf( "Valor? " );
            scanf("%d",&valor);
            no_insere(&p,valor);
            break;

        case 2:
            if (!lista_vazia(&p))
            {
                imprime(&p);

            }
            else
            {
                printf("Lista vazia!!\n");
            }
            break;

        case 3:
            if (!lista_vazia(&p))
            {
                imprime_separado(&p);
            }
            else
            {
                printf("Lista vazia!!\n");
            }
            break;
        }

    }
    return 0;
}
