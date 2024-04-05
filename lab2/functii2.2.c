#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


void stergere(int v[100], int *n, int (*pf)(int))
{
    for (int i = 0; i < (*n); i++)
    {
        if ((*pf)(v[i]) == 0)
        {
            for (int j = i; j < (*n) - 1; j++)
            {
                v[j] = v[j + 1];
            }
            (*n)--;
        }
    }
}
void citire(int v[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("v[%d]=",i);
        scanf("%d", &v[i]);
    }
}
void afisare(int v[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("v[%d]=%d\n",i,v[i]);
        
    }
}


int filtru(int x)
{
    if (x % 2 == 1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int v[100];
    int n;
    printf("n=");
    scanf("%d", &n);
    //int (*pf)(int);
    //pf = &filtru;
    citire(v,n);
    stergere(v, &n, filtru);
    printf("\n");
    afisare(v,n);
}