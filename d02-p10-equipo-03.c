/*Práctica 10 - Examen
Sección D02
Equipo: 3
Lopez Medina Allan Octavio
Montes Domínguez Alejandro
Orozco García Jorge Clemente
Trujillo Avila Alan David*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define TOTAL_PREGUNTAS 30
#define PREGUNTAS_MOSTRAR 10
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Pregunta
{
    const char *tex;
    const char *opciones[3];
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void equipo();
void registro();
void examen();
char presentarPregunta(struct Pregunta preguntas, int numero);
int evaluarRespuesta(char respuesta, int correcta);
void calcularCalificacion(int aciertos, int total, struct Pregunta preguntas[]);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char nombreCompleto[100];
int aciertosPregunta = 0;
int preguntasSeleccionadas[PREGUNTAS_MOSTRAR];
int respuestasCorrectas[PREGUNTAS_MOSTRAR];
const char *mostrarRetroalimentacion[TOTAL_PREGUNTAS];
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    system("chcp 65001 > nul");
    system("cls");

    char repetir;

    do
    {
        equipo();
        registro();
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

        int c;
        while ((c = getchar()) != '\n' && c != EOF)
        {
        }

        system("cls");

    } while (repetir == 's');

    printf("Gracias por realizar el examen. ¡Hasta luego!\n");
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
        {" ¿Qué forma se utiliza en un diagrama de flujo para representar una decisión o un if?",
         {"Rombo", "Círculo", "Rectángulo"}},
        {" ¿Cuál es la función del pseudocódigo en programación?",
         {"Representar la idea del código mediante un algoritmo y procesos.", "Empezar a desarrollar el código.", "Escribir la función de nuestro código y su objetivo."}},
        {" ¿Para qué sirven los lenguajes en programación?",
         {"Para comunicarnos verbalmente con los demás.", "Para crear código mediante la programación.", "Para aprender un nuevo idioma."}},
        {" ¿Cuál es la diferencia entre software y hardware?",
         {"El hardware son procesos internos de una computadora y el software es la parte física que hace que todo maquine.", "El software se refiere a los procesos internos de una computadora y el hardware a la parte física que hace que todo maquine", "El hardware se refiere a la memoria de una computadora únicamente, mientras que el software es la batería."}},
        {" ¿Hacia qué dirección va un diagrama de flujo?",
         {"Arriba", "Los dos lados", "Hacia abajo y de izquierda a derecha"}},
        {" ¿Cuál es el código que se maneja mediante ceros y unos?",
         {"Lenguaje", "Pseudocódigo", "Código binario"}},
        {" ¿Qué forma se utiliza en un diagrama de flujo para representar un proceso interno u operaciones?",
         {"Rombo", "Cículo", "Rectángulo"}}};

    mostrarRetroalimentacion[0] = "Respuesta correcta: Opción B. Ya que una de las funciones de stdlib.h es controlar el entorno de ejecución del programa y que el programa sea limpiado correctamente para seguir ejecutándose.";
    mostrarRetroalimentacion[1] = "Respuesta correcta: Opción C. La biblioteca conio.h es utilizada para operaciones de entrada/salida en lenguaje C.";
    mostrarRetroalimentacion[2] = "Respuesta correcta: Opción B. Este tipo de dato puede almacenar carácteres individualmente y se le puede asignar un tamaño determinado para arreglos.";
    mostrarRetroalimentacion[3] = "Respuesta correcta: Opción A. Los operadores relacionales comparan dos valores y determinan si la relación es verdadera o falsa.";
    mostrarRetroalimentacion[4] = "Respuesta correcta: Opción C. Las constantes son valores fijos declarados usualmente con #define.";
    mostrarRetroalimentacion[5] = "Respuesta correcta: Opción B. Los comentarios permiten documentar el código y facilitar la colaboración entre desarrolladores.";
    mostrarRetroalimentacion[6] = "Respuesta correcta: Opción C. For y while son estructuras de control utilizadas para realizar ciclos.";
    mostrarRetroalimentacion[7] = "Respuesta correcta: Opción B. La programación orientada a objetos organiza el código en clases y objetos.";
    mostrarRetroalimentacion[8] = "Respuesta correcta: Opción B. El paradigma imperativo describe paso a paso cómo deben ejecutarse las instrucciones.";
    mostrarRetroalimentacion[9] = "Respuesta correcta: Opción A. Haskell es un lenguaje funcional basado en funciones matemáticas.";
    mostrarRetroalimentacion[10] = "Respuesta correcta: Opción B. El paradigma lógico utiliza hechos y reglas, como en Prolog.";
    mostrarRetroalimentacion[11] = "Respuesta correcta: Opción B. Un algoritmo es un conjunto ordenado de pasos para resolver un problema.";
    mostrarRetroalimentacion[12] = "Respuesta correcta: Opción A. Las variables permiten almacenar datos y los operadores manipularlos.";
    mostrarRetroalimentacion[13] = "Respuesta correcta: Opción B. La estructura if ejecuta código dependiendo de si se cumple una condición.";
    mostrarRetroalimentacion[14] = "Respuesta correcta: Opción B. break finaliza un ciclo inmediatamente.";
    mostrarRetroalimentacion[15] = "Respuesta correcta: Opción B. Un diagrama de flujo representa un algoritmo mediante símbolos estandarizados.";
    mostrarRetroalimentacion[16] = "Respuesta correcta: Opción C. En 1945, Von Neumann definió la arquitectura moderna de computadoras.";
    mostrarRetroalimentacion[17] = "Respuesta correcta: Opción A. Incluye memoria, CPU, dispositivos de E/S y buses.";
    mostrarRetroalimentacion[18] = "Respuesta correcta: Opción B. La ALU ejecuta operaciones aritméticas y lógicas.";
    mostrarRetroalimentacion[19] = "Respuesta correcta: Opción A. El CPU ejecuta instrucciones y procesa datos.";
    mostrarRetroalimentacion[20] = "Respuesta correcta: Opción C. La programación modular divide el programa en partes pequeñas y organizadas.";
    mostrarRetroalimentacion[21] = "Respuesta correcta: Opción B. Para llamar una función solo se escribe su nombre y paréntesis.";
    mostrarRetroalimentacion[22] = "Respuesta correcta: Opción C. Mantener funciones pequeñas facilita mantenimiento, legibilidad y reutilización.";
    mostrarRetroalimentacion[23] = "Respuesta correcta: Opción A. El rombo representa decisiones en diagramas de flujo.";
    mostrarRetroalimentacion[24] = "Respuesta correcta: Opción A. El pseudocódigo representa ideas y procesos del algoritmo.";
    mostrarRetroalimentacion[25] = "Respuesta correcta: Opción B. Los lenguajes permiten crear programas mediante código.";
    mostrarRetroalimentacion[26] = "Respuesta correcta: Opción B. El software es lo digital; el hardware es lo físico.";
    mostrarRetroalimentacion[27] = "Respuesta correcta: Opción C. Un diagrama de flujo avanza hacia abajo y de izquierda a derecha.";
    mostrarRetroalimentacion[28] = "Respuesta correcta: Opción C. El código binario utiliza ceros y unos.";
    mostrarRetroalimentacion[29] = "Respuesta correcta: Opción C. El rectángulo representa procesos u operaciones en diagramas de flujo.";

    int aciertos = 0;
    aciertosPregunta = 0;
    int correctas[TOTAL_PREGUNTAS] = {
        1, 2, 1, 0, 2, 1, 2, 1, 1, 0, 1, 1, 0, 1, 1, 1, 2, 0, 1, 0, 2, 1, 2,
        0, 0, 1, 1, 2, 2, 2};

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
        int ind = indices[i];
        preguntasSeleccionadas[i] = ind;

        char respuesta = presentarPregunta(preguntas[ind], i + 1);

        int resultado = evaluarRespuesta(respuesta, correctas[ind]);
        respuestasCorrectas[i] = resultado;
        aciertos += resultado;
        aciertosPregunta += resultado;

        system("cls");
    }

    calcularCalificacion(aciertos, PREGUNTAS_MOSTRAR, preguntas);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char presentarPregunta(struct Pregunta preguntas, int numero)
{
    char r;
    int preguntasRespondidas = numero - 1;
    float porcentaje = (aciertosPregunta * 100.0f) / PREGUNTAS_MOSTRAR;

    system("cls");
    printf("=== EXAMEN DE %s. === (Pregunta %d/%d) | %0.0f %% de aciertos actuales\n\n", nombreCompleto, numero, PREGUNTAS_MOSTRAR, porcentaje);
    printf("%s\n", preguntas.tex);

    printf("  A) %s\n", preguntas.opciones[0]);
    printf("  B) %s\n", preguntas.opciones[1]);
    printf("  C) %s\n", preguntas.opciones[2]);

    do
    {
        printf("\nTu respuesta (a/b/c): ");
        scanf(" %c", &r);

        if (r >= 'A' && r <= 'Z')
            r = r + ('a' - 'A');

        if (r != 'a' && r != 'b' && r != 'c')
        {
            printf("¡Entrada inválida!. Solo se permite a, b o c.\n");
        }

    } while (r != 'a' && r != 'b' && r != 'c');

    return r;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calcularCalificacion(int aciertos, int total, struct Pregunta preguntas[])
{
    float calificacion = (aciertos * 100.0f) / total;

    printf("===== RESULTADO FINAL =====\n");
    printf("Porcentaje de aciertos total: %0.0f%%\n\n", calificacion);
    printf("Número de respuestas correctas: %d de %d\n", aciertos, total);

    printf("\n===== RETROALIMENTACIÓN =====\n\n");

    for (int i = 0; i < PREGUNTAS_MOSTRAR; i++)
    {
        int idc = preguntasSeleccionadas[i];
        int correcta = respuestasCorrectas[i];

        printf("Pregunta %d: %s\n", i + 1, preguntas[idc].tex);
        printf(" - %s\n", correcta ? "Correcta" : "Incorrecta");
        printf(" Retroalimentación: \n %s\n\n", mostrarRetroalimentacion[idc]);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void registro()
{
    printf("Ingresa tu nombre y apellido: ");
    fgets(nombreCompleto, sizeof(nombreCompleto), stdin);

    size_t len = strlen(nombreCompleto);
    if (len > 0 && nombreCompleto[len - 1] == '\n')
        nombreCompleto[len - 1] = '\0';
}

void equipo()
{
    printf("Fundamentos de programación\n");
    printf("Sección D02\n");
    printf("Práctica 10 - Exámen\n");
    printf("Equipo 3\n");
    printf("Exámen creado por:\n");
    printf("Lopez Medina Allan Octavio\n");
    printf("Montes Domínguez Alejandro\n");
    printf("Orozco García Jorge Clemente\n");
    printf("Trujillo Avila Alan David\n\n");
}