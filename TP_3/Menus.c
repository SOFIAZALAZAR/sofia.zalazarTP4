#include <stdio.h>
#include <stdlib.h>
#include "Menus.h"

int menu()
{
    int opcion;
    printf("\t\t***Menu Empleados***\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo .csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo .bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo .csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo .bin (modo binario).\n");
    printf("10. Salir\n");
    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);
    while(opcion<0 || opcion>10)
    {
        fflush(stdin);
        printf("Opcion invalida: ");
        scanf("%d", &opcion);
    }
    printf("\n\n");
    return opcion;
}

int menu2()
{
    int opcion;
    printf("\t\t***Menu Ordenar***\n\n");
    printf("1. Ordenar por ID\n");
    printf("2. Ordenar por Nombre\n");
    printf("3. Ordenar por Horas trabajadas\n");
    printf("4. Ordenar por sueldo\n");
    printf("5. Salir\n");
    printf("Ingrese Opcion: ");
    scanf("%d", &opcion);
    while(opcion<0 || opcion>5)
    {
        fflush(stdin);
        printf("Opcion invalida: ");
        scanf("%d", &opcion);
    }
    printf("\n\n");
    return opcion;
}
