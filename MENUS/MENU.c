//MENU PRINCIPAL DEL JUEGO

#include "../HEADER/Public.h"

/// @brief Prototipo funcion FRAME
void F_Menu();
/// @brief Prototipo funcion CALCULADORA
void C_Menu(char);

typedef enum{

	EXIT,       // 0 -> No hay sub Menu
	Opcion1,    // 1 -> Arriba
	Opcion2     // 2 -> Abajo
	
} subCursor;

typedef enum{
	
	EXIT_H = -1,//-1 -> H subiste mucho
	Clicker,    // 0
	Base,       // 1
	EffBase,    // 2
	Potencia,   // 3
	Ran,        // 4
	TAutom,     // 5
	EfAutom,    // 6
	Opciones,   // 7
	Partida,    // 8
	EXIT_L      // 9 -> L bajaste mucho
	
} Cursor;



/// @brief Definicion de todos los frames del menu, CONST
static struct{ 

	/// @brief Memoria de si existe un submenu y su posicion (NO-arriba-abajo)
	subCursor sCURSOR; 

	/// @brief Memoria de donde esta el usuario en el menu.
	Cursor CURSOR; 
	
	/// @brief Variable Auxiliar de seguro (0-> nada || 1-> Seguro?)
	int SURE; 

	/// @brief 1*Clicker, 2*Base, 3*Eficiencia de Base, 4*Potencia, 5*Ran#, 6*Autom retraso, 7*Autom Efficiencia, 8*Opciones, 9*partida
	char *MENU[9]; 
	
	/// @brief 1*Manual, 2*Autom, 3*Cargar, 4*Guardar, 5*Seguro
	char *SUBMENU[5];
	
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

//Funcion inicializadora y loop del menu
void I_Menu(){

	while(G_FRAME.CURSOR == MENU){

        F_Menu();

        C_Menu(getKEY());
    }

}

void F_Menu(){ //El menu mas importante !!!!!!!!!!!!OMG!!!!!!!!!!!!!!!!!!
	
	system("cls");

	printf("-Menu- -TAB para consultar Datos-\n\n");
	
	//Funcion de diseccion de todas las opciones del menu
	for(Cursor i = Clicker; i < EXIT_L; i++){
		
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
					printf(" -> %s\n", FRAME.SUBMENU[j+2]);
				}else{
					printf("\n");
				}

			}else{ //Selecciona solo la opcion
				printf("[%s]\n", FRAME.MENU[i]);

			}

		}else{ //No seleccionado
			printf("-%s-\n", FRAME.MENU[i]);

		}
		
	}
	
}

void C_Menu(char KEY){ //Calculo del menu

	switch(KEY){

		case 'U': //Mover el cursor hacia arriba
        	
			if(FRAME.sCURSOR == EXIT){ //No existe un submenu

				FRAME.CURSOR--; 
				if(FRAME.CURSOR == EXIT_H) FRAME.CURSOR = Partida;

			}else{ //Existe un submenu
				FRAME.sCURSOR = Opcion1;
			}

        break;

        case 'D': //Mover el cursor hacia abajo
        	
		if(FRAME.sCURSOR == EXIT){ //No existe submenu

				FRAME.CURSOR++; 
				if(FRAME.CURSOR == EXIT_L) FRAME.CURSOR = Clicker;

			}else{ //Existe un submenu
				FRAME.sCURSOR = Opcion2;
			}

        break;

        case 'L': //Salir de un submenu
            FRAME.sCURSOR = EXIT;
			FRAME.SURE = 0;

        break;

        case 'R': //Enter, entrar a otro menu u aun submenu
            
			switch(FRAME.CURSOR){

				case Clicker: //Posicionado en clicker

					if(FRAME.sCURSOR == EXIT){ //Si no existe el submenu, lo habilita
						FRAME.sCURSOR = Opcion1;

					}
					else{ //Si ya existia ejecuta el proximo menu

						//modifica el menu del puntero y el dato
						G_FRAME.CURSOR = CLICKER;
						G_FRAME.DATA = FRAME.sCURSOR;

						//Quita el submenu
						FRAME.sCURSOR = EXIT;

					}

				break;

				case Base:  //Posicionado en Base  
					G_FRAME.CURSOR = TABLA_MEJORAS;
					G_FRAME.DATA = 0;
				
				break;
				
				case EffBase: //Posicionado en EffBase
					G_FRAME.CURSOR = TABLA_MEJORAS;
					G_FRAME.DATA = 1;
				
				break;
				
				case Potencia: //Posicionado en Potencia
					G_FRAME.CURSOR = TABLA_MEJORAS;
					G_FRAME.DATA = 2;
				
				break;
				
				case Ran: //Posicionado en Ran 
					G_FRAME.CURSOR = TABLA_MEJORAS;
					G_FRAME.DATA = 3;
				
				break;
				
				case TAutom: //Posicionado en TAutom 
					G_FRAME.CURSOR = TABLA_MEJORAS;
					G_FRAME.DATA = 4;
				
				break;
				
				case EfAutom: //Posicionado en EfAutom
					G_FRAME.CURSOR = TABLA_MEJORAS;
					G_FRAME.DATA = 5;

				break;
				
				case Opciones://Posicionado en Opciones
					//modifica el menu del puntero
					G_FRAME.CURSOR = OPCIONES;
				
				break;
			
				case Partida: //Posicionado en Partida

					if(FRAME.sCURSOR == EXIT){ //Si no existe el submenu, lo habilita
						FRAME.sCURSOR = Opcion1;

					}
					else{

						if(FRAME.SURE == 1){
							
							//Mofica el puntero de menu y envia el dato
							G_FRAME.CURSOR = PARTIDA;
							G_FRAME.DATA = FRAME.sCURSOR;

							//Resetea la confirmacion y sale del submenu
							FRAME.SURE = 0;
							FRAME.sCURSOR = EXIT;


						}else{
							FRAME.SURE = 1;
						}

					}

				break;

				default:
				break;


			}

        break;

        case 'T': //Para ver el menu de informacion extra
            
			G_FRAME.CURSOR = TAB;

        break;

	}

}