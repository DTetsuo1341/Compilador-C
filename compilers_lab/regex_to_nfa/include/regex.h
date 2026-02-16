#ifndef REGEX_H
#define REGEX_H

/* ============================= */
/* PILA PARA SHUNTING-YARD */
/* ============================= */

typedef struct {
    char data[1024];
    int top;
} Pila;


/* ============================= */
/* MANEJO DE PILA */
/* ============================= */

void crear(Pila *p);
int vacia(Pila *p);
void push(Pila *p, char c);
char pop(Pila *p);
char peek(Pila *p);


/* ============================= */
/* UTILIDADES */
/* ============================= */

int esOperador(char c);
int precedencia(char c);
int esUnario(char c);


/* ============================= */
/* PARSER REGEX */
/* ============================= */

/* Inserta '.' donde hay concatenacion implicita */
void insertarConcat(char *infija, char *salida);

/* Convierte infija (con .) a postfija */
int postfija(char *infija, char *postfija);


#endif
