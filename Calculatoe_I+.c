//Cabecera de funciones publicas
#include "MENUS/Public.h"

int main(){

	//Comienzo a contar el tiempo transcurrido
	G_FRAME.GAME_VALUE->RELOJ.INIT = Tiempo_s(); //Referencia de comienzo de ejecucion

	srand(time(NULL)); //Inizializa el generador de numeros aleatorios
	
	while(1){
		
		switch(G_FRAME.CURSOR){
			case INTRO:
				I_Intro();

			break;
 			
			case MENU:
				I_Menu();

 			break;

			case CLICKER:       
				I_Clicker();

			break;

			case TABLA_MEJORAS: 
 			
			break;

			case OPCIONES:      
 			
			break;

			case PARTIDA:       
 			
			break;

			case TAB:            

			break;

		}
	
	}
	
	return 0;
}