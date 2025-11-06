//Cabecera de funciones publicas
#include "MENUS/Public.h"

int main(){

	srand(time(NULL)); //Inizializa el generador de numeros aleatorios
	
	while(1){

		actEXTRA(); //Actualiza referencia del extra
		
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
				I_TablaMejoras();

			break;

			case OPCIONES:      
				I_Opciones();

			break;

			case PARTIDA:       
				I_Partida();

			break;

			case TAB:            
				I_Tab();

			break;

		}
	
	}
	
	return 0;
}