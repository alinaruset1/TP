#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


void stergere(int *v, int*n,int (*pf)(int))
{
  for(int i=0; i <*n; i++)
    {
      if((*pf)(v[i])==0)
	{
	  for(int j=i; j<*n-1;j++)
	    v[j]=v[j+1];
	  (*n)--;
	}
    }
}
void citire(int *v, int n)
{
  for(int i=0; i <n; i++)
    {
      scanf("%d", &v[i]);
    }
}

void afisare(int *v, int n)
{

  for(int i=0; i <n ; i++)
    {
      printf("%d ", v[i]);
    }
}
int negative(int e)
{
  if (e<0)
    return 0;
  else
    return 1;
}


void p2()
{
  int n;
  scanf("%d", &n);
  int v[n];
  int(*pf)(int);
  pf= &negative;
   citire(v, n);
   stergere(v, &n, pf);
   printf("\n");
   afisare(v,n);
  
}
int main(void)
{ //p1();
  p2();
  return 0;
}
