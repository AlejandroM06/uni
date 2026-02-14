#include <stdio.h>

int main(){
    float manzanas, uvas, peras, iva, subtotal, total;
    iva = 16 * 0.01;

    printf("FRUTERIA - EL INGE\n");
    printf("==================\n");
    printf("Ingrese el precio de 1 kg de manzanas: ");
    scanf("%f", &manzanas);
    printf("Ingrese el precio de 1 kg de uvas: ");
    scanf("%f", &uvas);
    printf("Ingrese el precio de 1 kg de peras: ");
    scanf("%f", &peras);
    printf("\n1 kg de manzanas = %.1f\n", manzanas);
    printf("1 kg de uvas = %.1f\n", uvas);
    printf("1 kg de peras = %.1f\n\n", peras);

    subtotal = uvas + peras + manzanas;
    total = (iva * subtotal) + subtotal;

    printf("Subtotal = %.2f\n", subtotal);
    printf("IVA = %.2f\n", iva * subtotal);
    printf("Total = %.2f\n", total);
    
    return 0;
}