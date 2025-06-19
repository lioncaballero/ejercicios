#include <stdio.h>

int main (int argc, char *argv[]) {
    float edad1, edad2, edad3;
    printf("Ingresa la edad de la primera persona\n");
    scanf("%f", &edad1);
    if (edad1 < 0) {
        printf("La edad no puede ser negativa.\n");
        return 1;
    }
    printf("Ingresa la edad de la segunda persona\n");
    scanf("%f", &edad2);
    if (edad2 < 0) {
        printf("La edad no puede ser negativa.\n");
        return 1;
    }
    printf("Ingresa la edad de la tercera persona\n");
    scanf("%f", &edad3);
    if (edad3 < 0) {
        printf("La edad no puede ser negativa.\n");
        return 1;
    }
    if (edad1 > edad2 && edad1 > edad3) {
        printf("La primera persona es mayor a los demás\n");
    }
    else if (edad2 > edad1 && edad2 > edad3) {
        printf("La segunda persona es mayor a los demás\n");
    }
    else if (edad3 > edad1 && edad3 > edad2) {
        printf("La tercera persona es mayor a los demás\n");
    }
    else {
        printf("Todos son igual de viejos o hay un empate\n");
    }
    return 0;
}