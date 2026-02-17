#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "regex.h"

#define MAX 100

/**
 * @brief Inicializa una pila vacía.
 *
 * @param p Puntero a la pila a inicializar.
 * 
 * @return void
 */
void crear(Pila *p)
{
    p->tope = -1;
}

/**
 * @brief Verifica si la pila está vacía.
 *
 * @param p Puntero a la pila.
 *
 * @return 1 si la pila está vacía, 0 en caso contrario.
 */
int vacia(Pila *p)
{
    return p->tope == -1;
}

/**
 * @brief Inserta un elemento en la pila.
 *
 * @param p Puntero a la pila.
 * @param c Carácter a insertar.
 */
void push(Pila *p, char c)
{
    p->op[++p->tope] = c;
}

/**
 * @brief Extrae el elemento superior de la pila.
 *
 * @param p Puntero a la pila.
 *
 * @return Carácter almacenado en el tope de la pila.
 */
char pop(Pila *p)
{
    return p->op[p->tope--];
}

/**
 * @brief Obtiene el elemento superior sin eliminarlo.
 *
 * @param p Puntero a la pila.
 *
 * @return Carácter almacenado en el tope de la pila.
 */
char peek(Pila *p)
{
    return p->op[p->tope];
}

/**
 * @brief Determina si un carácter es un operador de regex.
 *
 * @param c Carácter a evaluar.
 *
 * @return 1 si es operador, 0 en caso contrario.
 */
int esOperador(char c)
{
    return (c == '*' || c == '+' || c == '?' || c == '.' || c == '|');
}

/**
 * @brief Determina si un operador es unario.
 *
 * Identifica operadores como *, + y ?, que actúan
 * sobre un solo operando.
 *
 * @param c Operador.
 *
 * @return 1 si es unario, 0 si no lo es.
 */
int esUnario(char c) {
    return c == '*' || c == '+' || c == '?';
}

/**
 * @brief Determina si dos simbolos juntos requiere concatenarse.
 * 
 * Identifica si dos elementos seguidos deben ingresar el simbolo de la concatenación o no.
 * 
 * @param c1 Primer caracter.
 * @param c2 Segundo caracter.
 * 
 * @return 1 si c1 y c2 estan concatenados y 0 en caso contrarió.
 */
int requiereConcat(char c1, char c2) {

    int izq =
        isalnum(c1) || c1 == ')' || esUnario(c1);

    int der =
        isalnum(c2) || c2 == '(';

    return izq && der;
}

/**
 * @brief Obtiene la precedencia de un operador.
 *
 * Define el orden de evaluación de los operadores
 * durante el algoritmo Shunting-Yard.
 *
 * @param c Operador.
 *
 * @return Valor entero que representa su precedencia.
 */
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

/**
 * @brief Inserta operadores de concatenación explícita.
 *
 * Convierte una expresión regular con concatenación implícita
 * en una expresión con el operador '.' explícito.
 *
 * Ejemplo:
 *   abc*  ->  a.b.c*
 *
 * @param infija Expresión regular original.
 * @param salida Expresión con concatenación explícita.
 */
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

/**
 * @brief Convierte una expresión infija a notación postfija.
 *
 * Aplica el algoritmo Shunting-Yard para transformar una
 * expresión regular con concatenación explícita en
 * notación postfija.
 *
 * @param infija Expresión regular en notación infija.
 * @param postfija Arreglo donde se almacena la expresión postfija.
 *
 * @return Longitud de la expresión postfija generada.
 */
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

