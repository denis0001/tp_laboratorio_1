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

int menu();
int initEmployees(Employee* list, int len);
int buscarLibre(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len, int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int len);
int mostrarEmpleado(Employee emp);
int agregarEmpleado(Employee* list, int len);
void sacarSaltoDeLinea(char cadena[]);
int bajaEmployee(Employee* list, int len);
int modificarEmployee(Employee* list, int len);
int salarios(Employee* list, int len);
int esNumerico(char str[]);
