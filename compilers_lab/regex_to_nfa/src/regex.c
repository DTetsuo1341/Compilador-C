#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "regex.h"

#define MAX 100



/* Método que crea la pila */
void crear(Pila *p)
{
    p->tope = -1;
}

int vacia(Pila *p)
{
    return p->tope == -1;
}

void push(Pila *p, char c)
{
    p->op[++p->tope] = c;
}

char pop(Pila *p)
{
    return p->op[p->tope--];
}

char peek(Pila *p)
{
    return p->op[p->tope];
}


int esOperador(char c)
{
    return (c == '*' || c == '+' || c == '?' || c == '.' || c == '|');
}

int esUnario(char c) {
    return c == '*' || c == '+' || c == '?';
}

int requiereConcat(char c1, char c2) {

    int izq =
        isalnum(c1) || c1 == ')' || esUnario(c1);

    int der =
        isalnum(c2) || c2 == '(';

    return izq && der;
}

int precedencia(char c)
{
    switch (c)
    {
    case '*':
        return 3;
    case '+':
        return 3;
    case '?':
        return 3;
    case '.':
        return 2;
    case '|':
        return 1;
    default:
        return 0;
    }
}

void insertarConcat(char *infija, char *salida)
{
    int i,j = 0;
    int longitud = strlen(infija);

    for(i = 0; i < longitud; i++)
    {
        char c1 = infija[i];
        char c2 = infija[i + 1];

        salida[j++] = c1;

        if(c2 == '\0')
            break;
        if (requiereConcat(c1, c2)) {
            salida[j++] = '.';
        }
    }
    salida[j] = '\0';
}


int postfija(char *infija, char *postfija)
{
    Pila p;
    crear(&p);

    int i,j = 0;
    int longitud = strlen(infija);

    for(i = 0; i < longitud; i++)
    {
        char c = infija[i];

        if(!esOperador(c) && c != '(' && c != ')')
            postfija[j++] = c;
        else
        {
            if(c == '('){
                push(&p, c);
            }
            else
            {
                if(c == ')'){
                    while(peek(&p) != '(')
                    {
                        postfija[j++] = pop(&p);
                    }
                    pop(&p);
                }
                else
                {
                    if(c == '.' || c == '*' || c == '?' || c == '+' || c == '|')
                    {
                        while(!vacia(&p) && precedencia(peek(&p)) >= precedencia(c))
                        {
                            postfija[j++] = pop(&p);
                        }
                        push(&p, c);
                    }
                }
            }
        }
            
    }
    

    while(!vacia(&p))
    {
        postfija[j++] = pop(&p);
    }

    postfija[j++] = '\0';
}

