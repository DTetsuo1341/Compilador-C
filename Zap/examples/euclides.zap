# Algoritmo de Euclides Extendido
# Calcula gcd(a, b) y los coeficientes de Bezout x, y
# tal que:  a*x + b*y = gcd(a, b)
#
# Como Zap no tiene retorno multiple, los coeficientes
# viajan en variables globales coef_x y coef_y.

int coef_x = 0;
int coef_y = 0;

fn euclides_ext(int a, int b) {
    if (b == 0) {
        coef_x = 1;
        coef_y = 0;
        rt a;
    }
    int rem = a % b;
    int mcd = euclides_ext(b, rem);
    int xp  = coef_x;
    int yp  = coef_y;
    coef_x  = yp;
    coef_y  = xp - ((a - a % b) / b) * yp;
    rt mcd;
}

int a;
int b;
rd(a);
rd(b);
int resultado = euclides_ext(a, b);
pr("MCD:");
pr(resultado);
pr("Coeficiente x (a*x + b*y = mcd):");
pr(coef_x);
pr("Coeficiente y (a*x + b*y = mcd):");
pr(coef_y);
