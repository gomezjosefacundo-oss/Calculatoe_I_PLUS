//Cabecera de funciones publicas
#include "HEADER/Public.h"

int main(){

	normalizarDinamicos(); //Añade referencias faltantes a las estructuras
	
	srand(time(NULL)); //Inizializa el generador de numeros aleatorios
	
	#ifdef ADMIN
	ModificarValores();
	#endif

while(1){
		
		actTIME();
		actEXTRA(); //Actualiza referencia del extra
		
		G_FRAME.P_MENUS[G_FRAME.CURSOR]();
		
	}
	
	return 0;
}