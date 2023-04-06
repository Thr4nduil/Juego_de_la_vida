#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "back.h"

#define CHANCE 7


char **inicializar (int fil, int col){

    char tablero[fil][col];

    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            tablero[i][j]= (rand()%CHANCE==0) ? 1:0 ;

        }
    }


    return tablero;
}

// Ver lo de los vecinos 
// Actualizar el tablero y puntero
