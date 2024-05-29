#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//1. Permutari
//Fie n un număr natural nenul.
// Să se genereze permutările de n elemente.

int n,v[100],vector[]={0, -1,-2,3,4},p;

void afisare1()
{
    for(int i=1; i<=n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int valid1(int k)
{
    for(int i=1; i<k; i++)
    {
        if(v[i]==v[k])
        {
            return 0;
        }
    }
    return 1;
}

int solutie1(int k)
{
    if(k==n)
    {
        return 1;
    }
    return 0;
}

void back1(int k)
{
    for(int i=1; i<=n; i++)
    {
        v[k]=i;
        if(valid1(k))
        {
            if(solutie1(k))
            {
                afisare1();
            }
            else{
                back1(k+1);
            }
        }
    }
}

void p1()
{
    n=5;
    back1(1);
}





//Problema 2.
//Fie n şi m două numere naturale nenule, m <= n. 
//Să se genereze aranjamentele de n elemente luate câte m


int valid2(int k)
{
    for(int i=1; i<k;i++)
    {
        if(v[i]==v[k])
        {
            return 0;
        }
    }
    return 1;
}

int solutie2(int k)
{
    if(k==p)
    {
        return 1;
    }
    return 0;
}

void afisare2(int k)
{
    for(int i=1; i<=p; i++)
    {
        printf("%d ", v[i]);

    }
    printf("\n");
}

void back2(int k)
{
    for(int i=1;i<=n; i++)
    {
        v[k]=i;
        if(valid2(k))
        {
            if(solutie2(k))
            {
                afisare2(k);
            }
            else
            {
                back2(k+1);
            }
        }
    }
}

void p2()
{
    n=4;
    p=2;
    back2(1);
}







//Problema 3.
//Combinari

void afisare3()
{
    for(int i=1;i<=p; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int valid3(int k)
{
    for(int i=1; i<k; i++)
    {
        if(v[i]==v[k])
        {
            return 0;
        }
        if(k>1)
        {
            if(v[k]<=v[k-1])
            {
                return 0;
            }
        }
    }
    return 1;
}


int solutie3(int k)
{
    if(k==p)
    {
        return 1;
    }
    return 0;
}

void back3(int k)
{
    for(int i=1; i<=n; i++)
    {
        v[k]=i;
        if(valid3(k))
        {
            if(solutie3(k))
            {
                afisare3();
            }
            else
            {
                back3(k+1);
            }
        }
    }
}

void p3()
{
    n=4;
    p=2;
    back3(1);
}







//Problema 4. Submultimi

void afisare4(int k)
{
    for(int i=1; i<=k; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int valid4(int k)
{
    if(k==1)
    {
        return 1;
    }
    if(v[k]>v[k-1])
    {
        return 1;
    }
    return 0;
}

void back4(int k)
{
    for(int i=1; i<=n; i++)
    {
        v[k]=i;
        if(valid4(k))
        {
                afisare4(k);
                back4(k+1);
        }
    }
}

void p4()
{
    n=4;
    back4(1);
}











//Problema 5
//Scrieti un program care afiseaza toate posibilitatile de a aranja elementele unui vector intreg astfel incat in sirul rezultat
//sa nu existe 2 numere negative alaturate

int sol[100];

void afisare()
{
    for(int i=1; i<=n; i++)
    {
        printf("%d ", vector[sol[i]]);

    }
    printf("\n");
}

int valid5(int k)
{
    for(int i=1; i<k; i++)
    {
        if(sol[i]==sol[k])
        {
            return 0;
        }
        if(vector[sol[i]]<0 && vector[sol[i-1]]<0)
        {
            return 0;
        }
    }
    return 1;
}

int solutie5(int k)
{
    return k==n-1;
}

void back5(int k)
{
    for(int i=1; i<=n; i++)
    {
        sol[k]=i;
        if(valid5(k))
        {
            if(solutie5(k))
            {
                afisare(k);
            }
            else
            {
                back5(k+1);
            }
        }
    }
}

void p5()
{
    n=5;
    back5(1);
}









//Problema 11
/*. Se citeşte de la tastatură dimensiunea n a unei matrici binare (cu elem. 0 sau 1). Să
se formeze toate matricele posibile astfel încât pe fiecare linie respectiv coloană să
fie exact un element nenul.*/

int matrice[10];

int valid11(int k)
{
    for(int i=1; i<k; i++)
    {
        if(matrice[i]==matrice[k])
        {
            return 0;
        }
    }
    return 1;
}

void afisare11()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
           if(j==matrice[i])
            printf("1 ");
            else
            printf("0 ");

        }
        printf("\n");
    }
    printf("\n");
}

int solutie11(int k)
{
    return k==n;
}

void back11(int k)
{
    for(int i=1; i<=n; i++)
    {
        matrice[k]=i;
        if(valid11(k))
        {
            if(solutie11(k))
            {
                afisare11();
            }
            else{
                back11(k+1);
            }
        }
    }
}


void p11()
{
    n=3;
    back11(1);
}






//Problema:
/*Se citeşte un număr natural nenul n, apoi n numere naturale distincte. Să se afişeze, în ordine lexicografică, 
permutările mulţimii formate din cele n numere citite.*/

int st[10];

void afisare6()
{
    for(int i=1; i<=n;i++)
    {
        printf("%d ", v[st[i]]);
    }
    printf("\n");
}

int verificare6(int k)
{
    for(int i=1;i<k; i++)
    {
        if(st[i]==st[k])
        {
            return 0;
        }
    }
    return 1;
}

int solutie6(int k)
{
    return k==n;
}

void back6(int k)
{
    for(int i=1;i<=n; i++)
    {
        st[k]=i;
        if(verificare6(k))
        {
            if(solutie6(k))
            {
                afisare6();
            }
            else{
                back6(k+1);
            }
        }
    }
}

void p6()
{
    n=5;
    for(int i=1;i<=n; i++)
    {
        scanf("%d", &v[i]);
    }
    back6(1);
}














/*Problema:

Se citeşte un număr natural nenul n, apoi n numere naturale distincte. Să se afişeze,
 în ordine lexicografică, șirurile din cele n valori cu proprietatea că oricare două valori învecinate sunt prime între ele.
*/


int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    if(a==1)
    return 1;
    return 0;

}

void afisare7()
{
    for(int i=1; i<=n; i++)
{
    printf("%d ", v[st[i]]);
}
printf("\n");
}

int verificare7(int k)
{
    for(int i=1; i<k; i++)
    {
        if(st[i]==st[k])
        {
            return 0;
        }
    }
        if(k>=2 && cmmdc(v[st[k]], v[st[k-1]])==0)
        {
            return 0;
        }
    
    return 1;
}

int solutie7(int k)
{
    return k==n;
}

void back7(int k)
{
    for(int i=1; i<=n;i++)
    {
        st[k]=i;
        if(verificare7(k))
        {
            if(solutie7(k))
            {
                afisare7(k);
            }
            else{
                back7(k+1);
            }
        }
    }
}

void p7()
{
    n=5;
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &v[i]);
    }
    back7(1);
}









