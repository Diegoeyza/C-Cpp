#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LNOMBRE 30

// Funcion que recibe dos punteros a strings (o sea, char **) en la forma
// de punteros generales (void *) y entrega la diferencia entre los largos
// de los strings. La usaremos para ordenar strings de más corto a más
// largo. El que los parámetros sean void * es un requisito para que sean
// compatibles con la función que ordena (qsort) que está escrita así para
// que pueda ordenar cualquier cosa.
int comparaporlargo(const void * e1, const void * e2) {
    // Lo primero es hacer el cast de void * a char **, el resultado es
    // para todos los efectos prácticos un string que se le puede pasar a
    // strlen. Para entender mejor el cast:
    //                    e1 es de tipo void *
    //
    //           (char **)e1 es de tipo char **, corresponde a la dirección de un elemento del arreglo
    //                                           que a su vez es un string (char *)
    //          *(char **)e1 es de tipo char *: el elemento del arreglo (lo apuntado por su dirección);
    //                                          como también es un puntero, lo que copiamos a s1 es la misma
    //                                          dirección, y por lo tanto podemos usar s1 como se usa
    //                                          cualquier string
    char * s1 = *(char **)e1;
    char * s2 = *(char **)e2;

    //retornamos la diferencia de las longitudes, de manera que el valor de
    //retorno será negativo si el primer argumento es menor, positivo si lo
    //es el segundo, y cero si son iguales.
    return strlen(s1)-strlen(s2);
}

int main() {
    // arreglo de cosas pesadas que queremos tener una única vez en la memoria
    // (podrían ser equipos de fútbol leídos desde un archivo)
    char nombres[][LNOMBRE] = {"Ignacio Carrera",
        "Arturo Prat",
        "Bernardo O'Higgins"
    };

    // cantidad de cosas en el arreglo (que también podríamos haber sacado al
    // leer el archivo)
    int cant_nombres = sizeof(nombres)/LNOMBRE;

    // PRIMERA PARTE: solución simple. Uno puede tener arreglos de int que digan los índices
    // de los nombres en el orden que interesa.

    // por ejemplo, si ordenamos por nombre, el orden es Arturo Prat (posición 1
    // en el arreglo original), Bdo. O'Higgins (pos 2) e Ignacio Carrera Pinto (0)
    // pero por apellido el orden es 0,2,1 (Carrera, O'Higgins, Prat) y por largo
    // es 1,0,2
    int pornombre[] = {1,2,0};
    int porapellido[] = {0,2,1};
    int porlargo[] = {1,0,2};

    // para listarlos por un orden concreto, simplemente sacamos los índices
    // del arreglo correspondiente:
    //     nombres[pornombre[0]]=nombres[1]=Arturo Prat
    //     nombres[pornombre[1]]=nombres[2]=Bernardo O'Higgins
    //     nombres[pornombre[2]]=nombres[0]=Ignacio Carrera
    printf("Ordenados por nombre:\n");
    for(int i=0;i<cant_nombres;i++) printf("%s\n", nombres[pornombre[i]]);

    // la misma idea se aplica para los otros órdenes.
    printf("\nOrdenados por apellido:\n");
    for(int i=0;i<cant_nombres;i++) printf("%s\n", nombres[porapellido[i]]);

    printf("\nOrdenados por largo:\n");
    for(int i=0;i<cant_nombres;i++) printf("%s\n", nombres[porlargo[i]]);

    printf("\n================= SEGUNDA PARTE ==============\n");
    // SEGUNDA PARTE: la versión más ninja de esta misma solución, es tener arreglos
    // de punteros ordenados por cada criterio. Esto permite trabajar directamente con
    // el arreglo, sin repetir los elementos en memoria (sólo se repite el puntero)
    
    // En vez de guardar índices enteros en un arreglo, guardamos directamente
    // punteros a los elementos.

    // Para entender cómo hacerlo, vamos de lo más simple a lo más complejo:

    // 1. Hacemos un arreglo de punteros, y lo llenamos con los punteros en el orden
    // que sabemos que tienen que tener, directamente en el código. Obviamente, esto
    // no es muy flexible para cuando queramos agregar más elementos, por ejemplo.
    char * ptr_pornombre[]={nombres[1], nombres[2], nombres[0]};
    
    // 2. Solución intermedia: sacamos el orden de un arreglo de int. Si podemos
    // automatizar la construcción del arreglo de int, podemos automatizar esta parte
    // pero seguimos con el problema de usar índices dentro de índices
    // (nombres[porapellido[i]])
    char * ptr_porapellido[cant_nombres];
    for(int i=0;i<cant_nombres;i++) ptr_porapellido[i]=nombres[porapellido[i]];

    // 3. Solución pro: copiamos el arreglo de punteros original, y hacemos que se ordene según
    // el criterio que queramos.

    //      3.1 se declara el arreglo
    char * ptr_porlargo[cant_nombres];

    //      3.2 se copia el arreglo original: solo se copian los punteros, por lo que
    //      no repetimos los elementos en sí en la memoria
    for(int i=0;i<cant_nombres;i++) ptr_porlargo[i]=nombres[i];

    //      3.3 le pasamos el trabajo de ordenar a qsort, que es una función de la
    //      librería estándar de C. La manera de llamarlo es:
    //
    //      qsort(arreglo, # de elementos, tamaño de los elementos, puntero a función)
    //
    //      La función que se usa para comparar debe recibir dos punteros y retornar
    //      un int, de manera parecida a como lo hace strcmp().
    qsort(ptr_porlargo, cant_nombres, sizeof(char*), comparaporlargo);
    //      qsort pasará por referencia a la función de comparación pares de
    //      elementos del arreglo para decidir el orden. Como estos elementos son
    //      char *, el paso por referencia se hará con char **. 

    // Se imprimen los resultados, para mostrar que las tres formas funcionan.
    printf("Ordenados por nombre:\n");
    for(int i=0;i<cant_nombres;i++) printf("%s\n", ptr_pornombre[i]);

    printf("\nOrdenados por apellido:\n");
    for(int i=0;i<cant_nombres;i++) printf("%s\n", ptr_porapellido[i]);

    printf("\nOrdenados por largo:\n");
    for(int i=0;i<cant_nombres;i++) printf("%s\n", ptr_porlargo[i]);

    // Ejercicio propuesto: escriba la funcion para comparar por nombres y haga que
    // se ordenen con qsort (la solución está comentada más abajo)

    return 0;
}


