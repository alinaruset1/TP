#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int n,k;
int v[MAX];

int verificare1(int p)
{
    if(v[p]==0)
        return 0;
    else
        return 1;
}

int solutie1(int p)
{
    int cnt=0;
    for(int i=0; i<=p; i++)
    {
        if(v[i]==1)
            cnt++;
    }
    return (p==n-1 && cnt==k);
}

void afisare1(void)
{
    for(int i=0; i<n; i++)
    {
        printf("%d", v[i]);
    }
    printf("\n");
}

void back1(int p)
{
    int i;
    if(p==n)
    return;
    for(i=0; i<=9; i++)
    {
        v[p]=i;
        if(verificare1(p))
        {
            if(solutie1(p))
            {
                afisare1();
            }   
            else
            {
                back1(p+1);
            }
        }
    }
}

void p1(void)
{
    n = 3;
    k = 2;
    back1(0);
}

//Problema 12.2

int verificare2(int p)
{
    for(int i=1; i<p; i++)
    {
        if(v[i]==v[p])
            return 0;
    }
    return 1;   
}

int solutie2(int p)
{
    int mijloc;
    if(p==n)
    {
        mijloc= n/2 + n%2;
        for(int i=1; i<mijloc;i++)
        {
            for(int j=i+1; j<=mijloc; j++)
            {
                if (v[i]<v[j])
                {
                    return 0;
                }
                
            }
        }

        for(int i=mijloc;i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(v[i]>v[j])
                    return 0;
            }
        }

        return 1;
    }
    else
        return 0;
}

void afisare2()
{
    for(int i=1; i<=n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void back2(int p)
{
    for(int i=1; i<=n; i++)
    {
        v[p]=i;
        if(verificare2(p))
        {
            if(solutie2(p))
                {
                    afisare2();
                }
            else
                {
                    back2(p+1);
                }
        }
    }
}

void p2(void)
{
    n = 5;
    back2(1);
}


//Problema 12.3

int numV[MAX], len, max;

void descompunere(int nr)
{
    int aux = nr, count = 0;
    len = 0;
    while (aux)
    {
        count++;
        aux = aux / 10;
    }
    while (nr)
    {
        numV[count - len] = nr % 10;
        len++;
        nr = nr / 10;
    }
}

int verificare3(int p)
{
    int i;
    for (i = 1; i < p; i++)
    {
        if (v[i] >= v[p])
        {
            return 0;
        }
    }
    return 1;
}

int solutie3(int p)
{
    if (p == (len - k))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int numar(void)
{
    int i, numar = 0;
    for (i = 1; i <= (len - k); i++)
    {
        numar = numar * 10 + numV[v[i]];
    }
    return numar;
}

void back3(int p)
{
    int i, aux;
    for (i = 1; i <= len; i++)
    {
        v[p] = i;
        if (verificare3(p))
        {
            if (solutie3(p))
            {
                aux = numar();
                if (aux > max)
                {
                    max = aux;
                }
            }
            else
            {
                back3(p + 1);
            }
        }
    }
}

void p3(void)
{
    n = 3452234;
    k = 4;
    descompunere(n);
    back3(1);
    printf("%d\n", max);
}


//Problema 12.4

char culori[7][100] = {" ", "alb", "galben", "rosu", "verde", "albastru", "negru"};

int verificare4(int p)
{
    int i;
    for (i = 1; i < p; i++)
    {
        if (v[i] == v[p]) //sa fie distincte 
        {
            return 0;
        }
    }
    return 1;
}

int solutie4(int p)
{
    if (p == 3 && (v[2] == 4 || v[2] == 2)) //la mijloc sa fie galben sau verde
    {
        return 1;
    }
    return 0;
}

void afisare4()
{
    int i;
    for (i = 1; i <= 3; i++)
    {
        printf("%s ", culori[v[i]]); //3 culori in total
    }
    printf("\n");
}

void back4(int p)
{
    int i;
    for (i = 1; i <= 6; i++) //6 pt ca sunt 6 culori diferite
    {
        v[p] = i;
        if (verificare4(p))
        {
            if (solutie4(p))
            {
                afisare4();
            }
            else
            {
                back4(p + 1);
            }
        }
    }
}

void p4(void)
{
    back4(1);
}

float volume[MAX] = {0.0, 1.23, 3.47, 0.89, 4.12, 2.36, 4.78, 1.56, 3.09, 0.45, 2.78, 4.33, 1.98, 3.67, 0.11, 2.45, 3.79, 4.56, 0.67, 2.88, 3.21}, volum;

int verificare5(int p)
{
    int i;
    for (i = 1; i < p; i++)
    {
        if (v[i] == v[p])
        {
            return 0;
        }
    }
    return 1;
}

int solutie5(int p)
{
    int i;
    float suma = 0.0;
    for (i = 1; i <= p; i++)
    {
        suma = suma + volume[v[i]];
    }
    return suma <= volum;
}

void afisare5(int p)
{
    int i;
    for (i = 1; i <= p; i++)
    {
        printf("%f ", volume[v[i]]);
    }
    printf("\n");
}

void back5(int p)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        v[p] = i;
        if (verificare5(p))
        {
            if (solutie5(p))
            {
                afisare5(p);
            }
            back5(p + 1);
        }
    }
}

void p5(void)
{
    n = 5;
    volum = 6.6;
    back5(1);
}

int main()
{
    p2();
    return 0;
}