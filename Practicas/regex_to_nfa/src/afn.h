#ifndef AFN_H
#define AFN_H

/**
 * @brief Representa un estado de un Autómata Finito No Determinista (AFN).
 *
 * Cada estado puede contener una transición etiquetada con un símbolo
 * o una transición epsilon (representada con el valor 0).
 *
 * Un estado puede tener hasta dos transiciones de salida, de acuerdo
 * con el método de construcción de Thompson.
 */
typedef struct Estado {
    int id;
    char simbolo;      // 0 = epsilon
    struct Estado *salida1;
    struct Estado *salida2;
} Estado;

/**
 * @brief Representa un Autómata Finito No Determinista (AFN).
 *
 * Un AFN está compuesto por un estado inicial y un estado final,
 * entre los cuales se encuentran las transiciones que representan
 * una expresión regular.
 *
 * Esta estructura es utilizada como unidad básica durante la
 * construcción y simulación del autómata.
 */
typedef struct {
    Estado *inicio;
    Estado *fin;
} AFN;

/* Funciones */

/**
 * Convierte de una expresión regular postfija a un AFN.
 * 
 * @param postfija Expresión regular postfija
 */
AFN regexAFN(char *postfija);

/**
 * Evalúa una cadena en un AFN.
 *
 * @param a AFN
 * @param cadena Cadena
 * @return 1 si acepta, 0 si no
 */
int evaluarAFN(AFN a, char *cadena);

#endif
