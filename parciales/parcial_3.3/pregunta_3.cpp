#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

char matriz[4][13] = {
	{ 'o', 'm', 'o', 'c', '\0', 'e', 'u', 'q', '\0', 'o', 'e', 'r', 'c' },
	{ '\0', 'a', 'b', 'o', 'r', 'p', 'a', '\0', 'a', '\0', 'y', 'o', 'v' },
	{ 'E', 'd', '\0', 'a', 'i', 'r', 'e', 't', 'a', 'm', '\0', 'a', 'l' },
	{ 'n', 'o', 'i', 'c', 'a', 'm', 'a', 'r', 'g', 'o', 'r', 'p', '\0' }
};

void mostrarMatriz(char matriz[4][13]) {
	for (int n = 0; n < 4; n++) {
		for (int m = 0; m < 13; m++) {
			printf("%c", matriz[n][m]);
		}
		printf("\n");
	}
}

void invertirMatriz(char matriz[4][13]) {
	char aux;
	for (int n = 0; n < 2; n++) {
		for (int m = 0; m < 13; m++) {
			if (matriz[n][m] == matriz[3 - n][12 - m]) {
				printf("El caracter \"%c\". Al invertir son iguales \n\n", matriz[n][m]);
			}
			aux = matriz[n][m];
			matriz[n][m] = matriz[3 - n][12 - m];
			matriz[3 - n][12 - m] = aux;
		}
	}
}

void main() {
	mostrarMatriz(matriz);
	printf("__________________________\n \n");
	invertirMatriz(matriz);
	mostrarMatriz(matriz);
	printf("__________________________\n \n");
	system("pause");
}