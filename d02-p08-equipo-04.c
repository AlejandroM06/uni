#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

typedef struct
{
    int cap;
    int ocupados;
    int invitados;
    float porcentaje;
    float ingresos;
    float precio;
    char *estado;
} Avion;

void gotoxy(int x, int y);
void dibujarMenu();
void mostrarOpciones(int opcion);
void menu(Avion *Avion, int opcion);
void inicializarAvion(Avion *Avion);
void mostrarDatosAvion(Avion *Avion);
void mostrarAsientos(Avion *Avion);
void venderBoleto(Avion *Avion);
void reservarInvitado(Avion *Avion);
void consultarIngresos(Avion *Avion);
void resumenFinal(Avion *Avion);
void actualizarPorcentaje(Avion *Avion);

int main()
{
    system("chcp 65001 > nul");
    system("cls");

    Avion Avion;
    inicializarAvion(&Avion);
    system("cls");
    dibujarMenu();
    mostrarDatosAvion(&Avion);
    menu(&Avion, 0);

    free(Avion.estado);
    return 0;
}

void gotoxy(int x, int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void dibujarMenu()
{
    system("cls");
    printf("\n\n                ================================\n");
    printf("                |        MENÚ PRINCIPAL        |\n");
    printf("                --------------------------------\n");
    for (int i = 0; i < 6; i++)
        printf("                |                              |\n");
    printf("                --------------------------------\n");
    printf("\n                Usa ↑ ↓ para navegar. ENTER para seleccionar.\n");
}

void mostrarOpciones(int opcion)
{
    char *opciones[] = {
        "Mostrar asientos",
        "Vender boleto",
        "Reservar invitado",
        "Consultar ingresos",
        "Salir"};

    for (int i = 0; i < 5; i++)
    {
        gotoxy(18, 6 + i);
        if (i == opcion)
            printf("➤ %-22s", opciones[i]);
        else
            printf("  %-22s", opciones[i]);
    }
}

void menu(Avion *Avion, int opcion)
{
    mostrarOpciones(opcion);
    mostrarDatosAvion(Avion);

    int tecla = getch();
    if (tecla == 224)
    {
        tecla = getch();
        switch (tecla)
        {
        case 72:
            opcion = (opcion - 1 + 5) % 5;
            break;
        case 80:
            opcion = (opcion + 1) % 5;
            break;
        }
        menu(Avion, opcion);
    }
    else if (tecla == 13)
    {
        system("cls");
        switch (opcion)
        {
        case 0:
            mostrarAsientos(Avion);
            break;
        case 1:
            venderBoleto(Avion);
            break;
        case 2:
            reservarInvitado(Avion);
            break;
        case 3:
            consultarIngresos(Avion);
            break;
        case 4:
            resumenFinal(Avion);
            return;
        }
        printf("\nPresione cualquier tecla para volver al menú...");
        getch();
        dibujarMenu();
        menu(Avion, opcion);
    }
    else
    {
        menu(Avion, opcion);
    }
}

void inicializarAvion(Avion *Avion)
{
    char input[50];
    float temp;

    printf("=== AVIÓN ===\n");
    printf("Capacidad total del avión: ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%f", &temp) != 1 || temp <= 0)
    {
        printf("Error: ingrese un número entero positivo.\n");
        inicializarAvion(Avion);
        return;
    }

    Avion->cap = (int)temp;
    if (Avion->cap <= 0)
    {
        printf("Error: la capacidad debe ser mayor a 0.\n");
        inicializarAvion(Avion);
        return;
    }

    Avion->estado = (char *)malloc(Avion->cap * sizeof(char));
    if (Avion->estado == NULL)
    {
        printf("Error: no se pudo asignar memoria.\n");
        exit(1);
    }

    printf("Precio del boleto (dottocoins): ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%f", &Avion->precio) != 1 || Avion->precio <= 0)
    {
        printf("Error: el precio debe ser un número positivo.\n");
        free(Avion->estado);
        inicializarAvion(Avion);
        return;
    }

    for (int i = 0; i < Avion->cap; i++)
        Avion->estado[i] = 'V';

    Avion->ocupados = 0;
    Avion->invitados = 0;
    Avion->ingresos = 0;
    Avion->porcentaje = 0.0;
}

