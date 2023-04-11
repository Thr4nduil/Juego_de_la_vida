#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "back.h"

#define N 10
#define GEN 10
#define MODO 0
#define VEC 1
#define CHANCE 7

char* inicializar(int fil , int col){ // LE PASO LA MATRIZ Y ME COMPLETA CON 1 EN LUGARES RANDOM
    //Reservo espacio de memoria
    char *tablero = (char*) malloc((fil*col)*sizeof(char));

    for(int i=0 ; i<fil ; i++){
        for(int j=0 ; j<col ; j++){
            tablero[i*col + j] = (rand()%CHANCE == 0) ? 1:0 ;
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
            celda=tablero[i*cols + j];
            nro_vecinos=vecinos[i][j];

            //printf("celda: %d, vecinos %d\n",celda,nro_vecinos);

            if(celda && (nro_vecinos==2 || nro_vecinos==3)){
                //printf("La celda sobrevive\n"); //ESTO DESPUES SE PUEDE CAMBIAR A 1 SOLA LINEA PERO COMO NO ME ANDABA LO DEJE ASI
                nueva_celda=1;
            }
            if(!celda && nro_vecinos==3){
                //printf("La celda revive\n");
                nueva_celda=1;
            }

            tablero[i*cols + j]=nueva_celda;
        }
    }

}

void get_vecinos(char *tablero , int fils , int cols){ // LE PASO LA MATRIZ TABLERO Y ME ACTUALIZA LA MATRIZ VECINOS CON LA CANTIDAD DE VECINOS VIVOS QUE VE CADA CELDA
    //printf("actualizando vecinos\n");
    for(int i=0 ; i<fils ; i++){ //RECORRE LA MATRIZ VECINOS Y ACTUALIZA SU NUMERO
        for(int j=0 ; j<cols ; j++){
            vecinos[i][j]=contar_vecinos(tablero,i,j); //PARA CADA POSICION COLOCA EL NUMERO DE VECINOS
        }
    }

}


/**
 * @brief Recibe el vector tablero, indicando la celda particular. 
 *        Cuenta la cantidad de celdas vecinas que estan vivas (1)
 * 
 * @param tablero   vector que representa al tablero
 * @param pos_fil   fila de la celda a analizar
 * @param pos_col   columna de la celda a analizar
 * @param fils      cantidad de filas del tablero
 * @param cols      cantidad de columnas del tablero
 * 
 * @return cant_vecinos     cantidad de vecinos para una celda determinada
 */
int contar_vecinos(char *tablero , int pos_fil, int pos_col , int fils , int cols){
    int cant_vecinos = 0;

    for(int i=pos_fil-1 ; i<=pos_fil+1 ; i++){
        for(int j=pos_col-1 ; j<=pos_col+1 ; j++){
            // Condiciones para asegurar que se lee dentro de la matriz
            if((i>=0 && i<=fils) && (j>=0 && j<=cols) && (i!=pos_fil || j!=pos_col)){
                cant_vecinos+=tablero[i*cols + j];
            }
        }
    }
    return cant_vecinos;
}
