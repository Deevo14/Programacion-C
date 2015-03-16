// Fuente Pregunta I Parcial II
// Nombre y Apellido: Ricardo Rodríguez

/* Explicacion de qué hace y cómo lo hace:

    El programa sirve para saber si un numero es primo, por lo tanto
nos pide que insertemos un numero el cual va a revisar si es primo. El proceso para
revisar si es primo es. 
- Al principio del programa existe una funcion void con paso de parametros que revisa si el numero insertado:
    1- Si el numero insertado es igual a 2 o 3. Por lo cual cumple con el objetivo, ES PRIMO
    2- Si es par el numero insertado. Por lo cual se saca el resto de 2 y si es igual a 0 es par.
       Si lo es mandar el mensaje diciendo que NO CUMPLE con el objetivo.
    3- Y por ultima opcion existe un bucle do-while que comienza en 3 y termina en la raiz cuadrada 
       del numero insertado. Este bucle saca el resto del numero insertado desde 3 hasta su raiz 
       cuadrada para saber si es primo. Si no es primo lo cual algun resto de un numero entre
       (3 - raiz cuadrada de numero insertado) es igual a 0 y NO CUMPLE con el objetivo del programa.
- La funcion main() el cual es la funcion principal del programa realiza:
    1 - Un bucle do-while para reiniciar el programa con una pregunta.
    2 - Y por ultimo la llamada de la funcion void.
    
Por teorema se dice que un numero es primo si no es par y su resto de los numeros 3 hasta la raiz cuadrada no es 0


*/

// Librerias 
#include<stdio.h>
#include<stdlib.h>
#include <math.h> // Libreria de funciones matemátaticas   *** SQRT (num) = Raiz Cuadrada de num ***

// Declaracion de Variables
int aux, num,resto;
char rsp;

// Funciones
void pregunta1(int num)
{
	if (num==2 || num==3)
		printf(" El numero %i  CUMPLE con el objetivo del programa \n" , num);
	else	
	  if ((num%2)== 0)
		printf(" El numero %i  NO CUMPLE con el objetivo del programa \n" , num);
      else
      {
        aux=3;
		       do
		       {
					resto=(num%aux);
					  if (resto==0)
					  {
						printf (" El numero %i  NO CUMPLE con el objetivo del programa \n" , num );
						aux=num;
			           }
			           else
					    aux=aux+1;
				}
                while (aux < sqrt(num));
				if (resto != 0)
				   printf (" El numero %i  CUMPLE con el objetivo del programa \n" , num);
        }
}
// Programa Principal
main()
{
// Ciclo de Repeticion
do
{
		printf("Ingrese el numero para efectuar el proceso \n");
		scanf("%i",&num);
		pregunta1(num);
		printf ("Desea efectuar otro proceso si=s no=n? \n");
		scanf(" %c",&rsp);
}
while (rsp != 'n');
	system("pause");
}
