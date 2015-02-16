/*
Visual C++: Para que deje complilar
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

int num;

long double factorial(int num) {
	long double fact;
	if (num != 1) {
		return num * factorial(num-1);
	}
	else
	{
		return 1;
	}
}

void main() {
	if (scanf("%i", &num)) {
		printf("%lf", factorial(num));
	}
	else {
		printf("ERROR: Solo numeros enteros");
	}
	fflush(stdin);
	system("pause");
}