//MENU PRINCIPAL DEL JUEGO

#include "../HEADER/Public.h"

/// @brief Prototipo funcion FRAME
void F_Opciones();
/// @brief Prototipo funcion CALCULADORA
void C_Opciones(char);

typedef enum{
	EXIT_H = -1,  //-1
	OpDelay,      // 0
	OpClick,      // 1
	OpCostClick,  // 2
    EXIT_L        // 3 -> Unicamente de referencia 
	
} Cursor;



/// @brief Definicion de todos los frames de las opciones
static struct{ 

	/// @brief Memoria de donde esta el usuario en el menu.
	Cursor CURSOR; 

	/// @brief 1*Mostrar Delay 2*Mostrar Click 
	char *MENU[3];

	/// @brief 1*Mostrar Delay 2*Mostrar Click 
	char *infoMENU[3];
	
} FRAME = {

	.CURSOR = OpDelay,

	.MENU = {
		[ 0] = "Mostrar Delay",
		[ 1] = "Mostrar Click",
		[ 2] = "Mostrar coste de click"

	},

	.infoMENU = {
		[ 0] = "Muestra el delay en el modo automatico",
		[ 1] = "Muestra el valor real entre clicks",
		[ 2] = "Muestra el coste equivalente en clicks y clicks-hora necesarios para una mejora"

	}
	
};


void I_Opciones(){

	while(G_FRAME.CURSOR == OPCIONES){

        F_Opciones();

        C_Opciones(getKEY());
    }

}

void F_Opciones(){
	
	OPCIONES_T *REF_Opciones = &G_FRAME.GAME_VALUE.OPCIONES;

	system("cls");

    printf("-Opciones- \n0 > Desactivado || 1 > Activado\n"); //Bienvenida

	printf("INFO: %s\n\n", FRAME.infoMENU[FRAME.CURSOR]);
	
	//Funcion de diseccion de todas las opciones del menu
	for(Cursor i = OpDelay; i < EXIT_L; i++){
		
		if(FRAME.CURSOR == i){ //Seleccionado
			printf("[%s]", FRAME.MENU[i]);

		}
        else{ //No seleccionado
			printf("-%s-", FRAME.MENU[i]);

		}

        printf(" > %0d \n", *REF_Opciones->P_OPCIONES[i] % 2);
		
	}
	
}

void C_Opciones(char KEY){

	OPCIONES_T *REF_Opciones = &G_FRAME.GAME_VALUE.OPCIONES;

	switch(KEY){

		case 'U': //Mover el cursor hacia arriba
        	
				FRAME.CURSOR--; 
				if(FRAME.CURSOR == EXIT_H) FRAME.CURSOR = EXIT_H+1;

        break;

        case 'D': //Mover el cursor hacia abajo
        	
		    FRAME.CURSOR++; 
			if(FRAME.CURSOR == EXIT_L) FRAME.CURSOR = EXIT_L-1;

        break;

        case 'L': // Salir de las opciones
			
            G_FRAME.CURSOR = MENU; // Pasa el cursor al menu

        break;

        case 'R': //Enter, cambiar el estado de opcion SELECCIONADA
            
			*REF_Opciones->P_OPCIONES[FRAME.CURSOR] = ~(*REF_Opciones->P_OPCIONES[FRAME.CURSOR]);

        break;

	}

}