//MENU PRINCIPAL DEL JUEGO

#include "Public.h"

typedef enum{

	EXIT,       // 0 -> No hay sub Menu
	Opcion1,    // 1 -> Arriba
	Opcion2     // 2 -> Abajo
	
} subCursor;

typedef enum{
	
	EXIT_H,     // 0 -> H subiste mucho
	Clicker,    // 1
	Base,       // 2
	EffBase,    // 3
	Potencia,   // 4
	Ran,        // 5
	TAutom,     // 6
	EfAutom,    // 7
	Opciones,   // 8
	Partida,    // 9
	EXIL_L      //10 -> L bajaste mucho
	
} Cursor;



static struct{ //Definicion de todos los frames del menu, CONST
	//Punteros a cadenas constantes - - -

	subCursor sCURSOR; //Memoria de si existe un submenu y su posicion (NO-arriba-abajo)

	Cursor CURSOR; //Memoria de donde esta el usuario en el menu.
	
	int SURE; //Variable Auxiliar de seguro	(0-> nada || 1-> Seguro?)

	char *MENU[9];
	//- 1*Clicker, 2*Base, 3*Eficiencia de Base, 4*Potencia, 5*Ran#, 6*Autom retraso, 7*Autom Efficiencia, 8*Opciones, 9*partida 
	char *SUBMENU[5];
	//- 1*Manual, 2*Autom, 3*Cargar, 4*Guardar, 5*Seguro

	
	
} FRAME = {
	
	.sCURSOR = EXIT,
	.CURSOR = Clicker,

	.MENU = {
		[ 0] = "Clicker",
		[ 1] = "Mej. Base",
		[ 2] = "Mej. Eficiencia Base",
		[ 3] = "Mej. Potencia",
		[ 4] = "Mej. Ran#",
		[ 5] = "Mej. Tiempo Autom",
		[ 6] = "Mej. Eficiencia Autom",
		[ 7] = "Opciones",
		[ 8] = "Partida"
		
		
	},
	.SUBMENU = {
		[ 0] = "Manual",
		[ 1] = "Automatico",
		[ 2] = "Cargar",
		[ 3] = "Guardar",
		[ 4] = "Seguro?"
		
	}
	
};

//Prototipos
void F_Menu();
void C_Menu(char, int *);

//Funcion inicializadora y loop del menu
void I_Menu(int *GENERAL_CURSOR){

	while(*GENERAL_CURSOR == 1){

        F_Menu();

        C_Menu(getKEY(), GENERAL_CURSOR);
    }

}

void F_Menu(){ //El menu mas importante OMG
	
	system("cls");

	printf("-Menu- -TAB para consultar Datos-\n\n");
	
	//Funcion de diseccion de todas las opciones del menu
	for(Cursor i = Clicker; i < Partida; i++){
		
		if(FRAME.CURSOR == i){ //Seleccionado

			if(FRAME.sCURSOR != EXIT){ //Seleccionado en subMenu
				printf("-%s-  ", FRAME.MENU[i]);

				int j = 0;
				if(i == Clicker){ j += 0;}
				else if(i == Partida){ j += 2;}

				if(FRAME.sCURSOR == Opcion1){    
					printf("[%s] || -%s-", FRAME.SUBMENU[j], FRAME.SUBMENU[j+1]);
				}
				if(FRAME.sCURSOR == Opcion2){ 							
					printf("-%s- || [%s]", FRAME.SUBMENU[j], FRAME.SUBMENU[j+1]);
				}

				if(FRAME.SURE == 1){
					printf(" -> %s", FRAME.SUBMENU[j+2]);
				}

			}else{ //Selecciona solo la opcion
				printf("[%s]\n", FRAME.MENU[i]);

			}

		}else{ //No seleccionado
			printf("-%s-\n", FRAME.MENU[i]);

		}
		
	}
	
}

void C_Menu(char KEY, int *GENERAL_CURSOR){ //Calculo del menu

	switch(KEY){

		case 'U': //Mover el cursor hacia arriba
        	
			if(FRAME.sCURSOR == EXIT){
				FRAME.CURSOR++; 
			}else{
				FRAME.sCURSOR = Opcion1;
			}

        break;

        case 'D': //Mover el cursor hacia abajo
        	
		if(FRAME.sCURSOR == EXIT){
				FRAME.CURSOR--; 
			}else{
				FRAME.sCURSOR = Opcion2;
			}

        break;

        case 'L': //Salir de un submenu
            

        break;

        case 'R': //Enter, entrar a otro menu u aun submenu
            

        break;

        case 'T': //Para ver temporalmente el menu de informacion extra
            

        break;

	}

	KEY = 0; //Tecla leida

}