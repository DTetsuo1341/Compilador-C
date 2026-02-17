#ifndef REGEX_H
#define REGEX_H

/**
 * @brief Estructura de pila para el algoritmo Shunting-Yard.
 *
 * Esta pila se utiliza para almacenar operadores durante
 * la conversión de una expresión regular en notación infija
 * a notación postfija.
 */
typedef struct {
    char op[1024];
    int tope;
} Pila;


/**
 * @brief Inicializa una pila vacía.
 *
 * @param p Puntero a la pila a inicializar.
 */
void crear(Pila *p);


/**
 * @brief Verifica si la pila está vacía.
 *
 * @param p Puntero a la pila.
 *
 * @return 1 si la pila está vacía, 0 en caso contrario.
 */
int vacia(Pila *p);

/**
 * @brief Inserta un elemento en la pila.
 *
 * @param p Puntero a la pila.
 * @param c Carácter a insertar.
 */
void push(Pila *p, char c);

/**
 * @brief Extrae el elemento superior de la pila.
 *
 * @param p Puntero a la pila.
 *
 * @return Carácter almacenado en el tope de la pila.
 */
char pop(Pila *p);

/**
 * @brief Obtiene el elemento superior sin eliminarlo.
 *
 * @param p Puntero a la pila.
 *
 * @return Carácter almacenado en el tope de la pila.
 */
char peek(Pila *p);


/**
 * @brief Determina si un carácter es un operador de regex.
 *
 * @param c Carácter a evaluar.
 *
 * @return 1 si es operador, 0 en caso contrario.
 */
int esOperador(char c);

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
int precedencia(char c);


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
int esUnario(char c);


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
void insertarConcat(char *infija, char *salida);

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
int postfija(char *infija, char *postfija);


#endif
