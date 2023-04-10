#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "back.h"

#define CHANCE 7


char* inicializar(int fil , int col){ // LE PASO LA MATRIZ Y ME COMPLETA CON 1 EN LUGARES RANDOM
    //Reservo espacio de memoria
    char *tablero = (char*) malloc((fil*col)*sizeof(char));

    for(int i=0 ; i<fil ; i++){
        for(int j=0 ; j<col ; j++){
            tablero[i*fil + j] = (rand()%CHANCE == 0) ? 1:0 ;
        }
    }
    return tablero;
}

void actualizar_tablero(char *tablero , int fils , int cols){
    char  nueva_celda,celda,nro_vecinos;

    //TODO: necesito vecinos

    for(int i=0 ; i<fils ; i++){
        for(int j=0 ; j<cols ; j++){
            nueva_celda=0;
            celda=tablero[i*fils + j];
            nro_vecinos=vecinos[i][j];
            //printf("celda: %d, vecinos %d\n",celda,nro_vecinos);

            /*Any live cell with two or three live neighbours survives.
            Any dead cell with three live neighbours becomes a live cell.
            All other live cells die in the next generation. Similarly, all other dead cells stay dead.*/

            if(celda && (nro_vecinos==2 || nro_vecinos==3)){
                //printf("La celda sobrevive\n"); //ESTO DESPUES SE PUEDE CAMBIAR A 1 SOLA LINEA PERO COMO NO ME ANDABA LO DEJE ASI
                nueva_celda=1;
            }
            if(!celda && nro_vecinos==3){
                //printf("La celda revive\n");
                nueva_celda=1;
            }

            tablero[i*fils + j]=nueva_celda;
        }
    }

}

void actualizar_vecinos(char tablero[][N],char vecinos[][N]){ // LE PASO LA MATRIZ TABLERO Y ME ACTUALIZA LA MATRIZ VECINOS CON LA CANTIDAD DE VECINOS VIVOS QUE VE CADA CELDA
    //printf("actualizando vecinos\n");
    for(int i=0;i<N;i++){ //RECORRE LA MATRIZ VECINOS Y ACTUALIZA SU NUMERO
        for(int j=0;j<N;j++){
            vecinos[i][j]=contar_vecinos(tablero,i,j); //PARA CADA POSICION COLOCA EL NUMERO DE VECINOS
        }
    }

}

char contar_vecinos(char tablero[][N],int i, int j){ // LE PASO LA MATRIZ TABLERO Y UNA CELDA EN PARTICULAR (i,j) Y BARRE SUS 8 VECINOS CONTANDO LA CANTIDAD DE 1s QUE HAY
    char vecinos=0;

    for(int x=j-1;x<=j+1;x++){
        for(int y=i-1;y<=i+1;y++){
            if(x>=0 && x<N && y>=0 && y<N && (x!=j || y!=i)){ // CONDICIONES PARA ASEGURAR QUE EL VALOR A PREGUNTAR ESTÉ DENTRO DE LOS LÍMITES DEL TABLERO BY CHATGPT
                vecinos+=tablero[y][x];
            }
        }
    }
    return vecinos;
}