void mostrarDatosAvion(Avion *Avion)
{
    gotoxy(18, 14);
    printf("Capacidad total: %d asientos", Avion->cap);
    gotoxy(18, 15);
    printf("Precio por boleto: %.2f dottocoins\n", Avion->precio);
    gotoxy(18, 16);
    printf("Boletos vendidos: %d", Avion->ocupados);
    gotoxy(18, 17);
    printf("Invitados: %d", Avion->invitados);
    gotoxy(18, 18);
    printf("Porcentaje de ventas: %.2f%%", Avion->porcentaje);
    gotoxy(18, 19);
    printf("Ingresos totales: %.2f dottocoins", Avion->ingresos);

    gotoxy(18, 21);
    if (Avion->porcentaje >= 60)
        printf("¡Se alcanzó el 60%% de ventas, el vuelo puede continuar!");
    else
        printf("No hay ventas suficientes para que el avión pueda despegar.");
}

void mostrarAsientos(Avion *Avion)
{
    printf("=== ESTADO DE ASIENTOS ===\n");
    printf("V = Vacío, O = Ocupado, I = Invitado\n\n");
    for (int i = 0; i < Avion->cap; i++)
    {
        printf("[%c] ", Avion->estado[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    printf("\n");
}

void venderBoleto(Avion *Avion)
{
    int asiento;
    mostrarAsientos(Avion);

    printf("\nSeleccione el número de asiento (1-%d): ", Avion->cap);
    scanf("%d", &asiento);

    if (asiento < 1 || asiento > Avion->cap)
    {
        printf("Error: número de asiento inválido.\n");
        return;
    }
    if (Avion->estado[asiento - 1] != 'V')
    {
        printf("Error: el asiento ya está ocupado o reservado.\n");
        return;
    }

    Avion->estado[asiento - 1] = 'O';
    Avion->ocupados++;
    Avion->ingresos += Avion->precio;
    actualizarPorcentaje(Avion);

    printf("¡Boleto vendido exitosamente! Asiento %d ocupado.\n", asiento);
}

void reservarInvitado(Avion *Avion)
{
    int asiento;
    mostrarAsientos(Avion);

    printf("\nSeleccione el número de asiento (1-%d): ", Avion->cap);
    scanf("%d", &asiento);

    if (asiento < 1 || asiento > Avion->cap)
    {
        printf("Error: número de asiento inválido.\n");
        return;
    }
    if (Avion->estado[asiento - 1] != 'V')
    {
        printf("Error: el asiento ya está ocupado o reservado.\n");
        return;
    }

    Avion->estado[asiento - 1] = 'I';
    Avion->invitados++;
    actualizarPorcentaje(Avion);

    printf("¡Invitado registrado exitosamente! Asiento %d reservado.\n", asiento);
}

void consultarIngresos(Avion *Avion)
{
    printf("=== CONSULTAR INGRESOS ===\n");
    printf("Boletos vendidos: %d\n", Avion->ocupados);
    printf("Invitados: %d\n", Avion->invitados);
    printf("Precio por boleto: %.2f dottocoins\n", Avion->precio);
    printf("Ingreso total: %.2f dottocoins\n", Avion->ingresos);
    printf("Porcentaje de ocupación: %.2f%%\n", Avion->porcentaje);
}

void resumenFinal(Avion *Avion)
{
    int libres = Avion->cap - Avion->ocupados - Avion->invitados;
    system("cls");
    printf("=====================================\n");
    printf("           RESUMEN DEL Avion         \n");
    printf("=====================================\n");
    printf("Boletos vendidos: %d\n", Avion->ocupados);
    printf("Precio por boleto: %.2f dottocoins\n", Avion->precio);
    printf("Invitados: %d\n", Avion->invitados);
    printf("Asientos libres: %d\n", libres);
    printf("Ganancia total: %.2f dottocoins\n", Avion->ingresos);
    printf("=====================================\n");
    printf("Gracias por usar.\n");
}

void actualizarPorcentaje(Avion *Avion)
{
    Avion->porcentaje = ((float)Avion->ocupados / Avion->cap) * 100.0;
}