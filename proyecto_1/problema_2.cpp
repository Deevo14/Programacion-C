/*
Visual C++: Para que deje complilar
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

float alm, costoP, costoF, ganancia, costoPNinos, gananciaDulces;
char tipo;
int rango, ninos, adultos, salados, dulces;

struct productoMayorTipo {
	int cantidad;
	char tipo;
} prodMayorT;

struct productoMayorGanancia {
	int rango;
	float ganancia;
	char tipo;
} prodMayorG;

/*
 *	Validacion float con scanf
 */

bool validacionFloat(float *scan, bool *validacion) {
	if (!scanf("%f", scan)) {
		return *validacion = false;
	}
	else {
		return *validacion = true;
	}
}

/*
 *	Validacion int con scanf
 */

bool validacionInt(int *scan, bool *validacion) {
	if (!scanf("%i", scan)) {
		return *validacion = false;
	}
	else {
		return *validacion = true;
	}
}

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

float promedio(float num1, float num2) {
	float promedio;
	num2 == 0 ? promedio = 0 : promedio = num1 / num2;
	return promedio;
}

void bienvenida() {
	system("cls");
	printf("Programa de una empresa del ramo de alimentos sobre los costos por producto. \n %i producto(s) agregado(s)\n\n", dulces + salados);
}

void pedirDatos() {
	bool validado[4];

	do {
		printf("- Insertar el costo de almacenamiento del producto: ");
		if (!validacionFloat(&alm, &validado[0])) {
			printf("- ERROR: Solo se permiten numeros reales\n \n");
		}
		fflush(stdin);
	} while (!validado[0]);

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

	do {
		printf("\n- Insertar el rango del producto (1-20): ");
		if (validacionInt(&rango, &validado[2])) {
			if (!validacionEntreNum(rango, 1, 20, &validado[3])) {
				printf("- ERROR: Solo numeros entre 1-20.\n");
			}
		}
		else {
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
		if (tipo == 'a' || tipo == 'A') {
			costoP = 4 * alm;
			ganancia = costoP*0.20;
			adultos++;
		}
		else {
			costoP = 6 * alm;
			ganancia = costoP*0.25;
			ninos++;
			costoPNinos += costoP;
		}
		gananciaDulces += ganancia;
	}

	costoF = costoP + ganancia;

	// Mayor producto con ganancia
	if (prodMayorG.ganancia <= ganancia) {
		prodMayorG.ganancia = ganancia;
		prodMayorG.tipo = tipo;
		prodMayorG.rango = rango;
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
	printf("A5 - Precio de venta al publico: %.2f\n", costoF);
	printf("A6 - Ganacia de la empresa: %.2f\n", ganancia);
	printf("\n_________________________________________\n \n");
}

bool deseaContinuar() {
	bool validado;
	char resp;

	do {
		printf("\n- Desea agregar otro producto? (S)i - (N)o: ");
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

void procesarReporte() {
	// Para saber cual es el tipo con mayor cantidad
	if (ninos >= adultos) {
		prodMayorT.tipo = 'n';
		prodMayorT.cantidad = ninos;
	}
	else {
		prodMayorT.tipo = 'a';
		prodMayorT.cantidad = adultos;
	}
}

void mostrarReporte() {
	printf("______________________________________________________________\n");
	printf("                        REPORTE FINAL \n");
	printf("______________________________________________________________\n \n");
	printf("B1 - Producto que se fabrico en mayor cantidad: \n");
	printf("B1 - Tipo: ");
	printf(prodMayorT.tipo == 'a' || prodMayorT.tipo == 'A' ? "(A)dulto" : "(N)inos");
	printf("\nB1 - Cantidad: %i \n \n", prodMayorT.cantidad);
	printf("B2 - Cantidad de variedades \n");
	printf("B2 - Salado: %i \n", salados);
	printf("B2 - Dulce: %i \n \n", dulces);
	printf("B3 - Total del costo de produccion para ninos:  %.2f\n", costoPNinos);
	printf("B4 - Total de ganancia de los productos dulces: %.2f\n", gananciaDulces);
	printf("B5 - Promedio del costo de produccion para ninos: %.2f \n", promedio(costoPNinos, (float)ninos));
	printf("B6 - Promedio de ganancias por dulces: %.2f \n\n", promedio(gananciaDulces, (float)dulces));
	printf("B7 - Producto que genero la maxima ganancia: \n");
	printf("B7 - Tipo: ");
	printf(prodMayorG.tipo == 'a' || prodMayorG.tipo == 'A' ? "(A)dulto" : "(N)inos");
	printf("\nB7 - Codigo: %i \n", prodMayorG.rango);
	printf("B7 - Ganancia: %.2f \n \n", prodMayorG.ganancia);
	printf("______________________________________________________________\n \n");
}

void main() {
	do {
		bienvenida();
		pedirDatos();
		procesarDatos();
		mostrarDatos();
	} while (!deseaContinuar());
	procesarReporte();
	bienvenida();
	mostrarReporte();
	system("pause");
}