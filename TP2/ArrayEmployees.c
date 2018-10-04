#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#define TAM 1000

/** \brief Verifica si el valor recibido es numérico
 *
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]){
    int i=0;
    while(str[i] !='\0'){
        if(str[i]<'0' || str[i] >'9')
            return 0;
        i++;
    }
    return 1;
}


/** \brief menu de opciones
 *
 * \return devuelve la opcion elegida
 *
 */

int menu()
{
    int opcion;
    system("cls");
    printf("****MENU****\n\n");
    printf("1- Altas\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informar\n");
    printf("5- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
    int flag= -1, i;

    if (list != NULL && len !=0){
        flag=0;
        for (i= 0; i<len; i++){
            list[i].isEmpty=1;
        }
    }
    return flag;
}


/** \brief busca el primer indice del array vacio
 *
 * \param list Employee*
 * \param len int
 * \return devuelve -1 si no encuentra indice vacio y si lo encuentra devuelve el indice
 *
 */
int buscarLibre(Employee* list, int len)
{
    int indice = -1, i;

    for (i=0; i< len; i++)
    {
        if (list[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int flag = -1, i;

    i= buscarLibre(list, TAM);

    Employee aux;

    if(i != -1){
        aux.id = id;
        strcpy(aux.name, name);
        strcpy(aux.lastName, lastName);
        aux.salary = salary;
        aux.idSector = sector;
        aux.isEmpty =0;
        list[i] = aux;
        flag = 0;
        }

    return flag;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len, int id)
{
    int i, flag = -1;

    for(i=0; i<len; i++){
        if(list[i].isEmpty == 0 && list[i].id == id){
            flag = i;
            break;
        }
    }
return flag;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
    int i, flag = -1;

    i = findEmployeeById(list, len, id);

    if (i != -1){
        list[i].isEmpty = 1;
        flag = 0;
    }
    return flag;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{

    Employee aux;

    int i, j;
    if (order == 1){
        for (i=0; i<len-1; i++){
            for (j=i+1; j<len; j++){
                if (list[i].isEmpty == 0){
                    if (strcmp(list[i].lastName,list[j].lastName) > 0){
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                    else if (strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].idSector > list[j].idSector){
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
    }
    else if (order == 2){
        for (i=0; i<len-1; i++){
            for (j=i+1; j<len; j++){
                if (list[i].isEmpty == 0){
                    if (strcmp(list[i].lastName,list[j].lastName) < 0){
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                    else if (strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].idSector < list[j].idSector){
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
    }
    return 0;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int len)
{
    int i;
    system("cls");
    printf("**** Lista de los empleados ****\n");
    printf("ID\tNombre\t\t\tApellido\t\tSalario\t\t\tSector\n");
    for (i=0; i<len; i++){
        if (list[i].isEmpty == 0){
            mostrarEmpleado(list[i]);
        }
    }
    printf("\n");
    return 0;
}

/** \brief muestra un empleado
*
* \param emp Employee*
* \return int
*
*/
int mostrarEmpleado(Employee emp)
{
    printf("%d\t%s\t\t\t%s\t\t\t%.2f\t\t\t%d\n", emp.id, emp.name, emp.lastName, emp.salary, emp.idSector);
    return 0;
}

/** \brief pide datos de un empleado
*
* \param list Employee*
* \param length int
* \return int
*
*/
int agregarEmpleado(Employee* list, int len)
{
    int indice, flag=-1;
    int sector;
    char name[51], lastName[51];
    float salary;

    indice = buscarLibre(list, len);

    system("cls");
    printf("*** Alta empleado ***\n");
    fflush(stdin);
    printf("\nIngrese nombre: ");
    fgets(name, 51, stdin);
    sacarSaltoDeLinea(name);
    fflush(stdin);
    printf("\nIngrese apellido: ");
    sacarSaltoDeLinea(lastName);
    fgets(lastName, 51, stdin);
    sacarSaltoDeLinea(lastName);
    printf("\nIngrese sueldo: ");
    fflush(stdin);
    scanf("%f", &salary);
    printf("\nIngrese sector: ");
    scanf("%d", &sector);
    flag = addEmployee(list, len, indice, name, lastName, salary, sector);
    return flag;

}

/** \brief elimina salto de linea en cadena
*
* \param cadena char
*
*/
void sacarSaltoDeLinea(char cadena[]){
    if (cadena[strlen(cadena)-1]=='\n'){
        cadena[strlen(cadena)-1]='\0';
    }
}

/** \brief da de baja a un empleado
*
* \param list Employee*
* \param length int
* \return int
*
*/
int bajaEmployee(Employee* list, int len){
    int i, id;
    char respuesta;
    i = printEmployees(list, len);
    printf("\nIngrese el ID a dar de baja: ");
    scanf("%d",&id);
    i = findEmployeeById(list, len, id);
    if (i == -1){
        printf("\nNo existe ese ID en elsistema\n");
    }
    else{
        printf("\nID\tNombre\t\t\tApellido\t\tSalario\t\t\tSector\n");
        mostrarEmpleado(list[i]);
        printf("\nDesea dar de baja al empleado? s/n: ");
        fflush(stdin);
        scanf("%c",&respuesta);
        if (respuesta == 's' || respuesta == 'S'){
            removeEmployee(list, len, id);
            printf("\nEmpleado dado de baja correctamente.\n");
        }
        else{
            printf("\nBaja cancelada.\n");
        }
    }
    return 0;
}

/** \brief modifica el nombre o apellido o salario o sector de un empleado
*
* \param list Employee*
* \param length int
* \return int
*
*/
int modificarEmployee(Employee* list, int len){
    char name[51], lastName[51];
    int i, id, sector, opcion, flag = 0;
    float salary;
    i = printEmployees(list, len);
    printf("\nIngrese el ID a modificar: ");
    scanf("%d",&id);
    i = findEmployeeById(list, len, id);
    if (i == -1){
        printf("\nNo existe ese ID en el sistema\n");
    }
    else{
        system("cls");
        printf("*** Modificacion de empleado ***\n");
        printf("\n1- Modificar nombre --%s--\n",list[i].name);
        printf("\n2- Modificar apellido --%s--\n",list[i].lastName);
        printf("\n3- Modificar salario --%.2f--\n",list[i].salary);
        printf("\n4- Modificar sector --%d--\n",list[i].idSector);
        printf("\n5- Cancelar.\n");
        printf("\nElija una opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                fflush(stdin);
                printf("\nIngrese nuevo nombre: ");
                fgets(name, 51, stdin);
                sacarSaltoDeLinea(name);
                strcpy(list[i].name, name);
                flag = 1;
                break;
            case 2:
                fflush(stdin);
                printf("\nIngrese nuevo apellido: ");
                fgets(lastName, 51, stdin);
                sacarSaltoDeLinea(lastName);
                strcpy(list[i].lastName, lastName);
                flag = 1;
                break;
            case 3:
                printf("\nIngrese nuevo salario: ");
                scanf("%f",&salary);
                list[i].salary = salary;
                flag = 1;
                break;
            case 4:
                printf("\nIngrese el nuevo sector: ");
                scanf("%d",&sector);
                list[i].idSector = sector;
                flag = 1;
                break;
            case 5:
                break;
            default:
                printf("\nOpcion incorrecta.");
                break;
        }
        if (flag)
            printf("\nSe modifico al empleado correctamente.\n\n");
    }
    return 0;
}

/** \brief calcula el total y el promedio de los salarios y cuantos superan el salario promedio
*
* \param list Employee*
* \param length int
* \return int
*
*/
int salarios(Employee* list, int len){
    float salariosTotal = 0;
    float promedioSalarios;
    int i, contadorSalarios = 0, contadorEmpleados = 0;
    for (i=0; i<len; i++){
        if (list[i].isEmpty == 0){
            salariosTotal = salariosTotal + list[i].salary;
            contadorSalarios++;
        }
    }
    promedioSalarios = salariosTotal/contadorSalarios;
    for (i=0; i<len; i++){
        if ((list[i].isEmpty == 0) && (list[i].salary > promedioSalarios))
            contadorEmpleados++;
    }
    system("cls");
    printf("*** Salarios ***\n");
    printf("\nEl monto total de los salarios es: %.2f\n",salariosTotal);
    printf("\nEl promedio de los salarios es: %.2f\n",promedioSalarios);
    printf("\nLos empleados que superan el promedio son: %d\n\n",contadorEmpleados);
    return 0;
}

