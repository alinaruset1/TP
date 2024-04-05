#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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
void citire2(char **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%c", &a[i][j]);
        }
    }
}
void p1()
{
    int **a = NULL;
    int n, m;
    printf("n=");
    scanf("%d", &n);
    printf("m=");
    scanf("%d", &m);

    if ((a = (int **)malloc(m * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (int i = 0; i < m; i++)
    {
        if ((a[i] = (int *)malloc(m * sizeof(int))) == NULL)
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
    int **b = NULL;

    if ((b = (int **)malloc(n * sizeof(int *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (int i = 0; i < n; i++)
    {
        if ((b[i] = (int *)malloc(n * sizeof(int))) == NULL)
        {
            for (i--; i >= 0; i--)
            {
                free(b[i]);
            }
            free(b);
            printf("Memorie insuficienta");

            exit(-2);
        }
    }
    citire(a, m, m);
    citire(b, n, n);
    for (int i = 0; i <= m - n; i++)
    {
        for (int j = 0; j <= m - n; j++)
        {
            int ok = 1;
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if (a[i + k][j + l] != b[k][l])
                    {
                        ok = 0;
                        break;
                    }
                }
                if (!ok)
                {
                    break;
                }
            }
            if (ok)
            {
                printf("(%d,%d) ", i, j);
            }
        }
    }
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
}
int verify(char **a, int dimensiune, int linie, int coloana, int dx, int dy, char *cuvant)
{
    int l = strlen(cuvant);
    for (int i = 0; i < l; i++)
    {
        int newL = linie + i * dx;
        int newC = coloana + i * dy;

        if (newL < 0 || newL >= dimensiune || newC < 0 || newC >= dimensiune || a[newL][newC] != cuvant[i])
        {
            return 0;
        }
    }

    return 1;
}

void p2()
{
    char **a = NULL;
    int m;
    printf("m=");
    scanf("%d", &m);
    if ((a = (char **)malloc(m * sizeof(char *))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    for (int i = 0; i < m; i++)
    {
        if ((a[i] = (char *)malloc(m * sizeof(char))) == NULL)
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
    citire2(a, m);
    char cuvant[100];
    printf("Cuvantul este: ");
    scanf("%s", cuvant);
    for (int i = 0; i <m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int dx = -1; dx <= 1; dx++)
            {
                for (int dy = -1; dy <= 1; dy++)
                {
                    if (dx != 0 || dy != 0)
                    { 
                        if (verify(a, m, i, j, dx, dy, cuvant))
                        {
                            printf("De la linia %d coloana %d ", i, j);

                            if (dx == 0)
                            {
                                if (dy == 1)
                                {
                                    printf("spre dreapta.\n");
                                }
                                else
                                {
                                    printf("spre stanga.\n");
                                }
                            }
                            else if (dy == 0)
                            {
                                if (dx == 1)
                                {
                                    printf("in jos.\n");
                                }
                                else
                                {
                                    printf("in sus.\n");
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
int main(void)
{
    //p1();
    p2();
}