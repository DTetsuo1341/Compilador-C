#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "regex.h"
#include "afn.h"


#define MAX 500

/**
 * @brief Función principal del programa regex_to_nfa.
 *
 * Este programa permite realizar dos operaciones principales:
 *
 * 1) Conversión de una expresión regular a notación postfija
 *    con concatenación explícita (-r).
 *
 * 2) Validación de cadenas de texto mediante un AFN construido
 *    a partir de una expresión regular (-t).
 *
 * El programa recibe la entrada estándar (stdin), lo que permite
 * su uso mediante pipes en sistemas Unix/Linux y Windows.
 *
 * Uso:
 *   ./regex_to_nfa -r   (convierte regex a postfija)
 *   ./regex_to_nfa -t   (valida cadenas con AFN)
 *
 * @param argc Número de argumentos de línea de comandos.
 * @param argv Arreglo de argumentos de línea de comandos.
 *
 * @return 0 si la ejecución es exitosa, 1 en caso de error.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Uso: %s -r | -t\n", argv[0]);
        return 1;
    }

    char regex[MAX];
    char infija[MAX];
    char post[MAX];
    char cadena[MAX];

    if (strcmp(argv[1], "-r") == 0)
    {
        /* Leer regex desde stdin */
        if (!fgets(regex, MAX, stdin))
            return 1;

        regex[strcspn(regex, "\n")] = 0; // quitar \n

        /* Agregar concatenación */
        insertarConcat(regex, infija);

        /* Convertir a postfija */
        postfija(infija, post);

        /* Imprimir resultado */
        printf("%s\n", post);
    }


    else if (strcmp(argv[1], "-t") == 0)
    {
        /* Leer regex */
        if (!fgets(regex, MAX, stdin))
            return 1;

        regex[strcspn(regex, "\n")] = 0;

        /* Procesar regex */
        insertarConcat(regex, infija);
        postfija(infija, post);

        /* Construir AFN */
        AFN a = regexAFN(post);

        /* Leer cadenas hasta EOF */
        while (fgets(cadena, MAX, stdin))
        {
            cadena[strcspn(cadena, "\n")] = 0;

            if (evaluarAFN(a, cadena))
                printf("1");
            else
                printf("0");
        }

        printf("\n");
    }


    else
    {
        fprintf(stderr, "Opción inválida: %s\n", argv[1]);
        return 1;
    }

    return 0;
}
