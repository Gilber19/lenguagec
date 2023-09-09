#include <stdio.h>
#define N 10 // constante para la capidad del inventario

int main() {
    int opc;
    printf("    \nM E N U\n");                          // menu para elegir opciones del programa
    printf("1.- Numeros Binarios\n");
    printf("2.- Calificacion Numerica a letra\n");
    printf("3.- Inventario\n");
    printf("0.- Salir\n");
    printf("Elige una opcion\n");
    scanf("%d", &opc);
    
    while (opc != 0) //ciclo para repetir el menu hasta dar la opcionn de salida
    {
        switch (opc) 
        {
            case 1:                              //Este programa convierte numeros decimales a numeros binarios
                int numero_decimal;              //binarios: numeros compuestos por el 1 y el 0 unicamente
                printf("Ingresa un numero: ");
                scanf("%d", &numero_decimal);
                if (numero_decimal < 0) 
                {
                    printf("Numero invalido\n");
                } 
                else 
                {
                    int num_bits = 0;
                    int temp = numero_decimal;
                    while (temp > 0) 
                    {
                        temp /= 2;
                        num_bits++;
                    }

                    int bits[num_bits];
                    int indice = 0;

                    while (numero_decimal > 0) 
                    {
                        bits[indice] = numero_decimal % 2;
                        numero_decimal /= 2;
                        indice++;
                    }

                    printf("Numero en bits: ");
                    for (int i = indice - 1; i >= 0; i--) 
                        {
                            printf("%d ", bits[i]);
                        }

                    printf("\nLos bits encendidos estan en la posicion: ");
                    for (int i = 0; i < indice; i++) 
                    {
                        if (bits[i] == 1) 
                            {
                                printf("%d ", i + 1);
                            }
                    }
                }
                break;

            case 2:
                int cal;                                 //Este programa lee tu calficacion del 0 al 100 y
                printf("Ingrese su calificacion: ");     // despliega su correspondiente en letra   
                scanf("%d", &cal);

                if (cal >= 90) 
                {
                    printf("Sacaste %d y es una A\n", cal);
                } 
                else if (cal >= 80) 
                {
                    printf("Obtuviste %d y es una B\n", cal);
                } else if (cal >= 70) 
                {
                    printf("Obtuviste %d y es una C\n", cal);
                } else if (cal >= 60) 
                {
                    printf("Obtuviste %d y es una D\n", cal);
                } else 
                {
                    printf("Obtuviste %d y es una F\n", cal);
                }
                break;

            case 3:                         //tenemos un inventario de un slo producto con un maximo definido por una constante
                int op, agr, ret;
                int invent;
                invent=0;
                do                          // ciclo para repetir el inventario
                {
                    
                    printf("Inventario\n");
                    printf("1. Agregar elementos\n");
                    printf("2. Retirar elementos\n");
                    printf("3. Mostrar inventario\n");
                    printf("4. Salir\n");
                    scanf("%d", &op);
                    switch (op) 
                    {
                        case 1:
                            printf("Cuantos elementos desea agregar: ");
                            scanf("%d", &agr);
                            if (invent + agr > N) 
                            {
                                printf("Excede la capacidad de inventario, ingrese otra cantidad\n");
                            } else 
                            {
                                invent += agr;
                                printf("Se agregaron %d elementos al inventario\n", agr);
                            }
                            break;

                        case 2:
                            printf("Cuantos elementos desea retirar: ");
                            scanf("%d", &ret);
                            if (ret > invent) 
                            {
                                printf("No puedes retirar mas elementos de los que hay en el inventario\n");
                            } 
                            else 
                            {
                                invent -= ret;
                                printf("Se retiraron %d elementos del inventario\n", ret);
                            }
                            break;

                        case 3:
                            printf("Hay %d productos en el inventario\n", invent);
                            if (invent == N) 
                            {
                                printf("El inventario esta lleno\n\n");
                            } 
                            else if (invent == 0) 
                            {
                                printf("El inventario esta vacio\n");
                            }
                            break;

                        case 4:
                            printf("Hasta luego\n");
                            break;

                        default:
                            printf("Opción invalida\n");
                            break;
                    }

                } while (op != 4);
                break;
            default:
                printf("Opción invalida\n");
                break;
        }

        printf("\nElige una opcion\n");
        scanf("%d", &opc);
    }

    printf("Hasta la proxima\n"); // salir completanmente del programa

    return 0;
}