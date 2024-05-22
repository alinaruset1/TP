#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Problema 11.1 Greedy
typedef struct {
float x,y;
}Punct;

double distanta(Punct a, Punct b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int gasire(Punct *p, int vizitat[], int n, Punct curent)
{
    int index=-1;
    double minim=100000;

    for(int i=0; i<n; i++)
    {
        if(vizitat[i]==0)
        {
            double dist=distanta(curent,p[i]);
            if(dist<minim)
            {
                minim=dist;
                index=i;
            }
        }
    }
    return index;
}

void p1()
{
    int n;
    Punct p[100];
    int vizitat[100]={0};

    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%1f %1f", &p[i].x, &p[i].y);
    }
    Punct curent={0, 0};
    for(int i=0; i<n; i++)
    {
        int index=gasire(p,vizitat,n,curent);
        if(index!=-1)
        {
            vizitat[index]=1;
            curent=p[index];
            printf("Punctul %d: (%.2f, %.2f)\n", index+1, curent.x, curent.y);
        }
    }

}

//Problema 11.2 Divide et Impera

void p2()
{
    int n;
    float ma,mb,m,d,G=667400000000, step, x=0, Fa,Fb;
    scanf("%d %1f %1f %1f %1f", &n, &ma, &mb, &m, &d);

    step=d/n;

    for(int i=0;i<=n;i++)
    {
        Fa=G*ma*m/(x*x);
        Fb=G*mb*m/((d-x)*(d-x));
        printf("%1f %1f %1f\n", x,Fa,Fb);
        x=x+step;
    }
}

//Problema 11.3

int red_matrice(int matrice[][100], int m, int n)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    else if(m==1&& n==1)
    {
        return matrice[0][0];
    }
    else
    {
        int mRow= m/2;
        int mCol=n/2;

        int stSus[m][n], drSus[m][n], stJos[m][n], drJos[m][n];

        for(int i=0; i<mRow;i++)
        {
            for(int j=0; j<mCol; j++)
            {
                stSus[i][j]=matrice[i][j];
            }
        }

        for(int i=0; i<mRow; i++)
        {
            for(int j=mCol;j<n; j++)
            {
                stJos[i][j]=matrice[i][j];
            }
        }

        for(int i=mRow; i<m; i++)
        {
            for(int j=0; j<mCol; j++)
            {
                drSus[i][j]=matrice[i][j];
            }
        }

        for(int i=mRow; i<m ; i++)
        {
            for(int j=mCol; j<n; j++)
            {
                drJos[i][j]=matrice[i][j];
            }
        }

        int redSS=red_matrice(stSus, mRow, mCol);
        int redSJ=red_matrice(stJos,m-mRow,mCol);
        int redDS=red_matrice(drSus,mRow,n-mCol);
        int redDJ=red_matrice(drJos,m-mRow,n-mCol);

        int maxS=(redSS>redDS) ? redSS : redDS;
        int minJ=(redSJ< redDJ) ? redSJ :redDJ;

        return maxS-minJ;
    }
}

void p3(void)
{
    int m, n, matrice[100][100], i, j;
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &matrice[i][j]);
        }
    }

    printf("%d\n", red_matrice(matrice, m, n));
}

// Problema 11.4 Greedy

typedef struct
{
    char nume[15];
    int valoare;
} Jucator;

int comparareJucatori(const void *a, const void *b)
{
    Jucator *jucator1 = (Jucator *)a;
    Jucator *jucator2 = (Jucator *)b;
    return jucator1->valoare - jucator2->valoare;
}

void p4(void)
{
    int n, m, i, count = 0;
    Jucator jucatori[100];
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%s %d", jucatori[i].nume, &jucatori[i].valoare);
    }

    qsort(jucatori, n, sizeof(Jucator), comparareJucatori);

    for (i = n - 1; i >= 0; i--)
    {
        if (count == n / m)
        {
            printf("\n");
            count = 0;
        }
        printf("%s %d\n", jucatori[i].nume, jucatori[i].valoare);
        count++;
    }
}


int main(void)
{
    //p3();
    p4();
}
