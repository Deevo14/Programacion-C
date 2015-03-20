#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

/*
*	Maximo de caracteres a cifrar
*/

const int MAX_CARACTERES = 40;

/*
*	Lenguaje del programa.
*  Al agregar una ñ o otro caracter el programa
*  se adaptara al nuevo caracter desde su validacion
*  hasta el cifrado o descifrado.
*/

char abecedario[] = "abcdefghijklmnopqrstuvwxyz";

/*
*	Al no desear ingregar un mensaje
*	se utilizara estas variables
*/

char men_cif[MAX_CARACTERES] = "pazyamor";
char men_des[MAX_CARACTERES] = "hokqoxgf";

/*
*	Inicializacion de variables necesarias
*  para el programa
*/

char mensaje[MAX_CARACTERES + 1], clave[MAX_CARACTERES], tipo, resp[2], matriz[sizeof(abecedario) - 1][sizeof(abecedario) - 1];
int mensajeT, abecedarioT = strlen(abecedario);

/*
*	Funcion que crea la matriz de VIGENERE
*/

void crearMatriz() {
	int z = 0;
	for (int n = 0; n < abecedarioT; n++) {
		for (int m = 0; m < abecedarioT; m++) {
			if (n + m < abecedarioT) {
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
*	Funcion de prueba para saber si la matriz
*	se creo correctamente
*/

void mostrarMatriz() {
	crearMatriz();
	for (int n = 0; n < abecedarioT; n++) {
		for (int m = 0; m < abecedarioT; m++) {
			printf(" %c ", matriz[n][m]);
		}
		printf("\n");
	}
}

/*
*	Funcion para obtener la clave final que se usará mediante el procedimiento de VIGENERE
*	EJEMPLO:   ESTAESLAORACIONAENCRIPTAR - ESTAESLACLAVE
*	RESULTADO: ESTAESLACLAVEESTAESLACLAV = CLAVE FINAL
*/

char * claveFinal(char clave[], int tamanio) {
	int claveContador = 0;
	if (strlen(clave) < tamanio) {
		for (int n = 0; n < tamanio; n++) {
			if (claveContador >= strlen(clave)) {
				claveContador = 0;
			}
			clave[n] = clave[claveContador];
			claveContador++;
		}
	}
	else { // Si la clave es mas larga que el mensaje se recortara la clave
		for (int n = 0; n < tamanio; n++) {
			clave[tamanio + n] = 0;
		}
	}
	return clave;
}

/*
*	Funcion bucle que da valores de 0 a abecedarioT
*	de un array de letras
*/

char * letrasANumeros(char cadena[], int tamanio) {
	for (int n = 0; n < tamanio; n++) {
		for (int i = 0; i < abecedarioT; i++) {
			if (cadena[n] == abecedario[i]) {
				cadena[n] = i;
			}
		}
	}
	return cadena;
}

/*
*	Cifrado de VIGENERE por matriz
*  o otros metodos
*/

char * cifrar(char mensaje[], char clave[]) {
	for (int n = 0; n < mensajeT; n++) {

		/*
		*	Metodo de cifrado usando la funcion letrasANumeros y sin
		*	matriz bidimencional. Por formula matematica de VIGENERE.
		*/

		//mensaje[n] = abecedario[(mensaje[n] + clave[n]) % abecedarioT];

		/*
		*  Metodo de cifrado sin usar la funcion letrasANumeros y sin matriz.
		*  Se usa ASCII. Usando las letras minusculas de la tabla ASCII
		*  y lo cual se le resta -97 al caracter a cifrar
		*  --- > Este metodo es el mas eficaz y rapido <----
		*/

		//mensaje[n] = abecedario[((mensaje[n] - 97) + (clave[n] - 97)) % abecedarioT];

		/*
		*	Metodo de cifrado usando array bidimencional con ASCII
		*  o con la funcion letrasANumeros
		*/

		// mensaje[n] = matriz[mensaje[n]-97][clave[n]-97]; // Por ASCII
		mensaje[n] = matriz[mensaje[n]][clave[n]]; // Por la funcion letrasANumeros
	}
	return mensaje;
}

/*
*	Descifrar usando la formula matematica de VIGENERE.
*	 - Si EL mensaje es mayor o igual se suma el caracter del mensaje y el caracter de la clave y se saca el resto de abecedarioT
*		(mensajeCaracterNumerico + claveCaracterNumero) MOD abecedarioT
*
*	 - Si el mensaje es menor, se resta el caracter del mensaje con el caracter de la clave y se suma abecedarioT
*		(mensajeCaracterNumerico - claveCaracterNumero) + abecedarioT
*/

char * descifrar(char mensaje[], char clave[]) {
	for (int n = 0; n < mensajeT; n++) {
		if (mensaje[n] >= clave[n]) {
			mensaje[n] = abecedario[(mensaje[n] - clave[n]) % abecedarioT]; // Por letrasANumeros()
			//mensaje[n] = abecedario[((mensaje[n] - 97) - (clave[n] - 97)) % abecedarioT]; // Por ASCII
		}
		else {
			mensaje[n] = abecedario[(mensaje[n] - clave[n]) + abecedarioT]; // Por letrasANumeros()
			//mensaje[n] = abecedario[((mensaje[n] - 97) - (clave[n] - 97)) % abecedarioT]; // Por ASCII
		}
	}
	return mensaje;
}

/*
*	Funcion que sirve para preguntar por dos opciones de un caracter
*	EJEMPLO:
*	preguntar("¿Deseas continuar con el programa?", variable a retornar (resp), caracter 1 (s), caracter 2 (n))
*/

void preguntar(char pregunta[], char * resp, char p1, char p2) {
	bool validado;
	do {
		printf("\n - %s: ", pregunta);
		fgets(resp, 2, stdin);
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
*	Diseño del programa
*/

void ui() {
	system("cls");
	printf(" ______________________________________________________________________________\n");
	printf("\n                               CIFRADO DE VIGENERE \n");
	printf(" ______________________________________________________________________________\n \n");
	if (tipo == 0) {
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
*	Funcion parecida a isalpha() de ctype.h pero sin usar los valores ascii
*	para que no tire error con la "Ñ" y acentos.
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
Funcion recursiva de esAlpha()
*/

bool esAlphaRecursivo(char caracter, int count = 0) { // Al inicializar la variable count, no es obligatoria ponerla al llamar a la funcion
	if (caracter == abecedario[count]) { // Si el caracter es igual al caracter del abecedario
		return true;
	}
	else if (count == abecedarioT){ // Si el count es el tamaño del abecedario. Por lo que ya reviso todo el abecedario.
		return false;
	}
	else {
		esAlphaRecursivo(caracter, count + 1); // recursividad
	}
}
/*
*	Funcion que pide una cadena
*	con todas las validaciones posibles.
*	Se usa para pedir el mensaje a cifrar o descifrar y la clave
*	 - dato = array a retornar
*	 - nombre = cadena de texto
*	 - cero = 0 si no tiene y 1 si tiene
*/

void pedirDato(char * dato, char * nombre, int cero) {
	bool validado;
	int tamanio;

	do {
		printf("\n - Insertar %s: ", nombre);
		fgets(dato, MAX_CARACTERES + 2 + cero, stdin); // Maximo 40 o 41 caracteres que lee el programa
		validado = true;
		tamanio = strlen(dato) - 1; // -1 ---> ignorar caracter nulo \0

		if (tamanio != 0) {
			for (int n = 0; n < tamanio - cero; n++) {
				dato[n] = tolower(dato[n]); // pasar todo a minusculas para evitar errores
				if (!esAlphaRecursivo(dato[n])) {
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
		dato[tamanio] = 0; // eliminar caracter nulo \0
		if (cero == 1) {
			dato[tamanio - 1] = 0; // Eliminar numero 0 del array
		}
		fflush(stdin); // Limpiar buffer.
	} while (!validado);
}

/*
*   Funcion que tiene otras funciones, para pedir
*	 la clave y el mensaje correctamente
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
	letrasANumeros(clave, mensajeT); /* BORRAR SI SE USA EL CIFRADO Y DESCIFRADO POR ASCII */
	letrasANumeros(mensaje, mensajeT); /* BORRAR SI SE USA EL CIFRADO Y DESCIFRADO POR ASCII */
	if (tipo == 'c' || tipo == 'C') {
		cifrar(mensaje, clave);
	}
	else {
		descifrar(mensaje, clave);
	}
}

/*
*   Funcion para mostrar los datos del cifrado
*   o descifrado.
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
*	Reiniciar variables.
*	Funcion que reincia todo para que el programa pueda volver
*	a empezar de 0 sin errores. Funciona cuando resp[1] tiene un valor
*/

void reiniciar() {
	if (resp[1] != 0) {
		tipo = 0;
		mensajeT = 0;
		resp[0] = 0;
		resp[1] = 0;

		for (int n = strlen(mensaje) + 1; n = 0; n--) {
			mensaje[n] = 0;
			clave[n] = 0;
		}
	}
}

main() {
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
