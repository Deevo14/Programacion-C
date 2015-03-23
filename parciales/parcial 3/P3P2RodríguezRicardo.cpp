/*
    Algoritmos y programacion
    Parcial 3
    Ricardo Rodríguez <ricardo96r@gmail.com>
*/

#include <stdio.h>
#include <stdlib.h>

int ordsel[4][4]={{12,11,10,9},{1,15,13,8},{2,6,3,7},{14,4,5,16}};

void mostrarMatriz(int ordsel[4][4]) {
    for (int n = 0; n < 4; n++) {
        for (int m = 0; m < 4; m++) {
            printf("%d \t", ordsel[n][m]);
        }
        printf("\n");
    }
}

void ordenarMatriz(int ordsel[4][4]) {
    int fmenor, cmenor, ia, aux;
    
    for(int n = 0; n < 4; n++) {
        for(int m = 0; m  < 4; m++) {
        fmenor = m;
        cmenor = n;
        ia = m;
        for(int k = n; k < 4; k++) {
             for (int j = ia; j < 4; j++) {
                  if (ordsel[fmenor][cmenor] > ordsel[j][k]) {
                      fmenor = j;
                      cmenor = k;
                  }
             }
             ia = 0;
        }
        aux = ordsel[m][n];
        ordsel[m][n] = ordsel[fmenor][cmenor];
        ordsel[fmenor][cmenor] = aux;
        }
    }
}

main() {
    printf("MATRIZ ORIGINAL\n \n");
    mostrarMatriz(ordsel);
    ordenarMatriz(ordsel);
    printf("\n______________________________________\n \n");
    printf("MATRIZ ORDENADA \n \n");
    mostrarMatriz(ordsel);
    printf("\n");
    system("pause");
}
