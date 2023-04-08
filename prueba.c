#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define CHANCE 3
#define GEN 10
#define TABL 0
#define VEC 1


// A RECORDAME CADA VEZ QUE HAGA UNA FUNCION QUE TENGA DE ENTRADA A TABLERO Y VECINOS DE PONERLOS EN ESE ORDEN
void inicializar(char tablero[][N],char vecinos[][N]);
void print_arr(char tablero[][N],char modo);
void actualizar_vecinos(char tablero[][N],char vecinos[][N]);
char contar_vecinos(char vecinos[][N],int i, int j);
void actualizar_tablero(char tablero[][N],char vecinos[][N]);


int main(void){
    char tablero[N][N]; 
    char vecinos[N][N];
    inicializar(tablero,vecinos);

    for(int i=1;i<=GEN;i++){            
        printf("------GENERACIÓN %d------\n",i);
        print_arr(tablero,TABL);
        actualizar_tablero(tablero,vecinos);
        actualizar_vecinos(tablero,vecinos);
    }
    //printf("hola");


    return 0;
}

void inicializar(char tablero[][N],char vecinos[][N]){ // LE PASO LA MATRIZ Y ME COMPLETA CON 1 EN LUGARES RANDOM
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tablero[i][j] = (rand()%CHANCE==0) ? 1:0 ;

        }
    }
    actualizar_vecinos(tablero,vecinos);
}

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

void actualizar_tablero(char tablero[][N],char vecinos[][N]){
    char nueva_celda,celda,nro_vecinos;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            nueva_celda=0;
            celda=tablero[i][j];
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

            tablero[i][j]=nueva_celda;
        }
    }

}
