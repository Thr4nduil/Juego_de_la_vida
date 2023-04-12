#include <stdio.h>
#include <unistd.h>
#include "back.h"
#include "front.h"

#define MODO 0
#define VEC 1
#define TABL 0

int main(void){

    // Consigo numero de filas y columnas
    printf("Ingrese numero de filas y columnas con el siguiente formato NxM con valores enteros entre 1 y 9: ");
    char FILS = getchar()-48;
    char x = getchar();
    char COLS = getchar()-48;
    char Err = getchar();
    fflush(stdin);

    if(FILS < 1 || FILS > 9 || COLS < 1 || COLS > 9 || Err != 10 || (x != 'x' && x!='X')){
        printf("Los valores ingresados no respetan el formato pedido");
        return 0;
    }

    // Consigo generacion
    printf("Ingrese el numero de generaciones, valor entero entre 01 y 99: ");
    char N1 = getchar()-48;
    char N2 = getchar()-48;
    Err = getchar();
    char GEN;
    fflush(stdin);

    if(N1 >= 0 && N1 <= 9 && N2 >= 0 && N2 <= 9 && Err == 10){
        GEN = N1*10 + N2;
    }
    else{
        printf("Los valores ingresados no respetan el formato pedido");
        return 0;
    }

    char *tablero = inicializar(FILS , COLS);

    for(int i=1;i<=GEN;i++){            
        printf("------GENERACION %d------\n",i);
        print_tablero(tablero , FILS , COLS ,TABL);
  
        actualizar_tablero(tablero , FILS , COLS);
        sleep(0.5);
    }

    free(tablero);
    return 0;
}
