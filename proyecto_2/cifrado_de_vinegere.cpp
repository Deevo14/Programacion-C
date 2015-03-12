#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

const int MAX_BUFFER = 40;

char men_cif[MAX_BUFFER] = "pazyamor";
char men_des[MAX_BUFFER] = "hokqoxgf";

char mensaje[MAX_BUFFER + 1], clave[MAX_BUFFER], tipo, resp[2], matriz[26][26]; // +1 --> es el 0 de confirmar
char abecedario[] = "abcdefghijklmnopqrstuvwxyz";
int mensajeT;

/*
*		Funcion que crea la tabla de vinegere
*/

void crearMatriz() {
	int z = 0;
	for (int n = 0; n < 26; n++) {
		for (int m = 0; m < 27; m++) {
			if (n + m < 26) {
				matriz[n][m] = abecedario[m + n];
			}
			else {
				matriz[n][m] = abecedario[z];
				z++;
			}
		}
		z = 0;
	}
}

/*
*		Funcion de prueba para saber si la matriz
*		se creo correctamente
*/

void mostrarMatriz() {
	crearMatriz();
	for (int n = 0; n < 26; n++) {
		for (int m = 0; m < 26; m++) {
			printf(" %c ", matriz[n][m]);
		}
		printf("\n");
	}
}

/*
*		Funcion para obtener la clave final que se usará mediante el procedimiento de VINEGERE
*		EJEMPLO:   ESTAESLAORACIONAENCRIPTAR - ESTAESLACLAVE
*		RESULTADO: ESTAESLACLAVEESTAESLACLAV = CLAVE FINAL
*/

char * claveFinal(char clave[], int tamanio) {
	int claveContador = 0;
	for (int n = 0; n < tamanio; n++) {
		if (claveContador >= strlen(clave)) {
			claveContador = 0;
		}
		clave[n] = clave[claveContador];
		claveContador++;
	}
	return clave;
}

/*
*		Funcion bucle que da valores de 0 a 26
*		de un array de letras
*/

char * letrasANumeros(char cadena[], int tamanio) {
	for (int n = 0; n < tamanio; n++) {
		for (int i = 0; i < 26; i++) {
			if (cadena[n] == abecedario[i]) {
				cadena[n] = i;
			}
		}
	}
	return cadena;
}

/*
*		Cifrado de vinegere por matriz o por formula matematica
*/

char * cifrar(char mensaje[], char clave[]) {
	for (int n = 0; n < mensajeT; n++) {
		// mensaje[n] = abecedario[(mensaje[n] + clave[n]) % 26]; /* METODO DE CIFRADO SIN USAR ARRAY BIDIMENCIONAL*/
		mensaje[n] = matriz[mensaje[n]][clave[n]];
	}
	return mensaje;
}

/*
*		Descifrar usando la formula matematica de vinegere.
*		 - Si EL mensaje es mayor o igual se suma el caracter del mensaje y el caracter de la clave y se saca el resto de 26
*			(mensajeCaracterNumerico + claveCaracterNumero) MOD 26
*
*		 - Si el mensaje es menor, se resta el caracter del mensaje con el caracter de la clave y se suma 26
*			(mensajeCaracterNumerico - claveCaracterNumero) + 26
*/

char * descifrar(char mensaje[], char clave[]) {
	for (int n = 0; n < mensajeT; n++) {
		if (mensaje[n] >= clave[n]) {
			mensaje[n] = abecedario[(mensaje[n] - clave[n]) % 26];
		}
		else {
			mensaje[n] = abecedario[(mensaje[n] - clave[n]) + 26];
		}
	}
	return mensaje;
}

/*
*		Funcion que sirve para preguntar por dos opciones de un caracter
*		EJEMPLO:
*		preguntar("¿Deseas continuar con el programa?", variable a retornar (resp), caracter 1 (s), caracter 2 (n))
*/

void preguntar(char pregunta[], char * resp, char p1, char p2) {
	bool validado;
	do {
		printf("\n - %s: ", pregunta);
		scanf(" %c", resp);
		validado = true; // Hasta que se demuestre lo contrario
		if (!(*resp == p1 || *resp == toupper(p1) || *resp == p2 || *resp == toupper(p2))) {
			validado = false;
			printf(" - ERROR: El valor insertado no esta permitido. Solo se permiten (%c/%c)", toupper(p1), toupper(p2));
		}
		printf("\n");
		fflush(stdin);
	} while (!validado);
}

/*
*		Diseño del programa
*/

void ui() {
	system("cls");
	printf(" ______________________________________________________________________________\n");
	printf("\n                               CIFRADO DE VINEGERE \n");
	printf(" ______________________________________________________________________________\n \n");
	if (tipo == NULL) {
		printf("   Opciones posibles: \n");
		printf("   C - Cifrar \n");
		printf("   D - Descifrar \n");
		printf(" ______________________________________________________________________________\n");
	}
	else {
		if (tipo == 'c' || tipo == 'C') {
			printf("                                  OPCION CIFRAR \n");
			printf(" ______________________________________________________________________________\n");
		}
		else {
			printf("                                OPCION DESCIFRAR \n");
			printf(" ______________________________________________________________________________\n");
		}
	}
}

