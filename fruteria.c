#include <stdio.h>

int main(){
    float manzanas, uvas, peras, iva, subtotal, total;
    manzanas = 40;
    uvas = 30;
    peras = 30;
    subtotal = uvas + peras + manzanas;
    iva = 16 * 0.01;
    total = (iva * subtotal) + subtotal;

    printf("FRUTERIA - EL INGE\n");
    printf("==================\n");
    printf("1 kg de manzanas = %.1f\n", manzanas);
    printf("1 kg de uvas = %.1f\n", uvas);
    printf("1 kg de peras = %.1f\n\n", peras);

    printf("Subtotal = %.2f\n", subtotal);
    printf("IVA = %.2f\n", iva * subtotal);
    printf("Total = %.2f\n", total);
    
    return 0;
}