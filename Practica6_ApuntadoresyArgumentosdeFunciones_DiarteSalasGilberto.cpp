#include <stdio.h>
#include <stdbool.h>

int sumaVect(int *array, int longitud);
void copVect(int *origen, int *destino, int longitud);
void concatenarArreglos(int *arreglo1, int longitud1, int *arreglo2, int longitud2, int *resultado);
bool compararArreglos(int *arreglo1, int *arreglo2, int longitud);
int encontrarMaximo(int *arreglo, int longitud);

int main()
{
    int opc;
    printf("M\tE\tN\tU");
    printf("1.-Suma de elementos en un arreglo:\n");
    printf("2.-Copia de arreglos:\n");
    printf("3.-Concatenación de arreglos:\n");
    printf("4.-Comparación de arreglos:\n");
    printf("5.-Encontrar el elemento máximo:\n\n");
    printf("Elije una opcion ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
    {
        int array[] = {1, 2, 3, 4, 5};
        int longitud = sizeof(array) / sizeof(array[0]);

        int resultado = sumaVect(array, longitud);
        printf("La suma de los elementos en el arreglo es: %d\n", resultado);
        break;
        
    }
    case 2:
    {

        int vectIni[] = {1, 2, 3, 4, 5};
        int longitud = sizeof(vectIni) / sizeof(vectIni[0]);

        int vectfin[longitud]; // El arreglo de destino debe tener la misma longitud que el arreglo de origen

        copVect(vectIni, vectfin, longitud);

        printf("Arreglo de origen: ");
        for (int i = 0; i < longitud; i++)
        {
            printf("%d ", vectIni[i]);
        }
        printf("\n");

        printf("Arreglo de destino: ");
        for (int i = 0; i < longitud; i++)
        {
            printf("%d ", vectfin[i]);
        }
        printf("\n");
        break;

    }
    case 3:
    {
        int arreglo1[] = {1, 2, 3};
        int longitud1 = sizeof(arreglo1) / sizeof(arreglo1[0]);

        int arreglo2[] = {4, 5, 6};
        int longitud2 = sizeof(arreglo2) / sizeof(arreglo2[0]);

        int longitudResultado = longitud1 + longitud2;
        int arregloResultado[longitudResultado];

        concatenarArreglos(arreglo1, longitud1, arreglo2, longitud2, arregloResultado);

        printf("Arreglo 1: ");
        for (int i = 0; i < longitud1; i++)
        {
            printf("%d ", arreglo1[i]);
        }
        printf("\n");

        printf("Arreglo 2: ");
        for (int i = 0; i < longitud2; i++)
        {
            printf("%d ", arreglo2[i]);
        }
        printf("\n");

        printf("Arreglo Concatenado: ");
        for (int i = 0; i < longitudResultado; i++)
        {
            printf("%d ", arregloResultado[i]);
        }
        printf("\n");
        break;

    }
    case 4:
    {
        int arreglo1[] = {1, 2, 3, 4, 5};
        int arreglo2[] = {1, 2, 3, 4, 5};
        int longitud = sizeof(arreglo1) / sizeof(arreglo1[0]);

        bool sonIguales = compararArreglos(arreglo1, arreglo2, longitud);

        if (sonIguales)
        {
            printf("Los arreglos son iguales.\n");
        }
        else
        {
            printf("Los arreglos no son iguales.\n");
        }
        break;

    }
    case 5:
    {
        int arreglo[] = {5, 12, 3, 8, 9, 7, 20};
        int longitud = sizeof(arreglo) / sizeof(arreglo[0]);

        int maximo = encontrarMaximo(arreglo, longitud);

        printf("El elemento máximo en el arreglo es: %d\n", maximo);
        break;
    }
    default:
        printf("opcion invalida\n");
        break;
    }

    return 0;
}

int sumaVect(int *array, int longitud)
{
    int suma = 0;
    int *ptr = array; // Inicializamos un puntero al inicio del arreglo

    for (int i = 0; i < longitud; i++)
    {
        suma += *ptr; // Sumamos el valor apuntado por ptr al acumulador
        ptr++;        // Movemos el puntero al siguiente elemento
    }

    return suma;
}

void copVect(int *origen, int *destino, int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        *(destino + i) = *(origen + i);
    }
}

void concatenarArreglos(int *arreglo1, int longitud1, int *arreglo2, int longitud2, int *resultado)
{
    // Copiar el primer arreglo al resultado
    for (int i = 0; i < longitud1; i++)
    {
        *(resultado + i) = *(arreglo1 + i);
    }

    // Copiar el segundo arreglo al resultado
    for (int i = 0; i < longitud2; i++)
    {
        *(resultado + longitud1 + i) = *(arreglo2 + i);
    }
}

bool compararArreglos(int *arreglo1, int *arreglo2, int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        if (*(arreglo1 + i) != *(arreglo2 + i))
        {
            return false; // Si se encuentra una diferencia, los arreglos no son iguales
        }
    }
    return true; // Si no se encuentra ninguna diferencia, los arreglos son iguales
}
int encontrarMaximo(int *arreglo, int longitud)
{
    int maximo = arreglo[0]; // Suponemos que el primer elemento es el máximo

    for (int i = 1; i < longitud; i++)
    {
        if (arreglo[i] > maximo)
        {
            maximo = arreglo[i]; // Actualizamos el máximo si encontramos un elemento mayor
        }
    }

    return maximo;
}