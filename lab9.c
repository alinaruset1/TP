#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
    int info;
    struct nod *next;
}nod;

void afisare(nod *lista)
{
    nod *p;
    for(p=lista; p!=NULL; p=p->next)
    {
        printf("%d ",p->info);
    }
    printf("\n");
}

nod *new(int info, nod *next)
{
    nod *nou=NULL;
    if((nou=malloc(1*sizeof(nou)))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    nou->info= info;
    nou->next=next;
    return nou;
}

nod *ainceput(int info, nod *lista)
{
    nod *nou=NULL;
    nou=new(info, lista);
    lista=nou;
    return lista;
}

nod *afinal(int info, nod *lista)
{
    nod *nou=NULL, *aux;
    nou=new(info,NULL);
    if(lista==NULL)
    {
        lista=nou;
    }
    else
    {
        for(aux=lista; aux->next!=NULL; aux=aux->next)
            ;
        aux->next=nou;
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
    for(aux=lista; aux->next->next!=NULL;aux=aux->next);
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
        for(ant=lista, aux=lista->next; aux!=NULL; ant=ant->next, aux=aux->next)
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
nod *init(int *size,FILE *f)
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

void p1()
{
    nod *lista1=NULL, *lista2=NULL;
    FILE *f=NULL;
    if((f=fopen("data.in.txt","r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    int size, data1, data2;
    lista1=init(&size, f);
    lista2=init(&size, f);
    for(int i=0; i<size;i++)
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
    nod *q, *aux, *ant;
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
    for(p=lista; p!=NULL; p=p->next)
    {
        if(p->info==info)
        {
            return 1;
        }

    }
    return 0;
}


void p3()
{
nod *lista1, *lista2, *lista3=NULL;
int size, i, data;
FILE *f=NULL;
if((f=fopen("data.in.txt", "r"))==NULL)
{
    perror(NULL);
    exit(-1);
}
lista1=init(&size, f);
lista2=init(&size, f);
for(int i=0; i<size; i++)
{
    data=lista1->info;
    lista1=sinceput(lista1);
    if(!interior(data, lista1))
    {
        lista3 = afinal(data, lista3);
    }

}
for(int i=0; i<size; i++)
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


void p5()
{
    nod *lista1, *lista2=NULL;
    FILE *f=NULL;
    if((f=fopen("data.in.txt", "r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    int size1,size2, i,data;
    lista1=init(&size1, f);
    lista2=init(&size2, f);
    if(size1>size2)
    {
        for(i=0; i<size1; i++)

        {
            data=lista1->info;
            if(!interior(data,lista2))
            {
                printf("0\n");
                freelist(lista1);
                freelist(lista2);
                return;
            }
        }
    }
    else
    {
        for(int i=0; i<size2; i++)
        {
            data=lista2->info;
            if(!interior(data, lista1))
            {
                printf("0\n");
                free(lista1);
                free(lista2);
                return ;
            }
        }
    }
    printf("1\n");
    free(lista1);
    free(lista2);

}

nod *cresc(int data, nod *lista)
{
    nod *p, *q, *nounod;
    nounod= new(data,NULL);
    if(lista==NULL)
    {
        lista=nounod;
    }
    else
    {
        if(nounod->info<lista->info)
        {
            ainceput(data, lista);
        }
        else
        {
            if(lista->next==NULL)
            {
                afinal(data, lista);
            }
            else
            {
                for(p=lista, q=lista->next; q!=NULL; p=p->next, q=q->next)
                {
                    if(p->info<=data && data<=q->info)
                    {
                        p->next=nounod;
                        nounod->next=q;
                        break;
                    }
                }
            }
        }
    }
    return lista;
}

nod *sortare(nod *lista)
{
    nod *p;
    nod *listasort=NULL;
    for(p=lista ; p!=NULL; p=p->next)
    {
        listasort = cresc(p->info, listasort);
    }
    return listasort;

}

void p6()
{
    FILE *f=NULL;
    if((f=fopen("data.in.txt", "r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    nod *lista;
    int size;
    lista=init(&size,f);
    lista=sortare(lista);
    afisare(lista);
    freelist(lista);

}

void p7()
{
    FILE *f=NULL;
    if((f=fopen("data.in.txt", "r"))==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    nod *lista1, *lista2, *p;
    int size1, size2;
    lista1=init(&size1,f);
    lista2=init(&size2,f);
    for(p=lista1; p!=NULL; p=p->next)
    {
        afinal(p->info, lista2);
    }
    lista2=sortare(lista2);
    afisare(lista2);
    freelist(lista1);
    freelist(lista2);
}
