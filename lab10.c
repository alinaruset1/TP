#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//Problema 10.1
int divizor(int a, int b)
{
    if(b==0)
        return a;
    else
        return divizor(b, a%b);
        
}

void p1()
{
    int d=divizor(6,17);
    printf("%d ", d);
}

//Problema 10.2
int suma(int n)
{
    if(n<10)
    return n;
    else
    return n%10+suma(n/10);
}

void p2()
{
    printf("%d ", suma(594));
}

//Problema 10.3

int max(int a,int b)
{
    if(a>b)
    return a;
    else
    return b;
}

int cifra_max(int n)
{
    if(n<10)
    return n;
    else
    return max(n%10,cifra_max(n/10));

}

void p3()
{
    printf("%d ", cifra_max(123));
}


//Problema 10.4

int fibonacci(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else
    return fibonacci(n-1)+fibonacci(n-2);
}

void p4()
{
    printf("%d", fibonacci(5));
}

//Problema 10.5
char* fibo_string(int n, const char* s1, const char* s2) {
    if (n == 1) {
        return strdup(s1);
    }
    if (n == 2) {
        return strdup(s2);
    }

    char* prev1 = strdup(s1);  
    char* prev2 = strdup(s2);  
    char* current = NULL;

    for (int i = 3; i <= n; i++) {

        current = (char*)malloc(strlen(prev1) + strlen(prev2) + 1);
        if (current == NULL) {
            perror(NULL);
            exit(EXIT_FAILURE);
        }

        strcpy(current, prev2);
        strcat(current, prev1);
        free(prev1);
        prev1 = prev2;
        prev2 = current;
    }
    free(prev1);

    return current;  
}

void p5()
{
    int n=6;
    const char *s1="a";
    const char *s2="b";
    printf("%s\n", fibo_string(n,s1,s2));
}

//Problema 10.6
double calculate_phi(double precision) {
    double p_phi = 0.0;
    double c_phi = 1.0;
    int n = 1;

    while (fabs(c_phi - p_phi) > precision) {
        n++;
        long long fn1 = fibonacci(n);
        long long fn = fibonacci(n - 1);
        
        p_phi = c_phi;
        c_phi = (double)fn1 / fn;
    }

    return c_phi;
}

void p6()
{
    double precision = 1e-10;
    double phi = calculate_phi(precision);

    printf("Valoarea lui Phi cu precizia %g este: %.10f\n", precision, phi);
    
}

//Problema 10.7

double serie(int x, double term, int n, double precision)
{
    if(fabs(term)<precision)
    return 0;
    return term+serie(x,term*x/(n+1), n+1, precision);
}

void p7()
{
    printf("%f ",serie(1, 1.0, 0, 1e-6));
}

//Problema 10.8
int bbsearch(int v[], int st, int dr, int x)
{
    if(st>dr)
    return 0;
    int mij=st+(dr-st)/2;
    if(v[mij]==x)
    {
        return 1;
    }
    if(v[mij]>x)
    return bbsearch(v,st, mij+1, x);

    return bbsearch(v,mij+1,dr,x);
}

int returnare(int v[], int size, int x)
{
    return bbsearch(v,0,size-1,x);
}
void p8()
{
    int v[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(v)/sizeof(v[0]);
    int x=5;
    if(returnare(v,size,x))
    {
        printf("S-a gasit");
    }
    else
    {
        printf("Nu s-a gasit");
    }
}
int main(void)
{

//p1();
//p2();
//p3();
//p4();
//p5();
//p6();
//p7();
p8();
    return 0;
}