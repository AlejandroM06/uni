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
    printf("+++++++++++++++++++++++++\n\n");
    printf("1 kg de manzanas = %.1f\n", manzanas);
    printf("1 kg de uvas = %.1f\n", uvas);
    printf("1 kg de peras = %.1f\n\n", peras);

    printf("Subtotal = %.2f pesos\n", subtotal);
    printf("IVA = %.2f pesos\n", iva * subtotal);
    printf("Total = %.2f pesos\n\n", total);
    printf("+++++++++++++++++++++++++");
    
    return 0;
}