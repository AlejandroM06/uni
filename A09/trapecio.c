#include <stdio.h>

int main()
{
    float baseMayor, baseMenor, altura;
    
    printf("Ingrese el valor de la base mayor del trapecio: ");
    scanf("%f", &baseMayor);    
    printf("Ingrese el valor de la base menor del trapecio: ");
    scanf("%f", &baseMenor);    
    printf("Ingrese el valor de la altura del trapecio: ");
    scanf("%f", &altura);

    float area = ((baseMayor + baseMenor) * altura) / 2;

    printf("El area del trapecio es: %.2f\n", area);

    return 0;
}