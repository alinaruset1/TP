#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
    int info;
    struct nod *next;
} nod;

void afisare(nod *lista)
{
    nod *p;
    for (p = lista; p != NULL; p = p->next)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}

nod *new(int info, nod *next)
{
    nod *nou = NULL;
    if ((nou = malloc(1 * sizeof(nou))) == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    nou->info = info;
    nou->next = next;
    return nou;
}

nod *ainceput(int info, nod *lista)
{
    nod *nou = NULL;
    nou = new (info, lista);
    lista = nou;
    return lista;
}

nod *afinal(int info, nod *lista)
{
    nod *nou = NULL, *aux;
    nou = new (info, NULL);
    if (lista == NULL)
    {
        lista = nou;
    }
    else
    {
        for (aux = lista; aux->next != NULL; aux = aux->next)
            ;
        aux->next = nou;
    }
    return lista;
}

nod *sinceput(nod *lista)
{
    if(lista==NULL)
    {
        return lista;
    }
    nod *aux;
    aux=lista;
    lista=lista->next;
    free(aux);
    return lista;
}

nod *sfinal(nod *lista)
{
    if(lista==NULL)
    {
        return lista;
    }
    if(lista->next==NULL)
    {
        free(lista);
        return NULL;
    }
    nod *aux, *final;
    for(aux=lista; aux->next->next!=NULL; aux=aux->next);
    final=aux->next;
    aux->next=NULL;
    free(final);
    return lista;

}

nod *sterge(int info, nod *lista)
{
    nod *aux, *ant;
    if(lista==NULL)
    {
        return lista;
    }
    if(lista->info==info)
    {
        aux=lista;
        lista=lista->next;
        free(aux);
    }
    else
    {
        for(ant=lista, aux=lista->next; aux!=NULL; ant=ant->next,aux=aux->next)
        {
            if(aux->info==info)
            {
                ant->next=aux->next;
                free(aux);
                break;
            }
        }
    }
    return lista;
}

void freelist(nod *lista)
{
    nod *aux;
    while(lista !=NULL)
    {
        aux=lista->next;
        free(lista);
        lista=aux;
    }

}

nod *init(int *size, FILE *f)
{

    nod *lista=NULL;
    int lungime, info;
    fscanf(f, "%d", &lungime);
    *size=lungime;
    for(int i=0; i<lungime; i++)
    {
        fscanf(f, "%d", &info);
        lista=afinal(info, lista);
    }
    return lista;

}

int minim(int size1, int size2)
{
 
    if(size1>size2)
    {
        return size2;
    }
    else
    return size1;
}

void p1()
{
    nod *lista1=NULL, *lista2=NULL;
    FILE *f=NULL;
    if((f=fopen("data.in.txt","r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    int size1, size2, i, data1, data2;
    lista1=init(&size1,f);
    lista2=init(&size2,f);
    int m=minim(size1, size2);
    for(i=0; i<m; i++)
    {
        data1=lista1->info;
        data2=lista2->info;
        if(data1!=data2)
        {
            printf("0\n");
            free(lista1);
            free(lista2);
            return;
        }
        lista1=sinceput(lista1);
        lista2=sinceput(lista2);

    }
    printf("1\n");
    free(lista1);
    free(lista2);
    if(fclose(f)!=0)
    {
        perror(NULL);
        exit(-1);
    }
}

void p2()
{
    nod *lista=NULL;
    int size;
    FILE *f=NULL;
    if((f=fopen("data.in.txt","r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    lista=init(&size,f);
    if(lista==NULL)
    {
        return ;
    }
    nod *ant, *q, *aux;
    for(aux=lista, q=lista->next; q!=NULL; ant=q, q=aux)
    {
        aux=q->next;
        q->next=ant;
    }
    q->next=ant;
    lista->next=NULL;
    lista=q;
    afisare(lista);
    freelist(lista);
    if(fclose(f)!=0)
    {
        perror(NULL);
        exit(-1);
    }
}

int interior(int info, nod *lista)
{
    nod *p;
    for (p = lista; p != NULL; p = p->next)
    {
        if (p->info == info)
        {
            return 1;
        }
    }
    return 0;
}

void p3(void)
{
    nod *lista1, *lista2, *lista3 = NULL;
    int size1, size2, i, data;
    FILE *f=NULL;
    if((f=fopen("data.in.txt","r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    lista1 = init(&size1,f);
    lista2 = init(&size2,f);
    for (i = 0; i < size1; i++)
    {
        data = lista1->info;
        lista1 = sinceput(lista1);
        if (!interior(data, lista1))
        {
            lista3 = afinal(data, lista3);
        }
    }
    for (i = 0; i < size2; i++)
    {
        data = lista2->info;
        lista2 = sinceput(lista2);
        if (!interior(data, lista3))
        {
            lista3 = afinal(data, lista3);
        }
    }
    afisare(lista3);
    freelist(lista1);
    freelist(lista2);
    freelist(lista3);
}

void p5(void)
{
    nod *lista1, *lista2;
    FILE *f=NULL;
    if((f=fopen("data.in.txt","r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    int size1, size2, i, data;
    lista1 = init(&size1,f);
    lista2 = init(&size2,f);
    if (size1 > size2)
    {
        for (i = 0; i < size1; i++)
        {
            data = lista1->info;
            if (!interior(data, lista2))
            {
                printf("0\n");
                freelist(lista1);
                freelist(lista2);
                return;
            }
            lista1 = lista1->next;
        }
    }
    else
    {
        for (i = 0; i < size2; i++)
        {
            data = lista2->info;
            if (!interior(data, lista1))
            {
                printf("0\n");
                freelist(lista1);
                freelist(lista2);
                return;
            }
            lista2 = lista2->next;
        }
    }
    printf("1\n");
    freelist(lista1);
    freelist(lista2);
}





int main()
{
    //p1();
    //p2();
    //p3();
    //p5();
    return 0;
}