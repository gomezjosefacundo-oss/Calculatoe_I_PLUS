#include <stdio.h> //Libreria estandar
#include <stdlib.h> //Para el system("pause")
#include <windows.h> //Para el Sleep(.) y getch()
//
#include "MEJORAS.c" //Definiciones Estructura MEJORAS
#include "VARIABLES.c" //Defino todas las variables del juego
#include "FUNCIONES.c" //Defino todas las funciones del juego (getKEY - )

#include "MENU.c" //Escritura facil de el funcionamiento del menu
//



int main(){
	
	F_Intro();
	
	while(1){
		
		F_Menu();
		//C_Menu(getKEY());
		
		system("pause");
	
	}
	
	return 0;
}