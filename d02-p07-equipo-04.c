#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

int menu(int seleccion)
{
    system("cls");
    printf("-------------------------------------------\n");
    printf("|        Men� - Asientos de avi�n         |\n");
    printf("-------------------------------------------\n");

    if (seleccion == 1)
    {
        printf("|    1. Mostrar asientos <<               |\n");
    }
    else
    {
        printf("|    1. Mostrar asientos                  |\n");
    }

    if (seleccion == 2)
    {
        printf("|    2. Vender boleto <<                  |\n");
    }
    else
    {
        printf("|    2. Vender boleto                     |\n");
    }

    if (seleccion == 3)
    {
        printf("|    3. Reservar invitado <<              |\n");
    }
    else
    {
        printf("|    3. Reservar invitado                 |\n");
    }

    if (seleccion == 4)
    {
        printf("|    4. Consultar ingresos <<             |\n");
    }
    else
    {
        printf("|    4. Consultar ingresos                |\n");
    }

    if (seleccion == 5)
    {
        printf("|    5. Salir <<                          |\n");
    }
    else
    {
        printf("|    5. Salir                             |\n");
    }

    printf("-------------------------------------------\n");

    printf("\nFundamentos de programaci�n\n");
    printf("Pr�ctica 7: Uso de la Iteraci�n - for\n");
    printf("Secci�n d02\n");
    printf("Equipo 04\n");
    printf("Montes Dominguez Alejandro\n");
    printf("Orozco Garcia Jorge Clemente\n");
    printf("Ramirez Tule David\n");
    printf("Ramirez Velazquez Denner Adrian\n\n");
    return 0;
}

int main()
{

    system("chcp 65001 > nul");
    setlocale(LC_ALL, "Mexico");

    float prec;
    int cap;
    int cont;

    printf("Ingrese el precio del boleto en Dottocoins: ");
    scanf("%f", &prec);
    printf("Cu�l es la capacidad del avi�n?: ");
    scanf("%i", &cap);
    int asiento[cap];

    for (cont = 1; cont <= cap; cont++)
    {
        asiento[cont] = 0;
    }

    int tecla;
    int seleccion = 1;
    for (;;)
    {

        menu(seleccion);

        tecla = _getch();
        if (tecla == 224)
        {
            tecla = _getch();
            switch (tecla)
            {
            case 72:
                seleccion--;
                if (seleccion < 1)
                {
                    seleccion = 5;
                }
                break;
            case 80:
                seleccion++;
                if (seleccion > 5)
                {
                    seleccion = 1;
                }
                break;
            }
        }
        else if (tecla == 13)
        {
            system("cls");
            switch (seleccion)
            {
            case 1:
            {
                printf("-------- Estado de asientos --------\n");
                int cont;
                for (cont = 1; cont <= cap; cont++)
                {
                    printf("Asiento %i: ", cont);
                    if (asiento[cont] == 0)
                    {
                        printf("Vac�o\n");
                    }
                    else if (asiento[cont] == 1)
                    {
                        printf("Ocupado\n");
                    }
                    else if (asiento[cont] == 2)
                    {
                        printf("Invitado\n");
                    }
                }
                break;
            }
            case 2:
            {
                int NumAsi;
                printf("-------- Vender boleto --------\n");
                printf("Ingrese el n�mero de asiento a comprar del 1 al %i: ", cap);
                scanf("%i", &NumAsi);

                if (NumAsi < 1 || NumAsi > cap)
                {
                    printf("Error: este asiento no extiste\n");
                }
                else if (asiento[NumAsi] == 0)
                {
                    asiento[NumAsi] = 1;
                    printf("El boleto se vendi� exitosamente");
                }
                else if (asiento[NumAsi] == 1)
                {
                    printf("Lo sentimos, este asiento ya est� ocupado\n", NumAsi);
                }
                else
                {
                    printf("Lo sentimos, este asiento ya est� reservado\n", NumAsi);
                }
                break;
            }
            case 3:
            {
                int NumAsi;
                printf("-------- Reservar invitado --------\n");
                printf("Ingrese el n�mero de asiento a reservar del 1 al %i: ", cap);
                scanf("%i", &NumAsi);

                if (NumAsi < 1 || NumAsi > cap)
                {
                    printf("Error: este asiento no extiste\n");
                }
                else if (asiento[NumAsi] == 0)
                {
                    asiento[NumAsi] = 2;
                    printf("El boleto se reserv� exitosamente");
                }
                else if (asiento[NumAsi] == 1)
                {
                    printf("Lo sentimos, este asiento ya est� ocupado\n", NumAsi);
                }
                else
                {
                    printf("Lo sentimos, este asiento ya est� reservado\n", NumAsi);
                }
                break;
            }
            case 4:
            {
                float TotIngresos = 0;
                int cont;
                for (cont = 1; cont <= cap; cont++)
                {
                    if (asiento[cont] == 1)
                    {
                        TotIngresos += prec;
                    }
                }

                printf("-------- Ingresos totales --------\n");
                printf("Ingresos totales: %.2f Dottocoins\n", TotIngresos);
                break;
            }
            case 5:
            {
                float IngFin = 0;
                int ocupados = 0;
                int invitados = 0;
                int vacios = 0;
                int cont;
                for (cont = 1; cont <= cap; cont++)
                {
                    if (asiento[cont] == 0)
                    {
                        vacios++;
                    }
                    else if (asiento[cont] == 1)
                    {
                        IngFin += prec;
                        ocupados++;
                    }
                    else if (asiento[cont] == 2)
                    {
                        invitados++;
                    }
                }

                printf("-------- Resumen de vuelo ---------\n");
                printf("Asientos ocupados: %i\n", ocupados);
                printf("Invitados: %i\n", invitados);
                printf("Asientos vac�os: %i\n", vacios);
                printf("Ingresos totales en Dottocoins: %.2f\n\n", IngFin);

                printf("Presiona una tecla para salir del programa...\n");

                _getch();
                return 0;
            }
            }

            _getch();
        }
    }

    return 0;
}