#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "funciones.h"

int main()
{
    int opcion, flagPrimerOperando=0, flagSegundoOperando=0;
    float x =0 ,y=0, resultadoSuma, resultadoResta, resultadoDivision, resultadoMultiplicacion;
    float resultadoFactorial1, resultadoFactorial2;

    do{ //se usa do while porque al menos se tiene que ejecutar una vez
        system("CLS");  //limpia pantalla
        printf("**********MENU**********");
        if (flagPrimerOperando==0){
            printf("\n\n1.Ingresar 1er operando (A=x)");
        }
        else{
             printf("\n\n1.Ingresar 1er operando (A= %.3f)",x);//cambia la x por el primer numero, si es que lo agregaron
        }
        if (flagSegundoOperando==0){
            printf("\n2.Ingresar 2do operando (B=y)");
        }
        else{
            printf("\n2.Ingresar 2do operando (B= %.3f)",y); //cambia la y por el segundo numero, si es que lo agregaron
        }

        printf("\n3.Calcular todas las operaciones");
        printf("\n4.Informar resultados");
        printf("\n5.Salir");

        printf("\n\nSeleccione opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                system("CLS");
                printf("Ingrese 1er operando: ");
                scanf("%f",&x);
                flagPrimerOperando=1; //flag de estado para saber que se ingreso al menos una vez un numero
                system("CLS");
                break;

            case 2:
                system("CLS");
                printf("Ingrese 2do operando: ");
                scanf("%f",&y);
                flagSegundoOperando=1; //flag de estado para saber que se ingreso al menos una vez un numero
                system("CLS");
                break;

            case 3:
                resultadoSuma=suma(x,y); //llama a la funcion suma y le envia dos numeros
                resultadoResta=resta(x,y); //llama a la funcion resta y le envia dos numeros
                resultadoDivision=division(x,y); //llama a la funcion division y le envia dos numeros
                resultadoMultiplicacion=multiplicacion(x,y);//llama a la funcion multiplicacion y le envia dos numeros
                resultadoFactorial1=factorial(x); //llama a la funcion factorial y le envia un solo numero
                resultadoFactorial2=factorial(y);
                system("CLS");
                break;

            case 4:
                system("CLS");
                if (flagPrimerOperando==0 || flagSegundoOperando==0){ //verifica si no se ingresó alguno de los dos numeros
                    printf("No se ha ingresado un operando\n");
                }
                if (flagPrimerOperando==1 && flagSegundoOperando==0){ //si se ingreso un solo numero se muestra solo ese
                    if(x<0){ //verifica que el numero sea negativo
                        printf("No se puede calcular el factorial de numeros negativos\n");
                    }
                    else{
                        printf("El factorial de %.3f es %.3f\n",x, resultadoFactorial1);
                    }
                }

                if (flagPrimerOperando==0 && flagSegundoOperando==1){
                    if(y<0){//verifica que el numero sea negativo
                        printf("No se puede calcular el factorial de numeros negativos\n");
                    }
                    else{
                        printf("El factorial de %.3f es %.3f\n",y, resultadoFactorial2);
                    }

                }

                if (flagPrimerOperando==1 && flagSegundoOperando==1){
                    printf("\nEl resultado de %.3f + %.3f es %.3f", x, y , resultadoSuma);
                    printf("\nEl resultado de %.3f - %.3f es %.3f", x, y , resultadoResta);
                    if (y==0){
                        printf("\nNo es posible dividir por cero");
                    }
                    else{
                        printf("\nEl resultado de %.3f / %.3f es %.3f", x, y , resultadoDivision);
                    }
                    printf("\nEl resultado de %.3f * %.3f es %.5f", x, y , resultadoMultiplicacion);
                    if(x<0 && y>=0){ //verifica si uno de los numeros es negativo y si lo es muestra el otro
                        printf("\nNo se puede calcular el factorial de numeros negativos\n");
                        printf("El factorial de %.3f es %.3f\n",y, resultadoFactorial2);
                    }
                    if(y<0 && x>=0){ //verifica si uno de los numeros es negativo y si lo es muestra el otro
                        printf("\nNo se puede calcular el factorial de numeros negativos\n");
                        printf("El factorial de %.3f es %.3f\n",x, resultadoFactorial1);
                    }
                    if(y>=0 && x>=0){ //verifica que los dos numeros sean positivos
                      printf("\nEl factorial de %.3f es %.3f y el factorial de %.3f es %.3f\n",x, resultadoFactorial1, y, resultadoFactorial2);
                    }
                    if(y<0 && x<0){ //verifica que los dos sean negativos
                            printf("\nNo se puede calcular el factorial de numeros negativos\n");
                    }
                }

                system("pause"); //hace una pausar en el programa
                break;

            case 5:
                break;


            default:
                system("CLS");
                printf("Opcion incorrecta\n");
                system("pause");
                break;

        }

    }while(opcion!=5); //sale del while solamente con 5


    return 0;
}


