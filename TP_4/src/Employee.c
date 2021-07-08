#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

/** \brief busca lugar en la memoria dinamica para la estructura, la inicializa y devuelve la direccion de memoria
 *
 * \return Employee* es NULL si no encuentra lugar
 *
 */
Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));
    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id =0;
        strcpy(nuevoEmpleado->nombre," ");
        nuevoEmpleado->horasTrabajadas = 0;
        nuevoEmpleado->sueldo = 0;

    }
    return nuevoEmpleado;

}
/** \brief crea un nuevo empleado en memoria dinamica y lo carga con los parametros pasados
 *
 * \param idStr char* puntero para el id
 * \param nombreStr char* puntero para el nombre
 * \param horasTrabajadasStr char* puntero para las horas trabajadas
 * \param char*strSueldo puntero para el sueldo
 * \return Employee* retorna null si no encuentra memoria o alguno de los parametros pasados no pasan la validacion
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char*strSueldo)
{

       Employee* nuevoEmpleado = employee_new();
    if(nuevoEmpleado != NULL)
    {
        if(!(employee_setId(nuevoEmpleado,atoi(idStr))&&
                employee_setNombre(nuevoEmpleado,nombreStr)&&
             employee_setHorasTrabajadas(nuevoEmpleado,atoi(horasTrabajadasStr))&&
                employee_setSueldo(nuevoEmpleado,atoi(strSueldo)))
          )
        {
            employee_delete(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }

    }

 return nuevoEmpleado;

}
/** \brief libera el espacio de memoria
 *
 * \param this Employee* puntero del elemento a eliminar
 * \return void
 *
 */
void employee_delete(Employee* this)
{
    free(this);
}

/** \brief setea el id del empleado
 *
 * \param this Employee* puntero a la estructura del empleado
 * \param id int valor que se va a cargar
 * \return int retorna 0 si el puntero es nulo o el id es menor a cero,
 *         1 si se cargo de manera correcta
 *
 */
int employee_setId(Employee* this,int id)
{
     int todoOk = 0;
    if(this!=NULL && id>0)
    {
        this->id = id;
        todoOk = 1;
    }

    return todoOk;

}
/** \brief toma el id del empleado de la estructura y se la pasa a una variable
 *
 * \param this Employee* puntero de la estructura
 * \param id int* puntero que recibe el id del empleado
 * \return int retorna 0 si alguno de los punteros es nulo,
 *              1 si esta todo ok
 *
 */
int employee_getId(Employee* this,int* id)
{

 int todoOk =0;

    if(this!=NULL && id !=NULL)
    {
        *id = this->id;
        todoOk = 1;

    }
    return todoOk;
}
/** \brief setea el nombre del empleado
 *
 * \param this Employee* puntero a la estructura del empleado
 * \param nombre char* valor que se va a cargar
 * \return int retorna 0 si el puntero es nulo o si el valor pasado supera el tamaño del espacio designado al nombre,
 *         1 si se cargo de manera correcta
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
  int todoOk = 0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)<128)
    {
        strcpy(this->nombre,nombre);
        todoOk = 1;
    }

    return todoOk;

}
/** \brief toma el nombre del empleado de la estructura y se lo pasa a una variable
 *
 * \param this Employee* puntero de la estructura
 * \param  nombre char* puntero que recibe el nombre del empleado
 * \return int retorna 0 si alguno de los punteros es nulo,
 *              1 si esta todo ok
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{

   int todoOk=0;
    if(this!=NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }
    return todoOk;

}

/** \brief setea las horas trabajadas del empleado
 *
 * \param this Employee* puntero a la estructura del empleado
 * \param sueldo int valor que se va a cargar
 * \return int retorna 0 si el puntero es nulo o el valor pasado es menor a cero,
 *         1 si se cargo de manera correcta
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
/** \brief toma las horas trabajadas del empleado de la estructura y se la pasa a una variable
 *
 * \param this Employee* puntero de la estructura
 * \param horasTrabajadas int* puntero que recibe las horas trabajadas del empleado
 * \return int retorna 0 si alguno de los punteros es nulo,
 *              1 si esta todo ok
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
     int todoOk =0;

    if(this!=NULL && horasTrabajadas !=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;

    }
    return todoOk;
}

/** \brief setea el sueldo del empleado
 *
 * \param this Employee* puntero a la estructura del empleado
 * \param horasTrabajadas int valor que se va a cargar
 * \return int retorna 0 si el puntero es nulo o el valor pasado es menor a cero,
 *         1 si se cargo de manera correcta
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
 {int todoOk = 0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
 }
 /** \brief toma el sueldo del empleado de la estructura y se la pasa a una variable
 *
 * \param this Employee* puntero de la estructura
 * \param sueldo int* puntero que recibe el sueldo del empleado
 * \return int retorna 0 si alguno de los punteros es nulo,
 *              1 si esta todo ok
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
     int todoOk =0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;

    }
    return todoOk;

}

/** \brief Muestra los campos de un empleado
 *
 * \param this Employee* puntero al empleado
 * \return int retorna 0 si el putero es nulo o si no valida los getters y 1 si esta ok
 *
 */
