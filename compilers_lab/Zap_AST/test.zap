# Test completo de Zap
# Cubre: tipos, funciones, if/ei/el, while, for, booleanos, strings, read, print

fn max(int a, int b) {
    if (a > b) {
        rt a;
    } el {
        rt b;
    }
}

fn es_positivo(int n) {
    if (n > 0) {
        rt T;
    } el {
        rt F;
    }
}

fn factorial(int n) {
    if (n <= 1) {
        rt 1;
    } el {
        rt n * factorial(n - 1);
    }
}

fn saluda(str nombre) {
    pr("hola");
    pr(nombre);
}

# Variables primitivas
int x = 42;
flt pi = 3.14;
str msg = "zap funciona";
bl activo = T;

# Operaciones aritmeticas
int suma = x + 10;
int producto = x * 2;
flt area = pi * 5;

# Comparaciones
bl grande = x >= 40;
bl igual = x == 42;

# Llamadas a funcion
int m = max(10, 20);
int fact = factorial(5);
bl pos = es_positivo(x);

# Print
pr(msg);
pr(fact);
pr(activo);

# Read
int entrada = rd(x);

# While
int i = 0;
wh (i < 5) {
    pr(i);
    i = i + 1;
}

# For
int j;
fo (j = 0; j < 3; j = j + 1) {
    int cuadrado = j * j;
    pr(cuadrado);
}

# If / ei / el
int val = 7;
if (val == 10) {
    pr("diez");
} ei (val == 7) {
    pr("siete");
} el {
    pr("otro");
}

# Expresiones anidadas
int complejo = (x + 2) * (factorial(3) - 1);
pr(complejo);