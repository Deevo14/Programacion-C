/*
    Algoritmos y programacion
    Parcial 3
    Ricardo Rodríguez <ricardo96r@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int num;

void bienvenida() {
    printf("Programa de numeros primos \n \n");
} 

void pedirNumero() {
    do {
        printf("- Insertar un numero entero positivo: ");
        scanf("%d", &num);
        if (num <= 0) {
        printf("- ERROR: el numero insertado no es un entero positivo \n \n");
        }
    } while(num <= 0);
}

bool es_par(int num) {
    if(num%2 == 0) {
        return true;
    } else {
        return false;
    }
}

bool es_primo(int num, int count = 3) {
    if(num == 3 || num == 2) {
        return true;
    } else if(num%count == 0) {
        return false;
    } else if(count != sqrt(num)) {
        return true;
    } else {
        es_primo(num, count+1);
    }
}

void mostrarDatos() {
    if (!es_par(num) || num == 2) {
        if (es_primo(num)) {
        printf("El numero %d es primo", num);
        } else {
        printf("El numero %d no es primo", num);
        }
    } else {
        printf("El numero %d no es primo y es par", num);
    }
}

main() {
    bienvenida();
    pedirNumero();
    mostrarDatos();
    printf("\n \n");
    system("pause");
}
