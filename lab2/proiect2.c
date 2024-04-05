#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Problema 1
int nrfunctie=1;
double functia1(double x)
{
	return (x*x*x+4)/(x*x+5);
}
double functia2(double x)
{
	return x+10;
}
double functia3(double x)
{
	return 2*x*x-1;
}

void tabelare(double(*f)(double), double A, double B, double P)
{

	for(int i=A; i<=B;i=i+P)
	{
		printf("------------");
	}
	printf("\n");
	printf("   f%d(x)  |", nrfunctie);
	nrfunctie++;
	for(int i=A;i<=B;i=i+P)
	{
		printf("  %.2f  |", f(i));
	}
} 
void p1()
{
	double A=0;
	double B=0;
	double P=0;
	printf("A=");scanf("%lf", &A);
	printf("B=");scanf("%lf", &B);
	printf("P=");scanf("%lf", &P);
	printf("    x     |");
	for(int i=A;i<=B;i+=P)
	{
		printf("    %d    |", i);
	}
	printf("\n");
	double (*f)(double);
	f=&functia1;
	tabelare(f,A,B,P);
	printf("\n");
	f=&functia2;
	tabelare(f,A,B,P);
	printf("\n");
	f=&functia3;
	tabelare(f,A,B,P);
	printf("\n");
	
}
/*
int main(void)
{
	p1();
}
*/

//Problema 2
int lungime(char *s)
{
	return strlen(s);
}
int vocale(char *s)
{
	int cnt=0;
	while(*s)
	{
		char ch=tolower(*s);
		if(ch=='a' || ch=='e' || ch=='i'||ch=='o'||ch=='u')
			cnt++;
		s++;

	}
	return cnt;
}
int mari(char *s)
{
	int cnt=0;
	while(*s)
	{
		if(isupper(*s))
			cnt++;
		s++;
	}
	return cnt;
}
int dif_ascii(char *s)
{
	int prima=(int)s[0];
	int ultima=(int)s[strlen(s)-1];
	return abs(ultima-prima);
}

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		fprintf(stderr,"Eroare la argumente");
		return 1;
	}
	FILE *f=NULL;
	if((f=fopen("CUVINTE.TXT","w"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}

	int (*functii[])(char*)={lungime,vocale,mari,dif_ascii};
	int nr=sizeof(functii)/sizeof(functii[0]);

	for(int i=1;i<argc; i++)
	{
		fprintf(f,"Cuvantul:%s\n", argv[i]);
		printf("Cuvantul:%s\n", argv[i]);
		for(int j=0; j<nr;j++)
		{
			int rez=functii[j](argv[i]);
			fprintf(f, "Rezultatul functiei %c: %d\n",'a'+j, rez);
			
		}
		fprintf(f,"\n");
	}
	if(fclose(f)!=0)
	{
		perror(NULL);
		exit(-1);
	}
	
	return 0;
}