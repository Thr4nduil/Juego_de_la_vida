#include <stdio.h>
#include "termlib.h"    /*Enable the use of getch and getche see termlib.c*/

//// gcc color.c termlib.c -o color


#define FIN_ARCHIVO  'Q'

int main (void)
{

    int evento;


	clrscr();		 // Clear Screen
	gotoxy(20,3);
	printf(GREEN_TEXT "Color Test (Press 'Q' to quit) \n" WHITE_TEXT);
	


    changemode(BUFFERED_OFF); // Turns terminal line buffering off (see termlib.c)

    while((evento = getch())!= FIN_ARCHIVO)  //Si hay evento
 

    changemode(BUFFERED_ON);  // Turns terminal line buffering on (see termlib.c)
}

