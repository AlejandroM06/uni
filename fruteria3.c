#include <stdio.h>

int main(){
    float manzanas, uvas, peras, iva, subtotal, total;
    float kiloManz, kiloUva, kiloPera;
    iva = 16 * 0.01;

    printf("\n\nFRUTERIA - EL INGE\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    printf("Ingrese el precio de 1 kg de manzanas: ");
    scanf("%f", &manzanas);
    printf("Ingrese el precio de 1 kg de uvas: ");
    scanf("%f", &uvas);
    printf("Ingrese el precio de 1 kg de peras: ");
    scanf("%f", &peras);
    printf("\nIngrese el numero de kg de manzanas que desea llevar: ");
    scanf("%f", &kiloManz);
    printf("Ingrese el numero de kg de uvas que desea llevar: ");
    scanf("%f", &kiloUva);
    printf("Ingrese el numero de kg de peras que desea llevar: ");
    scanf("%f", &kiloPera);
    printf("\n%.2f kg de manzanas = %.1f\n", kiloManz, manzanas * kiloManz);
    printf("%.2f kg de uvas = %.1f\n", kiloUva, uvas * kiloUva);
    printf("%.2f kg de peras = %.1f\n\n", kiloPera, peras * kiloPera);

    subtotal = (uvas * kiloUva) + (peras * kiloPera) + (manzanas * kiloManz);
    total = (iva * subtotal) + subtotal;

    printf("Subtotal = %.2f pesos\n", subtotal);
    printf("IVA = %.2f pesos\n", iva * subtotal);
    printf("Total = %.2f pesos\n\n", total);
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++++\n\n");
    
    return 0;
}