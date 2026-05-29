# N-esimo Numero Primo
# Lee N y encuentra el N-esimo primo por division de prueba.

fn es_primo(int n) {
    if (n < 2) {
        rt F;
    }
    int i   = 2;
    int rem = 0;
    wh (i * i <= n) {
        rem = n % i;
        if (rem == 0) {
            rt F;
        }
        i = i + 1;
    }
    rt T;
}

int n;
rd(n);
int conteo    = 0;
int candidato = 1;
int primo     = 0;
wh (conteo < n) {
    candidato = candidato + 1;
    primo = es_primo(candidato);
    if (primo == 1) {
        conteo = conteo + 1;
    }
}
pr("El N-esimo primo es:");
pr(candidato);