/*
*		Funcion parecida a isalpha() de ctype.h pero sin usar los valores ascii
*		para que no tire error con la "Ñ" y acentos.
*/

bool esAlpha(char caracter, char caracteres[]) {
	bool validado = false;
	for (int n = 0; n < strlen(caracteres); n++) {
		if (caracter == caracteres[n]) {
			validado = true;
			break;
		}
	}
	return validado;
}

/*
*		Funcion que pide una cadena
*		con todas las validaciones posibles.
*		Se usa para pedir el mensaje a cifrar o descifrar y la clave
*		 - dato = array a retornar
*		 - nombre = cadena de texto
*		 - cero = 0 si no tiene y 1 si tiene
*/

void pedirDato(char * dato, char * nombre, int cero) {
	bool validado;
	int tamanio;

	do {
		printf("\n - Insertar %s: ", nombre);
		fgets(dato, MAX_BUFFER + 2 + cero, stdin); // Maximo 41 caracteres que lee el programa
		validado = true;
		tamanio = strlen(dato) - 1; // -1 ---> ignorar caracter nulo \0

		if (tamanio != 0) {
			for (int n = 0; n < tamanio - cero; n++) {
				dato[n] = tolower(dato[n]); // pasar todo a minusculas para evitar errores
				if (!esAlpha(dato[n], abecedario)) {
					printf(" - ERROR: el valor insertado solo puede llevar caracteres del abecedario (A-Z)\n", dato);
					validado = false;
					break;
				}
			}
			if (cero == 1 && dato[tamanio - 1] != '0' && validado == true) {
				printf(" - ERROR: El mensaje no ha termiando en 0\n");
				validado = false;
			}
		}
		else {
			printf(" - ERROR: el valor insertado esta vacio. \n");
			validado = false;
		}
		dato[tamanio] = NULL; // eliminar caracter nulo \0
		if (cero == 1) {
			dato[tamanio - 1] = NULL; // Eliminar numero 0 del array
		}
		fflush(stdin); // Limpiar buffer.
	} while (!validado);
}

/*
*	   Funcion que tiene otras funciones, para pedir
*	   la clave y el mensaje correctamente
*/

void pedirDatos() {
	pedirDato(clave, "la clave", 0);
	ui();
	preguntar("Desea digitar el mensaje? (S)i - (N)o", &resp[0], 's', 'n');
	ui();
	if (resp[0] == 's' || resp[0] == 'S') {
		pedirDato(mensaje, "el mensaje", 1);
	}
	else {
		if (tipo == 'c' || tipo == 'C') {
			strcpy(mensaje, men_cif);
		}
		else {
			strcpy(mensaje, men_des);
		}
	}
}

/*
*   Funcion que contiene otras funciones
*   definidas
*/

void procesarDatos() {
	mensajeT = strlen(mensaje);
	claveFinal(clave, mensajeT);
	printf("\n - Clave      %s\n", clave); // Dato a mostrar al final
	letrasANumeros(clave, mensajeT);
	letrasANumeros(mensaje, mensajeT);
	if (tipo == 'c' || tipo == 'C') {
		cifrar(mensaje, clave);
	}
	else {
		descifrar(mensaje, clave);
	}
}

/*
*    Funcion para mostrar los datos del cifrado
*    o descifrado.
*/

void mostrarDatos() {
	if (tipo == 'c' || tipo == 'C') {
		printf("\n - Cifrado    %s \n \n", mensaje);
	}
	else {
		printf("\n - Descifrado %s  \n \n", mensaje);
	}
}

/*
*		Reiniciar variables.
*		Funcion que reincia todo para que el programa pueda volver
*		a empezar de 0 sin errores. Funciona cuando resp[1] tiene un valor
*/

void reiniciar() {
	if (resp[1] != NULL) {
		tipo = NULL;
		mensajeT = NULL;
		resp[0] = NULL;
		resp[1] = NULL;

		for (int n = strlen(mensaje) + 1; n = 0; n--) {
			mensaje[n] = NULL;
			clave[n] = NULL;
		}
	}
}

void main() {
	crearMatriz();
	do {
		reiniciar();

		ui();
		preguntar("Insertar opcion", &tipo, 'c', 'd');

		ui();
		pedirDatos();

		ui();
		printf("\n - Mensaje    %s \n", mensaje);
		procesarDatos();
		mostrarDatos();

		preguntar("Desea reiniciar el programa. (S)i - (N)o", &resp[1], 's', 'n');
	} while (resp[1] == 's' || resp[1] == 'S');
}