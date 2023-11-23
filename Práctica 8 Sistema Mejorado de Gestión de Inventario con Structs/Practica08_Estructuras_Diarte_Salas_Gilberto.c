/*  Practica08_Estructuras_Diarte_Salas_Gilberto
    Diarte Salas Gilberto 360954
    22 de noviembre del 2023
    Este archivo contiene el programa de un inventario basico
*/
// Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constantes
#define MAX 10000

// Estructuras
typedef struct _Producto
{
    int stock;
    char nomb[20];
    int cant;
    float precio;
} Tproduct;

// Prototipos de funciones
void agre_prod(Tproduct inventario[], int *n, int nProductos);
void guar_inven(Tproduct inventario[], int n);
void mostr_inven(Tproduct inventario[], int n);
void reti_prod(Tproduct inventario[], int *n);
int calc_prod(Tproduct inventario[], int n);
void val_tot(Tproduct inventario[], int n);
void ordenar(Tproduct inventario[], int n);
int vali_num(char mensj[], int ri, int rf);

/*
    Funcion: Main
    Descripcion: Aqui se encentra el programa, aqui mismo se llaman las funciones para el switch
*/
int main()
{
    Tproduct inventario[MAX];
    int opc, n, nProductos;
    n = 0;
    nProductos = 0;
    do
    {
        system("CLS");
        printf("M   E   N   U\n");
        printf("1.- Agregar elementos la inventario\n");
        printf("2.- Retirar elementos del inventario\n");
        printf("3.- Mostrar el inventario\n");
        printf("4.- Calcular el valor totol del inventario\n");
        printf("5.- Ordenar\n");
        printf("6.- Guardar inventario en archivo\n");
        printf("0.- Salir del programa\n");
        opc = vali_num("Que opcion desea realizar\n", 0, 6);
        system("CLS");

        switch (opc)
        {
        case 0:
            printf("Gracias...\n");
            break;

        case 1:
            if (nProductos >= MAX)
            {
                printf("Inventario lleno\n\n");
                break;
            }

            printf("Agregar producto\n\n");
            agre_prod(inventario, &n, nProductos);
            nProductos = calc_prod(inventario, n);
            break;

        case 2:
            if (nProductos < 1)
            {
                printf("Inventario vacio\n\n");
                break;
            }

            printf("Retirar producto\n\n");
            reti_prod(inventario, &n);
            nProductos = calc_prod(inventario, n);
            break;

        case 3:
            printf("Mostrar inventario\n");
            mostr_inven(inventario, n);
            break;

        case 4:
            printf("Valor total del inventario\n");
            val_tot(inventario, n);
            break;

        case 5:
            printf("Ordenar\n\n");
            ordenar(inventario, n);
            break;

        case 6:
            printf("Guardar inventario en archivo\n");
            guar_inven(inventario, n);
            break;

        default:
            printf("Opcion invalida\n");
            break;
        }
        system("PAUSE");
    } while (1);
}

int vali_num(char mensj[], int ri, int rf)
{
    int num;
    char cadena[100];
    do
    {
        printf("%s", mensj);
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena);

    } while (num < ri || num > rf);

    return num;
}
/*
    Funcion: calc_prod
    Descripcion: Calcula el numero de productos en el inventario
    Parametros: Producto inventario[], int n
    Valor de retorno: Numero de productos en el inventario
*/
int calc_prod(Tproduct inventario[], int n)
{
    int productos = 0;

    for (int i = 0; i < n; i++)
    {
        if (inventario[i].stock == 1)
        {
            productos += inventario[i].cant;
        }
    }

    return productos;
}

/*
    Funcion: agregarProducto
    Descripcion: Agrega un producto al inventario
    Parametros: Producto inventario[], int *n, int nProductos
*/
void agre_prod(Tproduct inventario[], int *n, int nProductos)
{
    printf("Nombre: ");
    scanf("%s", inventario[*n].nomb);

    int cantidad = vali_num("Cantidad: ", 1, MAX - nProductos);
    while (cantidad > MAX - nProductos || cantidad < 0)
    {
        printf("Cantidad invalida. Ingrese nuevamente.\n");
        cantidad = vali_num("Cantidad: ", 1, 50);
    }
    inventario[*n].cant = cantidad;

    float precio = vali_num("Precio: ", 1, 1000);
    while (precio < 0 || precio > 1000.0f)
    {
        printf("Precio invalido. Ingrese nuevamente.\n");
        precio = vali_num("Precio: ", 1, 1000);
    }
    inventario[*n].precio = precio;

    inventario[*n].stock = 1;
    (*n)++;
}

