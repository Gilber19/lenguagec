// Diarte Salas Gilberto 360954
// Lenguaje C
// Taller 7
// Apuntadores y Caracteres

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcion para validar un numero dentro de un rango
int vali_num(int ri, int rf, char msg[30], char msg2[30]);

// Funcion para imprimir nombres almacenados en un arreglo de apuntadores
void imprimirNombres(char **nombres, int n);

// Funcion para invertir una cadena de caracteres
void invertirCadena(char *cadena);

// Funcion para ordenar palabras en un arreglo de cadenas alfabeticamente
void ordenarPalabras(char caden[][20], int n);

int main()
{
    int opc;
    char *nombres[3];
    char lista[10][20];
    char cadena[] = {"AIBOFOBIA ANITA LAVA LA TINA"};

    do
    {
        printf("M E N U\n");
        printf("1.- Arreglo de apuntadores\n");
        printf("2.- Nombres\n");
        printf("3.- Funcion imprimir cadena\n");
        printf("4.- Invertir cadena\n");
        printf("5.- Ordenar cadena alfabeticamente\n");
        printf("6.- SALIR\n");
        opc = vali_num(1, 6, "\ningresa una opcion ", "\nopcion invalida, intentalo de nuevo\n\n");

        switch (opc)
        {
        case 1:
            // Asignar nombres a los apuntadores
            nombres[0] = "Gilberto";
            nombres[1] = "Jorge";
            nombres[2] = "Fernando";

            // Imprimir los nombres almacenados en los apuntadores
            for (int i = 0; i < 3; i++)
            {
                printf("%s\n", nombres[i]);
            }
            system("PAUSE");
            system("CLS");
            break;

        case 2:
            // Solicitar al usuario ingresar nombres y almacenarlos en el arreglo bidimensional
            for (int i = 0; i < 3; i++)
            {
                char nombre[100];
                printf("Ingresa el nombre #%d: ", i + 1);
                gets(nombre);
                strcpy(lista[i], nombre);
            }

            // Imprimir los nombres ingresados
            printf("Nombres ingresados:\n");
            for (int i = 0; i < 3; i++)
            {
                printf("Nombre #%d: %s\n", i + 1, lista[i]);
            }
            system("PAUSE");
            system("CLS");
            break;

        case 3:
            // Llamar a la funcion para imprimir los nombres almacenados en los apuntadores
            imprimirNombres(nombres, 3);
            system("PAUSE");
            system("CLS");
            break;

        case 4:
            // Llamar a la funcion para invertir la cadena de caracteres
            invertirCadena(cadena);
            printf("La cadena al reves es %s\n\n", cadena);
            system("PAUSE");
            system("CLS");
            break;

        case 5:
            printf("ingresa 10 palabras:\n");
            // Solicitar al usuario ingresar palabras y almacenarlas en el vector
            for (int i = 0; i < 10; i++)
            {
                char caden[20];
                gets(caden);
                strcpy(lista[i], caden);
            }

            // Llamar a la funcion para ordenar las palabras alfabeticamente
            ordenarPalabras(lista, 10);

            // Imprimir las palabras ordenadas
            printf("Palabras ordenadas:\n");
            for (int i = 0; i < 10; i++)
            {
                printf("%s\n", lista[i]);
            }
            system("PAUSE");
            system("CLS");
            break;

        default:
            break;
        }
    } while (opc != 6);

    return 0;
}

// Funcion para validar un numero dentro de un intervalo
int vali_num(int ri, int rf, char msg[30], char msg2[30])
{
    char xnum[30];
    int num;
    do
    {
        printf("%s", msg);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
        if (num < ri || num > rf)
        {
            printf("%s", msg2);
        }
    } while (num < ri || num > rf);
}

// Funcion para imprimir nombres almacenados en un vector de apuntadores
void imprimirNombres(char **nombres, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Nombre #%d: %s\n", i + 1, nombres[i]);
    }
}

// Funcion para invertir una cadena de caracteres
void invertirCadena(char *cadena)
{
    int j = strlen(cadena) - 1;
    int i = 0;
    char temp;
    while (i < j)
    {
        temp = cadena[i];
        cadena[i] = cadena[j];
        cadena[j] = temp;
        i++;
        j--;
    }
}

// Funcion para ordenar palabras en un arreglo de cadenas alfabeticamente
void ordenarPalabras(char caden[][20], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(caden[j], caden[j + 1]) > 0)
            {
                char temp[20];
                strcpy(temp, caden[j]);
                strcpy(caden[j], caden[j + 1]);
                strcpy(caden[j + 1], temp);
            }
        }
    }
}
