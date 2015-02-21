/*
Visual C++: Para que deje complilar
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

float carnet, media, nota[2];
char resp;

// Datos de cada curso
struct curso {
	int alumnos;
	float media;
} curso[2];

// Datos del alumno con mayor promedio
struct alumnoMayor {
	float carnet;
	float media;
} alumMayor;

// Datos del alumno con menor promedio
struct alumnoMenor {
	float carnet;
	float media = 20;
} alumMenor;

/*
 *   Validacion entre dos numeros enteros
 */

bool validacionEntreNum(float num, float entre1, float entre2, bool *validacion) {
	if (num >= entre1 && num <= entre2) {
		return *validacion = true;
	}
	else {
		return *validacion = false;
	}
}

/*
 *   Funcion promedio con validacion de divison entre 0
 */

float promedio(float num1, float num2) {
	return num2 == 0 ? 0 : num1 / num2;
}

void bienvenida() {
	system("cls");
	printf("Programa del departamento de programacion: Distribucion de alumnos por curso. \n");
	printf("%i alumno(s) agregado(s). \n \n", curso[0].alumnos + curso[1].alumnos);
}

void pedirDatos() {
	bool validado[3];

	// Primer Scanf: pedir cedula
	do {
		printf("- Insertar la cedula del estudiante: ");
		if (!scanf("%f", &carnet)) {
			printf("- ERROR: Solo se permiten numeros\n \n");
			validado[0] = false;
		}
		else {
			validado[0] = true;
		}
		fflush(stdin);
	} while (!validado[0]);

	// Segundo y tercer scanf: pedir notas
	for (int i = 0; i < 2; i++) {
		do {
			printf("\n- Insertar la nota (%i): ", i);
			if (scanf("%f", &nota[i])) {
				validado[1] = true;
				if (!validacionEntreNum(nota[i], 0, 20, &validado[2])) {
					printf("- ERROR: Solo numeros entre 0-20.\n");
				}
			}
			else {
				validado[1] = false;
				printf("- ERROR: Solo se permiten numeros.\n");
			}
			fflush(stdin);
		} while (!validado[1] || !validado[2]);
	}
}

/*
 *	 Funcion para saber cual alumno tiene mayor 
 *   y menor promedio de notas
 */

void rankingMedia(char tipo[], float media, float carnet, float *mediaX, float *carnetX){
	if (tipo == "Mayor") {
		if (*mediaX <= media) {
			*mediaX = media;
			*carnetX = carnet;
		}
	}
	else {
		if (*mediaX >= media) { // alum_menor = 20
			*mediaX = media;
			*carnetX = carnet;
		}
	}
}

void procesarDatos() {
	media = promedio(nota[0] + nota[1], 2);

	if (media >= 15) { // Curso A
		curso[0].alumnos++;
		curso[0].media += media;
	}
	else { // Curso B
		curso[1].alumnos++;
		curso[1].media += media;
	}

	rankingMedia("Mayor", media, carnet, &alumMayor.media, &alumMayor.carnet);
	rankingMedia("Menor", media, carnet, &alumMenor.media, &alumMenor.carnet);
}

void mostrarDatos() {
	printf("\n___________________________________________________________\n");
	printf("                  Reporte por alumno\n");
	printf("___________________________________________________________\n \n");
	printf("A1 - Carnet del estudiantes: %.0f\n", carnet);
	printf("A2 - Notas del curso anterior: %.2f - %.2f\n", nota[0], nota[1]);
	printf("A3 - Media de notas: %.2f\n", media);
	printf("A4 - Curso: ");
	printf(media >= 15 ? "A" : "B");
	printf("\n___________________________________________________________\n \n");
}

void deseaContinuar() {
	bool validado;

	do {
		printf("\n- Desea agregar a otro alumno. (S)i - (N)o: ");
		scanf(" %c", &resp);
		if (!(resp == 's' || resp == 'S' || resp == 'n' || resp == 'N')) {
			validado = false;
			printf("- ERROR: El valor insertado no esta permitido. Solo se permiten (S/N)");
			resp = 's';
		}
		else {
			validado = true;
		}
		printf("\n");
		fflush(stdin);
	} while (!validado);
}

void mostrarReporte() {
	printf("_________________________________________\n");
	printf("             REPORTE FINAL \n");
	printf("_________________________________________\n \n");

	printf("B1 - Cantidad de alumnos: \n");
	printf("B1 - Curso A: %i \n", curso[0].alumnos);
	printf("B1 - Curso B: %i \n \n", curso[1].alumnos);

	printf("B2 - Promedio de notas: \n");
	printf("B2 - Curso A: %.2f \n", promedio(curso[0].media, (float)curso[0].alumnos));
	printf("B2 - Curso B: %.2f \n \n", promedio(curso[1].media, (float)curso[1].alumnos));

	printf("B3 - Alumno con mayor promedio: \n");
	printf("B3 - Carnet: %.0f \n", alumMayor.carnet);
	printf("B3 - Promedio: %.2f \n \n", alumMayor.media);

	printf("B4 - Alumno con menor promedio: \n");
	printf("B4 - Carnet: %.0f \n", alumMenor.carnet);
	printf("B4 - Promedio: %.2f \n", alumMenor.media);
	printf("_________________________________________\n \n");
}

void main() {
	do {
		bienvenida();
		pedirDatos();
		procesarDatos();
		mostrarDatos();
		deseaContinuar();
	} while (resp == 's' || resp == 'S');
	bienvenida();
	mostrarReporte();
	system("pause");
}