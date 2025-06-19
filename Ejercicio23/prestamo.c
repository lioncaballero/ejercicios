#include <stdio.h>
int main() {
    float monto, tasaInteres, montoTotal, pagoMensual;
    int meses;
    printf("Ingrese el monto del prestamo: ");
    scanf("%f", &monto);
     if (monto <= 0) {
        printf("El valor ingresado no puede ser cero o negativo.\n");
        return 1;
    }
    printf("Ingrese el num de meses para el pago: ");
    scanf("%d", &meses);
     if (meses <= 0) {
        printf("El valor ingresado no puede ser cero o negativa.\n");
        return 1;
    }
    if (monto > 10000) {
        tasaInteres = 0.15;
    } else {
        tasaInteres = 0.10;
    }
    montoTotal = monto + (monto * tasaInteres);
    pagoMensual = montoTotal / meses;
    printf("\nResumen del prestamo:\n");
    printf("Monto del prestamo: $%.2f\n", monto);
    printf("Tasa de Interes aplicada: %.0f%%\n", tasaInteres * 100);
    printf("Monto total a pagar: $%.2f\n", montoTotal);
    printf("Pago mensual durante %d meses: $%.2f\n", meses, pagoMensual);
    return 0;
}