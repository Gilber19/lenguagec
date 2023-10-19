#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int vali_num(int ri, int rf);
void multiplicarPorDos(int *pointer);
void sumarAElementos(int *arreglo, int valor);

int main()
{
    srand(time(NULL));
    int opc;
    do
    {
        system("CLS");
        printf("M\tE\tN\tU\n");
        printf("1.- Apuntadores Basicos:\n");
        printf("2.- Pasar Apuntadores a una Funcion:\n");
        printf("3.- Arreglos:\n");
        printf("4.- Modificar Elementos de un Arreglo:\n");
        printf("0.- SALIR\n");
        printf("Elige una opcion\n");
        opc = vali_num(0, 4);
        switch (opc)
        {
        case 1:
        {
            int x = 10, *ptr = &x;
            printf("El valor de x es: %d\n", x);
            printf("El valor al que apunta ptr es: %d\n", *ptr);
            system("PAUSE");
            break;
        }
        case 2:
        {
            int numero = 5;
            int *pointer = &numero;
            multiplicarPorDos(pointer);
            printf("El valor del numero era 5 y ahora es %d\n", numero);
            system("PAUSE");
            break;
        }
        case 3:
        {
            int vectr[7];
            int *ptr = vectr;
            // Inicializa el arreglo con valores unicos en el rango de 1 a 50
            for (int i = 0; i < 7; i++)
            {
                int valor;
                int repetido;

                do
                {
                    valor = (rand() % 50) + 1;
                    repetido = 0;

                    for (int j = 0; j < i; j++)
                    {
                        if (vectr[j] == valor)
                        {
                            repetido = 1;
                            break;
                        }
                    }
                } while (repetido);

                vectr[i] = valor;
            }

            // Imprime los elementos del arreglo utilizando el puntero
            for (int i = 0; i < 7; i++)
            {
                printf("Elemento %d: %d\n", i, *ptr);
                ptr++;
            }
            system("PAUSE");
            break;
        }
        case 4:
        {
            int vect[10];
            for (int i = 0; i < 10; i++)
            {
                vect[i]=rand ()% 100+1;
            }
            
            int valor = 10;

            printf("Arreglo original: ");
            for (int i = 0; i < 10; i++)
            {
                printf("%d ", vect[i]);
            }
            printf("\n");

            sumarAElementos(vect, valor);

            printf("Arreglo modificado: ");
            for (int i = 0; i < 10; i++)
            {
                printf("%d ", vect[i]);
            }
            printf("\n");
            system("PAUSE");
            break;
            
        }
        case 0:
        {
            printf("HASTA LA PROXIMA\n");
            break;
        }
        }
    } while (opc != 0);

    return 0;
}

int vali_num(int ri, int rf)
{
    int num;
    char cadena[10];
    do
    {
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena);
    } while (num < ri || num > rf);

    return num;
}

void multiplicarPorDos(int *pointer)
{
    *pointer = (*pointer) * 2;
}

void sumarAElementos(int *arreglo, int valor)
{
    for (int i = 0; i < 10; i++)
    {
        *arreglo = *arreglo + valor;
        arreglo++; // Avanza al siguiente elemento del arreglo
    }
}