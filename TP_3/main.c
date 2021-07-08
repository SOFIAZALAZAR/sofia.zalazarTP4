#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menus.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int nextId = 1;
    char path[128];
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {   system("cls");
        option = menu();
        switch(option)
        {
        case 1:
            printf("Ingrese Path_");
            fflush(stdin);
            gets(path);
            if(controller_loadFromText(path,listaEmpleados,&nextId))
             {
                printf("datos cargados con exito!\n");
            }else{
            printf("No se pudieron cargar los datos!\n");
            }
            system("pause");
            break;
        case 2:
            printf("Ingrese Path_");
            fflush(stdin);
            gets(path);
            if(controller_loadFromBinary(path,listaEmpleados,&nextId))
            {
                printf("datos cargados con exito!\n");
            }else{
            printf("No se pudieron cargar los datos!\n");
            }
            system("pause");
            break;
        case 3:
           if(controller_addEmployee(listaEmpleados,&nextId))
           {
            printf("Alta exitosa!\n");
           }else{
            printf("No se pudo dar de alta el empleado\n");
           }
           system("pause");
            break;
        case 4:
             if(controller_editEmployee(listaEmpleados,&nextId))
            {
                printf("Modificacion exitosa!\n");
            }else{
                printf("No se realizaron cambios!\n");
            }
            system("pause");
            break;
            break;
        case 5:
            if(controller_removeEmployee(listaEmpleados,&nextId))
            {
                printf("Baja exitosa!\n");
            }else{
                printf("No se realizo la baja!\n");
            }
            system("pause");
            break;
        case 6:
            controller_ListEmployee(listaEmpleados);
            system("pause");
            break;
        case 7:
            if(controller_sortEmployee(listaEmpleados))
            {
                printf("Ordenado de manera exitosa!\n");
            }else{
            printf("No se pudo ordenar\n");
            }
            system("pause");
            break;
        case 8:
            printf("Ingrese Path_");
            fflush(stdin);
            gets(path);
            if(controller_saveAsText(path,listaEmpleados))
             {
                printf("datos guardados con exito!\n");
            }else{
            printf("No se pudieron guardar los datos!\n");
            }
            system("pause");
            break;
        case 9:
            printf("Ingrese Path_");
            fflush(stdin);
            gets(path);
            if(controller_saveAsBinary(path,listaEmpleados))
             {
                printf("datos guardados con exito!\n");
            }else{
            printf("No se pudieron guardar los datos!\n");
            }
            system("pause");
            break;
        case 10:
            ll_deleteLinkedList(listaEmpleados);
            break;

        }
    }
    while(option != 10);
    return 0;
}
