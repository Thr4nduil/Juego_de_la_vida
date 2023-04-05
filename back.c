#include <stdio.h>

#include <stdlib.h>
#include <time.h>

#define CHANCE 7
#define FIL 10
#define COL 10

int main(void){

    char tablero[FIL][COL];

    for(int i=0;i<FIL;i++){
        for(int j=0;j<COL;j++){
            tablero[i][j]=(rand()%CHANCE==0) ? 1:0 ;

        }
    }

   // ESTO HAY QUE CAMBIARLO AL FRONT END
    for(int i=0;i<FIL;i++){
        for(int j=0;j<COL;j++){
            printf("%d",tablero[i][j]);
        }
        printf("\n");
    }

    return 0;
}