/*Práctica 10
Sección D02
Montes Domínguez Alejandro
Orozco García Jorge Clemente
Alan David Trujillo Avila
Allan Octavio Lopez Medina*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

#define gotoxy(x, y)                                                    \
    {                                                                   \
        COORD pos;                                                      \
        pos.X = x;                                                      \
        pos.Y = y;                                                      \
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); \
    }

void nombres();
void menu();

int main()
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "Mexico");
    nombres();
    menu();

    return 0;
}

void nombres()
{
    system("cls");
    printf("Práctica 10 - Simulador de Examen\n");
    printf("Sección D02\n");
    printf("Montes Domínguez Alejandro\n");
    printf("Orozco García Jorge Clemente\n");
    printf("Alan David Trujillo Avila\n");
    printf("Allan Octavio Lopez Medina\n\n");
}

void menu()
{
    const int Arriba = 72;
    const int Abajo = 80;
    const int Enter = 13;
    int Tecla;
    int OpcSelect = 1;
    int Salir = 0;
    int x = 55;
    int Nombre;
    int PresentarPregunta;
    int EvaluarRespuesta;
    int CalcularCalificacion;
    char nombre[100];

    for (;;)
    {
        gotoxy(x, 10);
        printf("╔═════════════════════════════════════════════╗");
        gotoxy(x, 11);
        printf("║ Ingresa tu nombre                           ║");
        gotoxy(x, 12);
        printf("╠═════════════════════════════════════════════╣");
        gotoxy(x, 13);
        printf("║                                             ║");
        gotoxy(x, 14);
        printf("╚═════════════════════════════════════════════╝");
        gotoxy(x + 2, 13);
        fgets(nombre, 50, stdin);
        nombre[strcspn(nombre, "\n")] = '\0';
        system("cls");
        printf("Hola %s, tu examen iniciará pronto.\n", nombre);

        Tecla = getch();
        if (Tecla == 0 || Tecla == 224)
        {
            Tecla = getch();
            if (Tecla == Arriba && OpcSelect > 1)
                OpcSelect--;
            if (Tecla == Abajo && OpcSelect < 3)
                OpcSelect++;
        }
        else if (Tecla == Enter)
        {
            switch (OpcSelect)
            {
            case 1:
                break;
            }
        }
    }
}