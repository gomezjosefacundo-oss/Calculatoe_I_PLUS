//MENU PRINCIPAL DEL JUEGO

#include "Public.h"

//Prototipos
void F_Opciones();
void C_Opciones(char);

typedef enum{
	EXIT_H = -1,  //-1
	OpDelay,      // 0
	OpClick,      // 1
    EXIT_L        // 2 -> Unicamente de referencia 
	
} Cursor;



static struct{ //Definicion de todos los frames de las opciones


	Cursor CURSOR; //Memoria de donde esta el usuario en el menu.

	char *MENU[2];
	//- 1*Mostrar Delay 2*Mostrar Click 

	
	
} FRAME = {

	.CURSOR = OpDelay,

	.MENU = {
		[ 0] = "Mostrar Delay",
		[ 1] = "Mostrar Click"
		
		
	}
	
};

//Funcion inicializadora y loop del menu
void I_Opciones(){

	while(G_FRAME.CURSOR == OPCIONES){

        F_Opciones();

        C_Opciones(getKEY());
    }

}

void F_Opciones(){ //El menu mas importante OMG
	
	system("cls");

    printf("-Opciones- \n0 > Desactivado || 1 > Activado\n"); //Bienvenida
	
	//Funcion de diseccion de todas las opciones del menu
	for(Cursor i = OpDelay; i < EXIT_L; i++){
		
		if(FRAME.CURSOR == i){ //Seleccionado
			printf("[%s]", FRAME.MENU[i]);

		}
        else{ //No seleccionado
			printf("-%s-", FRAME.MENU[i]);

		}

        int BUFF = 0;

        if(i == 0) BUFF = G_FRAME.GAME_VALUE->OPCIONES.ShowDelay;
        if(i == 1) BUFF = G_FRAME.GAME_VALUE->OPCIONES.ShowClick;

        printf(" > %01d\n", BUFF);
		
	}
	
}

void C_Opciones(char KEY){ //Calculo del menu

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

        case 'R': //Enter, entrar a otro menu u aun submenu
            
			switch(FRAME.CURSOR){

				case OpDelay: //Alternar estado de la opcion de Delay

					if(G_FRAME.GAME_VALUE->OPCIONES.ShowDelay) 
                        G_FRAME.GAME_VALUE->OPCIONES.ShowDelay = 0;
                    else G_FRAME.GAME_VALUE->OPCIONES.ShowDelay = 1;
				break;

				case OpClick:  //Alterna el estado de la opcion de Click
					
                    if(G_FRAME.GAME_VALUE->OPCIONES.ShowClick) 
                        G_FRAME.GAME_VALUE->OPCIONES.ShowClick = 0;
                    else G_FRAME.GAME_VALUE->OPCIONES.ShowClick = 1;
				break;
				
			}

        break;

	}

}