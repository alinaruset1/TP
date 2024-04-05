#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 6.1

void err(int conditie, const char *fmt, ...)
{
    if(conditie)
    {
        va_list va;
        va_start(va, fmt);
        fprintf(stderr, "eroare:");
        vfprintf(stderr, fmt, va);
        va_end(va);
        fputc('\n', stderr);
        exit(EXIT_FAILURE);
    }

}

void p1(void)
{
    int i,n;
    float x,y,e,min,max;
    printf("n=");
    scanf("%d", &n);
    err(n<=0 || n>100, "n invalid :%d\n", n);
    printf("x=");
    scanf("%g", &x);
    printf("y=");
    scanf("%g", &y);
    err(x >= y, "x=%g nu este mai mic decat y=%g\n", x, y);
    max = x;
    min = y;
    for(i =0; i<n; i++)
    {
        printf("e=");
        scanf("%g", &e);
        err(e<x || e>y, "element invalid :%d\n", e);
        if (e <min)
        min = e;
        if(e >max)
        max=e;
    }
    printf("min: %g, max: %g\n", min, max);
}

// 6.2

float *allocVec(int n, ...)
{
    va_list va;
    va_start(va, n);
    float *v=NULL;
    if((v=malloc(n*sizeof(float)))==NULL)
    {
        va_end(va);
        return NULL;
    }

    for(int i=0; i <n; i++)
    {
        v[i]=va_arg(va, double);
    }
    va_end(va);
    return v;
}

void p2()
{
    float *v;
    v=allocVec(3, 7.2, -1, 0);
    for(int i=0; i<3; i++)
    {
        printf("%f", v[i]);
    }
    printf("\n");
    free(v);
}

// 6.3

void absN(int n, ...)
{
    va_list va;
    va_start(va,n);
    float *p;
    for(int i=0; i<n; i++)
    {
        p= va_arg(va, float * );
        *p=fabs(*p);
    }
    va_end(va);
}

void p3()
{
    float x= -1.2, y=3.4;
    absN(2, &x, &y);
    printf("%f %f\n", x, y);
}

int crescator(char tip, int n,...)
{
    va_list va;
    va_start(va, n);
    int x, a_x;
    float y, a_y;
    for(int i=0; i<n; i++)
    {
        if (i==0)
        {
            switch(tip)
            {
                case 'd':
               {
                 a_x=va_arg(va, int);
               }
               case 'f':
               {
                a_y=va_arg(va, double);
                }
            }
        }
        else
        {
            switch (tip)
            {
            case 'd':
            {
                x = va_arg(va, int);
                if (x < a_x)
                {
                    return 0;
                }
                a_x = x;
            }
            case 'i':
            {
                y = va_arg(va, double);
                if (y < a_y)
                {
                    return 0;
                }
                a_y = y;
            }
            }
        }
    }
    return 1;
}
void p4(void)
{
    printf("%d\n", crescator(3, 'd', -1, 7, 9));
}


//6.5
void input(const char *fmt, ...)
{
    int *ptr1, i;
    float *ptr2;
    char *ptr3;
    va_list va;
    va_start(va, fmt);
    for (i = 1; i < strlen(fmt); i++)
    {
        if (fmt[i - 1] == '%')
        {
            switch (fmt[i])
            {
            case 'd':
            {
                ptr1 = va_arg(va, int *);
                scanf("%d", ptr1);
                break;
            }
            case 'f':
            {
                ptr2 = va_arg(va, float *);
                scanf("%f", ptr2);
                break;
            }
            case 'c':
            {
                ptr3 = va_arg(va, char *);
                scanf(" %c", ptr3);
                break;
            }
            }
        }
    }
    va_end(va);
}

void p5(void)
{
    int n;
    char ch;
    input("n=%dch=%c", &n, &ch);
    printf("%d %c\n", n, ch);
}


// 6.6

char *concat(int n, ...)
{
    char *string, *concatS=NULL;
    va_list va;
    va_start(va, n);
    for(int i=0; i <n; i++)
    {
        string=va_arg(va, char*);
        if((concatS=realloc(concatS, (strlen(string)+1)*sizeof(char)))==NULL)
        {
            va_end(va);
            return NULL;
        }
        strcat(concatS, string);
        strcat(concatS, " ");
    }
    va_end(va);
    return concatS;
}
void p6(void)
{
    char *string = concat(3, "Ion", "si", "Ana");
    printf("%s\n", string);
    free(string);
}

// 6.8
void sortare(int n, ...)
{
    int *v = NULL;
    if ((v = malloc(n * sizeof(int))) == NULL)
    {
        return;
    }
    va_list va;
    va_start(va, n);
    int i, j, aux;
    for (i = 0; i < n; i++)
    {
        v[i] = *(va_arg(va, int *));
    }
    va_end(va);
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    va_start(va, n);
    for (i = 0; i < n; i++)
    {
        *(va_arg(va, int *)) = v[i];
    }
    free(v);
    va_end(va);
}

void p8(void)
{
    int x = 5, y = 3, z = 8;
    sortare(3, &x, &y, &z);
    printf("%d %d %d\n", x, y, z);
}


// 6.9
void p9(int argc, char **argv)
{
    int i;
    float s = 0;
    for (i = 1; i < argc; i++)
    {
        s += atof(argv[i]);
    }
    printf("%f\n", s);
}

//6.11
void p11(int argc, char **argv)
{
    float expresie, numar;
    int i;
    expresie = atof(argv[1]);
    for (i = 2; i < argc; i+=2)
    {
        if (strcmp(argv[i], "add") == 0)
        {
            numar = atof(argv[i + 1]);
            expresie += numar;
        }
        else if (strcmp(argv[i], "sub") == 0)
        {
            numar = atof(argv[i + 1]);
            expresie -= numar;
        }
        else if (strcmp(argv[i], "mul") == 0)
        {
            numar = atof(argv[i + 1]);
            expresie *= numar;
        }
        else if (strcmp(argv[i], "div") == 0)
        {
            numar = atof(argv[i + 1]);
            expresie /= numar;
        }
    }
    printf("%f\n", expresie);
}

int main(void)
{
    //p1();
    //p2();
    //p3();
    //p4();
    //p5();
    p6();
    return 0;
}