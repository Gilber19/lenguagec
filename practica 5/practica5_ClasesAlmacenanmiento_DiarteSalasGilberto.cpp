/*
ClasesAlmacenamiento_DSG.c
Diarte Salas Gilberto
30 de septiembre de 2023
Este archivo contiene los codigos de la práctica 5
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Prototipos de funciones
void menu(void);
void numeroGanador(void);
int generarNumeroLoteria(void);
int generarVelocidad(void);
void iniciarCarrera(void);

int main()
{
    // Inicializacion del generador de numeros aleatorios
    srand(time(NULL));

    // Llamada a la funcion de menu principal
    menu();
    return 0;
}

// Funcion para mostrar el menu y seleccionar una opcion
void menu()
{
    int op;
    do
    {
        printf("\t MENU \n");
        printf("1. Loteria\n");
        printf("2. Carrera de coches\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            system("CLS");
            numeroGanador();
            break;
        case 2:
            system("CLS");
            iniciarCarrera();
            break;
        case 3:
            system ("CLS");
            printf("Gracias por jugar!!!\n\n");
            break;
        default:
            printf("\nOpcion Invalida, intentalo de nuevo\n");
            system("PAUSE");
        }
    } while (op != 3);
}

// Funcion para generar un numero aleatorio para la loteria
int generarNumeroLoteria()
{
    return rand() % 100 + 1;
}

// Funcion para simular un juego de loteria
void numeroGanador()
{
    static int ganador = 0;
    int n;

    if (ganador == 0)
    {
        ganador = generarNumeroLoteria(); // Genera el numero ganador si no esta definido
    }

    n = generarNumeroLoteria(); // Genera el numero del jugador

    if (n == ganador)
    {
        printf("\n¡Felicidades, ganaste la loteria!\n\n");
    }
    else
    {
        printf("\nLo siento, no ganaste esta vez\n\n");
    }
}

// Funcion para generar una velocidad aleatoria para los coches
int generarVelocidad()
{
    return rand() % 101 + 100;
}

// Funcion para simular una carrera de coches
void iniciarCarrera()
{
    // Genera velocidades aleatorias para los coches
    int auto1 = generarVelocidad();
    int auto2 = generarVelocidad();
    int auto3 = generarVelocidad();

    // Nombres de los coches
    char piloto1[20] = "Checo Perez";
    char piloto2[20] = "Max Verstappen";
    char piloto3[20] = "Fernando Alonso";

    int distancia = 1500;                          // Distancia de la carrera
    float tiempo_auto1 = (float)distancia / auto1; // Calcula el tiempo de auto1
    float tiempo_auto2 = (float)distancia / auto2; // Calcula el tiempo de auto2
    float tiempo_auto3 = (float)distancia / auto3; // Calcula el tiempo de auto3

    // Muestra los resultados de la carrera
    printf("\n%s \t Velocidad: %d km/h \t Tiempo: %.2f s", piloto1, auto1, tiempo_auto1);
    printf("\n%s \t Velocidad: %d km/h \t Tiempo: %.2f s", piloto2, auto2, tiempo_auto2);
    printf("\n%s  Velocidad: %d km/h \t Tiempo: %.2f s\n", piloto3, auto3, tiempo_auto3);

    // Determina al ganador de la carrera
    if (tiempo_auto1 < tiempo_auto2)
    {
        if (tiempo_auto1 < tiempo_auto3)
        {
            printf("\n%s es el ganador de la carrera!\n\n", piloto1);
        }
        else
        {
            printf("\n%s es el ganador de la carrera!\n\n", piloto3);
        }
    }
    else
    {
        if (tiempo_auto2 < tiempo_auto3)
        {
            printf("\n%s es el ganador de la carrera!\n\n", piloto2);
        }
        else
        {
            printf("\n%s es el ganador de la carrera!\n\n", piloto3);
        }
    }
}
