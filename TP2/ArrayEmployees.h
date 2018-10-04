#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000


typedef struct{
int id;
char name[51];
char lastName[51];
float salary;
int idSector;
int isEmpty;
}Employee;


/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);


/** \brief busca el primer indice del array vacio
 *
 * \param list Employee*
 * \param len int
 * \return devuelve -1 si no encuentra indice vacio y si lo encuentra devuelve el indice
 *
 */
int buscarLibre(Employee* list, int len);


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
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);


/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len, int id);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);


/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int len);


/** \brief muestra un empleado
*
* \param emp Employee*
* \return int
*
*/
int mostrarEmpleado(Employee emp);


/** \brief pide datos de un empleado
*
* \param list Employee*
* \param length int
* \return int
*
*/
int agregarEmpleado(Employee* list, int len);


/** \brief elimina salto de linea en cadena
*
* \param cadena char
*
*/
void sacarSaltoDeLinea(char cadena[]);


/** \brief da de baja a un empleado
*
* \param list Employee*
* \param length int
* \return int
*
*/
int bajaEmployee(Employee* list, int len);


/** \brief modifica el nombre o apellido o salario o sector de un empleado
*
* \param list Employee*
* \param length int
* \return int
*
*/
int modificarEmployee(Employee* list, int len);

/** \brief calcula el total y el promedio de los salarios y cuantos superan el salario promedio
*
* \param list Employee*
* \param length int
* \return int
*
*/
int salarios(Employee* list, int len);


int menu();
