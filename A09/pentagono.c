#include <stdio.h>

int main()
{
    float lados;
    
    printf("Ingrese el valor de un lado del pentagono: ");
    scanf("%f", &lados);    

    float apotema = lados / (2 * 0.726542528);
    float perimetro = lados * 6;
    float area = (perimetro * apotema) / 2;

    printf("El area del pentagono es: %.2f\n", area);

    return 0;
}