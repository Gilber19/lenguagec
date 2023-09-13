#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, secret, ac=0;
    srand(time(NULL));
    secret = rand() % 100 + 1;
    goto inicio;

inicio:
    printf("Bienvenido al juego\n");
    printf("Teines que adivinar un numero al azar\n");
    printf("que esta entre 1 y 100, el programa\n");
    printf("contara tu numero de intentos,suerte!\n");

adivinanza:
    printf("Intenta adivianr el numero secreto\n");
    scanf("%d", &num);
    while (num != secret)
    {
        ac = ac + 1;
        goto comparacionyrespuesta;
    }

comparacionyrespuesta:

    if (num == secret)
    {
        printf("Felicidades, ganaste\n");
        printf("Tu numero de intentos fue de %d \n", ac+1);
        goto reinicio;
    }

    else
    {
        if (num < secret)
        {
            printf("El numero que buscas es mayor\n");
            goto adivinanza;
        }
        else
        {
            printf("El numero que buscas es menor\n");
            goto adivinanza;
        }
    }

reinicio:
    int opc;
    printf("Desea jugar de nuevo?\n");
    printf("1.-si\n");
    printf("2.-no\n");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        ac = 0;
        secret=rand() % 100 +1;
        goto adivinanza;
        break;
    case 2:
        printf("Adios");
        break;
    default:
        printf("opcion no valida");
        goto reinicio;
        break;
    }

    return 0;
}