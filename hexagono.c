#include <stdio.h>

int main()
{
    float lados;
    
    printf("Ingrese el valor de los lados del hexagono: ");
    scanf("%f", &lados);

    float apotema = lados / (2 * 0.57735);
    float perimetro = lados * 6;
    float area = (perimetro * apotema) / 2;

    printf("El area del tu hexagono es: %.2f\n", area);

    return 0;
}