//Problema:
/*
Se citește un număr natural impar n (n<10). 
Afișați în ordine lexicografică toate permutările mulțimii {1,2,…,n} în care n se află în mijlocul permutării.
*/

void afisare8()
{
    for(int i=1; i<=n;i++)
    {
        printf("%d ", v[st[i]]);
    }
    printf("\n");
}


int valid8(int k)
{
    int mijloc=n/2+1;
    for(int i=1;i<k;i++)
    {
        if(st[i]==st[k])
        {
            return 0;
        }
    }

    if (k == n / 2 + 1 && st[k] != n)
    {
        return 0;
    }
    return 1;
}

int solutie8(int k)
{
    return k==n;
}

void back8(int k)
{
    for(int i=1; i<=n; i++)
    {
        st[k]=i;
        if(valid8(k))
        {
            if(solutie8(k))
            {
                afisare8();
            }
            else
            {
                back8(k+1);
            }
        }
    }
}

void p8()
{
    n=7;
    for(int i=1;i<=n; i++)
    {
        scanf("%d", &v[i]);
    }
    back8(1);
}











/*
Anagramele unui cuvant citit
*/
char w[100]="maria";

void afisare9()
{
    for(int i=0;i<n; i++)
    {
        printf("%c",w[st[i]]);

    }
    printf("\n");
}

int valid9(int k)
{
    for(int i=0; i<k; i++)
    {
        if(st[i]==st[k])
        {
            return 0;
        }
    }
    return 1;
}

int solutie9(int k)
{
    return k==n-1;
}

void back9(int k)
{
    for(int i=0; i<n; i++)
    {
        st[k]=i;
        if(valid9(k))
        {
            if(solutie9(k))
            {
                afisare9();

            }
            else
            {
                back9(k+1);
            }
        }
    }
}

void p9()
{
n=strlen(w);
back9(1);

}
int main()
{
    //p1();
    //p2();
    //p3();
    //p4();
    //p5();
    p9();

}