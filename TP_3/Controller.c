#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "controller.h"
#include "Menus.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \param pId int* puntero al id
 * \return int retorna 0 si algun puntero es nulo,el archivo no existe o el usuario cancela que se sobreescriva el listado
 *                      1 si se cargaron los datos de forma correcta
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee,int* pId)
{
     int todoOk =0;
    char confirma;
    if(path!=NULL && pArrayListEmployee!=NULL && pId!=NULL)
    {
        FILE* f = fopen(path, "r");
        if(f == NULL)
        {
            printf("no se pudo abrir el archivo\n");
        }

        if(f!=NULL && !ll_isEmpty(pArrayListEmployee))
        {
            printf("Cuidado se van a sobreescribir los empleados\n");
            printf("Desea continuar?: \n");
            fflush(stdin);
            scanf("%c", &confirma);

        }
        if(f!=NULL &&(ll_isEmpty(pArrayListEmployee) || confirma == 's'))
        {
            ll_clear(pArrayListEmployee);
            todoOk = parser_EmployeeFromText(f,pArrayListEmployee,pId);
        }
        fclose(f);
    }

    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \param pId int* puntero al id
 * \return int retorna 0 si algun puntero es nulo,el archivo no existe o el usuario cancela que se sobreescriva el listado
 *                      1 si se cargaron los datos de forma correcta
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee,int*pId)
{
   int todoOk =0;
    char confirma;
    if(path!=NULL && pArrayListEmployee!=NULL && pId!=NULL)
    {
        FILE* f = fopen(path, "rb");
        if(f == NULL)
        {
            printf("no se pudo abrir el archivo\n");
        }

        if(f!=NULL && !ll_isEmpty(pArrayListEmployee))
        {
            printf("Cuidado se van a sobreescribir los empleados\n");
            printf("Desea continuar?: \n");
            fflush(stdin);
            scanf("%c", &confirma);

        }
        if(f!=NULL &&(ll_isEmpty(pArrayListEmployee) || confirma == 's'))
        {
            ll_clear(pArrayListEmployee);
            todoOk = parser_EmployeeFromBinary(f,pArrayListEmployee,pId);
        }
        fclose(f);
    }

    return todoOk;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \param pId int* puntero al id
 * \return int retorna 0 si algun puntero es nulo o los valores que ingresa el usuario no pasan las validaciones,
 *                     1 si se cargo ok a la lista
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* pId)
{
    int todoOk = 0;
    Employee* auxEmpleado = NULL;
    char buffer[3][100];
    if(pArrayListEmployee != NULL && pId!=NULL)
    {
        auxEmpleado = employee_new();
        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(buffer[0]);
        printf("Ingrese Horas Trabajadas: ");
        fflush(stdin);
        gets(buffer[1]);
        printf("Ingrese Sueldo: ");
        fflush(stdin);
        gets(buffer[2]);
        if(auxEmpleado!=NULL && (employee_setId(auxEmpleado,*pId)&&
                                 employee_setNombre(auxEmpleado,buffer[0])&&
                                 employee_setHorasTrabajadas(auxEmpleado,atoi(buffer[1]))&&
                                 employee_setSueldo(auxEmpleado,atoi(buffer[2])))
          )
        {
            ll_add(pArrayListEmployee,auxEmpleado);
            (*pId)++;
            todoOk = 1;
        }
    }

    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista de empleados
 * \param pId int* puntero al id
 * \return int retorna 0 si alguno de los puntero es nulo o el ususario cancela la modificacion,
 *                      1 si la modificacion es exitosa
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee,int* pId)
{
    int todoOk = 0;
    int id;
    char confirma;
    int indice = -1;
    char buffer[3][100];
    Employee* aux = NULL;
    Employee* newEmpleado = NULL;
    if(pArrayListEmployee!=NULL && pId!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("Ingrese el Id del empleado que desea modificar: ");
        fflush(stdin);
        scanf("%d",&id);
        if(id>0 && id<*pId)
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                aux = ll_get(pArrayListEmployee,i);
                if(aux->id == id)
                {
                    indice = ll_indexOf(pArrayListEmployee,aux);
                    system("cls");
                    mostrarEmpleado(aux);
                    break;
                }
            }
            if(indice!=-1)
            {
                newEmpleado = employee_new();
                printf("Ingrese Nombre: ");
                fflush(stdin);
                gets(buffer[0]);
                printf("Ingrese Horas Trabajadas: ");
                fflush(stdin);
                gets(buffer[1]);
                printf("Ingrese Sueldo: ");
                fflush(stdin);
                gets(buffer[2]);
                if(newEmpleado!=NULL && (employee_setId(newEmpleado,id)&&
                                         employee_setNombre(newEmpleado,buffer[0])&&
                                         employee_setHorasTrabajadas(newEmpleado,atoi(buffer[1]))&&
                                         employee_setSueldo(newEmpleado,atoi(buffer[2])))
                  )
                {
                    system("cls");
                    mostrarEmpleado(newEmpleado);
                    printf("Confirma?: ");
                    fflush(stdin);
                    scanf("%c",&confirma);
                    if(confirma=='s')
                    {
                        ll_set(pArrayListEmployee,indice,newEmpleado);
                        todoOk = 1;
                    }

                }
            }

        }
        else
        {
            printf("No se pudo encontrar el id ingresado!\n");
        }
    }

    return todoOk;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* puntero a la lista de empleados
 * \param pId int* puntero al id
 * \return int retorna 0 si algun puntero es nulo o si el usuario no confirma la baja,
 *                     1 si la baja esta ok
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee,int* pId)
{
    int todoOk = 0;
    int id;
    char confirma;
    Employee* aux = NULL;
    if(pArrayListEmployee!=NULL && pId!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);
        printf("Ingrese el Id del empleado que desea eliminar: ");
        fflush(stdin);
        scanf("%d",&id);
        if(id>0 && id<*pId)
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                aux = ll_get(pArrayListEmployee,i);
                if(aux->id == id)
                {
                    break;
                }

            }
            system("cls");
            mostrarEmpleado(aux);
            printf("Confirma?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                ll_remove(pArrayListEmployee,ll_indexOf(pArrayListEmployee,aux));
                todoOk = 1;
            }
        }
        else
        {
            printf("No se pudo encontrar el id ingresado!\n");
        }

    }

    return todoOk;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero el listado
 * \return int retorna 0 si el puntero es nulo,
 *                     1 si esta ok
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* auxEmp = NULL;
    if(pArrayListEmployee != NULL)
    {
        printf("------------------------------------------------\n");
        printf(" ID  |        NOMBRE   |  H.TRABAJADAS | SUELDO\n");
        printf("------------------------------------------------\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee,i);
            mostrarEmpleado(auxEmp);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* puntero al listado
 * \return int retorna 0 si el puntero es nulo,
 *                     1 si el ordenamiento esta ok
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    int orden;
    if(pArrayListEmployee!=NULL)
    {
        switch(menu2())
        {
        case 1:
            printf("Ingrese 1 para ordenar de manera ascendente y 0 de manera descendente: \n");
            fflush(stdin);
            scanf("%d",&orden);
            if(orden==1||orden==0)
            {
                if(ll_sort(pArrayListEmployee,employee_CmpId,orden)==0)
                {
                    todoOk=1;
                }
            }
            break;
        case 2:
            printf("Ingrese 1 para ordenar de manera ascendente y 0 de manera descendente: \n");
            fflush(stdin);
            scanf("%d",&orden);
            if(orden==1||orden==0)
            {
                if(ll_sort(pArrayListEmployee,employee_CmpNombre,orden)==0)
                {
                    todoOk=1;
                }
            }
            break;
        case 3:
            printf("Ingrese 1 para ordenar de manera ascendente y 0 de manera descendente: \n");
            fflush(stdin);
            scanf("%d",&orden);
            if(orden==1||orden==0)
            {
                if(ll_sort(pArrayListEmployee,employee_CmpHorasTrabajdas,orden)==0)
                {
                    todoOk=1;
                }
            }
            break;
        case 4:
            printf("Ingrese 1 para ordenar de manera ascendente y 0 de manera descendente: \n");
            fflush(stdin);
            scanf("%d",&orden);
            if(orden==1||orden==0)
            {
                if(ll_sort(pArrayListEmployee,employee_CmpSueldo,orden)==0)
                {
                    todoOk=1;
                }
            }
            break;
        case 5:
            break;
        }

    }

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \return int retorna 0 si algun puntero es nulo o si el usuario cancela sobreescribir,
 *                      1 si se guardan de manera correcta
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    char confirma;
    int cant;
    Employee* auxEmpleado=NULL;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* f;
        if((f=fopen(path,"r"))!=NULL)
        {
            printf("Cuidado se van a sobreescribir los datos\n");
            printf("Desea continuar?: \n");
            fflush(stdin);
            scanf("%c", &confirma);
        }
        if(f==NULL || confirma == 's')
        {
            f = fopen(path,"w");
            if(f == NULL)
            {
                printf("No se pudo abrir el archivo\n");
            }
            fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
                cant = fprintf(f,"%d,%s,%d,%d\n"
                               ,auxEmpleado->id
                               ,auxEmpleado->nombre
                               ,auxEmpleado->horasTrabajadas
                               ,auxEmpleado->sueldo
                              );
                if(cant !=0)
                {
                    todoOk = 1;
                }

            }

        }
        fclose(f);
    }
    return todoOk;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* nombre del archivo
 * \param pArrayListEmployee LinkedList* puntero a la lista
 * \return int retorna 0 si algun puntero es nulo o si el usuario cancela sobreescribir,
 *                      1 si se guardan de manera correcta
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    char confirma;
    Employee* auxEmpleado=NULL;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        FILE* f;
        if((f=fopen(path,"rb"))!=NULL)
        {
            printf("Cuidado se van a sobreescribir los datos\n");
            printf("Desea continuar?: \n");
            fflush(stdin);
            scanf("%c", &confirma);
        }
        if(f==NULL || confirma == 's')
        {
            f = fopen(path,"wb");
            if(f == NULL)
            {
                printf("No se pudo abrir el archivo\n");
            }
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado = (Employee*)ll_get(pArrayListEmployee,i);
                fwrite(auxEmpleado, sizeof(Employee),1, f);
            }
            todoOk = 1;
        }
        fclose(f);
    }

    return todoOk;
}

