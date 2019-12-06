#include<stdio.h>
#include<string.h>
int main()
{
    int vet[100],i;
    i=0;
    while(i<100)
    {
        vet[i]=i;
        i++;
    }
    for(i=0;i<100;i++)
    {
        printf(" %d",vet[i]);
    }

}
