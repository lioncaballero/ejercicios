#include <stdio.h>

int main() {
    float lado1, lado2, lado3;
    printf("Ingresa la longitud del primer lado: ");
    scanf("%f", &lado1);
    if (lado1 <= 0) {
        printf("El valor ingresado no puede ser cero o negativo.\n");
        return 1;
    }
    printf("Ingresa la longitud del segundo lado: ");
    scanf("%f", &lado2);
    if (lado2 <= 0) {
        printf("El valor ingresado no puede ser cero o negativo.\n");
        return 1;
    }
    printf("Ingresa la longitud del tercer lado: ");
    scanf("%f", &lado3);
    if (lado3 <= 0) {
        printf("El valor ingresado no puede ser cero o negativo.\n");
        return 1;
    }
    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
        if (lado1 == lado2 && lado2 == lado3) {
            printf("El triangulo es equilatero.\n");
        } else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            printf("El triangulo es isosceles.\n");
        } else {
            printf("El triangulo es escaleno.\n");
        }
    } else {
        printf("Las longitudes no forman un triangulo valido.\n");
    }
    return 0;
}