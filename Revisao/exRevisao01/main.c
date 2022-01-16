#include <stdio.h>
#include <stdlib.h>
typedef struct lista
{
    int num;
    struct lista * prox;
} item;

int listaVazia(item *ini)
{
    if(ini==NULL)
    {
        exit(1);
    }
    return 0;
}
item * leituraLista1(item *ini,item *proximo)
{
    proximo = ini;
    if(!listaVazia(ini))
    {
        char resp;
        do
        {
            printf("\nInforme os valores da lista 1: ");
            scanf("%d",&proximo->num);
            printf("Quer continuar? <[S/N]>");
            scanf("%s",&resp);
            proximo->prox=(item*)malloc(sizeof(item));
            proximo = proximo->prox;
        }
        while(resp!='n');
        proximo->prox=NULL;
    }

}
void mostrarLista(item *ini,item *proximo)
{
    proximo->prox=ini;
    printf("Os valores foram: ");
    while(proximo!=NULL)
    {
        printf("%d",proximo->num);
        proximo=proximo->prox;
    }
}

int main()
{
    item *inicio = (item *)malloc(sizeof(item));
    item *proximo = (item *)malloc(sizeof(item));
    leituraLista1(inicio,proximo);
    mostrarLista(inicio,proximo);
    return 0;
}
