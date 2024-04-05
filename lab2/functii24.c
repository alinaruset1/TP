#include <stdio.h>
#include <math.h>
void tabelare(double a, double b, int n, double (*functie)(double))
{
    double i, pas;
    pas = (b - a) / n;
    for (i = a; i <= b; i += pas)
    {
        printf("f(%f)=%f\n", i, functie(i));
    }
}

void p4(void)
{
    int a,b,pas;
    printf("Valoarea lui a:");
    scanf("%d", &a);
    printf("Valoarea lui b:");
    scanf("%d", &b);
    printf("Valoarea pasului:");
    scanf("%d", &pas);
    printf("Functia cos\n");
    tabelare(a, b, pas, cos);
    printf("Functia sqrt\n");
    tabelare(a, b, pas, sqrt);
    printf("Functia fabs\n");
    tabelare(a, b, pas, fabs);
}
int main(void)
{
    p4();
    return 0;
    
}