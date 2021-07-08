/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menus.h"

int main(void)
{
    // startTesting(1);  // ll_newLinkedList
    //startTesting(2);  // ll_len
    //  startTesting(3);  // getNode - test_getNode
    //   startTesting(4);  // addNode - test_addNode
    /*    startTesting(5);  // ll_add
     startTesting(6);  // ll_get
     startTesting(7);  // ll_set
     startTesting(8);  // ll_remove
     startTesting(9);  // ll_clear
     startTesting(10); // ll_deleteLinkedList
    startTesting(11); // ll_indexOf
      startTesting(12); // ll_isEmpty
      startTesting(13); // ll_push
      startTesting(14); // ll_pop
    startTesting(15); // ll_contains
    startTesting(16); // ll_containsAll*/
    //startTesting(17); // ll_subList
    //startTesting(18); // ll_clone
    //startTesting(19); // ll_sort

    int option = 0;
    int nextId = 1;
    char path[128];
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaBaja = ll_newLinkedList();
    LinkedList* listaClonada = ll_newLinkedList();
    do
    {
        system("cls");
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
            }
            else
            {
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
            }
            else
            {
                printf("No se pudieron cargar los datos!\n");
            }
            system("pause");
            break;
        case 3:
            if(controller_addEmployee(listaEmpleados,&nextId))
            {
                printf("Alta exitosa!\n");
            }
            else
            {
                printf("No se pudo dar de alta el empleado\n");
            }
            system("pause");
            break;
        case 4:
            if(controller_editEmployee(listaEmpleados,&nextId))
            {
                printf("Modificacion exitosa!\n");
            }
            else
            {
                printf("No se realizaron cambios!\n");
            }
            system("pause");
            break;
            break;
        case 5:
            if(controller_removeEmployee(listaEmpleados,&nextId,listaBaja))
            {
                printf("Baja exitosa!\n");
            }
            else
            {
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
            }
            else
            {
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
            }
            else
            {
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
            }
            else
            {
                printf("No se pudieron guardar los datos!\n");
            }
            system("pause");
            break;
        case 10:
            controller_ListEmployee(listaBaja);
            system("pause");
            break;
        case 11:
            if(controller_addEmployeeRemove(listaEmpleados,listaBaja))
            {
                printf("Alta exitosa!\n");
            }
            else
            {
                printf("No se pudo dar de alta el empleado\n");
            }
            system("pause");
            break;
        case 12:
            printf("Ingrese Path_");
            fflush(stdin);
            gets(path);
            if(controller_cloneList(listaBaja,listaClonada,path))
            {
                printf("datos guardados con exito!\n");
            }
            else
            {
                printf("No se pudieron guardar los datos!\n");
            }
            system("pause");
            break;
        case 13:
            ll_deleteLinkedList(listaEmpleados);
            ll_deleteLinkedList(listaBaja);
            ll_deleteLinkedList(listaClonada);
            break;

        }
    }
    while(option != 13);


    return 0;
}

































