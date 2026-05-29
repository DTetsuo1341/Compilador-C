# Conjetura de Collatz
# Lee un entero n y cuenta los pasos hasta llegar a 1.
# Si n es par  → n = n / 2
# Si n es impar → n = 3*n + 1

fn collatz(int n) {
    int pasos = 0;
    int rem   = 0;
    wh (n != 1) {
        rem = n % 2;
        if (rem == 0) {
            n = n / 2;
        } el {
            n = n * 3 + 1;
        }
        pasos = pasos + 1;
    }
    rt pasos;
}

int num;
rd(num);
int resultado;
resultado = collatz(num);
pr("Pasos hasta llegar a 1:");
pr(resultado);
