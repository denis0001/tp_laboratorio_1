#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#define TAM 1000

int main()
{
    char seguir = 's';
    int r, flag = 0;
    Employee list[TAM];
    initEmployees(list, TAM);

    do
    {
        switch(menu())
        {
        case 1:
            r = agregarEmpleado(list, TAM);
            if (r != -1){
                 flag = 1;
            }
            system("pause");
            break;
        case 2:
            if(flag > 0){
                r = modificarEmployee(list, TAM);
                system("pause");
                break;
            }
            if (flag == 0){
                printf("No hay datos cargados.\n");
                system("pause");
                break;
            }
        case 3:
            if(flag > 0){
                r = bajaEmployee(list, TAM);

                system("pause");
                break;
            }
            if (flag == 0){
                printf("No hay datos cargados.\n");
                system("pause");
                break;
            }
        case 4:
            if(flag > 0){
                r = sortEmployees(list, TAM, 1);
                r = printEmployees(list, TAM);
                system("pause");
                r = salarios(list, TAM);
                system("pause");
                break;
            }
            if (flag == 0){
                printf("No hay datos cargados.\n");
                system("pause");
                break;
            }
        case 5:
            seguir = 'n';
            break;

        default:
            printf("Opcion incorrecta.\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');

    return 0;
}
