#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

int n, k;

void pedirNumeros(int *n, int *k) {
	do {
		printf("- Insertar la base del numero: ");
		scanf("%d", n);
		if (*n < 1) {
			printf("- Error: el numero insertado no es un entero positivo\n \n");
		}
	} while (*n < 1);

	do {
		printf("\n- Insertar el indice de potecia:");
		scanf("%d", k);
		if (*k < 1) {
			printf("- Error: el numero insertado no es un entero positivo \n");
		}
	} while (*k < 1);
}

int potencia(int n, int k) {
	if (k >= 2) {
		return n*potencia(n, k - 1);
	}
	else {
		return n;
	}
}

void main() {
	printf("Programa que obtiene la potencia de un numero elevado a x\n \n");
	pedirNumeros(&n, &k);
	printf("\n- El resultado es: %d \n \n", potencia(n, k));
	printf("%d - %d ", n, k);
	system("pause");
}