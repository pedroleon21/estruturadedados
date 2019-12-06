#include<stdio.h>
#include<stdlib.h>

//struturas de armazenamento
typedef struct no
{
    int var;
    struct no * prx;
    struct no * ant;
} no;
typedef struct fila
{
    struct no * prm;
    struct no * ult;
} fila;

//prototipação
no * alloca_no();
fila * alloca_fila();
void push_inicio(int num, fila *f);
void menu(fila *f);
void mostra(fila *f);
int pop_inicio(fila *f);

int main()
{
    fila *f;
    f=NULL;
    menu(f);
    return 0;
}
void menu(fila *f)
{
    int op=1;
    while(op)
    {
        printf("\n1. push inicio");
        printf("\n2. push    fim");
        printf("\n3. pop  inicio");
        printf("\n4. pop     fim");
        printf("\n5. mostrar    ");
        printf("\n6. mostrar upD");
        printf("\n7. Apagar     ");
        printf("\n8. nova   fila");
        printf("\nDigite a Opção: ");
        scanf("%d",&op);
        switch(op)
        {
        case 0:
            printf("saindo....");
            break;
        case 1:
            printf("\n Digite o numero : ");
            scanf("%d",&op);
            push_inicio(op,f);
            op=1;
            break;
        case 3:
            op=pop_inicio(f);
            if(op!=-1)
            {
                printf("\n pop: %d",op);
            }
            else
            {
                printf("\n vazio");
            }
            op=3;
            break;
        case 5:
            printf("\n\n");
            mostra(f);
            break;
        default:
            break;
        }
    }
}
void mostra(fila *f)
{
    no *aux;
    if(f!=NULL)
    {
        aux=f->prm;
        while(aux!=NULL)
        {
            printf(" %d",aux->var);
            aux=aux->prx;
        }
    }
}
int pop_inicio(fila *f)
{
    int pvar;
    no * aux;
    if(f!=NULL)
    {
        if(f->prm!= NULL)
        {
            aux=f->prm;
            f->prm=f->prm->prx;
            f->prm->ant=NULL;
            pvar=aux->var;
            free(aux);
            return pvar;
        }
    }
    return -1;
}
void push_inicio(int num, fila *f)
{
    no *aux;
    aux=alloca_no();
    aux->var=num;
    if(f==NULL)
    {
        printf("alocado");
        f=alloca_fila();
    }
    if(f->prm==NULL)
    {
        printf(" primeiro");
        f->prm=f->ult=aux;
    }
    else
    {
        printf(" enezimo");
        aux->prx=f->prm;
        f->prm->ant=aux;
        f->prm=aux;
    }
}
no * alloca_no()
{
    return ((no*)calloc(1,sizeof(no)));
}
fila * alloca_fila()
{
    return ((fila*)calloc(1,sizeof(fila)));
}
