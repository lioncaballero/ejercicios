#include <stdio.h>

#define NUM_ESTUDIANTES 5
#define NUM_ASIGNATURAS 3
#define NOTA_APROBATORIA 6.0f

const char *nombreEstudiante[NUM_ESTUDIANTES] = {
    "Estudiante 1", "Estudiante 2", "Estudiante 3",
    "Estudiante 4", "Estudiante 5"
};

const char *nombreAsignatura[NUM_ASIGNATURAS] = {
    "Matematicas", "Ciencias", "Historia"
};

void ingresarCalificaciones(float cal[NUM_ESTUDIANTES][NUM_ASIGNATURAS]) {
    printf("INGRESO DE CALIFICACIONES\n");

    for (int e = 0; e < NUM_ESTUDIANTES; e++) {
        printf("\n  ► %s\n", nombreEstudiante[e]);

        for (int a = 0; a < NUM_ASIGNATURAS; a++) {
            float nota;
            int valido;

            do {
                valido = 1;
                printf("    %-14s: ", nombreAsignatura[a]);

                if (scanf("%f", &nota) != 1) {
                    printf("Entrada no numerica. Ingrese un numero entre 0 y 10.\n");
                    while (getchar() != '\n');
                    valido = 0;
                } else if (nota < 0.0f || nota > 10.0f) {
                    printf("Valor fuera de rango 0-10. Intente de nuevo.\n");
                    valido = 0;
                }
            } while (!valido);

            cal[e][a] = nota;
        }
    }
}

float calcularPromedioEstudiante(float cal[NUM_ESTUDIANTES][NUM_ASIGNATURAS],
                                 int e) {
    float suma = 0.0f;
    for (int a = 0; a < NUM_ASIGNATURAS; a++)
        suma += cal[e][a];
    return suma / NUM_ASIGNATURAS;
}

float calcularPromedioAsignatura(float cal[NUM_ESTUDIANTES][NUM_ASIGNATURAS],
                                 int a) {
    float suma = 0.0f;
    for (int e = 0; e < NUM_ESTUDIANTES; e++)
        suma += cal[e][a];
    return suma / NUM_ESTUDIANTES;
}

void mostrarReporteEstudiantes(float cal[NUM_ESTUDIANTES][NUM_ASIGNATURAS]) {
    printf("REPORTE POR ESTUDIANTE\n");
    printf(" %-14s │ %9s │ %9s │ %9s │ %6s \n",
           "Estudiante", "Promedio", "Máximo", "Mínimo", "Estado");

    for (int e = 0; e < NUM_ESTUDIANTES; e++) {
        float promedio = calcularPromedioEstudiante(cal, e);

        float maximo = cal[e][0];
        float minimo = cal[e][0];
        for (int a = 1; a < NUM_ASIGNATURAS; a++) {
            if (cal[e][a] > maximo) maximo = cal[e][a];
            if (cal[e][a] < minimo) minimo = cal[e][a];
        }

        const char *estado = (promedio >= NOTA_APROBATORIA) ? "APRUEBA" : "REPRUEBA";

        printf(" %-14s │ %9.2f │ %9.2f │ %9.2f │ %7s \n",
               nombreEstudiante[e], promedio, maximo, minimo, estado);
    }
      printf("\n");
}

void mostrarReporteAsignaturas(float cal[NUM_ESTUDIANTES][NUM_ASIGNATURAS]) {
    printf("REPORTE POR ASIGNATURA\n");
    printf(" %-14s │ %8s │ %6s │ %6s │ %8s │ %8s \n",
           "Asignatura", "Promedio", "Máximo", "Mínimo", "Aprobados", "Reprobados");

    for (int a = 0; a < NUM_ASIGNATURAS; a++) {
        float promedio = calcularPromedioAsignatura(cal, a);

        float maximo = cal[0][a];
        float minimo = cal[0][a];
        int aprobados  = 0;
        int reprobados = 0;

        for (int e = 0; e < NUM_ESTUDIANTES; e++) {
            if (cal[e][a] > maximo) maximo = cal[e][a];
            if (cal[e][a] < minimo) minimo = cal[e][a];
            if (cal[e][a] >= NOTA_APROBATORIA)
                aprobados++;
            else
                reprobados++;
        }

        printf(" %-14s │ %8.2f │ %6.2f │ %6.2f │ %9d │ %10d \n",
               nombreAsignatura[a], promedio, maximo, minimo,
               aprobados, reprobados);
    }
    printf("\n");
}

void mostrarMatrizCalificaciones(float cal[NUM_ESTUDIANTES][NUM_ASIGNATURAS]) {
      printf("\n\n");
    printf("TABLA DE CALIFICACIONES\n");
    printf(" %-14s", "Estudiante");
    for (int a = 0; a < NUM_ASIGNATURAS; a++)
        printf(" │ %-12s", nombreAsignatura[a]);
        printf("\n");

    for (int e = 0; e < NUM_ESTUDIANTES; e++) {
        printf(" %-14s", nombreEstudiante[e]);
        for (int a = 0; a < NUM_ASIGNATURAS; a++)
            printf(" │ %12.2f", cal[e][a]);
        printf(" \n");
    }
    printf("\n");
}

int main(void) {

    float calificaciones[NUM_ESTUDIANTES][NUM_ASIGNATURAS];

    printf("SISTEMA DE GESTIÓN DE CALIFICACIONES\n");
    printf("Escuela - Año lectivo 2025-2026\n");
    printf("  Estudiantes : %d\n", NUM_ESTUDIANTES);
    printf("  Asignaturas : %d\n", NUM_ASIGNATURAS);
    printf("  Nota mínima aprobatoria : %.1f\n", NOTA_APROBATORIA);

    ingresarCalificaciones(calificaciones);

    mostrarMatrizCalificaciones(calificaciones);
    mostrarReporteEstudiantes(calificaciones);
    mostrarReporteAsignaturas(calificaciones);

    printf("\n  Programa finalizado correctamente.\n\n");
    return 0;
}