# Rutina de Kaprekar (numeros de 4 digitos)
# Constante de Kaprekar: 6174
#
# Proceso por paso:
#   1. Extraer los 4 digitos.
#   2. Ordenar ascendente y descendente.
#   3. Restar menor del mayor.
#   4. Repetir hasta llegar a 6174.

fn kaprekar_paso(int n) {
    # Extraccion de digitos con division exacta (sin residuo)
    int d4 = n % 10;
    int d3 = (n % 100  - d4)       / 10;
    int d2 = (n % 1000 - n % 100)  / 100;
    int d1 = (n        - n % 1000) / 1000;
    int tmp = 0;

    # Burbuja de 4 elementos — ordena d1 <= d2 <= d3 <= d4
    if (d1 > d2) { tmp = d1; d1 = d2; d2 = tmp; }
    if (d2 > d3) { tmp = d2; d2 = d3; d3 = tmp; }
    if (d3 > d4) { tmp = d3; d3 = d4; d4 = tmp; }
    if (d1 > d2) { tmp = d1; d1 = d2; d2 = tmp; }
    if (d2 > d3) { tmp = d2; d2 = d3; d3 = tmp; }
    if (d1 > d2) { tmp = d1; d1 = d2; d2 = tmp; }

    int asc  = d1 * 1000 + d2 * 100 + d3 * 10 + d4;
    int desc = d4 * 1000 + d3 * 100 + d2 * 10 + d1;

    rt desc - asc;
}

int num;
rd(num);
int pasos = 0;
wh (num != 6174) {
    num   = kaprekar_paso(num);
    pasos = pasos + 1;
    pr(num);
}
pr("Constante de Kaprekar alcanzada en pasos:");
pr(pasos);
