#include <stdio.h>
#include <math.h>
#include <time.h>
#define PI 3.14159

int main()
{
    int opcion;
    do
    {
        printf("Que programa desea usar\n");
        printf("1.- Calculadora\n");
        printf("2.- Juego de adivinar un numero\n");
        printf("3.- Calcular Areas\n");
        printf("4.- Salir\n");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            int num1, num2;
            float resultado;
            char operador;
            do
            {
                printf("Ingrese el primer valor ");
                scanf("%d", &num1);
                fflush(stdin);
                printf("Ingrese el segundo valor ");
                scanf("%d", &num2);
                fflush(stdin);
                printf("Que operacion desea realizar +,-,/,* \n PRESIONE s PRARA SALIR\n");
                scanf(" %c", &operador);
                switch (operador)
                {
                case '+':
                    resultado = num1 + num2;
                    printf("El resultado es = %.2f\n\n", resultado);
                    break;
                case '-':
                    resultado = num1 - num2;
                    printf("El resultado es = %.2f\n\n", resultado);
                    break;
                case '/':
                    resultado = (float)num1 / num2;
                    printf("El resultado es = %.2f\n\n", resultado);
                    break;
                case '*':
                    resultado = num1 * num2;
                    printf("El resultado es = %.2f\n\n", resultado);
                    break;
                case 's':
                    break;
                default:
                    printf("Operación no válida\n");
                    break;
                }
            } while (operador != 's');
            
            break;

        case 2:
            int numadi, numexac, opcionJuego;
            srand(time(NULL));
            numexac = rand() % 100 + 1;
            
            do
            {
                printf("Trata de adivinar un numero que estoy pensando ");
                do
                {
                    scanf("%d", &numadi);
                    if (numadi != numexac)
                    {
                        if (numadi > numexac)
                        {
                            printf("Estas muy arriba\n");
                        }
                        else
                        {
                            printf("Estas muy abajo\n");
                        }
                    }
                    else
                    {
                        printf("¡Felicitaciones, ganaste!\n\n");
                    }
                } while (numadi != numexac);
                
                printf("Si desea jugar de nuevo, presione 2; sino, presione 1: ");
                scanf("%d", &opcionJuego);
            } while (opcionJuego != 1);
            
            break;

        case 3:
            float area;
            int radio, altura, lado, base, opc;

            do
            {
                printf("De que figura desea el Area\n\n");
                printf("1 Triangulo\n");
                printf("2 Circulo\n");
                printf("3 Rectangulo\n");
                printf("4 Cubo\n");
                printf("5 Cilindro\n");
                printf("6 Salir\n");
                scanf("%d", &opc);

                switch (opc)
                {
                case 1:
                    printf("Ingrese la base: ");
                    scanf("%d", &base);
                    printf("Ingrese la altura: ");
                    scanf("%d", &altura);
                    area = (base * altura) / 2.0;
                    printf("El area es de %.2f\n\n", area);
                    break;
                case 2:
                    printf("Ingrese el radio: ");
                    scanf("%d", &radio);
                    area = PI * pow(radio, 2);
                    printf("El area es de %.2f\n\n", area);
                    break;
                case 3:
                    printf("Ingrese la base: ");
                    scanf("%d", &base);
                    printf("Ingrese la altura: ");
                    scanf("%d", &altura);
                    area = base * altura;
                    printf("El area es de %.2f\n\n", area);
                    break;
                case 4:
                    printf("Ingrese un lado del cubo: ");
                    scanf("%d", &lado);
                    area = 6 * pow(lado, 2);
                    printf("El area es de %.2f\n\n", area);
                    break;
                case 5:
                    printf("Ingrese el radio: ");
                    scanf("%d", &radio);
                    printf("Ingrese la altura: ");
                    scanf("%d", &altura);
                    area = (2 * PI * radio * altura) + (2 * PI * pow(radio, 2));
                    printf("El area es de %.2f\n\n", area);
                    break;
                case 6:
                    break;  // Salir del bucle interno
                default:
                    break;
                }
            } while (opc != 6);
            
            break;

        default:
            break;
        }

    } while (opcion != 4);

    return 0;
}