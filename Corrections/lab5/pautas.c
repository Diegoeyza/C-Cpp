#include <stdio.h>

typedef struct Operacion{
    int a, b, c;
    int resultado;
}op;

void suma(op*o) {
    int resultado = o->a + (o->b + o->c);
    printf("El resultado de la suma es: %d\n", resultado);
}

void resta(op*o) {
    o ->resultado = o->a - (o->b + o->c);
    printf("El resultado de la resta es: %d\n", o->resultado);
}

int main(){

op op1;

printf("Ingrese tres numeros: ");
scanf("%d %d %d", &op1.a, &op1.b, &op1.c);

suma(&op1);
resta(&op1);
return 0;
}






//-----------------------------------------------------------

#include <stdio.h>

int sumar(int x, int y) {
    return (x + y);
}

int restar(int x, int y) {
    return (x - y);
}

typedef int (*OperacionFn)(int, int); // Function pointer type

typedef struct {
    char operacion;
    OperacionFn funcion;
} MenuItem;

int main() {
    int op1;
    int op2;
    int opcion;

    MenuItem ff[] = {{'+', sumar}, {'-', restar}};

    printf("Ingrese dos numeros: \n");
    scanf("%d %d", &op1, &op2);

    printf("Seleccione una operacion: \n"
           "  1. Suma\n"
           "  2. Resta\n"
           "Opcion: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Resultado: %d\n", ff[0].funcion(op1, op2));
            break;
        case 2:
            printf("Resultado: %d\n", ff[1].funcion(op1, op2));
            break;
        default:
            printf("Opcion no valida.\n"); 
            break;
    }

    return 0;
}