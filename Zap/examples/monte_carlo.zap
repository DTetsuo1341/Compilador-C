# Aproximacion de Pi por el Metodo de Monte Carlo
#
# Sin flotantes ni aleatorio nativo, se usa:
#   - Un LCG entero (a=1103, c=12345, m=32768) para generar pseudoaleatorios.
#   - Coordenadas escaladas al rango [0, 1000).
#   - Un punto cae "dentro" si x^2 + y^2 <= 1 000 000 (radio 1000).
#
# Salida: pi * 1000  (ejemplo: 3141 ≈ 3.141)
# Recomendado: ingresar 10000 iteraciones.

int seed = 42;

fn siguiente_rand() {
    seed = (seed * 1103 + 12345) % 32768;
    rt seed;
}

int iters;
rd(iters);

int dentro = 0;
int i      = 0;
int rx     = 0;
int ry     = 0;
int x      = 0;
int y      = 0;
int dist2  = 0;

wh (i < iters) {
    rx    = siguiente_rand();
    ry    = siguiente_rand();
    x     = rx % 1000;
    y     = ry % 1000;
    dist2 = x * x + y * y;
    if (dist2 <= 1000000) {
        dentro = dentro + 1;
    }
    i = i + 1;
}

int pi_aprox = 4000 * dentro / iters;
pr("Pi aproximado (multiplicado por 1000):");
pr(pi_aprox);
