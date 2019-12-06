#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//definição das estruturas usadas
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

//portotipação
void saindo(no * n);//função para limpar não vazar memoria...
int buscar(no * n,int num);
void mostrar_i();
int pop_ini();
no * cria_no();
fila * cria_fila();
void menu();
void push_ini(int num);
void push_fim(int num);
int pop_fim();
void mostrar();
void menu();

//variaveis gobais
struct fila * F=NULL;

int main()
{
    int i;
    for(i=0;i<10000;i++)
    {
        push_fim(i);
    }
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
        printf("\n9.apagar     ");
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
            op=pop_ini();
            if(op!=-1)
            {
                printf("\n\n\tnumero: %d ",op);

            }
            else printf("\n\n\tNULL ");
            op=1;
            break;
        case 4:
            op=pop_fim();
            if(op!=-1)
            {
                printf("\n\n\tnumero: %d ",op);
            }
            else printf("\n\n\tNULL ");
            op=1;
            break;
        case 5:
            mostrar();
            break;
        case 6:
            mostrar_i();
            break;
        case 7:
            printf("\nDigite o Numero: ");
            scanf("%d",&op);
            if(F!=NULL)
            {
                if(op==buscar(F->ini,op))
                {
                    printf("\n\n\tNa fila");
                }
                else
                {
                    printf("\n\n\tNão encontrado");
                }
            }
            else
            {
                printf("\n\n\tVazio");
            }
            op=1;
            break;
            case 9:
            if(F!=NULL)
            {
                saindo(F->ini);
                F=NULL;
            }
            break;
        case 0:
            printf("saindo");
            if(F!=NULL)saindo(F->ini);
            break;
        default:
            printf("\n Opção invalida\n\n");
            break;
        }
    }
}
/*int bubble()
{
    no *aux0,*aux1,*aux2,*aux3;
    int i,j,tamanho,flag=1;
    for(i=0;i<tamanho && flag;i++)
    {
        flag=0;
        for(j=0;j<tamanho-i;j++)
        {
            if(aux1->var>aux2->var)
            {
                if()

                flag=1;
            }
        }

    }
}*/

void saindo(no * n)
{
    no *aux;
    if(n!=NULL)
    {
        aux=n->prx;
        free(n);
        saindo(aux);
    }
}
int buscar(no * n,int num)
{
    if(n!=NULL)
    {
        if(n->var==num)
        {
            return n->var;
        }
        else
        {
            return buscar(n->prx,num);
        }
    }
    else
    {
        return -1;
    }
}

fila * cria_fila()//função para alocar fila com ponteiros nulos
{
    fila * f;
    f=(malloc(sizeof(fila)));
    f->fim=f->ini=NULL;
    return f;
}
void push_ini(int num) //push no inicio na fila
{
    no * aux,*newn;
    if(F==NULL) F=cria_fila();
    if(F->ini==NULL) F->ini=F->fim=cria_no();
    else
    {
        aux=F->fim;
        newn=cria_no();
        aux->ant=newn;
        newn->prx=aux;
        F->ini=newn;
    }
    F->ini->var=num;
}
void push_fim(int num) // push no fim da fila
{
    no * aux, *newn;
    if(F==NULL) F=cria_fila();
    if(F->fim==NULL) F->ini=F->fim=cria_no();
    else
    {
        aux=F->fim;
        newn=cria_no();
        newn->ant=aux;
        aux->prx=newn;
        F->fim=newn;
    }
    F->fim->var=num;
}
no * cria_no() // aloca no com valores nulos
{
    no * n;
    n=malloc(sizeof(n));
    n->var=0;
    n->ant=n->prx=NULL;
    return n;
}
int pop_fim() //tira o ultimo da fila
{
    int num;
    no *aux=NULL;
    if(F==NULL) return -1;
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
int pop_ini() //tira o prim da fila
{
    int num;
    no *aux=NULL;
    if(F==NULL) return -1;
    aux=F->ini;
    if(F->fim==F->ini)
    {
        num=F->ini->var;
        F->fim=F->ini=NULL;
        free(F);
        F=NULL;
    }
    else
    {
        num=F->ini->var;
        F->ini=F->ini->prx;
        F->ini->ant=NULL;
    }
    free(aux);
    return num;
}

void mostrar() //mostrar do primeiro ao ultimo
{
    no *aux;
    if(F==NULL)
    {
        printf("\n Vazio");
        return ;
    }
    aux=F->ini;
    while(aux!=NULL)
    {
        printf(" %d",aux->var);
        aux=aux->prx;
    }
}
void mostrar_i() // mostra do ultimo ao primeiro (invertido)
{
    no *aux;
    if(F==NULL)
    {
        printf("\n Vazio");
        return ;
    }
    aux=F->fim;
    while(aux!=NULL)
    {
        printf(" %d",aux->var);
        aux=aux->ant;
    }
}
