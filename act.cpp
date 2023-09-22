#include <stdio.h>

void menu();
void fibonacci(int num);
int calcularFibonacciRecursion(int n);
int coeficiente(int n, int k); // Declarar la función coeficiente antes del main
void generarTrianguloPascal(int n);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op;
    printf("Que desea hacer\n");
    printf("1.-Fibonacci\n");
    printf("2.-Fibonacci Recursivo\n");
    printf("3.-Triángulo de Pascal\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:
        int num, opc;
        do
        {
            printf("Cuantas veces quiere mostrar Fibonacci: ");
            scanf("%d", &num);
            fibonacci(num);
            printf("Quieres ver otra serie de Fibonacci\n1.-Si\n2.-No\n");
            scanf("%d", &opc);
        } while (opc == 1);
        printf("\nHasta luego\n");

        break;
    case 2:
        int n, opcc;
        do
        {
            printf("Ingrese el número de términos de la serie Fibonacci que desea calcular: ");
            scanf("%d", &n);
            printf("Serie Fibonacci de %d términos:\n", n);
            for (int i = 0; i < n; i++)
            {
                printf("%d ", calcularFibonacciRecursion(i));
            }
            printf("Quieres ver otra serie de Fibonacci\n1.-Si\n2.-No\n");
            scanf("%d", &opcc);
        } while (opcc == 1);
        printf("\nHasta luego, gracias\n");
        break;
    case 3:
        int numm, oop;
        do
        {
            printf("Ingrese el número de filas para el Triángulo de Pascal: ");
            scanf("%d", &numm);
            generarTrianguloPascal(numm);
            printf("Quieres ver otro triangulo de Pascal\n1.-Si\n2.-No\n");
            scanf("%d", &oop);
        } while (oop == 1);

        break;
    default:
        printf("opcion invalida, vuelve a intentarlo\n");
        break;
    }
}

void fibonacci(int num)
{
    int result = 0, ant = -1, sig = 1;
    for (int i = 0; i < num; i++)
    {
        result = ant + sig;
        printf("%d ", result);
        ant = sig;
        sig = result;
    }
    printf("\n");
}

int calcularFibonacciRecursion(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return calcularFibonacciRecursion(n - 1) + calcularFibonacciRecursion(n - 2);
    }
}

int coeficiente(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1; // Caso base: C(n, 0) = C(n, n) = 1
    }
    else
    {
        // Utiliza recursión para calcular C(n, k) = C(n-1, k-1) + C(n-1, k)
        return coeficiente(n - 1, k - 1) + coeficiente(n - 1, k);
    }
}

void generarTrianguloPascal(int n)
{
    for (int i = 0; i < n; i++)
    {
        // Imprimir espacios en blanco para alinear los coeficientes
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        for (int j = 0; j <= i; j++)
        {
            // Calcular y mostrar el coeficiente binomial para cada posición
            printf("%d ", coeficiente(i, j));
        }
        printf("\n");
    }
}
