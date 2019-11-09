#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct no
{
    int var;
    struct no *ant;
    struct no *prx;
} no;
typedef struct fila
{
    struct no * ini;
    struct no * fim;
} fila;

void mostrar_i(no * n);
no * cria_no();
fila * cria_fila();
void menu();
void push_ini(int num);
void push_fim(int num);
int pop_fim();
void mostrar(no * n);

struct fila * F;
void menu();
int main()
{
    menu();
    return 0;
}
void menu()
{
    int op=1;
    while(op!=0)
    {
        printf("\n\n\tescolha dentre as opções");
        printf("\n0.sair");
        printf("\n1.push inicio");
        printf("\n2.push fim   ");
        printf("\n3.pop  inicio");
        printf("\n4.pop  fim   ");
        printf("\n5.mostrar    ");
        printf("\n6.mostrar invetida");
        printf("\n7.buscar     ");
        printf("\n8.ordenar    ");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            printf("\n Digite o Numero: ");
            scanf("%d",&op);
            push_ini(op);
            op=1;
            break;
        case 2:
            printf("\n Digite o Numero: ");
            scanf("%d",&op);
            push_fim(op);
            op=1;
            break;
        case 3:
            break;
        case 4:
            op=pop_fim();
            if(op!=-1)
            {
                printf("\n\n\tnumero: %d ",op);
                op=1;
            }
            else printf("\n\n\tNULL ");
            op=1;
            break;
        case 5:
            mostrar(F->ini);
            break;
        case 6:
            mostrar_i(F->fim);
            break;
        case 0:
            printf("saindo.......");
            break;
        default:
            printf("\n Opção invalida\n\n");
            break;
        }
    }
}

fila * cria_fila()
{
    return (fila*)(calloc(1,sizeof(fila)));
}
void push_ini(int num)
{
    if(F==NULL) F=cria_fila();
    if(F->ini==NULL) F->ini=F->fim=cria_no();
    else
    {
        F->ini->ant=cria_no();
        F->ini->ant=F->ini;
        F->ini=F->ini->ant;
    }
    F->ini->var=num;
}
void push_fim(int num)
{
    if(F==NULL) F=cria_fila();
    if(F->fim==NULL) F->ini=F->fim=cria_no();
    else
    {
        F->fim->prx=cria_no();
        F->fim->prx->ant=F->fim;
        F->fim=F->fim->prx;
    }
    F->fim->var=num;
}
no * cria_no()
{
    return (no*)(calloc(1,sizeof(no)));
}
int pop_fim()
{
    int num;
    no *aux;
    if(F==NULL) return -1;
    aux=F->fim;
    if(F->fim==F->ini)
    {
        num=F->fim->var;
        F->fim=F->ini=NULL;
        free(F);
        F=NULL;
    }
    else
    {
        num=F->fim->var;
        F->fim=F->fim->ant;
        F->fim->prx=NULL;
    }
    free(aux);
    return num;
}
void mostrar(no * n)
{
    if(n!= NULL)
    {
        printf(" %d",n->var);
        mostrar(n->prx);
    }
    return;
}
void mostrar_i(no * n)
{
    if(n!= NULL)
    {
        printf(" %d",n->var);
        mostrar(n->ant);
    }
    return;
}
