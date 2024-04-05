#include<stdio.h>
#include <stdint.h>
#include <stdlib.h>
//PROBLEMA 4.0
typedef struct Student{
    char nume:2; 
    uint8_t nota:1;      
}Student;

void p0()
{
    Student student;
    printf("Introduceti numele studentului:");
    scanf("%16s", student.nume);
    printf("Introduceti nota studentului: ");
    scanf("%d", &student.nota);

    printf("\nStudentul %s are nota %d.\n", student.nume, student.nota);

}

//PROBLEMA 4.1
typedef struct
{
	char nume[15];
	int dimensiune: 10;
	unsigned int tip: 2;
	unsigned int tip_fisier: 2;
}Info;
void p1()
{
	
	Info fisier;
	int aux1=0;
	int aux2=0;
	int aux3=0;
	printf("Nume fisier: ");
	scanf("%s", fisier.nume);
	printf("Dimensiunea fisierului:");
	scanf("%d",&aux1);
	fisier.dimensiune=aux1;
	printf("Tipul fisierului: (.txt - 0, .doc-1, .xls-2)");
	scanf("%d", &aux2);
	fisier.tip=aux2;
	printf("Tipul fisierului: (normal-0, read-only-1)");
	scanf("%d", &aux3);
	fisier.tip_fisier=aux3;
	printf("Datele codificare sunt %s, %d, %d, %d\n", fisier.nume, fisier.dimensiune, fisier.tip, fisier.tip_fisier);

}
//PROBLEMA 4.2
typedef struct
{
	char nume[15];
	int dimensiune: 10;
	unsigned int tip: 2;
	unsigned int tip_fisier: 2;
}Info;

void p2()
{
	Info v[10];
	
	int n=0;
	int aux1=0;
	int aux2=0;
	int aux3=0;
	printf("Numarul de fisiere citite:");
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		
		printf("Nume fisier: ");
		scanf("%s", v[i].nume);
		printf("Dimensiunea fisierului:");
		scanf("%d",&aux1);
		v[i].dimensiune=aux1;
		printf("Tipul fisierului: (.txt - 0, .doc-1, .xls-2)");
		scanf("%d", &aux2);
		v[i].tip=aux2;
		printf("Tipul fisierului: (normal-0, read-only-1)");
		scanf("%d", &aux3);
		v[i].tip_fisier=aux3;
	}
	FILE *f=NULL;
	if((f=fopen("memorie.txt", "wt"))==NULL)
	{
		perror(NULL);
		exit(-1);
	}
	for(int i=0;i<n;i++)
	{
		fprintf(f, "%s %d %d %d\n", v[i].nume, v[i].dimensiune, v[i].tip, v[i].tip_fisier);
	}
	if(fclose(f)!=1)
	{
		perror(NULL);
		exit(-1);
	}
}

//SUBIECTUL 1
typedef struct car{
    unsigned int cod : 15;
    unsigned int locuri : 4;
    unsigned int putere : 9;
    char marca[100];
    char culoare[100];
    unsigned int an : 15;
} car;

void adaugare(car *c, int *n) {
    car nou;
    printf("Noul automobil:\n");
    int aux;
    printf("Cod: "); 
	scanf("%d",&aux);
    nou.cod=aux;
    printf("Locuri: "); 
    scanf("%d",&aux);
    nou.locuri=aux;
    printf("Puterea: "); 
    scanf("%d",&aux);
    nou.putere=aux;
    printf("An: "); 
    scanf("%d",&aux);
    nou.an=aux;
    printf("Marca: "); 
    scanf("%s", nou.marca);
    printf("Culoare: ");
     scanf("%s", nou.culoare);
    c[*n] = nou;
    (*n)++;
}

void stergere(car *c, int *n, int cod) {
    int i, j;
    for (i = 0; i < *n; i++) {
        if (c[i].cod == cod) {
            for (j = i + 1; j < *n; j++) {
                c[j - 1] = c[j];
            }
            (*n)--;
            return;
        }
    }
    printf("CODUL NU EXISTA.\n");
}

void afisare(car *c, int n) {
    printf("Lista de automobile:\n");
    for (int i = 0; i < n; i++) {
        printf("Cod: %d\nLocuri: %d\nPutere: %d\nAn: %d\nMarca: %s\nCuloare: %s\n\n", c[i].cod, c[i].locuri, c[i].putere, c[i].an, c[i].marca, c[i].culoare);
    }
}

void p3()
{
    car c[100];
    int n = 0;
    int opt;

    printf("Introduceti numarul de automobile: ");
    scanf("%d", &n);

    while (1) {
        printf("\nMENIU:\n1. Introducerea unui automobil nou\n2. Stergerea unui automobil dupa cod\n3. Afisarea intregii liste de automobile\n4. Afisarea automobilelor cu un anumit numar de locuri\n5. Ordonarea listei dupa anul fabricatiei\n0. Iesire\n");
        printf("Optiune: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                adaugare(c, &n);
                break;
            case 2:
                if (n > 0) {
                    int cod;
                    printf("Introduceti codul masinii de sters: ");
                    scanf("%d", &cod);
                    stergere(c, &n, cod);
                } else {
                    printf("Nu exista automobile de sters.\n");
                }
                break;
            case 3:
                afisare(c, n);
                break;
            case 0:
                printf("Programul s-a incheiat.\n");
                return 0;
            default:
                printf("Optiune invalida.\n");
        }
    }
}



int main()
{
    p0();
//p1();
//p2();
//p3();

	return 0;
}
