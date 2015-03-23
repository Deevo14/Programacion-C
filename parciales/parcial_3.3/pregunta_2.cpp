#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

int edades[3][3] = {
	{ 17, 19, 20 },
	{ 20, 18, 28 },
	{ 20, 25, 26 },
};

void mostrarMatriz(int edades[3][3]) {
	for (int n = 0; n < 3; n++) {
		for (int m = 0; m < 3; m++) {
			printf("%d \t", edades[n][m]);
		}
		printf("\n");
	}
}

float promedioEdades(int edades[3][3]) {
	float promedio = 0, count = 0;
	for (int n = 0; n < 3; n++) {
		for (int m = 0; m < 3; m++) {
			promedio += edades[n][m];
			count++;
		}
	}
	return promedio /= count;
}

int menorEdad(int edades[3][3]) {
	int menor = edades[0][0];
	for (int n = 0; n < 3; n++) {
		for (int m = 0; m < 3; m++) {
			if (menor > edades[n][m]) {
				menor = edades[n][m];
			}
		}
	}
	return menor;
}

void main() {
	mostrarMatriz(edades);
	printf("______________________\n \n");
	printf("El promedio de edades es: %.2f \n \n", promedioEdades(edades));
	printf("El menor de la clase tiene: %d \n \n", menorEdad(edades));
	system("pause");
}