int mostrarEmpleado(Employee* this)
{
    int todoOk = 0;
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    if(this!=NULL
            &&  employee_getId(this,&id)
            && employee_getNombre(this,nombre)
            && employee_getHorasTrabajadas(this, &horas)
            && employee_getSueldo(this,&sueldo)
      )
    {
        printf("%4d  %15s       %3d          %3d \n"
               ,this->id
               ,this->nombre
               ,this->horasTrabajadas
               ,this->sueldo);
        todoOk = 1;
    }
    return todoOk;
}


/** \brief compara los Id de los empleados
 *
 * \param a void* puntero al primer empleado
 * \param b void* puntero al segundo empleado
 * \return int retorna 0 si el igual o alguno de los punteros es nulo,
 *                     1 si el primer es mayor que el segundo,
 *                    -1 si el primer es menor que el segundo
 *
 */

int employee_CmpId(void* a,void* b)
{
    int retorno=0;
    Employee* emp1;
    Employee* emp2;
    if(a!=NULL && b!=NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        if(emp1->id > emp2->id)
        {
            retorno=1;
        }
        else if(emp1->id < emp2->id)
        {
            retorno= -1;
        }
    }
    return retorno;
}
/** \brief compara los nombres de los empleados
 *
 * \param a void* puntero al primer empleado
 * \param b void* puntero al segundo empleado
 * \return int retorna 0 si el igual o alguno de los punteros es nulo,
 *                     1 si el primer es mayor que el segundo,
 *                    -1 si el primer es menor que el segundo
 *
 */
int employee_CmpNombre(void* a,void* b)
{
    int retorno=0;
    Employee* emp1;
    Employee* emp2;
    if(a!=NULL && b!=NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;
        retorno = strcmp(emp1->nombre,emp2->nombre);
    }
    return retorno;
}
/** \brief compara las horas trabajadas de los empleados
 *
 * \param a void* puntero al primer empleado
 * \param b void* puntero al segundo empleado
 * \return int retorna 0 si el igual o alguno de los punteros es nulo,
 *                     1 si el primer es mayor que el segundo,
 *                    -1 si el primer es menor que el segundo
 *
 */
int employee_CmpHorasTrabajdas(void* a,void* b)
{
   int retorno=0;
    Employee* emp1;
    Employee* emp2;
    if(a!=NULL && b!=NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        if(emp1->horasTrabajadas > emp2->horasTrabajadas)
        {
            retorno=1;
        }
        else if(emp1->horasTrabajadas < emp2->horasTrabajadas)
        {
            retorno= -1;
        }
    }
    return retorno;

}
/** \brief compara los sueldos de los empleados
 *
 * \param a void* puntero al primer empleado
 * \param b void* puntero al segundo empleado
 * \return int retorna 0 si el igual o alguno de los punteros es nulo,
 *                     1 si el primer es mayor que el segundo,
 *                    -1 si el primer es menor que el segundo
 *
 */
int employee_CmpSueldo(void* a,void* b)
{
    int retorno=0;
    Employee* emp1;
    Employee* emp2;
    if(a!=NULL && b!=NULL)
    {
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;

        if(emp1->sueldo > emp2->sueldo)
        {
            retorno=1;
        }
        else if(emp1->sueldo < emp2->sueldo)
        {
            retorno= -1;
        }
    }
    return retorno;
}

