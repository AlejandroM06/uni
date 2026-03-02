#include <stdio.h>
#include <math.h>

int main()
{
    double lados;
    
    printf("Ingrese el valor de los lados del hexagono: ");
    scanf("%lf", &lados);

    double apotema = lados / (2 * (tan(0.523599)));
    double perimetro = lados * 6;
    double area = (perimetro * apotema) / 2;

    printf("El area del tu hexagono es: %.2lf\n", area);

    return 0;
}