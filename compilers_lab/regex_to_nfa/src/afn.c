#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "afn.h"

#define MAX 100
#define MAX_ESTADOS 500


/**
 * @brief Pila para almacenar autómatas durante la construcción del AFN.
 *
 * Esta estructura se utiliza durante el algoritmo de Thompson para
 * almacenar temporalmente los autómatas parciales generados a partir
 * de la expresión regular en notación postfija.
 *
 * Cada elemento de la pila representa un AFN intermedio que posteriormente
 * puede ser combinado mediante operadores como concatenación, unión,
 * cerradura de Kleene, etc.
 */
typedef struct pilaAFN
{
    AFN aut[MAX];
    int top;    
}pilaAFN;


/*Contador con el que iniciamos a conocer la cantidad de autómatas*/
int contador = 0;


/**
 * @brief Crea un nuevo estado del AFN.
 *
 * Reserva memoria dinámicamente para un nuevo estado y le asigna
 * un identificador único, un símbolo de transición y salidas inicializadas
 * en NULL.
 *
 * El valor del símbolo 0 representa una transición epsilon.
 *
 * @param c Símbolo asociado al estado. Use 0 para epsilon.
 *
 * @return Puntero al estado creado.
 */
Estado* creaionEdo(char c)
{
    Estado *e = malloc(sizeof(Estado));

    e->id = contador++;
    e->simbolo = c;
    e->salida1 = NULL;
    e->salida2 = NULL;

    return e;

}

/**
 * @brief Crea un AFN básico para un símbolo.
 *
 * Construye un autómata finito no determinista elemental que reconoce
 * un único símbolo, siguiendo el método de Thompson.
 *
 * El autómata generado tiene un estado inicial con una transición
 * etiquetada con el símbolo y un estado final con transición epsilon.
 *
 * @param c Símbolo que reconocerá el autómata.
 *
 * @return AFN que acepta el símbolo especificado.
 */
AFN simbolo(char c)
{
    Estado *i = creaionEdo(c);
    Estado *f = creaionEdo(0);

    i->salida1 = f;

    AFN a = {i, f};

    return a;
}

/**
 * @brief Crea un AFN a partir de una expresión postfija.
 * 
 * Lee el cada simbolo perteneciente a la expresión postfija, utilizando el
 * algoritmo de Thompson para crear un AFN guardandolo en la pila si llega a ser utilizado despues.
 * 
 * @param postfija Cadena que contieene la expresión regular en notación postfija.
 * 
 * @return Un AFN.
 */
AFN regexAFN(char *postfija)
{
    pilaAFN pila;
    pila.top = -1;

    for(int i = 0; postfija[i]; i++){
        char c = postfija[i];

        //Caso simbolo
        if(isalnum(c))
        {
            AFN a = simbolo(c);
            pila.aut[++pila.top] = a;
        }
        //Concatenación
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
        //Operador OR
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
        //Cerradura Kleene
        else if(c == '*')
        {
            AFN a = pila.aut[pila.top--];

            //Creamos estado inicial y final
            Estado *i = creaionEdo(0);
            Estado *f = creaionEdo(0);

            //El nuevo estado inicial apunta al final y al inicio del autómata anterior
            i->salida1 = a.inicio;
            i->salida2 = f;

            //El automata se apunta al inicio de si mismo y al estado final
            a.fin->salida1 = a.inicio;
            a.fin->salida2 = f;

            //Creamos el nuevo automata
            AFN r = {i, f};
            
            //Lo añadimos a la pila
            pila.aut[++pila.top] = r;

        }
        //Cerradura positiva
        else if(c == '+')
        {
            //Lo mismo que la cerradura Klenne pero que el nuevo estado inicial no apunta al final
            AFN a = pila.aut[pila.top--];

            Estado *i = creaionEdo(0);
            Estado *f = creaionEdo(0);

            i->salida1 = a.inicio;

            a.fin->salida1 = a.inicio;
            a.fin->salida2 = f;

            AFN r = {i, f};

            pila.aut[++pila.top] = r;
        }
        //Cero o una ocurrencia
        else if(c == '?'){
            //Lo mismo que el operador OR pero solo un automata y la otra opción el 
            //nuevo estado inicial apunta al nuevo estado final con transición epsilon
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

/**
 * @brief Imprime un resumen de los estados del autómata.
 * 
 * Realiza un recorrido por cada transición no nula a un estado del autómata.
 * 
 * @param a AFN a imprimir.
 * 
 * @return void.
 */
void imprimirAFN(AFN a)
{
    Estado *cola[MAX];
    int frente = 0, fin = 0;

    int visitado[MAX] = {0};

    printf("\n===== AFN =====\n");
    printf("Estado inicial: %d\n", a.inicio->id);
    printf("Estado final  : %d\n\n", a.fin->id);

    //Mete en la cola al estado inicial
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

/**
 * @brief Calcula la cerradura epsilon de un estado.
 *
 * Obtiene todos los estados alcanzables desde un estado inicial
 * utilizando únicamente transiciones epsilon (sin consumir símbolos).
 *
 * Esta función recorre recursivamente el autómata para incluir todos
 * los estados accesibles por transiciones ε.
 *
 * Es utilizada durante la simulación del AFN antes y después de
 * aplicar la función mover.
 *
 * @param e Estado inicial desde el cual se calcula la cerradura.
 * @param conjunto Arreglo donde se almacenan los estados alcanzados.
 * @param n Puntero al número actual de estados en el conjunto.
 * @param visitado Arreglo que marca los estados ya visitados.
 *
 * @return void
 */
void epsilonCierre(Estado *e, Estado **conjunto, int *n, int *visitado)
{
    
    if (!e)
        return;

    if (visitado[e->id])
        return;

    //Marca al estado como visitado
    visitado[e->id] = 1;

    //Lo añade al conjunto que forma parte de la cerradura
    conjunto[(*n)++] = e;

    if (e->simbolo == 0) // epsilon
    {
        epsilonCierre(e->salida1, conjunto, n, visitado);
        epsilonCierre(e->salida2, conjunto, n, visitado);
    }
}


/**
 * @brief Calcula el conjunto de estados alcanzables al consumir un símbolo.
 *
 * Dado un conjunto de estados actuales, esta función obtiene todos los
 * estados destino a los que se puede llegar mediante una transición
 * etiquetada con el símbolo especificado.
 *
 * No considera transiciones epsilon. La cerradura-ε debe aplicarse
 * posteriormente al resultado.
 *
 * @param actuales Arreglo con los estados actuales del AFN
 * @param n Número de estados en el arreglo actual
 * @param simbolo Símbolo de entrada a consumir
 * @param resultado Arreglo donde se almacenan los estados alcanzables.
 * @param m Puntero donde se guarda la cantidad de estados resultantes.
 *
 * @return void
 */
void mover(Estado **actuales, int n, char simbolo, Estado **resultado, int *m)
{
    *m = 0;

    for (int i = 0; i < n; i++)
    {
        Estado *e = actuales[i];

        //Junta los estados que se pueden llegar con el simbolo y el conjunto actual
        if (e->simbolo == simbolo && e->salida1)
        {
            resultado[(*m)++] = e->salida1;
        }
    }
}

/**
 * @brief Evalúa si la cadena es aceptada por el AFN.
 * Simula el autómata finito no determinista utilizando
 * cerradura-ε y la función mover.
 *
 * @param a AFN construido con Thompson
 * @param cadena Cadena a evaluar
 *
 * @return 1 si es aceptada, 0 en otro caso
 */
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