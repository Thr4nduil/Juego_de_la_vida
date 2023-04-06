#include <stdio.h>
#include "front.h"



void print_tablero(int **tablero,int fil, int col){
    for(int i=0;i<fil;i++){
        for(int j=0;j<col;j++){
            printf("%d",tablero[i][j]);
        }
        printf("\n");
    }

 }