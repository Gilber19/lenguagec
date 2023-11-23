// examen parcial de lenguaje C
// Registro de mascotas con historia clinica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

// declaracion de la estructura
// con los tipos de datos de las mascotas

typedef struct _veterinaria
{
    char especie[30];
    char genero[10];
    char nombre[20];
    char color[20];
    char clinica[50];
    int edad;
    int clave;
} Vet;

// prototipo de funciones

void agregar_registro(Vet *veter);
void actualizar_clinica(Vet *veter, int n);
void mostrar_registro(Vet *veter, int n);
void almacenar_datos(Vet *veter, int n);
void buscar_registro(Vet *veter, int n);

int main()
{
    Vet veterinaria[MAX]; // maximo de mascotas para el registro
    int opc; 
    int n = 0; // contador de mascotas

    do
    {
        printf("\nM E   N   U\n");
        printf("1. Agregar Registro\n");
        printf("2. Actualizar Clinica\n");
        printf("3. Mostrar Registro\n");
        printf("4. Almacenar Datos\n");
        printf("5. Buscar Registro\n");
        printf("0. Salir\n");

        printf("Ingrese la opcion ");
        fflush(stdin);
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            agregar_registro(&veterinaria[n]);
            system("PAUSE");
            system("CLS");
            n++;
            break;
        case 2:
            actualizar_clinica(veterinaria, n);
            system("PAUSE");
            system("CLS");
            break;
        case 3:
            mostrar_registro(veterinaria, n);
            break;
        case 4:
            almacenar_datos(veterinaria, n);
            system("PAUSE");
            system("CLS");
            break;
        case 5:
            buscar_registro(veterinaria, n);
            system("PAUSE");
            system("CLS");
            break;
        case 0:
            printf("Gracias...\n");
            break;
        default:
            printf("Opcion no valida\n");
        }

    } while (opc != 0);

    return 0;
}

/*
    esta funcion realiza la captura de datos manualmente por el usuario
    para su posterior almacenamiento en la estructura
*/
void agregar_registro(Vet *veter)
{
    printf("Ingrese la especie de la mascota ");
    scanf("%s", veter->especie);

    printf("Ingrese el genero de la mascota ");
    scanf("%s", veter->genero);

    printf("Ingrese el nombre de la mascota ");
    scanf("%s", veter->nombre);

    printf("Ingrese el color de la mascota ");
    scanf("%s", veter->color);

    printf("Ingrese la edad de la mascota ");
    scanf("%d", &(veter->edad));

    printf("Ingrese la clave de la mascota ");
    scanf("%d", &(veter->clave));

    printf("Ingrese la historia clinica ");
    scanf("%s", &(veter->clinica));
}

/*
    Aqui se busca la clave de la mascota
    para verificar su existencia, y si asi es 
    se modifica la clinica de la mascota
*/
void actualizar_clinica(Vet *veter, int n)
{
    int clave;
    int encontrado = 0;

    printf("Ingrese la clave de la mascota a actualizar ");
    scanf("%d", &clave);

    for (int i = 0; i < n; i++)
    {
        if (veter[i].clave == clave)
        {
            printf("Ingrese la nueva clinica de la mascota ");
            scanf("%s", veter[i].clinica);
            encontrado = 1;
            break; 
        }
    }

    if (!encontrado)
    {
        printf("No se encontro la mascota\n");
    }
}


/*
    esta funcion busca un registro en base a la clave
    porporcionada de la mascota para despues desplegar
     en pantalla todas las mascotas qe se ha registrado en la estructura
*/
void mostrar_registro(Vet *veter, int n)
{
    if (n == 0)
    {
        printf("No hay registros para mostrar\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nRegistro %d:\n", i + 1);
        printf("Especie: %s\n", veter[i].especie);
        printf("Genero: %s\n", veter[i].genero);
        printf("Nombre: %s\n", veter[i].nombre);
        printf("Color: %s\n", veter[i].color);
        printf("Edad: %d\n", veter[i].edad);
        printf("Clave: %d\n", veter[i].clave);
        printf("Clinica: %s\n", veter[i].clinica);
        system("PAUSE");
        system("CLS");
    }
}


/*
    Se almacenan los datos generando un archivo de texto

*/
void almacenar_datos(Vet *veter, int n)
{
    FILE *fa;
    fa = fopen("veterinaria.txt", "w");

    if (fa == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(fa, "%15s %8s %10s %10s %10s %10s %17s \n", "Especie", "Genero", "Nombre", "Color", "Edad", "Clave", "Clinica");

    for (int i = 0; i < n; i++)
    {
        fprintf(fa, "%15s %8s %10s %10s %10d %10d %17s\n", veter[i].especie, veter[i].genero, veter[i].nombre,
                veter[i].color, veter[i].edad, veter[i].clave, veter[i].clinica);
    }

    fclose(fa);
    printf("datos guardados\n");
}

/*
    se busca una mascota especifica con la clave de la misma

*/
void buscar_registro(Vet *veter, int n)
{
    int clave;
    printf("Ingrese la clave de la mascota");
    scanf("%d", &clave);

    for (int i = 0; i < n; i++)
    {
        if (veter[i].clave == clave)
        {
            printf("\nRegistro encontrado\n");
            printf("Especie: %s\n", veter[i].especie);
            printf("Genero: %s\n", veter[i].genero);
            printf("Nombre: %s\n", veter[i].nombre);
            printf("Color: %s\n", veter[i].color);
            printf("Edad: %d\n", veter[i].edad);
            printf("Clave: %d\n", veter[i].clave);
            printf("Clinica: %s\n", veter[i].clinica);
            system("PAUSE");
            system("CLS");
            return;
        }
    }
    printf("No se encontró la mascota\n");
}
