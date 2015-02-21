/*
Visual C++: Para que deje complilar
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

float alm, costoP, ganancia, costoPNinos, gananciaDulces;
char tipo, resp;
int rango, ninos, adultos, salados, dulces;

// Datos del tipo (A - N) que tiene mas cantidad
struct tipoMayorCantidad {
	int cantidad;
	char tipo;
} tipoMayor;

// Datos del producto de mayor ganacia
struct productoMayorGanancia {
	int rango;
	float ganancia;
	char tipo;
} gananciaMayor;

/*
 *	Validacion entre dos numeros enteros
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
 *   Funcion promedio con validacion de divison entre 0
 */

float promedio(float num1, float num2) {
	return num2 == 0 ? 0 : num1 / num2;
}

void bienvenida() {
	system("cls");
	printf("Programa de una empresa del ramo de alimentos sobre los costos por producto. \n %i producto(s) agregado(s)\n\n", dulces + salados);
}

void pedirDatos() {
	bool validado[4];

	// Primer scanf: Almacenamiento
	do {
		printf("- Insertar el costo de almacenamiento del producto: ");
		if (!scanf("%f", &alm)) {
			validado[0] = false;
			printf("- ERROR: Solo se permiten numeros reales\n \n");
		}
		else {
			validado[0] = true;
		}
		fflush(stdin);
	} while (!validado[0]);

	// Segundo scanf: tipo de producto
	do {
		printf("\n- Insertar el tipo de producto: (N)inos - (A)dultos: ");
		scanf("%c", &tipo);
		if (!(tipo == 'n' || tipo == 'N' || tipo == 'a' || tipo == 'A')) {
			validado[1] = false;
			printf("- ERROR: El valor insertado no esta permitido. Solo se permiten (S/N)\n");
		}
		else {
			validado[1] = true;
		}
		fflush(stdin);
	} while (!validado[1]);

	// Tercer scanf: Rango
	do {
		printf("\n- Insertar el rango del producto (1-20): ");
		if (scanf("%i", &rango)) {
			validado[2] = true;
			if (!validacionEntreNum(rango, 1, 20, &validado[3])) {
				printf("- ERROR: Solo numeros entre 1-20.\n");
			}
		}
		else {
			validado[2] = false;
			printf("- ERROR: Solo se permiten numeros.\n");
		}
		fflush(stdin);
	} while (!validado[2] || !validado[3]);
}

void procesarDatos() {
	// Salados
	if (rango <= 10) {
		salados++;
		if (tipo == 'n' || tipo == 'N') {
			costoP = 2 * alm;
			ganancia = costoP*0.10;
			ninos++;
			costoPNinos += costoP;
		}
		else {
			costoP = 4 * alm;
			ganancia = costoP*0.15;
			adultos++;
		}
	}
	// Dulces
	else {
		dulces++;
		if (tipo == 'n' || tipo == 'N') {
			costoP = 4 * alm;
			ganancia = costoP*0.15;
			ninos++;
			costoPNinos += costoP;
		}
		else {
			costoP = 6 * alm;
			ganancia = costoP*0.25;
			adultos++;
		}
		gananciaDulces += ganancia;
	}

	// Ganacia mayor
	if (gananciaMayor.ganancia <= ganancia) {
		gananciaMayor.ganancia = ganancia;
		gananciaMayor.tipo = tipo;
		gananciaMayor.rango = rango;
	}
}

void mostrarDatos() {
	printf("\n_________________________________________\n");
	printf("          Reporte por producto\n");
	printf("_________________________________________\n \n");
	printf("A1 - Tipo de producto: ");
	printf(tipo == 'a' || tipo == 'A' ? "(A)dulto" : "(N)inos");
	printf("\nA2 - Codigo de variedad : %i - ", rango);
	printf(rango >= 11 ? "dulce" : "salado");
	printf("\nA3 - Costo de almacenamiento %.2f\n", alm);
	printf("A4 - Valor de produccion: %.2f\n", costoP);
	printf("A5 - Precio de venta al publico: %.2f\n", costoP + ganancia);
	printf("A6 - Ganacia de la empresa: %.2f\n", ganancia);
	printf("\n_________________________________________\n \n");
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

void tipoMayorCantidad(int ninos, int adultos, char *tipo, int *cantidad) {
	if (ninos >= adultos) {
		*tipo = 'n';
		*cantidad = ninos;
	}
	else {
		*tipo = 'a';
		*cantidad = adultos;
	}
}

void procesarReporte() {
	tipoMayorCantidad(ninos, adultos, &tipoMayor.tipo, &tipoMayor.cantidad);
}

void mostrarReporte() {
	printf("______________________________________________________________\n");
	printf("                        REPORTE FINAL \n");
	printf("______________________________________________________________\n \n");
	printf("B1 - Producto que se fabrico en mayor cantidad: \n");
	printf("B1 - Tipo: ");
	printf(tipoMayor.tipo == 'a' || tipoMayor.tipo == 'A' ? "(A)dulto" : "(N)inos");
	printf("\nB1 - Cantidad: %i \n \n", tipoMayor.cantidad);
	printf("B2 - Cantidad de variedades \n");
	printf("B2 - Salado: %i \n", salados);
	printf("B2 - Dulce: %i \n \n", dulces);
	printf("B3 - Total del costo de produccion para ninos:  %.2f\n", costoPNinos);
	printf("B4 - Total de ganancia de los productos dulces: %.2f\n", gananciaDulces);
	printf("B5 - Promedio del costo de produccion para ninos: %.2f \n", promedio(costoPNinos, (float)ninos));
	printf("B6 - Promedio de ganancias por dulces: %.2f \n\n", promedio(gananciaDulces, (float)dulces));
	printf("B7 - Producto que genero la maxima ganancia: \n");
	printf("B7 - Tipo: ");
	printf(gananciaMayor.tipo == 'a' || gananciaMayor.tipo == 'A' ? "(A)dulto" : "(N)inos");
	printf("\nB7 - Codigo: %i \n", gananciaMayor.rango);
	printf("B7 - Ganancia: %.2f \n \n", gananciaMayor.ganancia);
	printf("______________________________________________________________\n \n");
}

void main() {
	do {
		bienvenida();
		pedirDatos();
		procesarDatos();
		mostrarDatos();
		deseaContinuar();
	} while (resp == 's' || resp == 'S');
	procesarReporte();
	bienvenida();
	mostrarReporte();
	system("pause");
}