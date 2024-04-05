#include <stdio.h>
#include <stdlib.h>
#define MAX 10000000

void afisare(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%4d ", a[i][j]);
        }
        printf("\n");
    }
}
void citire(int **a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
void ex83()
{
    int **a;
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    if ((a = (int **)malloc(m * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    for (int i = 0; i < m; i++)
    {
        if ((a[i] = (int *)malloc(n * sizeof(int))) == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(a[i]);
            }
            free(a);
            printf("Memorie insuficienta");

            exit(-2);
        }
    }

    int c = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = c;
            c++;
        }
    }
    afisare(a, m, n);
    for (int i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);

    
}

void ex84()
{
    int **a, aux;
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    if ((a = (int **)malloc(m * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    for (int i = 0; i < m; i++)
    {
        if ((a[i] = (int *)malloc(n * sizeof(int))) == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(a[i]);
            }
            free(a);
            printf("Memorie insuficienta");

            exit(-2);
        }
    }
    citire(a, m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                aux = a[i][j];
                a[i][j] = a[j][i];
                a[j][i] = aux;
            }
        }
    }
    afisare(a, m, n);
    for (int i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);
}

void ex85(void)
{
    int **a;
    int n, m;
    scanf("%d", &m);
    scanf("%d", &n);
    // alocare dinamica matrice
    if ((a = (int **)malloc(m * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (int i = 0; i < m; i++)
    {
        if ((a[i] = (int *)malloc(n * sizeof(int))) == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(a[i]);
            }
            free(a);
            printf("Memorie insuficienta");

            exit(-2);
        }
    }
    citire(a, m, n);

    int *v = NULL;
    if ((v = malloc(m * sizeof(int))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }

    for (int i = 0; i < m; i++)
    {
        v[i] = 0; // initializare suma de pe fiecare linie cu 0
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[i] = v[i] + a[i][j]; // aflare suma pe fiecare linie
        }
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d ", v[i]);
    }
    for (int i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);
}

void ex86()
{
    int **a;
    int n, m;
    scanf("%d", &m);
    scanf("%d", &n);
    // alocare dinamica matrice
    if ((a = (int **)malloc(m * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (int i = 0; i < m; i++)
    {
        if ((a[i] = (int *)malloc(n * sizeof(int))) == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(a[i]);
            }
            free(a);
            printf("Memorie insuficienta");

            exit(-2);
        }
    }

    int *nr = NULL;
    if ((nr = (int *)malloc(n * sizeof(int))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Introduceti numarul de prieteni al persoanei %d: ", i);
        scanf("%d", &nr[i]);

        a[i] = (int *)malloc(nr[i] * sizeof(int)); // Alocare dinamică pentru prietenii fiecărei persoane

        if (a[i] == NULL)
        {
            printf("Eroare la alocarea memoriei.\n");
            exit(-1);
        }

        printf("Introduceți prietenii persoanei %d: ", i);
        for (int j = 0; j < nr[i]; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        int total = nr[i];
        printf("Persoana %d are %d prieteni.\n", i, total);
        free(a[i]);
    }
    free(a);
    free(nr);
}
void ex87()
{
    int n = 0;
    int distanta = MAX;
    int oras1 = 0;
    int oras2 = 0;
    printf("n=");
    scanf("%d", &n);
    int **a = NULL;
    if ((a = (int **)malloc(n * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
        if (a[i] == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(a[i]);
            }
            free(a);
            perror(NULL);
            exit(-1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                printf("Distanta dintre orasul %d si %d este:", i, j);
                scanf("%d", &a[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            else
            {
                if ((a[i][j] > 0) && (a[i][j] < distanta))
                {
                    oras1 = i;
                    oras2 = j;
                    distanta = a[i][j];
                }
            }
        }
    }
    printf("Distanta minima este de %d intre orasul %d si orasul %d\n", distanta, oras1, oras2);
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);
}

void ex88()
{
    int **a = NULL;
    int **b = NULL;
    int m, n, p;
    printf("m=");
    scanf("%d", &m);
    printf("n=");
    scanf("%d", &n);
    printf("p=");
    scanf("%d", &p);
    int **c = NULL;
    if ((a = (int **)malloc(m * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (int i = 0; i < m; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
        if (a[i] == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(a[i]);
            }
            free(a);
            perror(NULL);
            exit(-1);
        }
    }
    if ((b = (int **)malloc(n * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = (int *)malloc(p * sizeof(int));
        if (b[i] == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(b[i]);
            }
            free(b);
            perror(NULL);
            exit(-1);
        }
    }
    if ((c = (int **)malloc(m * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (int i = 0; i < m; i++)
    {
        c[i] = (int *)malloc(p * sizeof(int));
        if (c[i] == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(c[i]);
            }
            free(c);
            perror(NULL);
            exit(-1);
        }
    }
    citire(a, m, n);
    citire(b, n, p);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }
    afisare(c, m, p);
    for (int i = 0; i < m; i++)
    {
        free(a[i]);
    }
    free(a);
    for (int i = 0; i < n; i++)
    {
        free(b[i]);
    }
    free(b);
    for (int i = 0; i < m; i++)
    {
        free(c[i]);
    }
    free(c);
}

void ex89()
{
    int **a;
    int n;
    printf("n=");
    scanf("%d", &n);
    if ((a = (int **)malloc(n * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        if ((a[i] = (int *)malloc(n * sizeof(int))) == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(a[i]);
            }
            free(a);
            printf("Memorie insuficienta");

            exit(-2);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
    afisare(a, n, n);
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);
}
void ex810()
{
    int n;

    printf("n=");
    scanf("%d", &n);
    int a[n][4];

    for (int i = 0; i < n; i++) {
        printf("Produsul %d: ", i + 1);
        for (int j = 0; j < 4; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        int cnt= 1;
        for (int j = 1; j < 4; j++) {
            if (a[i][j] <= a[i][j - 1]) {
                cnt = 0;
                break;
            }
        }
        if (cnt) {
            printf("Produsul %d\n", i + 1);
        }
    }

}

int main(void)
{
    // ex83();
    // ex84();
    // ex85();
    // ex86();
    //ex87();
    //ex88();
    // ex89();
    //ex810();
    return 0;
}
