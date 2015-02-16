/*
Visual C++: Para que deje complilar
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int num;

bool es_par(int num) {
	if (num % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}

int es_primo(int num) {
	bool primo = false;
	int n = 3;
	if (!es_par(num)) {
		primo = true;
		do {
			if (num % n == 0) {
				primo = false;
				//printf("Falso \n");
			}
			//printf("Division: %i\n", n);
			n++;
		} while (n <= sqrt((float)num) && primo); // sqrt = raiz de math.h;
	}
	if (primo) {
		return true;
	}
	else {
		return false;
	}
}

bool validacionInt(int *scan, bool *validacion) {
	if (!scanf("%i", scan)) {
		return *validacion = false;
	}
	else {
		return *validacion = true;
	}
}

void bienvenida() {
	system("cls");
	printf("Programa que te muestra si es un numero primo o no.\n \n");
}

void pedirDatos() {
	bool validado;

	do {
		printf("- Insertar un numero: ");
		if (!validacionInt(&num, &validado)) {
			printf("- ERROR: Solo se permiten numeros\n \n");
		}
	} while (!validado);
}

void mostrarDatos() {
	time_t start_t, end_t;

	time(&start_t);
	if (es_primo(num)) {
		printf("- El numero %i es primo\n", num);
	}
	else {
		printf("- El numero %i no es primo\n", num);
	}
	time(&end_t);
	printf("\nEl programa ha tardado: %lf segundos.\n", end_t - start_t);
}

bool deseaContinuar() {
	bool validado;
	char resp;

	do {
		printf("\n- Desea agregar otro numero? (S)i - (N)o: ");
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

	if (resp == 'n' || resp == 'N') {
		return true;
	}
	else {
		return false;
	}
}

void main() {
	do {
		bienvenida();
		pedirDatos();
		mostrarDatos();
	} while (!deseaContinuar());
}