#include <stdio.h>

/*Escribe un programa en C que encuentre y muestre todos los números perfectos
 en un rango dado por el usuario. Un número perfecto es un número entero positivo
  que es igual a la suma de sus divisores propios positivos (excluyendo a sí mismo).
Requisitos del programa:
+Solicita al usuario que ingrese un número entero positivo "n" que representa el rango.
+El programa buscará números perfectos en el rango de 1 a "n".
+Valida que "n" sea un número entero positivo.
+Si encuentras un número perfecto, muestra ese número y sus divisores propios positivos.
+Después de encontrar todos los números perfectos en el rango, pregunta al usuario si desea
buscar números perfectos en otro rango. Si la respuesta es afirmativa, el programa debe repetirse;
 de lo contrario, debe finalizar.*/

int numperf(int num);

int main()
{
    int num,opc;

    do
    {
        printf("Ingresa un numero entero positivo");
        scanf("%d", &num);

        if (num < 0)
        {
            printf("opcion invalida, debe ser un numero positivo\n");
        }
        else
        {
            if (num > 0)
            {
                printf("Numeros perfectos de 1 a %d:\n", num);
                for (int i = 1; i <= num; i++)
                {
                    if (numperf(i))
                    {

                        printf("%d es un numero perfecto\n", i);
                        printf(" 1");
                        for (int j = 2; j <= i / 2; j++)
                        {
                            
                            if (i % j == 0)
                            {
                                printf(" %d", j);
                            }
                        }
                        printf("\n");
                    }
                }
            }
            printf("deseas buscar numeros perfectos en otro rango?\n1.-Si\n0.-Salir");
            scanf("%d",&num);
        }

    } while (num != 0);
    
    return 0;
}

int numperf(int num)
{
    int sumdiv = 0;
    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            sumdiv += i;
        }
    }
    return sumdiv == num;
}