#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TOTAL_PREGUNTAS 30
#define PREGUNTAS_MOSTRAR 10

struct Pregunta
{
    const char *tex;
    const char *opciones[3];
};

void examen();
char presentarPregunta(struct Pregunta preguntas, int numero);
int evaluarRespuesta(char respuesta, int correcta);
void calcularCalificacion(int aciertos, int total);

int main()
{
    system("chcp 65001 > nul");
    system("cls");

    char repetir;

    do
    {
        examen();

        do
        {
            printf("\n¿Deseas volver a iniciar el examen? (s/n): ");
            scanf(" %c", &repetir);

            if (repetir >= 'A' && repetir <= 'Z')
                repetir += 'a' - 'A';

            if (repetir != 's' && repetir != 'n')
                printf("!Entrada inválida!. Solo se permite 's' o 'n'.\n");

        } while (repetir != 's' && repetir != 'n');

        system("cls");

    } while (repetir == 's');

    printf("Gracias por realizar el examen. ¡Hasta luego!\n");
    return 0;
}

void examen()
{
    srand(time(NULL));

    struct Pregunta preguntas[TOTAL_PREGUNTAS] = {
        {" ¿Qué función necesita del uso de la biblioteca stdlib.h?",
         {"Sizeof", "System cls", "Scanf"}},
        {" ¿Qué funciones necesitan del uso de la biblioteca conio.h",
         {"For y while", "If, else if y else", "Getch y getche "}},
        {" ¿Cuál de las siguientes variables puede almacenar y manipular carácteres de manera individual?",
         {"Int", "Char", "Float"}},
        {" ¿Cuál de los siguientes símbolos funcionan como operadores relacionales?",
         {"> < >= <=", "+ - / *", "&& || !"}},
        {" ¿Qué es una constante?",
         {"Es una variable que almacenan datos cuyo valor puede cambiar durante la ejecución de un programa", "Es una función que puede almacenar un grupo de variables y ser transportadas a otras partes del código", "Es una variable que almacenan datos cuyo valor se mantiene constante durante la ejecución de un programa"}},
        {" ¿Qué función cumplen los comentarios dentro del código?",
         {"La correcta ejecución del programa", "Interactuar con otros desarrolladores y brindar información e instrucciones", "Ejecutar comandos del sistema para realizar diversas tareas"}},
        {" ¿Cuál de las siguientes opciones es una estructura de control?",
         {"Scanf y fgets", "Int y float", "For y while"}},
        {" ¿Cuál de los siguientes es un paradigma de programación?",
         {"Programación lineal", "Programación orientada a objetos", "Programación de archivos"}},
        {" ¿Qué característica es propia del paradigma imperativo?",
         {"Basarse en la lógica matemática", "Describir cómo se deben ejecutar las instrucciones", "Programar sin utilizar variables"}},
        {" ¿Cuál de los siguientes lenguajes está asociado al paradigma funcional?",
         {"Haskell", "C", "HTML"}},
        {" ¿Qué paradigma se caracteriza por el uso de hechos, reglas y consultas?",
         {"Orientado a objetos", "Declarativo lógico", "Imperativo"}},
        {" ¿Cuál de las siguientes opciones representa un algoritmo?",
         {"Una computadora", "Un conjunto ordenado de pasos", "Un lenguaje de programación"}},
        {" ¿Cuál de los siguientes elementos es necesario para escribir un programa?",
         {"Variables y operadores", "Solo comentarios", "Documentos de Word"}},
        {" ¿Cuál de las siguientes opciones es una estructura condicional?",
         {"for", "if", "do-while"}},
        {" ¿Cuál de las siguientes instrucciones se utiliza para detener un ciclo antes de que termine?",
         {"continue", "break", "do"}},
        {" ¿Qué define mejor a un diagrama de flujo?",
         {"Un dibujo para decorar programas", "Un gráfico con símbolos que representa un algoritmo", "Un archivo de texto sin símbolos"}},
        {" ¿Cuando se creó el modelo de Von Neumann?",
         {"1940", "1930", "1945"}},
        {" ¿Cuáles son los componentes principales del modelo de von Neumann?",
         {"Memoria, dispositivos de entrada y salida, CPU y buses de comunicación", "Memoria, CPU, mouse y monitor", "CPU, teclado, memoria y ALU"}},
        {" ¿Cómo se llama la función que está dentro del CPU que permite realizar operaciones matemáticas y lógicas?",
         {"CU", "ALU", "LUA"}},
        {" ¿Qué hace el CPU?",
         {"Ejecuta instrucciones y procesa datos", "Enfría los componentes de la computadora", "Almacena fotos y videos"}},
        {" ¿Qué es la programación modular?",
         {"Significa que hay que declarar variables globales", "Consiste en repetir código", "Consiste en dividir el programa en archivos o funciones más pequeños y organizados"}},
        {" ¿Cual es la forma correcta de llamar una función?",
         {"Copiar todo el código dentro de donde lo queramos usar", "Escribir el nombre de la función", "Escribirla en un #define"}},
        {" ¿Por qué por lo general se recomienda que cada función tenga una tarea?",
         {"Para que el código sea más largo y se vea profesional", "Para que todas las variables sean globales", "Porque así es más fácil entender, mantener y reutilizar el código"}},
        {"Pregunta 24",
         {"a", "b", "c"}},
        {"Pregunta 25",
         {"a", "b", "c"}},
        {"Pregunta 26",
         {"a", "b", "c"}},
        {"Pregunta 27",
         {"a", "b", "c"}},
        {"Pregunta 28",
         {"a", "b", "c"}},
        {"Pregunta 29",
         {"a", "b", "c"}},
        {"Pregunta 30",
         {"a", "b", "c"}}};

    int aciertos = 0;
    int correctas[TOTAL_PREGUNTAS] = {
        2, 2, 1, 0, 2, 1, 2, 1, 1, 0, 1, 1, 0, 1, 1, 1, 2, 0, 1, 0, 2, 1, 2,
        0, 0, 0, 0, 0, 0, 0};

    int indices[TOTAL_PREGUNTAS];
    for (int i = 0; i < TOTAL_PREGUNTAS; i++)
        indices[i] = i;

    for (int i = TOTAL_PREGUNTAS - 1; i > 0; i--)
    {
        int r = rand() % (i + 1);
        int tmp = indices[i];
        indices[i] = indices[r];
        indices[r] = tmp;
    }

    for (int i = 0; i < PREGUNTAS_MOSTRAR; i++)
    {
        int id = indices[i];

        char respuesta = presentarPregunta(preguntas[id], i + 1);

        aciertos += evaluarRespuesta(respuesta, correctas[id]);

        system("cls");
    }

    calcularCalificacion(aciertos, PREGUNTAS_MOSTRAR);
}

