#include "funciones.h"

float suma(float primerNumero, float segundoNumero){
    return primerNumero+segundoNumero;
}

float resta(float primerNumero, float segundoNumero){
    return primerNumero-segundoNumero;
}

float division (float primerNumero, float segundoNumero){
    return primerNumero/segundoNumero;
}

float multiplicacion(float primerNumero, float segundoNumero){
    return primerNumero*segundoNumero;
}

float factorial(float numero){
    float i;
    float resultado = 1;

    for(i=numero; i>0; i--){
        resultado=resultado*i;
    }
    return resultado;
}
