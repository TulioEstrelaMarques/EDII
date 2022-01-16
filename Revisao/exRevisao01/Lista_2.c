#include <stdio.h>
//#include<conio.h>

//Otimização de Proteinas Utilizando Imerção Estocástica por proximidade com distâncias intervalares

struct no
{
    int info;
    struct no *ant;
    struct no *prox;
};
typedef struct no Lista;

void ini_lista(Lista *p)
{
    p->ant=NULL;
    p->prox=NULL;
}


void ins_no_fim(Lista *p, int x)
{
    Lista *q,*r;
    q=(Lista*) malloc (sizeof (Lista));
    r=p;
    while(r->prox!=NULL)
    {
        r=r->prox;
    }
    q->info=x;
    q->prox=NULL;
    q->ant=r;
    r->prox=q;
}

void ins_no_ini(Lista *p, int x)
{
     Lista *q,*r;
     q=(Lista*) malloc (sizeof (Lista));
     r=p;
     if(r->prox==NULL)
     {
      q->info=x;
      q->prox=NULL;
      q->ant=p;
      p->prox=q;
     }else
     {
      q->info=x;
      r=p->prox;
      q->prox=r;
      q->ant=p;
      p->prox=q;
      r->ant=q;
     }
}

void inseord(Lista *p, int x)
{
    Lista *q,*r,*j;
    r=p;
    q=(Lista*) malloc (sizeof (Lista));
    q->info=x;
    if(r->prox==NULL)
    {
        r->prox=q;
        q->ant=r;
        q->prox=NULL;
    }else
        {
            while(r->prox!=NULL)
                {
                    r=r->prox;
                    if((x>r->info))
                        {
                            if(r->prox==NULL)
                            {
                                q->prox=r->prox;
                                q->ant=r;
                                r->prox=q;
                                return 0;
                            }else
                                {
                                    j=r->prox;
                                    if(j->info>x)
                                    {
                                        q->prox=r->prox;
                                        q->ant=r;
                                        r->prox=q;
                                        j->ant=q;
                                        return 0;
                                    }
                                }
                        }
                }
                j=p->prox;
                q->prox=j;
                q->ant=p;
                p->prox=q;
                j->ant=q;
        }
}

void mescla(Lista *l1, Lista *l2)
{
    int i=0;
    Lista *q,*r,*s,*t;
    q=l1;
    s=l2;
    while(i!=5)
    {
        q=q->prox;
        s=s->prox;
    }
    r=q->prox;
    t=s->prox;
    q->prox=t;
    s->prox=r;
    r->ant=t;
    t->ant=r;
}


void imprimeListaInv(Lista *p)
{
    Lista *q;
    q=p;
    if(p->prox==NULL)
    {
        printf("Lista Vazia!!\n");
    }
    while(q->prox!=NULL)
    {
        q=q->prox;
    }

    while(q->ant!=NULL)
    {
        printf("<--[%i]--> ",q->info);
        q=q->ant;
    }
    printf("NULL\n");
}

void imprimeLista(Lista *lista)
{
    Lista *listaAux;

    if(lista->prox==NULL)
    {
        printf("Lista Vazia!!\n");
    }
    else
    {
        printf("NULL ");
        listaAux = lista->prox;
        while(listaAux != NULL)
        {
            printf("<--[%i]--> ", listaAux->info);
            listaAux = listaAux->prox;
        }
        printf("NULL\n");
    }
}

int remov_ini(Lista *p)
{
    int x;
    Lista *q,*r;
    q=p->prox;
    if(q==NULL)
    {
        printf("Lista Vazia-Remove\n");
        return;
    }
    else if(q->prox==NULL)
    {
            p->prox=q->prox;
            x=q->info;
            printf("%i\n\n",x);
            free(q);
            return x;
    }
    else
        {
            r=q->prox;
            p->prox=q->prox;
            r->ant=p;
            x=q->info;
            printf("%i\n\n",x);
            free(q);
            return x;
        }
}

int remov_fim(Lista *p)
{
    int x;
    Lista *q,*r;
    q=p->prox;
    if(q==NULL)
    {
        printf("Lista Vazia-Remove - FIM\n");
        return;
    }
    else if(q->prox==NULL)
    {
        p->prox=q->prox;
        x=q->info;
        free(q);
        return x;
    }
    else
    {
            while(q->prox!=NULL)
            {
                r=q;
                q=q->prox;
            }
            r->prox=q->prox;
            q->ant=NULL;
            x=q->info;
            free(q);
            return x;
    }
}

int ins_no_x(Lista *p, int x, int valor)
{
    Lista *q,*r,*no;
    no=(Lista*)malloc(sizeof(Lista));
    no->info=valor;
    q=p;
    while((q->info!=x) && (q->prox!=NULL))
    {
        r=q;
        q=q->prox;
    }
    if(q->info==x)
    {
     no->prox=r->prox;
     no->ant=r;
     q->ant=no;
     r->prox=no;
    }else if(q->prox==NULL)
            {
                printf("Valor nao encontrado!!!\n");
            }
}

