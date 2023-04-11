<<<<<<< HEAD
int main(void){
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "back.h"
#include "front.h"

#define N 10
#define CHANCE 3
#define GEN 10
#define TABL 0
#define VEC 1
#define FILS N
#define COLS N

int main(void){

    char *tablero = inicializar(FILS , COLS);

    for(int i=1;i<=GEN;i++){            
        printf("------GENERACIÓN %d------\n",i);
        print_arr(tablero,TABL);
        actualizar_tablero(tablero);
    }

    free(tablero);
    return 0;
}



















































//culo sucio
>>>>>>> 7bd53c7c2b5648bde3f99c023ee90058bb201f9b
