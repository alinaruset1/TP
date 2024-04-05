#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
#define SIZE 100
int top=-1;
int stack[MAX_SIZE];
void push(int item)
{
    if(top==MAX_SIZE)
    {
        printf("Stiva e plina\n");
        return;
    }
    stack[++top]=item;
}
int pop()
{
    if(top==-1)
    {
        printf("Stiva e goala\n");
        return -1;
    }
    return stack[top--];
}
void display()
{
    if(top==-1)
    {
        printf("Stiva e goala\n");
        return;
    }
    printf("Elementele din stiva sunt:");
    for(int i=top;i>=0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
void p1()
{
  push(10);
push(20);
push(30);
display();
printf("Elementul extras din stiva : %d\n", pop());
display(); 
}

//PROBLEMA 3.2
int front=-1, rear=-1;
int queue[MAX_SIZE];
void enqueue(int item)
{
    if(rear==MAX_SIZE-1)
    {
        printf("Coada este plina\n");
        return ;
    }
    if(front==-1)
    {
        front=0;
    }
    queue[++rear]=item;
}

int dequeue()
{
    if(front==-1 || front>rear)
    {
        printf("Coada e goala\n");
        return -1;
    }
    return queue[front++];
}
void display_queue()
{
    if(front ==-1 || front>rear)
    {
        printf("Coada e goala\n");
        return ;
    }
    printf("Elementele din coada sunt:");
    for(int i=front; i<=rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
void p2()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display_queue();
    printf("Elementul extras din coada : %d\n", dequeue());
    display_queue();
}

//PROBLEMA 3.3
char stiva[SIZE][100];
int row=-1;

void push_string(char *new)
{
    if(row==SIZE-1)
    {
        printf("Stiva e plina\n");
        return ;
    }
    strcpy(stiva[++row], new);
}

char *pop_String(void)
{
    if(row==-1)
    {
        printf("Stiva e goala\n");
        return NULL;
    }
    return stiva[row--];
}
void p3(void)
{
    char text[SIZE], *buffer;
    int optiune, citiri = 0;
    do
    {
        printf("1 - Citeste text nou\n");
        printf("2 - Salveaza text\n");
        printf("3 - Undo text\n");
        printf("4 - Afiseaza textul actual\n");
        printf("0 - Exit\n");
        printf("Introdu optiunea: ");
        scanf("%d", &optiune);

        switch (optiune)
        {
        case 1:
        {
            getchar();
            if (fgets(text, 100, stdin) == NULL)
            {
                printf("Eroare la citire.\n");
            }
            else
            {
                citiri++;
            }
            break;
        }
        case 2:
        {
            if (citiri == 0)
            {
                printf("Citeste mai intai un text.\n");
                break;
            }
            else
            {
                pushString(text);
            }
            break;
        }
        case 3:
        {
            buffer = popString();
            if (buffer != NULL)
            {
                strcpy(text, buffer);
            }
            break;
        }
        case 4:
        {
            printf("%s", text);
        }
        case 0:
        {
            break;
        }
        default:
        {
            printf("Ai introdus o operatie invalida.\n");
        }
        }
    } while (optiune != 0);
}

char coada[SIZE][256];
int fata = -1, spate = -1;

void enqueueM(char *mesaj)
{
    if (spate == SIZE - 1)
    {
        printf("Coada este plina\n");
        return;
    }
    if (fata == -1)
    {
        fata = 0;
    }
    strcpy(coada[++spate], mesaj);
}

char *dequeueM(void)
{
    if (fata == -1 || fata > spate)
    {
        printf("Coada este goala\n");
        return NULL;
    }
    return coada[fata++];
}

void p4(void)
{
    char mesaj[256], *vector;
    int optiune, citiri = 0;
    do
    {
        printf("1 - Citeste mesaj nou\n");
        printf("2 - Salveaza mesaj\n");
        printf("3 - Recupereaza mesaj\n");
        printf("4 - Afiseaza mesaj actual\n");
        printf("0 - Exit\n");
        printf("Introdu optiunea: ");
        scanf("%d", &optiune);

        switch (optiune)
        {
        case 1:
        {
            getchar();
            if (fgets(mesaj, 256, stdin) == NULL)
            {
                printf("Eroare la citire.\n");
            }
            else
            {
                citiri++;
            }
            break;
        }
        case 2:
        {
            if (citiri == 0)
            {
                printf("Citeste mai intai un mesaj.\n");
                break;
            }
            else
            {
                enqueueM(mesaj);
            }
            break;
        }
        case 3:
        {
            vector = dequeueM();
            if (vector != NULL)
            {
                strcpy(mesaj, vector);
            }
            break;
        }
        case 4:
        {
            printf("%s", mesaj);
        }
        case 0:
        {
            break;
        }
        default:
        {
            printf("Ai introdus o operatie invalida.\n");
        }
        }
    } while (optiune != 0);
}

int main(void)
{
    //p1();
    //p2();
    //p4();
    return 0;
}