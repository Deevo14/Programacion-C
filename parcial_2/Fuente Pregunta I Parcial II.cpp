// Fuente Pregunta I Parcial II
// Nombre y Apellido:
// Carnet:
/* Explicacion de qué hace y cómo lo hace:







*/

// Librerias 
#include<stdio.h>
#include<stdib.h>
#include <math.h> // Libreria de funciones matemátaticas   *** SQRT (num) = Raiz Cuadrada de num ***

// Declaracion de Variables
int aux, num,resto;
 rsp;

// Funciones
void pregunta1(int num);
{
	if (num=2 || num=3)
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
					  if resto==0
					  {
						printf (" El numero %i  NO CUMPLE con el objetivo del programa \n" , num );
						aux=num;
			           }
			           else
					    aux=aux+1;
				}
                while aux < sqrt(num);
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
		print("Ingrese el numero para efectuar el proceso \n");
		scanf("%i",&num);
		pregunta1(num);
		printf ("Desea efectuar otro proceso si=s no=n? \n");
		scanf(" %c",&rsp);
}
while (rsp != "n"); 
	system("pause");
}
