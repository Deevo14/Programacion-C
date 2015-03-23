/*
    Algoritmos y programacion
    Parcial 2 Parte 2
*/

#include <stdio.h>
#include <stdlib.h>

float carnet, nota[2], media, cmayor, mmayor, cmenor, mmenor = 20, mediaA, mediaB;;
int alumA, alumB;
char resp;

float fmedia(float num, float cantidad) {
    return cantidad == 0 ? 0 : num/cantidad;
}

void fmayor(float carnet, float media, float *cmayor, float *mmayor) {
    if (media >= *mmayor) {
        *cmayor = carnet;
        *mmayor = media;
    }
}

void fmenor(float carnet, float media, float *cmenor, float *mmenor) {
        if (media <= *mmenor) {
        *cmenor = carnet;
        *mmenor = media;
    }
}

void bienvenida() {
    system("cls");
    printf("Programa del Departamento de Programación. Ubicar a los nuevos alumnos en dos grupos diferentes \n");
    printf("%i alumno(s) agregado(s) \n\n", alumA + alumB);
}

void pedirDatos() {
    printf("- Insertar el carnet del estudiante: ");
    scanf("%f", &carnet);
    
    printf("- Insertar la nota 1: ", nota[0]);
    scanf("%f", &nota[0]);
    
    printf("- Insertar la nota 2: ", nota[1]);
    scanf("%f", &nota[1]);
}

void procesarDatos() {
    media = fmedia(nota[0] + nota[1], 2);
    
    if (media >= 15) {
        alumA++;
        mediaA += media;
    } else {
        alumB++;
        mediaB += media;
    }
    
    fmayor(carnet, media, &cmayor, &mmayor);
    fmenor(carnet, media, &cmenor, &mmenor);
}

void mostrarDatos() {
    printf("\nA1 - El numero de carnet del estudiante: %.0f \n", carnet);
    printf("A2 - Las notas de los dos cursos anteriores: %.2f - %.2f \n", nota[0], nota[1]);
    printf("A3 - La media obtenida del estudiante: %.2f \n", media);
    printf("A4 - Quedo en el curso: ");
    printf(media >= 15 ? "A" : "B");
    printf("\n \n");
}

void deseaContinuar() {
    printf("Desea agregar a otro estudiante? (S)i o (N)o");
    scanf(" %c", &resp);
}

void mostrarReporte() {
    printf("B1 - Cantidad de alumnos por curso. \n");
    printf("B1 - Curso A: %i \n", alumA);
    printf("B1 - Curso B: %i \n\n", alumB);
    
    printf("B2 - Promedio de las notas previas de los alumnos de cada-curso \n");
    printf("B2 - Curso A: %.2f \n", fmedia(mediaA, (float)alumA));
    printf("B2 - Curso B: %.2f \n\n", fmedia(mediaA, (float)alumA));
    
    printf("B3 - Alumno con mayor promedio \n");
    printf("B3 - Cedula: %.0f \n", cmayor);
    printf("B3 - Promedio: %.2f \n\n", mmayor);
    
    printf("B4 - Alumno con menor promedio: \n");
    printf("B4 - Cedula: %.0f \n", cmenor);
    printf("B4 - Promedio: %.2f \n\n", mmenor);
}

main() {
    do {
        bienvenida();
        pedirDatos();
        procesarDatos();
        mostrarDatos();
        deseaContinuar();
    } while(resp == 's' || resp == 'S');
    bienvenida();
    mostrarReporte();
    
    system("pause");
}
