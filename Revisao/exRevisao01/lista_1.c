#include<stdio.h>
#include<stdlib.h>


struct NoLis
{
    int val;
    char nome[10];
    char ende[10];
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

int tamanho_lista(No *p)
{
    No *q;
    int i=0;
    q=p;
    while(q->prox!=NULL)
    {
        q=q->prox;
        i++;
    }
    return i;
}

int localiza(No *p, int x)
{
    No *q;
    int i=0;
    q=p;
    while((q->prox!=NULL) && (q->val!=x))
    {
     i++;
     q=q->prox;
    }
    if(q->val!=x)
    {
        i=0;
    }
    return i;
}

void Ins_Inic(No *p, int x)
{
    No *q;
    q=(No*) malloc(sizeof(No));
    q->val=x;
    q->prox=p->prox;        //p->prox==NULL q->prox=p->prox==NULL
    p->prox=q;
}


void no_insere_apos_elem(No *p, int x, int y)
{
    No *q,*pos;
    q=(No*) malloc(sizeof(No));
    q->val=x;
    pos=p;
    while((pos->val!=y) && (pos->prox!=NULL))
                {
                    pos=pos->prox;
                }
    q->prox=pos->prox;
    pos->prox=q;
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

void no_insere_ord_elem(No *p, int x)
{
    No *q,*pos,*ant;
    q=(No*) malloc(sizeof(No));
    q->val=x;
    pos=p;
    while((pos->prox!=NULL) && (pos->val>=x))
                {
                    ant=pos;
                    pos=pos->prox;
                }
    if(pos==NULL)
       {
         Ins_Inic(p,x);
       }
    if(pos->val<=x)
       {
          q->prox=pos;
          ant->prox=q;
       }else
            {
              no_insere_fim(p,x);
            }
}

int no_remove_elem(No *p, int x)
{
    No *q,*ant;
    q=p;

    if((q->prox==NULL) || (p==NULL))
    {
        printf("Lista Vazia!!!");
        //return 0;
    }
    else
        {
            while((q->prox!=NULL) && (q->val!=x))
                {
                    ant=q;
                    q=q->prox;
                }
            ant->prox=q->prox;
            free(q);
        }
}

int no_remove_fim(No *p)
{
    No *q,*ant;
    q=p;

    if((q->prox==NULL) || (p==NULL))
    {
        printf("Lista Vazia!!!");
        return 0;
    }
    else
        {
            while(q->prox!=NULL)
                {
                    ant=q;
                    q=q->prox;
                }
            ant->prox=NULL;
            free(q);
        }
}

int no_remove_ini(No *p)
{
    No *q;
    int x;
    if(lista_vazia(&p) || (p->prox==NULL))
    {
        printf("Lista Vazia!!!");
        return 0;
    }
    q=p->prox;
    x=q->val;
    p->prox=q->prox;
    free(q);
    //return x;
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


void imprimi_end(No *p)
{
    No *q;
    q=p->prox;
    printf("\n");
    while(q!=NULL)
    {
        printf("[%i][%i][%i]-->",&q->val,q->val,q->prox);
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
		printf( "1 - Inserir elemento no inicio\n" );
		printf( "2 - Inserir elemento no fim da lista\n" );
		printf( "3 - Remover elemento no inicio\n" );
		printf( "4 - Remover elemento no final\n" );
		printf( "5 - Mostrar lista\n" );
		printf( "6 - Mostrar lista com endereço\n");
		printf( "7 - Localizar\n" );
		printf( "8 - Inserir no meio\n");
		printf( "9 - Remover no por valor\n" );
		printf( "10 - Inserir de forma decrescente\n");
		printf( "11 - Tamanho\n");
		printf( "Opcao?  " );
		scanf( "%d",&op);
		switch( op ){
		    case 0:
                exit(0);
			    break;
			case 1:
				printf( "Valor? " );
				scanf( "%d", &valor );
				Ins_Inic(&p,valor);
				break;
			case 2:
				printf( "Valor? " );
				scanf("%d",&valor);
				no_insere_fim(&p,valor);
				break;
			case 3:
			    no_remove_ini(&p);
				break;
			case 4:
			    no_remove_fim(&p);
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
				break;
			case 6:
                    imprimi_end(&p);
			    break;
			case 7:
                printf("Digite o valor:\n");
			    scanf("%d",&valor);
			    valor=localiza(&p,valor);
			    printf("Posicao %i\n",valor);
				break;
			case 8:
				printf("Digite o valor:\n");
			    scanf("%d",&valor);
			    printf("Definir a pos a posição:\n");
			    scanf("%d",&y);
                no_insere_apos_elem(&p,valor,y);
                break;
            case 9:
				printf("Digite o valor:\n");
			    scanf("%d",&valor);
                no_remove_elem(&p,valor);
                break;
            case 10:
				printf("Digite o valor:\n");
			    scanf("%d",&valor);
                no_insere_ord_elem(&p,valor);
                break;
            case 11:
               tam=tamanho_lista(&p);
               printf("Tamanho da lista: %i elementos\n",tam);
		}

	}
}