char presentarPregunta(struct Pregunta preguntas, int numero)
{
    char r;

    printf("=== EXAMEN === (Pregunta %d/%d)\n\n", numero, PREGUNTAS_MOSTRAR);
    printf("%s\n", preguntas.tex);

    printf("  a) %s\n", preguntas.opciones[0]);
    printf("  b) %s\n", preguntas.opciones[1]);
    printf("  c) %s\n", preguntas.opciones[2]);

    do
    {
        printf("\nTu respuesta (a/b/c): ");
        scanf(" %c", &r);

        if (r >= 'A' && r <= 'Z')
            r = r + ('a' - 'A');

        if (r != 'a' && r != 'b' && r != 'c')
        {
            printf("⚠ Entrada inválida. Solo se permite a, b o c.\n");
        }

    } while (r != 'a' && r != 'b' && r != 'c');

    return r;
}

int evaluarRespuesta(char respuesta, int correcta)
{
    int valor;
    if (respuesta == 'a')
        valor = 0;
    else if (respuesta == 'b')
        valor = 1;
    else
        valor = 2;

    if (valor == correcta)
        return 1;
    else
        return 0;
}

void calcularCalificacion(int aciertos, int total)
{
    float calificacion = (aciertos * 10.0f) / total;

    printf("===== RESULTADO FINAL =====\n");
    printf("Aciertos: %d de %d\n", aciertos, total);
    printf("Calificación: %.1f\n\n", calificacion);
}