int remove_x(Lista *p,int x)
{
    Lista *q,*r,*z;
    q=p;
    while((q->prox!=NULL) && (q->info!=x))
    {
        z=q;
        q=q->prox;
    }
    if(q->info==x)
        {
            if(q->prox!=NULL)
            {
             r=q->prox;
             z->prox=q->prox;
             r->ant=z;
             x=q->info;
             free(q);
            }else
            { //nao remove no final de forma correta
              p->prox=NULL;
              q->ant=NULL;
              x=q->info;
              free(q);
            }
        }
        else
            {
             printf("Lista vazia ou valor nao encontrado!!!\n");
            }
        return x;
}

int tamanho(Lista *p)
{
    Lista *q;
    int i=0;
    q=p;
    while(q->prox!=NULL)
    {
        q=q->prox;
        i++;
    }
    return i;
}

void troca_ini_fim(Lista *p)
{
    Lista *q,*s,*z;
    q=p->prox;
    if(p==NULL)
    {
        printf("Lista Vazia");
    }else if(q->prox==NULL)
            {
                printf("So possui um elemento!!!");
            }else if(tamanho(p)==2)
                {
                    s=q->prox;
                    s->prox=q;
                    q->ant=s;
                    p->prox=s;
                    q->prox=NULL;
                    s->ant=p;
                }
                else
                {
                   s=q;
                   while(s->prox!=NULL)
                   {
                       z=s;
                       s=s->prox;
                   }
                    s->prox=q->prox;
                    p->prox=s;
                    q->prox=NULL;
                    z->prox=q;
                    q->ant=z;
                    s->ant=p;
                    z->ant=s;
                }
}

int busca_elem(Lista *p, int x)
{
    Lista *q;
    q=p->prox;
    if(p==NULL)
    {
        printf("Lista Vazia");
    }else
        {
            while((q->prox!=NULL)&&(q->info!=x))
            {
                q=q->prox;
            }
            if(q->prox==NULL)
            {
                return -1;
            }else
                {
                    return q->info;
                }
        }

}

int main()
{
    int op,valor,x;
    Lista *p;
    p=(Lista*) malloc(sizeof(Lista));
    ini_lista(p);
    while(op != 0 )
    {
        //system("cls");
        puts("*******************************************************");
        puts("*******    Lista Linear Duplamente Encadeada   ********");
        puts("*******************************************************");
        puts("**         0 - Sair                                  **");
        puts("**         1 - Inserir elemento no inicio            **");
        puts("**         2 - Inserir elemento no fim da lista      **");
        puts("**         3 - Inserir antes X elemento              **");
        puts("**         4 - Remover elemento no inicio            **");
        puts("**         5 - Remover elemento no final             **");
        puts("**         6 - Remover x elemento                    **");
        puts("**         7 - Mostrar lista                         **");
        puts("**         8 - Mostrar lista invertida               **");
        puts("**         9 - Tamanho                               **");
        puts("**         10 - Troca elemento ini - fim             **");
        puts("**         11 - Busca um elemento X                  **");
        puts("**         12 - Insere ordenado   X                  **");
        puts("**         13 - Ordenar uma lista com N valores      **");
        puts("*******************************************************");
        printf("Opcao? =  ");
        scanf( "%d",&op);
        switch( op )
        {
        case 0:
            break;
        case 1:
            printf("Valor? = ");
            scanf("%d", &valor);
            ins_no_ini(p,valor);
        break;
        case 2:
            printf("Valor? = ");
            scanf("%d", &valor);
            ins_no_fim(p,valor);
        break;
        case 3:
            printf("Valor? = ");
            scanf("%d", &valor);
            printf("Valor a ser localizado? = ");
            scanf("%d", &x);
            ins_no_x(p,x,valor);
        break;
        case 4:
            printf("Valor: %i\n",remov_ini(p));
        break;
        case 5:
            printf("Valor: %i\n",remov_fim(p));
        break;
        case 6:
            printf("Valor? = \n");
            scanf("%d", &valor);
            printf("%i",remove_x(p,valor));
        break;
        case 7:
            imprimeLista(p);
        break;
        case 8:
            imprimeListaInv(p);
        break;
        case 9:
            printf("Tamanho: %i\n",tamanho(p));
        break;
        case 10:
            troca_ini_fim(p);
        break;
        case 11:
            printf("Digite um valor:\n");
            scanf("%i",&valor);
            printf("Valor retornado: %i\n",busca_elem(p,valor));
        break;
        case 12:
            printf("Digite um valor:\n");
            scanf("%i",&valor);
            printf("Digite um valor:%i\n",valor);
            inseord(p,valor);
        break;
        }
    }
    return 0;
}
