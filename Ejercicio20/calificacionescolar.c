#include <stdio.h>
int main (int argc, char *argv[]) {
    float cali;
    printf("Ingresa la calificacion del 0 hasta el 100\n");
    scanf("%f", &cali);
    while (cali>=0 && cali<=100)
    {
        if (cali>=0 && cali<=60)
    {
        printf("Tiene una calificacion F\n");
    } else if (cali<=69)
    {
        printf("Tiene una calificacion D\n");
    } else if (cali<=79)
    {
        printf("Tiene una calificacion C\n");
    } else if (cali<=89)
    {
        printf("Tiene una calificacion B\n");
    } else if (cali<=100)
    {
        printf("Tiene una calificacion A\n");
    }
    printf("Ingresa la calificacion del 0 hasta el 100\n");
    scanf("%f", &cali);
    }
    if (cali<0 || cali>100)
    {
        printf("La calificacion ingresada no es del 0 hasta el 100");
    }
    return 0;
}