# Test incorrecto de Zap
# Contiene errores semanticos intencionales para probar el SemanticAnalyzer

int a = 10;
int a = 20; # ERROR 1: Redeclaracion

fantasma = 5; # ERROR 2: Asignacion a variable no declarada

str texto = "hola";
int numero = texto; # ERROR 3: Asignacion de tipos incompatibles (str a int)

flt calculo = texto * 3.14; # ERROR 4: Operacion aritmetica invalida (str * flt)

if (texto) { # ERROR 5: Condicion de IF no es booleana
    pr("esto no deberia compilar");
}

fn prueba() {
    bl bandera = T;
    bandera = 100; # ERROR 6: Asignacion de tipos incompatibles (int a bl)
}