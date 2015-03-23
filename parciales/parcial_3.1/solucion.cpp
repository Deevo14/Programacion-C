#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int m, n;
char resp;
int matriz[4][4]={{3,10,12,7},
                  {33,22,13,21},
                  {15,6,3,30},
                  {16,20,27,2}};

int ordsel[4][4] = { { 3, 10, 12, 7 },
{ 33, 22, 13, 21 },
{ 15, 6, 3, 30 },
{ 16, 20, 27, 2 } };


int numero[2];

void mostrarMatriz(int matriz[4][4]) {
	for (int k = 0; k<4; k++)
	{
		for (int m = 0; m<4; m++)
			printf("%d\t", matriz[k][m]);
		printf("\n");
	}
}

void ordenarAscendenteColumna(int matriz[4][4]) {
	int imenor, aux;

	for (int m = 0; m < 4; m++) {
		for (int n = 3; n > -1; n--) {
			imenor = n;
			for (int j = n; j > -1; j--) {
				if (matriz[imenor][m] > matriz[j][m]) {
					imenor = j;
				}
			}
			aux = matriz[n][m];
			matriz[n][m] = matriz[imenor][m];
			matriz[imenor][m] = aux;
		}
	}
}

void pedirNumeros() {
	for (int n = 0; n < 2; n++) {
		printf("Insertar el numero(%d): ", n);
		scanf("%d", &numero[n]);
		printf("\n");
	}
}

// maximo comun divisor
int mcd(int m, int n)
{
	if (m%n == 0)
		return n;
	else
		return mcd(n, m%n);
}

void ordenarMenorMayor(int matriz[4][4]) {
	int fmenor, cmenor, aux, ia;
	for (int n = 0; n < 4; n++) {
		for (int m = 0; m < 4; m++) {
			fmenor = n;
			cmenor = m;
			ia = m;
			for (int k = n; k < 4; k++) {
				for (int j = ia; j < 4; j++) {
					if (matriz[fmenor][cmenor] > matriz[k][j]) {
						fmenor = k;
						cmenor = j;
					}
				}
				ia = 0;
			}
			aux = matriz[fmenor][cmenor];
			matriz[fmenor][cmenor] = matriz[n][m];
			matriz[n][m] = aux;
		}
	}
}

void main()
{
	mostrarMatriz(ordsel);
	printf("\n _____________________ \n");
	ordenarMenorMayor(ordsel);
	mostrarMatriz(ordsel);
	system("pause");
}
