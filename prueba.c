#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

int respuesta = 0;
int aciertos = 0;
char opc[100];

int presentarPregunta(char pregunta[], char a[], char b[], char c[])
{
    system("cls");
    printf("%s\n\n", pregunta);
    printf("A) %s\n", a);
    printf("B) %s\n", b);
    printf("C) %s\n", c);
    printf("\nRespuesta: ");

    for(;;)
    {
        scanf(" %c", opc);

        if(opc[0]=='A')
        {
            break;
        }

        else if(opc[0]=='B')
        {
            break;
        }

        else if(opc[0]=='C')
        {
            break;
        }
        else
        {
            printf("Opción no válida...");
            getch();
        }
    }

    return 0;
}

int evaluarRespuesta(char correcta)
{
    if(opc[0]==correcta)
    {
        respuesta=1;
    }
    else
    {
        respuesta=0;
    }

    if (respuesta==1)
    {
        aciertos++;
    }

    return 0;
}

int calcularCalificacion()
{
    system("cls");
    printf("Tuviste %i aciertos de 10",aciertos);
    getch();

    return 0;
}

int main()
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "Mexico");
    srand(time(NULL));

    char nombre[50];

    char *preguntas[30] = {
        "¿Qué función necesita del uso de la biblioteca stdlib.h?",
        "¿Qué funciones necesitan del uso de la biblioteca conio.h?",
        "¿Cuál de las siguientes variables puede almacenar y manipular carácteres de manera individual?",
        "¿Cuál de los siguientes símbolos funcionan como operadores relacionales?",
        "¿Qué es una constante?",
        "¿Qué función cumplen los comentarios dentro del código?",
        "¿Cuál de las siguientes opciones es una estructura de control?",
        "¿Cuál de los siguientes es un paradigma de programación?",
        "¿Qué característica es propia del paradigma imperativo?",
        "¿Cuál de los siguientes lenguajes está asociado al paradigma funcional?",
        "¿Qué paradigma se caracteriza por el uso de hechos, reglas y consultas?",
        "¿Cuál de las siguientes opciones representa un algoritmo?",
        "¿Cuál de los siguientes elementos es necesario para escribir un programa?",
        "¿Cuál de las siguientes opciones es una estructura condicional?",
        "¿Cuál de las siguientes instrucciones se utiliza para detener un ciclo antes de que termine?",
        "¿Qué define mejor a un diagrama de flujo?",
        "¿Cuando se creó el modelo de Von Neumann?",
        "¿Cuáles son los componentes principales del modelo de von Neumann?",
        "¿Cómo se llama la función que está dentro del CPU que permite realizar operaciones matemáticas y lógicas?",
        "¿Qué hace el CPU?",
        "¿Qué es la programación modular?",
        "¿Cual es la forma correcta de llamar una función?",
        "¿Por qué por lo general se recomienda que cada función tenga una tarea?",
        "¿Que forma se utiliza en un diagrama de flujo para representar una decisición o un if?",
        "Cual es la función del pseudocódigo en programación?",
        "¿Para qué sirven los lenguajes en programación?",
        "¿Cuál es la diferencia entre software y hardware?",
        "¿Hacia qué dirección va un diagrama de flujo?",
        "¿Cuál es el código que se maneja mediante ceros y unos?",
        "¿Qué forma se utiliza en un diagrama de flujo para representar un proceso interno u operaciones?"
    };

    char *opcA[30] = {
        "Sizeof", "For y while", "Int",
        "> < >= <=", "Es una variable que almacenan datos cuyo valor puede cambiar durante la ejecución de un programa", "La correcta ejecución del programa",
        "Scanf y fgets", "Programación lineal", "Basarse en la lógica matemática",
        "Haskell", "Orientado a objetos", "Una computadora",
        "Variables y operadores", "for", "continue",
        "Un dibujo para decorar programas", "1940", "Memoria, dispositivos de entrada y salida, CPU y buses de comunicación.",
        "CU", "Ejecuta instrucciones y procesa datos.", "Significa que hay que declarar variables globales.",
        "Copiar todo el código dentro de donde lo queramos usar.", "Para que el código sea más largo y se vea profesional.", "Rombo",
        "Representar la idea del código mediante un algoritmo y procesos", "para comunicarnos verbalmente con los demás", "El hardware son procesos internos de una computadora y el software es la parte física que hace que todo maquine",
        "Arriba", "lenguaje", "Rombo"
    };

    char *opcB[30] = {
        "System cls", "If, else if y else", "Char",
        "+ - / *", "Es una función que puede almacenar un grupo de variables y ser transportadas a otras partes del código", "Interactuar con otros desarrolladores y brindar información e instrucciones",
        "Int y float", "Programación orientada a objetos", "Describir cómo se deben ejecutar las instrucciones",
        "C", "Declarativo lógico", "Un conjunto ordenado de pasos",
        "Solo comentarios", "if", "break",
        "Un gráfico con símbolos que representa un algoritmo", "1930", "Memoria, CPU, mouse y monitor.",
        "ALU", "Enfría los componentes de la computadora.", "Consiste en repetir código.",
        "Escribir el nombre de la función.", "Para que todas las variables sean globales.", "Circulo",
        "Empezar a desarrollar el código", "Para crear código mediante la programación", "El software se refiere a los procesos internos de una computadora y el hardware a la parte física que hace que todo maquine",
        "Los lados", "Pseudocódigo", "Círculo"
    };

    char *opcC[30] = {
        "Scanf", "Getch y getche", "Float",
        "&& || !", "Es una variable que almacenan datos cuyo valor se mantiene constante durante la ejecución de un programa", "ejecutar comandos del sistema para realizar diversas tareas",
        "For y while", "Programación de archivos", "Programar sin utilizar variables",
        "HTML", "Imperativo", "Un lenguaje de programación",
        "Documentos de Word", "do-while", "do",
        "Un archivo de texto sin símbolos", "1945", "CPU, teclado, memoria y ALU.",
        "LUA", "Almacena fotos y videos.", "Consiste en dividir el programa en archivos o funciones más pequeños y organizados.",
        "Escribirla en un #define.", "Porque así es más fácil entender, mantener y reutilizar el código.", "Rectangulo",
        "Escribir la función de nuestro código y su objetivo", "Para aprender un nuevo idioma", "El hardware se refiere a la memoria de una computadora únicamente, mientras que el software es la batería.",
        "Abajo", "Código binario", "Rectángulo"
    };

    char respuestasCorrectas[30] = {
        'B', 'C', 'B',
        'A', 'C', 'B',
        'C', 'B', 'B',
        'A', 'B', 'B',
        'A', 'B', 'B',
        'B', 'C', 'A',
        'B', 'A', 'C',
        'B', 'C', 'A',
        'A', 'B', 'B',
        'C', 'C', 'C'
    };

    printf("Práctica 10 - Simulador de Examen\n");
    printf("Sección D02\n");
    printf("Montes Domínguez Alejandro\n");
    printf("Orozco García Jorge Clemente\n");
    printf("Alan David Trujillo Avila\n");
    printf("Allan Octavio Lopez Medina\n\n");
    printf("Presione una tecla para continuar...");
    getch();
    system("cls");

    printf("Cuál es tu nombre? ");
    fgets(nombre,50,stdin);

    printf("Presione una tecla para empezar el examen, ¡Éxito!");
    getch();
    system("cls");


    for(;;)
    {
        aciertos = 0;
        int preguntasRealizadas[30] = {0};
        int contador = 0;

        while(contador < 10)
        {
            int indiceAleatorio = rand() % 30;

            if(preguntasRealizadas[indiceAleatorio] == 0)
            {
                presentarPregunta(preguntas[indiceAleatorio], opcA[indiceAleatorio], opcB[indiceAleatorio], opcC[indiceAleatorio]);

                evaluarRespuesta(respuestasCorrectas[indiceAleatorio]);

                preguntasRealizadas[indiceAleatorio] = 1;
                contador++;
            }
        }

        calcularCalificacion();

        for(;;)
        {
            system("cls");
            char deci;
            printf("¿Quieres repetir el examen?(Escoge (s) ó (n)) ");
            scanf(" %c", &deci);

            if(deci=='s')
            {
                system("cls");
                break;
            }

            else if(deci=='n')
            {
                system("cls");
                printf("Hasta luego!");
                getch();
                return 0;
            }

            else
            {
                system("cls");
                printf("Opción no válida...");
                getch();
            }
        }

    }


    return 0;
}
