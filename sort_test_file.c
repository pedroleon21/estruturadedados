#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
void bubblesort(int V[],int tamanho);
void insertionsort(int V[], int tamanho);
void mergeSort(int vetor[], int comeco, int fim);
void merge(int vetor[], int comeco, int meio, int fim);
void quicksort(int *vet,int inicio,int fim);
int bbinaria(int *V,int inicio,int fim,int n);


int main()
{
    int i,tamanho=100, *V, aux, j,count=0;
    scanf("%d",&tamanho);
    printf("\nalocado");

    V= (int*)calloc(tamanho,sizeof(int));
    printf("\nsetando");
    for(i=0; i<tamanho; i++)
    {
        V[i]=i;
    }
    printf("\nembaralhando\n");
    for(i=0; i<tamanho; i++)
    {
        j=rand()%tamanho;
        aux=V[j];
        V[j]=V[i];
        V[i]=aux;
    }
    for(i=0; i<tamanho; i++)
    {
        printf(" %d",V[i]);
    }
    printf("\nordenando...\n");
    //bubblesort(V,tamanho);
    quicksort(V,0,tamanho-1);
    //mergeSort(V,0,tamanho);
    printf("\n");
    for(i=0; i<tamanho; i++)
    {
        printf(" %d",V[i]);
    }
    //printf("\n busca binaria:");
    //scanf("%d",&count);
    //count=bbinaria(V,0,tamanho-1,count);
    if(count) printf("\nencontrado");
    //free(V);
    return 0;
}
int bbinaria(int *V,int inicio,int fim,int n)
{
    int meio=(fim-inicio)/2;
    if (V[meio]==n) return V[meio];
    if(n>V[meio]) return bbinaria(V,meio,fim,n);
    if(n<V[meio]) return bbinaria(V,inicio,meio,n);
    return 0;
}
void insertionsort(int V[], int tamanho)
{
    int i,j,aux;
    i=1;
    while(i<tamanho)
    {
        aux=V[i];
        j=i-1;
        while(aux<V[j] && j>=0)
        {
            V[j+1]=V[j];
            j--;
        }
        V[j+1]=aux;
        i++;
    }
}
void bubblesort(int V[],int tamanho)
{
    int i,j,flag=1,aux;
    for(i=0; i<tamanho && flag; i++)
    {
        flag=0;
        for(j=1; j<tamanho-i; j++)
        {
            if(V[j-1]>V[j])
            {
                flag=1;
                aux = V[j-1];
                V[j-1]=V[j];
                V[j]=aux;
            }
        }
    }
}

void quicksort(int  *vet,int inicio,int fim)
{
    int i,f,aux,pivo;
    i=inicio;
    f=fim;
    pivo=vet[inicio+1];
    while(i<=f)
    {
        while(vet[i]<pivo && i< fim) i++;
        while(vet[f]>pivo && f >=0) f--;
        if(i<=f)
        {
            aux=vet[i];
            vet[i]=vet[f];
            vet[f]=aux;
            i++;
            f--;
        }
    }
    if(i<fim) quicksort(vet,i,fim);
    if(f>inicio) quicksort(vet,inicio,f);
}

/*
void quicksort(int V[], int inicio, int fim)
{
    int i, j, pivo, aux;
    i = inicio;
    j = fim-1;
    printf("\n %d",fim);
    pivo = V[(inicio + fim) / 2];
    while(i < j)
    {
        while(V[i] < pivo && i < fim)
        {
            i++;
        }
        while(V[j] > pivo && j > inicio)
        {
            j--;
        }
        if(i < j)
        {
            aux = V[i];
            V[i] = V[j];
            V[j] = aux;
            i++;
            j--;
        }
    }
    if(j > inicio)
        quicksort(V, inicio, j+1);
    if(i < fim)
        quicksort(V, i, fim);
}

*/
void merge(int vetor[], int comeco, int meio, int fim)
{
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));
    while(com1 <= meio && com2 <= fim)
    {
        if(vetor[com1] < vetor[com2])
        {
            vetAux[comAux] = vetor[com1];
            com1++;
        }
        else
        {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }
    while(com1 <= meio)   //Caso ainda haja elementos na primeira metade
    {
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }
    while(com2 <= fim)     //Caso ainda haja elementos na segunda metade
    {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }
    for(comAux = comeco; comAux <= fim; comAux++)     //Move os elementos de volta para o vetor original
    {
        vetor[comAux] = vetAux[comAux-comeco];
    }
    free(vetAux);
}
void mergeSort(int vetor[], int comeco, int fim)
{
    if (comeco < fim)
    {
        int meio = (fim+comeco)/2;
        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}
