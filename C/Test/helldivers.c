#include <stdio.h>

int main(){
    printf("Bienvenido al Gestor de Munición y Armamento Helldiver\n------------------------------------------------------");
    int rifles=10;
    int granadas=20;
    int lanzacohetes=15;
    int entry=0;
    int madd=0;
    int end=0;
    printf("\nInventario Inicial:\n- Rifles: %d\n- Granadas: %d\n- Lanzacohetes: %d\n", rifles, granadas, lanzacohetes);
    while (end!=1){
        printf("\nSelecciona una acción:\n1. Reabastecer munición\n2. Desplegar armamento\n3. Mostrar inventario actual\n4. Finalizar misión\n> ");
        scanf("%d",&entry);
        if (entry==4||entry>4||entry<0){
            end++;
            printf("\nMisión Finalizada\nInventario Final:\n- Rifles: %d\n- Granadas: %d\n- Lanzacohetes: %d\n¡Gracias por asegurar el éxito de la misión, la Super Tierra te lo agradece!\n", rifles, granadas, lanzacohetes);
        }
        else if (entry==1){
            printf("\nSelecciona qué tipo de munición a reabastecer\n1. Rifles\n2. Granadas\n3. Lanzacohetes\n> ");
            scanf("%d",&entry);
            
            if (entry==1){
                printf("Ingresa la cantidad de munición a añadir: ");
                scanf("%d", &madd);
                rifles=rifles+madd;
                printf("\nMunición reabastecida.");
                printf("\nInventario Actual:\n- Rifles: %d\n- Granadas: %d\n- Lanzacohetes: %d\n", rifles, granadas, lanzacohetes);
            }
            else if (entry==2){
                printf("Ingresa la cantidad de munición a añadir: ");
                scanf("%d", &madd);
                granadas=granadas+madd;
                printf("\nMunición reabastecida.");
                printf("\nInventario Actual:\n- Rifles: %d\n- Granadas: %d\n- Lanzacohetes: %d\n", rifles, granadas, lanzacohetes);
            }
            else if (entry==3){
                printf("Ingresa la cantidad de munición a añadir: ");
                scanf("%d", &madd);
                lanzacohetes=lanzacohetes+madd;
                printf("\nMunición reabastecida.\n");
                printf("\nInventario Actual:\n- Rifles: %d\n- Granadas: %d\n- Lanzacohetes: %d\n", rifles, granadas, lanzacohetes);
            }
            else{
                printf("\nInstrucción incorrecta");
            }



        }
        else if (entry==2){
            printf("\nSelecciona el tipo de armamento a desplegar\n1. Rifles\n2. Granadas\n3. Lanzacohetes\n> ");
            scanf("%d", &entry);
            if (entry==1){
                printf("\nIngresa la cantidad de rifles a desplegar: ");
                scanf("%d", &entry);
                if (rifles-entry>=0){
                rifles=rifles-entry;
                printf("\n\nRifles desplegados.\n");
                printf("\nInventario Actual:\n- Rifles: %d\n- Granadas: %d\n- Lanzacohetes: %d\n", rifles, granadas, lanzacohetes);
                }
                else{
                    printf("\nNo hay suficientes rifles");
                }
            }
            else if (entry==2){
                printf("\nIngresa la cantidad de granadas a desplegar: ");
                if (granadas-entry>=0){
                        granadas=granadas-entry;
                    printf("\n\nGranadas desplegadas.\n");
                    printf("\nInventario Actual:\n- Rifles: %d\n- Granadas: %d\n- Lanzacohetes: %d\n", rifles, granadas, lanzacohetes);
                }
                else{
                    printf("\nNo hay suficientes granadas");
                }
            }
            else if (entry==3){
                printf("\nIngresa la cantidad de lanzacohetes a desplegar: ");
                scanf("%d", &entry);
                if (rifles-entry>=0){
                    lanzacohetes=lanzacohetes-entry;
                    printf("\n\nLanzacohetes desplegados.\n");
                    printf("\nInventario Actual:\n- Rifles: %d\n- Granadas: %d\n- Lanzacohetes: %d\n", rifles, granadas, lanzacohetes);
                }
                else{
                    printf("\nNo hay suficientes lanzacohetes");
                }
            }


        }
        else if (entry==3){
            printf("\nInventario Actual:\n- Rifles: %d\n- Granadas: %d\n- Lanzacohetes: %d\n", rifles, granadas, lanzacohetes);
        }
        else{
            printf("Instrucción no válida");
        }

    }

return 0;
}