/*
    Funcion: reti_prod
    Descripcion: Retira un producto del inventario
    Parametros: Producto inventario[], int *n
*/
void reti_prod(Tproduct inventario[], int *n)
{
    char nombre[30];
    int cantidad;

    printf("Nombre: ");
    scanf("%s", nombre);

    for (int i = 0; i < *n; i++)
    {
        if (strcmp(inventario[i].nomb, nombre) == 0)
        {
            printf("Cantidad: ");
            scanf("%d", &cantidad);

            if (cantidad > inventario[i].cant)
            {
                printf("No hay suficientes productos\n\n");
                return;
            }

            inventario[i].cant -= cantidad;

            if (inventario[i].cant == 0)
            {
                inventario[i].stock = 0;
            }

            return;
        }
    }

    printf("Producto no encontrado\n\n");
}

/*
    Funcion: mostr_inven
    Descripcion: Muestra lso productos ya inventariados
    Parametros: Producto inventario[], int n
*/
void mostr_inven(Tproduct inventario[], int n)
{
    if (n < 1)
    {
        printf("\nInventario vacio\n\n");
        return;
    }

    printf("\nPRODUCTO                 CANTIDAD   PRECIO I   PRECIO T\n\n");

    int productosImpresos[MAX] = {0};

    for (int i = 0; i < n; i++)
    {
        if (inventario[i].stock == 1 && productosImpresos[i] == 0)
        {
            printf("%-20s", inventario[i].nomb);
            printf("   %-3d", inventario[i].cant);
            printf("        %-7.2f", inventario[i].precio);
            printf("    %-8.2f", inventario[i].cant * inventario[i].precio);
            printf("\n");

            // Marcamos el producto como impreso
            productosImpresos[i] = 1;

            // Buscamos si hay productos iguales y los marcamos también
            for (int j = i + 1; j < n; j++)
            {
                if (strcmp(inventario[i].nomb, inventario[j].nomb) == 0)
                {
                    productosImpresos[j] = 1;
                }
            }
        }
    }
}

/*
    Funcion: valorTotal
    Descripcion: Calcula el valor total del inventario
    Parametros: Producto inventario[], int n
*/
void val_tot(Tproduct inventario[], int n)
{
    float total = 0;
    for (int i = 0; i < n; i++)
    {
        total += inventario[i].cant * inventario[i].precio;
    }

    printf("Valor total: %.2f\n\n", total);
}

/*
    Funcion: ordenar
    Descripcion: Ordena el inventario por precio, cantidad o nombre
    Parametros: Producto inventario[], int n
*/
void ordenar(Tproduct inventario[], int n)
{
    int op;
    Tproduct aux;

    do
    {
        system("CLS");
        printf("1.- Precio\n");
        printf("2.- Cantidad\n");
        printf("3.- Nombre\n");
        printf("4.- Salir\n");

        printf("\nOpcion: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i; j < n; j++)
                {
                    if (inventario[i].precio > inventario[j].precio)
                    {
                        aux = inventario[i];
                        inventario[i] = inventario[j];
                        inventario[j] = aux;
                    }
                }
            }
            printf("\nOrdenado por precio\n\n");
            break;

        case 2:
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i; j < n; j++)
                {
                    if (inventario[i].cant > inventario[j].cant)
                    {
                        aux = inventario[i];
                        inventario[i] = inventario[j];
                        inventario[j] = aux;
                    }
                }
            }
            printf("\nOrdenado por cantidad\n\n");
            break;

        case 3:
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i; j < n; j++)
                {
                    if (strcmp(inventario[i].nomb, inventario[j].nomb) > 0)
                    {
                        aux = inventario[i];
                        inventario[i] = inventario[j];
                        inventario[j] = aux;
                    }
                }
            }
            printf("\nOrdenado por nombre\n\n");
            break;

        case 4:
            return;

        default:
            printf("Opcion no valida\n\n");
        }
    } while (op < 1 || op > 4);
}


/*
    Funcion: guar_inven
    Descripcion: Guarda los productos del inventario en un archivo de texto
    Parametros: Tproduct inventario, n
*/
void guar_inven(Tproduct inventario[], int n)
{
    FILE *archivo;
    archivo = fopen("inventario.txt", "w");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return;
    }

    fprintf(archivo, "Producto\tCantidad\tPrecio por Unidad\tPrecio Total\n");

    // Creamos un arreglo para almacenar los productos ya impresos
    int productosImpresos[MAX] = {0};

    for (int i = 0; i < n; i++)
    {
        if (inventario[i].stock == 1 && productosImpresos[i] == 0)
        {
            float precioTotalProducto = inventario[i].cant * inventario[i].precio;
            float precioPorUnidad = inventario[i].precio;

            fprintf(archivo, "%10s\t%5d\t%.2f\t%.2f\n", inventario[i].nomb, inventario[i].cant, precioPorUnidad, precioTotalProducto);

            // Marcamos el producto como impreso
            productosImpresos[i] = 1;

            // Buscamos si hay productos iguales y los marcamos también
            for (int j = i + 1; j < n; j++)
            {
                if (strcmp(inventario[i].nomb, inventario[j].nomb) == 0)
                {
                    productosImpresos[j] = 1;
                }
            }
        }
    }

    fclose(archivo);
    printf("Inventario guardado en archivo correctamente\n");
}