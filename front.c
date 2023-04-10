#include <stdio.h>
#include "front.h"



void print_arr(char arr[][N],char modo){ // modo 0 imprime tablero con "*" en los lugares donde hay 1. modo 1 imprime el valor directamente
    //printf("imprimiendo en modo %d\n",modo);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!modo){
                printf("|%c",(arr[i][j]==1) ? '*': ' '); // EN ESTE MODO, PREGUNTA SI EL VALOR DE LA CELDA ES 1 E IMPRIME UN "*"
            }
            else{
                printf("|%d",arr[i][j]); // EN ESTE MODO IMPRIME DIRECTAMENTE EL VALOR DE LA CELDA
            }

        }
        printf("|\n");
    }

}
