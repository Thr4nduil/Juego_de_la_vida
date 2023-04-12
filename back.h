#ifndef _BACK_H_
#define _BACK_H_

// ------------ HEADERS ------------
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//------------ DEFINICIONES ------------
#define CHANCE 3   //MIENTRAS MENOR SEA MAYOR SE´RA LA CANTIDAD INICIAL

// ------------ FUNCIONES ------------
extern char *inicializar (int, int);

extern void actualizar_tablero(char * , int , int );

void get_vecinos(char* , char* , int , int);

char contar_vecinos(char* , int , int , int , int);

#endif
