#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "afn.h"

#define MAX 100
#define MAX_ESTADOS 500


/*Guardamos los autómatas creados en una pila*/
typedef struct pilaAFN
{
    AFN aut[MAX];
    int top;    
}pilaAFN;


/*Contador con el que iniciamos a conocer la cantidad de autómatas*/
int contador = 0;

Estado* creaionEdo(char c)
{
    Estado *e = malloc(sizeof(Estado));

    e->id = contador++;
    e->simbolo = c;
    e->salida1 = NULL;
    e->salida2 = NULL;

    return e;

}

/*Creacion de automata que solo lee un simbolo*/
AFN simbolo(char c)
{
    Estado *i = creaionEdo(c);
    Estado *f = creaionEdo(0);

    i->salida1 = f;

    AFN a = {i, f};

    return a;
}

AFN regexAFN(char *postfija)
{
    pilaAFN pila;
    pila.top = -1;

    for(int i = 0; postfija[i]; i++){
        char c = postfija[i];

        /*Caso simbolo*/
        if(isalnum(c))
        {
            AFN a = simbolo(c);
            pila.aut[++pila.top] = a;
        }
        /*Concatenación*/
        else if(c == '.')
        {
            //Último automata añadido a la pila
            AFN a = pila.aut[pila.top--];
            //Autómata anterior al último añadido a la pila
            AFN b = pila.aut[pila.top--];

            b.fin->simbolo = 0;
            b.fin->salida1 = a.inicio;

            AFN r = {b.inicio, a.fin};
            pila.aut[++pila.top] = r;

        }
        else if (c == '|')
        {
            AFN b = pila.aut[pila.top--];
            AFN a = pila.aut[pila.top--];

            //El 0 representa la transición epsilon
            Estado *i = creaionEdo(0);
            Estado *f= creaionEdo(0);

            //Apunta a los dos atutomatas posibles
            i->salida1 = a.inicio;
            i->salida2 = b.inicio;

            //Los estados finales de los anteriores automatas apiuntan al nuevo edd. final
            a.fin->salida1 = f;
            b.fin->salida1 = f;

            AFN r = {i, f};

            //Añadimos el automata a la pila
            pila.aut[++pila.top] = r;
            
        }

        else if(c == '*')
        {
            AFN a = pila.aut[pila.top--];

            //Creamos estado inicial y final
            Estado *i = creaionEdo(0);
            Estado *f = creaionEdo(0);

            i->salida1 = a.inicio;
            i->salida2 = f;

            a.fin->salida1 = a.inicio;
            a.fin->salida2 = f;

            //Creamos el nuevo automata
            AFN r = {i, f};
            
            //Lo añadimos a la pila
            pila.aut[++pila.top] = r;

        }

        else if(c == '+')
        {
            AFN a = pila.aut[pila.top--];

            Estado *i = creaionEdo(0);
            Estado *f = creaionEdo(0);

            i->salida1 = a.inicio;

            a.fin->salida1 = a.inicio;
            a.fin->salida2 = f;

            AFN r = {i, f};

            pila.aut[++pila.top] = r;
        }

        else if(c == '?'){

            AFN a = pila.aut[pila.top--];

            Estado *i = creaionEdo(0);
            Estado *f = creaionEdo(0);

            i->salida1 = a.inicio;
            i->salida2 = f;

            a.fin->salida1 = f;

            AFN r = {i, f};

            pila.aut[++pila.top] = r;
        }
        
    }

    return pila.aut[pila.top];
}

void imprimirAFN(AFN a)
{
    Estado *cola[MAX];
    int frente = 0, fin = 0;

    int visitado[MAX] = {0};

    printf("\n===== AFN =====\n");
    printf("Estado inicial: %d\n", a.inicio->id);
    printf("Estado final  : %d\n\n", a.fin->id);

    // Encolar estado inicial
    cola[fin++] = a.inicio;
    visitado[a.inicio->id] = 1;

    while (frente < fin)
    {
        Estado *e = cola[frente++];

        printf("Estado %d ", e->id);

        // Mostrar si es final
        if (e == a.fin)
            printf("(FINAL)");

        printf("\n");

        // Mostrar símbolo
        if (e->simbolo == 0)
            printf("  Simbolo : ε\n");
        else
            printf("  Simbolo : %c\n", e->simbolo);

        // Salida 1
        if (e->salida1)
        {
            printf("  salida1 -> %d\n", e->salida1->id);

            if (!visitado[e->salida1->id])
            {
                cola[fin++] = e->salida1;
                visitado[e->salida1->id] = 1;
            }
        }
        else
        {
            printf("  salida1 -> NULL\n");
        }

        // Salida 2
        if (e->salida2)
        {
            printf("  salida2 -> %d\n", e->salida2->id);

            if (!visitado[e->salida2->id])
            {
                cola[fin++] = e->salida2;
                visitado[e->salida2->id] = 1;
            }
        }
        else
        {
            printf("  salida2 -> NULL\n");
        }

        printf("\n");
    }

    printf("===== FIN AFN =====\n");
}

void epsilonCierre(Estado *e, Estado **conjunto, int *n, int *visitado)
{
    if (!e) return;

    if (visitado[e->id])
        return;

    visitado[e->id] = 1;

    conjunto[(*n)++] = e;

    if (e->simbolo == 0) // epsilon
    {
        epsilonCierre(e->salida1, conjunto, n, visitado);
        epsilonCierre(e->salida2, conjunto, n, visitado);
    }
}


void mover(Estado **actuales, int n,
           char simbolo,
           Estado **resultado, int *m)
{
    *m = 0;

    for (int i = 0; i < n; i++)
    {
        Estado *e = actuales[i];

        if (e->simbolo == simbolo && e->salida1)
        {
            resultado[(*m)++] = e->salida1;
        }
    }
}

int evaluarAFN(AFN a, char *cadena)
{
    Estado *actuales[MAX_ESTADOS];
    Estado *siguientes[MAX_ESTADOS];

    int nActual = 0;
    int nSig = 0;

    int visitado[MAX_ESTADOS];

    /* Cierre inicial */
    for (int i = 0; i < MAX_ESTADOS; i++)
        visitado[i] = 0;

    epsilonCierre(a.inicio, actuales, &nActual, visitado);

    /* Procesar cadena */
    for (int i = 0; cadena[i]; i++)
    {
        char c = cadena[i];

        /* Mover con símbolo */
        mover(actuales, nActual, c, siguientes, &nSig);

        /* Nuevo cierre */
        nActual = 0;

        for (int j = 0; j < MAX_ESTADOS; j++)
            visitado[j] = 0;

        for (int j = 0; j < nSig; j++)
        {
            epsilonCierre(siguientes[j], actuales, &nActual, visitado);
        }

        if (nActual == 0)
            return 0; // muerto
    }

    /* Ver si llegamos al final */
    for (int i = 0; i < nActual; i++)
    {
        if (actuales[i] == a.fin)
            return 1;
    }

    return 0;
}