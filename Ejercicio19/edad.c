#include <stdio.h>
int main() {
    float edad;
    printf("Ingresa tu edad: ");
    scanf("%f", &edad);
    if (edad < 0) {
        printf("La edad ingresada es incorrecta\n");
        return 1;
    }
    if (edad <= 12) {
        printf("Es niño\n");
    } else if (edad <= 17) {
        printf("Es adolescente\n");
    } else if (edad <= 64) {
        printf("Es adulto\n");
    } else {
        printf("Es adulto mayor\n");
    }
    if (edad < 65) {
        printf("Para ser adulto mayor te faltan %.0f años\n", 65 - edad);
    }
    return 0;
}