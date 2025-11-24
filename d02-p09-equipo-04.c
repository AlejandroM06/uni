/*Fundamentos de programación
PRÁCTICA 09 – Gestión Avanzada de Viajes en Avión
Sección d02
Equipo 04
Montes Domínguez Alejandro
Orozco García Jorge Clemente
Ramirez Tule David
Ramirez Velazquez Denner Adrian*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

struct Avion
{
    float prec;
    int cap;
    int ocupados;
    int invitados;
    int vacios;
    float ingresos;
    float porcentaje;
};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int menu(int seleccion, float porcentaje, int consoleWidth)
{
    system("cls");
    int y = 2;

    char *linea = "-------------------------------------------";
    int menul = strlen(linea);
    int x = (consoleWidth - menul) / 2;


    gotoxy(x, y++);
    printf("╔═════════════════════════════════════════╗\n");
    gotoxy(x, y++);
    printf("║         Menú - Asientos de avión        ║\n");
    gotoxy(x, y++);
    printf("╠═════════════════════════════════════════╣\n");

    if (seleccion == 1)
    {
        gotoxy(x, y++);
        printf("║ ► 1. Mostrar asientos                   ║\n");
    }
    else
    {
        gotoxy(x, y++);
        printf("║   1. Mostrar asientos                   ║\n");
    }

    if (seleccion == 2)
    {
        gotoxy(x, y++);
        printf("║ ► 2. Vender boleto                      ║\n");
    }
    else
    {
        gotoxy(x, y++);
        printf("║   2. Vender boleto                      ║\n");
    }

    if (seleccion == 3)
    {
        gotoxy(x, y++);
        printf("║ ► 3. Reservar invitado                  ║\n");
    }

    else
    {
        gotoxy(x, y++);
        printf("║   3. Reservar invitado                  ║\n");
    }

    if (seleccion == 4)
    {
        gotoxy(x, y++);
        printf("║ ► 4. Consultar ingresos                 ║\n");
    }
    else
    {
        gotoxy(x, y++);
        printf("║   4. Consultar ingresos                 ║\n");
    }
 if (seleccion == 5)
    {
        gotoxy(x, y++);
        printf("║ ► 5. Datos de los programadores         ║\n");
    }

    else
    {
        gotoxy(x, y++);
        printf("║   5. Datos de los programadores         ║\n");
    }

    if (seleccion == 6)
    {
        gotoxy(x, y++);
        printf("║ ► 6. Salir                              ║\n");
    }

    else
    {
        gotoxy(x, y++);
        printf("║   6. Salir                              ║\n");
    }

    gotoxy(x, y++);
    printf("╚═════════════════════════════════════════╝\n");

    y++;

    char porc[100];
    sprintf(porc, "Ocupación: %.2f%%", porcentaje);
    gotoxy((consoleWidth - strlen(porc)) / 2, y++);
    printf("%s", porc);

    if (porcentaje >= 60.0)
    {
        char *despegue = "¡El avión puede despegar!";
        gotoxy((consoleWidth - strlen(despegue)) / 2, y++);
        printf("%s", despegue);
    }
    else
    {
        char *minn = "El avión despega hasta el 60% \n";
        gotoxy((consoleWidth - strlen(minn)) / 2, y++);
        printf("%s", minn);
    }
    y++;

    return 0;
}

int main()
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "Mexico");

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    consoleWidth = csbi.dwSize.X;

    struct Avion miAvion;
    int cont;

    for (;;)
    {
        system("cls");
        char *men1 = "Ingrese el precio del boleto en Dottocoins: ";
        gotoxy((consoleWidth - strlen(men1)) / 2, 9);
        printf("%s", men1);
        scanf("%f", &miAvion.prec);

        if (miAvion.prec > 0)
        {
            break;
        }
        else
        {
            char *err1 = "Error: El precio debe ser mayor que 0.";
            char *rein = "Presione una tecla para reintentar...";
            gotoxy((consoleWidth - strlen(err1)) / 2, 12);
            printf("%s", err1);
            gotoxy((consoleWidth - strlen(rein)) / 2, 13);
            printf("%s", rein);
        }
        _getch();
    }

    for (;;)
    {

        char *men2 = "Cuál es la capacidad del avión?: ";
        gotoxy((consoleWidth - strlen(men2)) / 2, 11);
        printf("%s", men2);
        scanf("%i", &miAvion.cap);

        if (miAvion.cap > 0)
        {
            break;
        }
        else
        {
            char *err2 = "Error: La capacidad debe ser mayor que 0.";
            char *rein2 = "Presione una tecla para reintentar...";
            gotoxy((consoleWidth - strlen(err2)) / 2, 13);
            printf("%s", err2);
            gotoxy((consoleWidth - strlen(rein2)) / 2, 14);
            printf("%s", rein2);
        }
        _getch();
        system("cls");
    }

    int asiento[miAvion.cap + 1];

    for (cont = 1; cont <= miAvion.cap; cont++)
    {
        asiento[cont] = 0;
    }

    int tecla;
    int seleccion = 1;
    for (;;)
    {
        miAvion.ocupados = 0;
        miAvion.invitados = 0;
        miAvion.vacios = 0;
        miAvion.ingresos = 0;

        for (cont = 1; cont <= miAvion.cap; cont++)
        {
            if (asiento[cont] == 1)
            {
                miAvion.ocupados++;
                miAvion.ingresos += miAvion.prec;
            }
            else if (asiento[cont] == 2)
            {
                miAvion.invitados++;
            }
            else
            {
                miAvion.vacios++;
            }
        }

        miAvion.porcentaje = 0;
        if (miAvion.cap > 0)
        {
            miAvion.porcentaje = ((float)miAvion.ocupados + (float)miAvion.invitados) / (float)miAvion.cap * 100;
        }

        menu(seleccion, miAvion.porcentaje, consoleWidth);

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
                    seleccion = 6;
                }
                break;
            case 80:
                seleccion++;
                if (seleccion > 6)
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
                char *titulo1 = "-------- Estado de asientos --------";
                gotoxy((consoleWidth - strlen(titulo1)) / 2, 2);
                printf("%s\n", titulo1);

                int y = 4;
                for (cont = 1; cont <= miAvion.cap; cont++)
                {
                    char asient[50];
                    sprintf(asient, "Asiento %i: ", cont);

                    int xpos = (consoleWidth - 20) / 2;
                    gotoxy(xpos, y);
                    printf("%s", asient);

                    if (asiento[cont] == 0)
                    {
                        printf("Vacío\n");
                    }
                    else if (asiento[cont] == 1)
                    {
                        printf("Ocupado\n");
                    }
                    else if (asiento[cont] == 2)
                    {
                        printf("Invitado\n");
                    }
                    y++;
                }
                char *conti = "Presiona una tecla para continuar...";
                gotoxy((consoleWidth - strlen(conti)) / 2, y + 2);
                printf("%s", conti);
                break;
            }
            case 2:
            {
                int NumAsi;
                char *titulo2 = "-------- Vender boleto --------";
                gotoxy((consoleWidth - strlen(titulo2)) / 2, 2);
                printf("%s\n", titulo2);

                char comp[100];
                sprintf(comp, "Ingrese el número de asiento a comprar del 1 al %i: ", miAvion.cap);
                gotoxy((consoleWidth - strlen(comp)) / 2, 4);
                printf("%s", comp);
                scanf("%i", &NumAsi);

                char *noex = "Error: este asiento no extiste";
                char *ok = "El boleto se vendió exitosamente";
                char *oc = "Lo sentimos, este asiento ya está ocupado";
                char *re = "Lo sentimos, este asiento ya está reservado";

                if (NumAsi < 1 || NumAsi > miAvion.cap)
                {
                    gotoxy((consoleWidth - strlen(noex)) / 2, 6);
                    printf("%s\n", noex);
                }
                else if (asiento[NumAsi] == 0)
                {
                    asiento[NumAsi] = 1;
                    gotoxy((consoleWidth - strlen(ok)) / 2, 6);
                    printf("%s", ok);
                }
                else if (asiento[NumAsi] == 1)
                {
                    gotoxy((consoleWidth - strlen(oc)) / 2, 6);
                    printf("%s\n", oc);
                }
                else
                {
                    gotoxy((consoleWidth - strlen(re)) / 2, 6);
                    printf("%s\n", re);
                }

                char *conti2 = "Presiona una tecla para continuar...";
                gotoxy((consoleWidth - strlen(conti2)) / 2, 20);
                printf("%s", conti2);
                break;
            }
            case 3:
            {
                int NumAsi;
                char *titulo3 = "-------- Reservar invitado --------";
                gotoxy((consoleWidth - strlen(titulo3)) / 2, 2);
                printf("%s\n", titulo3);

                char res[100];
                sprintf(res, "Ingrese el número de asiento a reservar del 1 al %i: ", miAvion.cap);
                gotoxy((consoleWidth - strlen(res)) / 2, 4);
                printf("%s", res);
                scanf("%i", &NumAsi);

                char *noex2 = "Error: este asiento no extiste";
                char *ok2 = "El boleto se reservó exitosamente";
                char *oc2 = "Lo sentimos, este asiento ya está ocupado";
                char *re2 = "Lo sentimos, este asiento ya está reservado";

                if (NumAsi < 1 || NumAsi > miAvion.cap)
                {
                    gotoxy((consoleWidth - strlen(noex2)) / 2, 6);
                    printf("%s\n", noex2);
                }
                else if (asiento[NumAsi] == 0)
                {
                    asiento[NumAsi] = 2;
                    gotoxy((consoleWidth - strlen(ok2)) / 2, 6);
                    printf("%s", ok2);
                }
                else if (asiento[NumAsi] == 1)
                {
                    gotoxy((consoleWidth - strlen(oc2)) / 2, 6);
                    printf("%s\n", oc2);
                }
                else
                {
                    gotoxy((consoleWidth - strlen(re2)) / 2, 6);
                    printf("%s\n", re2);
                }

                char *conti3 = "Presiona una tecla para continuar...";
                gotoxy((consoleWidth - strlen(conti3)) / 2, 20);
                printf("%s", conti3);
                break;
            }
            case 4:
            {
                char *titulo4 = "-------- Ingresos totales --------";
                gotoxy((consoleWidth - strlen(titulo4)) / 2, 2);
                printf("%s\n", titulo4);

                char dottot[100];
                sprintf(dottot, "Ingresos totales: %.2f Dottocoins", miAvion.ingresos);
                gotoxy((consoleWidth - strlen(dottot)) / 2, 4);
                printf("%s\n", dottot);

                char *conti4 = "Presiona una tecla para continuar...";
                gotoxy((consoleWidth - strlen(conti4)) / 2, 20);
                printf("%s", conti4);
                break;
            }
            case 5:
            {
                system("cls");
                    int y = 2;

    char *info1 = "Fundamentos de programación";
    char *info2 = "PRÁCTICA 09 – Gestión Avanzada de Viajes en Avión";
    char *info3 = "Sección d02";
    char *info4 = "Equipo 04";
    char *info5 = "Montes Domínguez Alejandro";
    char *info6 = "Orozco García Jorge Clemente";
    char *info7 = "Ramirez Tule David";
    char *info8 = "Ramirez Velazquez Denner Adrian";

    gotoxy((consoleWidth - strlen(info1)) / 2, y++);
    printf("%s\n", info1);
    gotoxy((consoleWidth - strlen(info2)) / 2, y++);
    printf("%s\n", info2);
    gotoxy((consoleWidth - strlen(info3)) / 2, y++);
    printf("%s\n", info3);
    gotoxy((consoleWidth - strlen(info4)) / 2, y++);
    printf("%s\n", info4);
    gotoxy((consoleWidth - strlen(info5)) / 2, y++);
    printf("%s\n", info5);
    gotoxy((consoleWidth - strlen(info6)) / 2, y++);
    printf("%s\n", info6);
    gotoxy((consoleWidth - strlen(info7)) / 2, y++);
    printf("%s\n", info7);
    gotoxy((consoleWidth - strlen(info8)) / 2, y++);
    printf("%s\n", info8);


               char *conti5 = "Presiona una tecla para continuar...";
                gotoxy((consoleWidth - strlen(conti5)) / 2, 20);
                printf("%s", conti5);
                break;
            }
                    case 6:
            {
                int yr = 4;
                char *titulo5 = "-------- Resumen de vuelo ---------";
                gotoxy((consoleWidth - strlen(titulo5)) / 2, 2);
                printf("%s\n", titulo5);

                char o[50], i[50], v[50], t[100];
                sprintf(o, "Asientos ocupados: %i", miAvion.ocupados);
                sprintf(i, "Invitados: %i", miAvion.invitados);
                sprintf(v, "Asientos vacíos: %i", miAvion.vacios);
                sprintf(t, "Ingresos totales en Dottocoins: %.2f", miAvion.ingresos);

                gotoxy((consoleWidth - strlen(o)) / 2, yr++);
                printf("%s\n", o);
                gotoxy((consoleWidth - strlen(i)) / 2, yr++);
                printf("%s\n", i);
                gotoxy((consoleWidth - strlen(v)) / 2, yr++);
                printf("%s\n", v);
                yr++;
                gotoxy((consoleWidth - strlen(t)) / 2, yr++);
                printf("%s\n\n", t);

                yr++;
                char *conti6 = "Presiona una tecla para salir del programa...";
                gotoxy((consoleWidth - strlen(conti6)) / 2, yr++);
                printf("%s\n", conti6);

                _getch();
                return 0;
            }
            }

            _getch();
        }
    }

    return 0;
}
