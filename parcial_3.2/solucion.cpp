#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

int fact, precios[3][3] = { { 3, 1, 2 }, { 4, 5, 8 }, { 2, 9, 0 } }, menor;
int diagord[5][5] = { { 3, 1, 2, 5, 2 }, { 4, 5, 8, 3, 6 }, { 2, 9, 0, 1, 9 }, { 2, 9, 0, 1, 9 }, { 2, 9, 0, 1, 9 } };
float prompro[3];

/*
	Pregunta 1
*/
void pedirNumeroFactorial() {
	printf("Inserta un numero para obtener su factorial \n");
	scanf("%d", &fact);
}

int factorial(int num) {
	if (num > 1) {
		return num*factorial(num - 1);
	}
	else {
		return 1;
	}
}

/*
	Pregunta 2
*/
void promedioPreciosPorSupermercado(int precios[3][3]) {
	int contador = 0;
	for (int n = 0; n < 3; n++) {
		for (int m = 0; m < 3; m++) {
			prompro[n] += precios[m][n];
			contador++;
		}
		prompro[n] = prompro[n]/contador;
		contador = 0;
	}
}

void mostrarPromedio(float prompro[]) {
	printf("Promedio por supermercado \n");
	for (int n = 0; n < 3; n++) {
		printf("El promedio por supermercado del producto (%d) = %.2f \n", n, prompro[n]);
	}
}

void menorPrecio(int precio[3][3], int * menor) {
	int fmenor, cmenor;
	*menor = precios[0][0];
	for (int k = 0; k < 3; k++) {
		for (int j = 0; j < 3; j++) {
			if (*menor > precios[k][j]) {
				*menor = precios[k][j];
			}
		}
	}
}

void mostrarMenorPrecio() {
	printf("\n \n El menor precio es: %d \n \n", menor);
}

/* 
	Pregunta 3
*/
void ordenarDescendentePorDiagonal(int diagord[5][5]) {
	int mayor, aux;
	for (int n = 0; n < 5; n++) {
		mayor = n;
		for (int m = n; m < 5; m++) {
			if (diagord[mayor][mayor] < diagord[m][m]) {
				mayor = m;
			}
		}
		aux = diagord[n][n];
		diagord[n][n] = diagord[mayor][mayor];
		diagord[mayor][mayor] = aux;
	}
}

void mostrarMatriz(int diagord[5][5]) {
	for (int n = 0; n < 5; n++) {
		for (int m = 0; m < 5; m++) {
			printf("%d\t", diagord[n][m]);
		}
		printf("\n");
	}
}

void main() {
	/* Pregunta 1
	pedirNumeroFactorial();
	printf("\n Factorial = ", factorial(fact));
	*/

	/* Pregunta 2
	promedioPreciosPorSupermercado(precios);
	mostrarPromedio(prompro);
	menorPrecio(precios, &menor);
	mostrarMenorPrecio();
	*/

	/* Pregunta 3 
	mostrarMatriz(diagord);
	printf("______________________________________\n");
	ordenarDescendentePorDiagonal(diagord);
	mostrarMatriz(diagord);
	system("pause");
	*/
}