/*
Visual C++: Para que deje complilar
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double num;
char resp;

/*
*	Saber si un numero es par devolviendo
*  un tipo bool
*/

bool es_par(double num) {
	if (fmod(num, 2) == 0) { // Fmod saca el resto de un numero Double o float. El "%" no permite float ni double
		return true;
	}
	else {
		return false;
	}
}

/*
*	Funcion para saber si es un numero primo.
*	REGLA DE PRIMOS:
*  - Tiene que ser impar por la funcion es_par()
*	- Si es impar se dividen todos los numeros del 3 hasta la raiz cuadrada de ese numero
*    y si su resto no es igual a 0 es primo. sqrt(num) = raiz del numero.
*/

bool es_primo(double num) {
	bool primo = false; // Incializar
	double n = 3; // Comienza con dividir con 3 hasta la raiz cuadrada
	if (!es_par(num)) {
		primo = true; // Es posible que sea primo por ser impar
		do {
			//printf("Division: %i\n", n);
			if (fmod(num, n) == 0) {
				primo = false; // No es primo
				//printf("Parar bucle\n");
			}
			n++;
		} while (n <= sqrt(num) && primo); // Hasta su raiz cuadrada o hasta que primo = false
	}
	if (primo || num == 2 || num == 3) {
		return true;
	}
	else {
		return false;
	}
}

void bienvenida() {
	system("cls");
	printf("Programa que te muestra si es un numero es primo o no.\n \n");
}

void pedirDatos() {
	bool validado;

	do {
		printf("- Insertar un numero: ");
		validado = true; // Reiniciar variable
		if (!scanf("%lf", &num)) {
			printf("- ERROR: Solo se permiten numeros\n \n");
			validado = false;
		}
		else {
			if (!(num > 0)){
				validado = false;
				printf("- ERROR: Solo numeros enteros positivos\n \n");
			}
		}
		fflush(stdin);
	} while (!validado);
}

void mostrarDatos() {
	if (es_primo(num)) {
		printf("- El numero %.0f es primo\n", num);
	}
	else {
		printf("- El numero %.0f no es primo\n", num);
	}
}

void deseaContinuar() {
	bool validado;
	do {
		printf("\n- Desea intentar con otro numero? (S)i - (N)o: ");
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

void main() {
	do {
		bienvenida();
		pedirDatos();
		mostrarDatos();
		deseaContinuar();
	} while (resp == 's' || resp == 'S');
}
