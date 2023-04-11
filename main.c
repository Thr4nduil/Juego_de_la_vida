#include <stdio.h>
#include "back.h"
#include "front.h"

#define N 10
#define GEN 10
#define MODO 0
#define VEC 1
#define FILS N
#define COLS N

int main(void){

    char *tablero = inicializar(FILS , COLS);

    for(int i=1;i<=GEN;i++){            
        printf("------GENERACIÓN %d------\n",i);
        print_arr(tablero,MODO);
        actualizar_tablero(tablero,FILS,COLS);
    }

    free(tablero);
    return 0;
}
