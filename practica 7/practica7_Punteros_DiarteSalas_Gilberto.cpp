//"Practica7_Punteros_DiarteSalas_Gilberto"
// Diarte Salas Gilberto
// 08-Noviembre-2023
// Este programa emplea punteros para relizazar diferentes tareas

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Prototipos de funciones
void argumentosOperaciones(char *arg2[]);
void matrizMultidimensional();
void ordenacionPalabras();
int vali_num(int ri, int rf, char msg[30], char msg2[30]);

int main(int arg, char *arg2[])
{
    int opc;

    do
    {
        printf("   M   E   N   U   \n");
        printf("1.- OPERACIONES CON ARGUMENTOS \n");
        printf("2.- ORDENACION DE PALABRAS \n");
        printf("3.- MATRIZ 3X3 \n");
        printf("0. Salir\n");
        opc=vali_num(0,3,"Elige una opcion\n","opcion invalida, intntalo de nuevo\n");

        system("CLS");

        switch (opc)
        {
        case 1:
            argumentosOperaciones(arg2);
            system("PAUSE");
            break;
        case 2:
            ordenacionPalabras();
            system("PAUSE");
            break;
        case 3:
            matrizMultidimensional();
            system("PAUSE");
            break;
        case 0:
            printf("Adiossssss :)...\n");
            break;
        }

        system("CLS");
        printf("\n");
    } while (opc != 0);

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

void argumentosOperaciones(char *arg2[])
{
    int num1 = atoi(arg2[1]);
    int num2 = atoi(arg2[2]);
    printf("La suma de %d + %d = %d\n", num1, num2, num1 + num2);
    printf("La resta de %d - %d = %d\n", num1, num2, num1 - num2);
    printf("La multiplicacion de %d * %d = %d\n", num1, num2, num1 * num2);
    printf("La division de %d / %d = %.2f\n", num1, num2, (float)num1 / num2);
}

void matrizMultidimensional()
{
    // Inicializa la semilla para la generacion de numeros aleatorios
    srand(time(NULL));

    int matrizMultidimensional[3][3];
    int max = 0, fila = 0, colum = 0, suma = 0;

    // Puntero al primer elemento de la matrizMultidimensional
    int *ptr = &matrizMultidimensional[0][0];

    // Genera numeros aleatorios y calcula la suma y el elemento maximo
    for (int i = 0; i < 3 * 3; i++)
    {
        matrizMultidimensional[i / 3][i % 3] = rand() % 20 + 1; // Numeros aleatorios entre 1 y 20
        suma += *ptr;

        if (*ptr > max)
        {
            max = *ptr;
            fila = i / 3;
            colum = i % 3;
        }

        ptr++;
    }

    // Imprime la matrizMultidimensional generada
    printf("Matriz generada:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\t", matrizMultidimensional[i][j]);
        }
        printf("\n");
    }

    // Imprime los resultados
    printf("\nSuma de la matriz: %d\n", suma);
    printf("Elemento mas grande: %d\n", max);
    printf("Fila %d\nColumna %d\n", fila, colum);
}

void ordenacionPalabras()
{
    int frutas = 15;
    char *palabras[frutas] = {"manzana", "banana", "cereza", "uva", "naranja", "pera", "aguacate", "kiwi", "fruta del dragon", "fresa", "papaya", "arandano", "melon", "frambuesa", "coco"};
    char *temp;
    int i, j;

    // Ordenar
    for (i = 0; i < frutas - 1; i++)
    {
        for (j = i + 1; j < frutas; j++)
        {
            if (strcmp(palabras[i], palabras[j]) > 0)
            {
                temp = palabras[i];
                palabras[i] = palabras[j];
                palabras[j] = temp;
            }
        }
    }

    // Imprimir
    for (i = 0; i < frutas; i++)
    {
        printf("%s\n", palabras[i]);
    }
}