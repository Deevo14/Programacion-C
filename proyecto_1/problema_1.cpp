/*
	Hecho en Visual C++:
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

int nota[2];
float carnet, media;

/*
	Datos que se guardan hasta el final del programa
*/

struct curso {
	int alumnos;
	float media;
} curso[2];

struct alumnoMayor {
	float carnet;
	float media;
} alumMayor;

struct alumnoMenor {
	float carnet;
	float media = 20;
} alumMenor;

/*
	Validacion float con scanf
*/

bool validacionFloat(float *scan, bool *validacion) {
	if (!scanf("%f", scan)) {
		while (getchar() != '\n');
		return *validacion = false;
	}
	else {
		return *validacion = true;
	}
}

/*
	Validacion int con scanf
*/

bool validacionInt(int *scan, bool *validacion) {
	if (!scanf("%i", scan)) {
		while (getchar() != '\n');
		return *validacion = false;
	}
	else {
		return *validacion = true;
	}
}

/*
	Validacion entre dos numeros enteros
*/

bool validacionEntreNum(int num, int entre1, int entre2, bool *validacion) {
	if (num >= entre1 && num <= entre2) {
		return *validacion = true;
	}
	else {
		return *validacion = false;
	}
}

/*
	Promedio de dos numeros enteros con resultado float
*/

float promedio(float num1, float num2) {
	float promedio;
	num2 == 0 ? promedio = 0 : promedio = num1 / num2;
	return promedio;
}

void bienvenida() {
	system("cls");
	printf("Programa del departamento de programacion: Distribucion de alumnos por curso. \n %i alumno(s) agregado(s). \n \n", curso[0].alumnos + curso[1].alumnos);
}

void pedirDatos() {
	bool validado[3];

	do {
		printf("- Insertar la cedula del estudiante: ");
		if (!validacionFloat(&carnet, &validado[0])) {
			printf("- ERROR: Solo se permiten numeros\n \n");
		}
	} while (!validado[0]);

	for (int i = 0; i < 2; i++) {
		do {
			printf("\n- Insertar la nota (%i): ", i);
			if (validacionInt(&nota[i], &validado[1])) {
				if (!validacionEntreNum(nota[i], 0, 20, &validado[2])) {
					printf("- ERROR: Solo numeros entre 0-20.\n");
				}
			}
			else {
				printf("- ERROR: Solo se permiten numeros.\n");
			}
		} while (!validado[1] || !validado[2]);
	}
}

void procesarDatos() {
	media = promedio((float)(nota[0] + nota[1]), 2);

	if (media >= 15) { // Curso A
		curso[0].alumnos++;
		curso[0].media += media;
	}
	else { // Curso B
		curso[1].alumnos++;
		curso[1].media += media;
	}

	// Hallar al alumno con mayor promedio
	if (alumMayor.media <= media) {
		alumMayor.media = media;
		alumMayor.carnet = carnet;
	}

	// Hallar al alumno con menor promedio
	if (alumMenor.media >= media) { // alum_menor = 20
		alumMenor.media = media;
		alumMenor.carnet = carnet;
	}
}

void mostrarDatos() {
	printf("\nA  - REPORTE: por alumno\n");
	printf("A1 - Carnet del estudiantes: %.0f\n", carnet);
	printf("A2 - Notas del curso anterior: %i - %i\n", nota[0], nota[1]);
	printf("A3 - Media de notas: %.2f\n", media);
	printf("A4 - Curso: ");
	printf(media >= 15 ? "A" : "B");
	printf("\n");
}

bool deseaContinuar() {
	bool validado = true;
	char resp;

	do {
		printf("\n- Desea agregar a otro alumno. (S)i - (N)o: ");
		scanf(" %c", &resp);
		if (!(resp == 's' || resp == 'S' || resp == 'n' || resp == 'N')) {
			validado = false;
			printf("- ERROR: El valor insertado no esta permitido. Solo se permiten (S/N)");
		}
		printf("\n");
	} while (!validado);

	if (resp == 'n' || resp == 'N') {
		return true;
	}
	else {
		return false;
	}

	system("cls");
}

void procesarReporte() {
	curso[0].media = promedio(curso[0].media, (float)curso[0].alumnos);
	curso[1].media = promedio(curso[1].media, (float)curso[0].alumnos);
}

void mostrarReporte() {
	system("cls");
	printf("_________________________________________\n");
	printf("             REPORTE FINAL \n");
	printf("_________________________________________\n \n");

	printf("B1 - Cantidad de alumnos: \n");
	printf("B1 - Curso A: %i \n", curso[0].alumnos);
	printf("B1 - Curso B: %i \n \n", curso[1].alumnos);

	printf("B2 - Promedio de notas \n");
	printf("B2 - Curso A: %.2f \n", curso[0].media);
	printf("B2 - Curso B: %.2f \n \n", curso[1].media);

	printf("B3 - Alumno con mayor promedio: \n");
	printf("B3 - Carnet: %.0f \n", alumMayor.carnet);
	printf("B3 - Promedio: %.2f \n \n", alumMayor.media);

	printf("B4 - Alumno con menor promedio: \n");
	printf("B4 - Carnet: %.0f \n", alumMenor.carnet);
	printf("B4 - Promedio: %.2f \n \n", alumMenor.media);
}

void main() {
	do {
		bienvenida();
		pedirDatos();
		procesarDatos();
		mostrarDatos();
	} while (!deseaContinuar());
	procesarReporte();
	mostrarReporte();
	system("pause");
}