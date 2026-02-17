#ifndef AFN_H
#define AFN_H

typedef struct Estado {
    int id;
    char simbolo;      // 0 = epsilon
    struct Estado *salida1;
    struct Estado *salida2;
} Estado;

typedef struct {
    Estado *inicio;
    Estado *fin;
} AFN;

/* Funciones */
AFN regexAFN(char *postfija);

int evaluarAFN(AFN a, char *cadena);

#endif
