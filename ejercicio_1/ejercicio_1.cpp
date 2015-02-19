#include <stdio.h>
#include <stdlib.h>

int cedula, rad, cadT, resT, radT, minCedula;
bool validado1, validado2;
float total, totalT, minPago = 4500;
char resp, codigo;

float promedio(float num1, float num2) {
    float promedio;
    num2 = 0 ? promedio = 0 : promedio = num1/num2;
    return promedio;
}

void bienvenida() {
    system("cls");
    printf("Programa sobre pacientes \n %i paciente(s) agregado(s) \n \n", cadT + resT);
}

void pedirDatos() {
    do {
    validado1 = true;
    printf("- Insertar la cedula del paciente: ");
    if (!scanf("%i", &cedula)) {
        printf("-ERROR: dato invalido \n \n");
        validado1 = false;
    }
    fflush(stdin);
    } while(!validado1);
    
    do {
    printf("\n- Insertar el problema del paciente (R/C): ");
    scanf("%c", &codigo);
    if(codigo == 'r' || codigo == 'R' || codigo == 'c' || codigo == 'C') {
        validado2 = true;
    } else {
        printf("- ERROR: dato invalido\n");
        validado2 = false;
    }
    fflush(stdin);
    } while(!validado2);
}

void procesarDatos() {
    if (codigo == 'c' || codigo == 'C') {
        rad = 1;
        cadT++;
    } else {
        rad = 3;
        resT++;
    }
    radT += rad;
    total = rad*1000+1500;
    total = rad == 3 ? (total - total*0.1) : total;
    totalT += total;
    
    // minPago = 4500;
    if (minPago >= total) {
        minPago = total;
        minCedula = cedula;
    }
}

void mostrarDatos() {
    printf("\n- Cedula de identidad: %i  \n", cedula);
    printf("- Tipo de problema: ");
    printf((codigo == 'c' || codigo == 'C') ? "Cardiovascular (C)" : "Respiratorio (R)");
    printf("\n- Numero de radiografias: %i \n", rad);
    printf("- Cantidad a pagar %.2f \n", total);
}

void deseaContinuar(char *resp) {
    bool valid;
    
    do {
    printf("\n- Desea agregar a otro paciente? (S)i - (N)o: ");
    scanf("%c", resp);
    if(*resp == 'n' || *resp == 'N' || *resp == 's' || *resp == 'S') {
        valid = true;
    } else {
        printf("- ERROR: dato invalido\n");
        valid = false;
    }
    fflush(stdin);
    } while (!valid);
}

void mostrarReporte() {
    printf("- Catidad de pacientes por problema Cardiovascular: %i \n", cadT);
    printf("- Catidad de pacientes por problema Respiratorio: %i \n", resT);
    printf("- Cantidad de radiografia ordenadas %i\n", radT);
    printf("- Monto total percibido por las radiografias y honorarios %.2f\n", totalT);
    printf("- Promedio de pago por paciente %.2f \n \n", promedio(totalT, (float)cadT+resT));
    printf("- El paciente que pago menos: \n");
    printf("- Pago: %.2f \n", minPago);
    printf("- Cedula: %i \n \n", minCedula);
}

main() {
    do {
    bienvenida();
    pedirDatos();
    procesarDatos();
    mostrarDatos();
    deseaContinuar(&resp);
    } while (resp == 's' || resp == 'S');
    bienvenida();
    mostrarReporte();
    system("pause");
}
