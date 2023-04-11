#ifndef _BACK_H_
#define _BACK_H_

// ------------ FUNCIONES ------------
extern char *inicializar (int, int);

extern void actualizar_tablero(char * , int fils , int cols);

extern void actualizar_vecinos(char tablero[][N],char vecinos[][N]);

int contar_vecinos(char* , int , int , int , int);

#endif
