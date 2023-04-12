#include "back.h"

/**
 * @brief crea un vector/matriz tablero, que contiene a todas las celdas del tablero
 * 
 * @param fil cantidad de filas del tablero
 * @param col cantidad de columnas del tablero
 * 
 * @return tablero  puntero que apunta al espacio reservado para el tablero
 */
char* inicializar(int fil , int col){
    //Reservo espacio de memoria
    char *tablero = (char*) malloc((fil*col)*sizeof(char));
    srand (time(NULL));

    for(int i=0 ; i<fil ; i++){
        for(int j=0 ; j<col ; j++){
            tablero[i*col + j] = (rand()%CHANCE == 0) ? 1:0 ;
        }
    }
    return tablero;
}

/**
 * @brief Actualiza al tablero acorde a las reglas del juego
 * 
 * @param tablero   puntero al tablero
 * @param fils      cantidad de filas del tablero
 * @param cols      cantidad de columnas del tablero
 */
void actualizar_tablero(char *tablero , int fils , int cols){
    char  nueva_celda,celda,nro_vecinos;

    // Vecinos
    char *vecinos = (char*) malloc((fils*cols)*sizeof(char));
    get_vecinos(tablero , vecinos , fils , cols);

    // Logica del juego
    for(int i=0 ; i<fils ; i++){
        for(int j=0 ; j<cols ; j++){
            nueva_celda=0;
            celda=tablero[i*cols + j];
            nro_vecinos=vecinos[i*cols+j];

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
    free(vecinos);
}

/**
 * @brief Calcula la cantidad de vecinos vivos que tiene cada celda
 * 
 * @param tablero 
 * @param vecinos 
 * @param fils 
 * @param cols 
 */
void get_vecinos(char *tablero , char *vecinos , int fils , int cols){ // LE PASO LA MATRIZ TABLERO Y ME ACTUALIZA LA MATRIZ VECINOS CON LA CANTIDAD DE VECINOS VIVOS QUE VE CADA CELDA
    //printf("actualizando vecinos\n");
    for(int i=0 ; i<fils ; i++){ //RECORRE LA MATRIZ VECINOS Y ACTUALIZA SU NUMERO
        for(int j=0 ; j<cols ; j++){
            vecinos[i*cols+j] = contar_vecinos(tablero,i,j,fils,cols); //PARA CADA POSICION COLOCA EL NUMERO DE VECINOS
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
