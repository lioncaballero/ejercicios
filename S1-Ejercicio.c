#include <stdio.h>

int main() {
    int IDproducto;
    char nombreproducto[50];
    int cantidadenstock;
    float preciounidad;
    float totalganancias = 0;
    int opciones;
    int unidadesparavender;
    int unidadesparaagregar;
    float descuento;
    float preciofinal;

    printf("SISTEMA DE VENTAS\n\n");

    do {
        printf("ID del producto (mayor a 0): ");
        scanf("%d", &IDproducto);
        if (IDproducto <= 0) {
            printf("Error: debe ser mayor a 0\n");
        }
    } while (IDproducto <= 0);

    printf("Nombre del producto: ");
    scanf(" %[^\n]", nombreproducto);

    do {
        printf("Cantidad en stock (mayor a 0): ");
        scanf("%d", &cantidadenstock);
        if (cantidadenstock <= 0) {
            printf("Error: debe ser mayor a 0\n");
        }
    } while (cantidadenstock <= 0);

    do {
        printf("Precio por unidad (mayor a 0): ");
        scanf("%f", &preciounidad);
        if (preciounidad <= 0) {
            printf("Error: debe ser mayor a 0\n");
        }
    } while (preciounidad <= 0);

    int continuar = 1;

    while (continuar == 1) {
        printf("\nMENU\n");
        printf("1. Vender\n");
        printf("2. Agregar stock\n");
        printf("3. Ver producto\n");
        printf("4. Ver ganancias\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opciones);

        switch(opciones) {
            case 1:
                printf("\nUnidades a vender: ");
                scanf("%d", &unidadesparavender);

                if (unidadesparavender <= 0) {
                    printf("Cantidad invalida\n");
                    break;
                }

                if (unidadesparavender > cantidadenstock) {
                    printf("No hay suficiente stock\n");
                    break;
                }

                printf("Descuento (0-100): ");
                scanf("%f", &descuento);

                if (descuento < 0 || descuento > 100) {
                    printf("Descuento invalido\n");
                    break;
                }

                preciofinal = preciounidad * (1 - descuento / 100);

                cantidadenstock = cantidadenstock - unidadesparavender;
                totalganancias = totalganancias + (preciofinal * unidadesparavender);

                printf("Venta realizada\n");
                printf("Stock: %d\n", cantidadenstock);
                break;

            case 2:
                printf("\nUnidades a agregar: ");
                scanf("%d", &unidadesparaagregar);

                if (unidadesparaagregar <= 0) {
                    printf("Cantidad invalida\n");
                    break;
                }

                cantidadenstock = cantidadenstock + unidadesparaagregar;

                printf("Nuevo stock: %d\n", cantidadenstock);
                break;

            case 3:
                printf("\nProducto\n");
                printf("ID: %d\n", IDproducto);
                printf("Nombre: %s\n", nombreproducto);
                printf("Stock: %d\n", cantidadenstock);
                printf("Precio: %.2f\n", preciounidad);
                break;

            case 4:
                printf("\nGanancias: %.2f\n", totalganancias);
                break;

            case 5:
                continuar = 0;
                printf("Fin del programa\n");
                break;

            default:
                printf("Opcion invalida\n");
                break;
        }
    }

    return 0;
}