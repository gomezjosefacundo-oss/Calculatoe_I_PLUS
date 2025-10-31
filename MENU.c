//Acceso de funciones que actualizan la pantalla y hacen anclaje entre menus

//Todos los frames a usar en el menu (al ser todos constantes de caracteres), se guardaran en la estructura FRAME por orden.

//Todas las funciones que usan los frames para actualizar la pantalla empezaran con "F_" para distingirse como Frames
//Todas las funciones que calculan los frames para actualizar el estado del cursor empezaran con "C_"

//Se añade "m" para el cursor, al ser el cursor principal del menu

typedef enum{
	
	EXIT,       // 0 -> No hay sub menu
	Opcion1,    // 1 -> Arriba
	Opcion2     // 2 -> Abajo
	
} mF_subCursor;

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
	
} mF_Cursor;



struct{ //Definicion de todos los frames del menu, CONST
	//Punteros a cadenas constantes - - -
	
	mF_subCursor sCURSOR; //Memoria de si existe un submenu y su posicion (NO-arriba-abajo)

	mF_Cursor CURSOR; //Memoria de donde esta el usuario en el menu.
	
	int SURE; //Variable Auxiliar de seguro	(0-> nada || 1-> Seguro?)

	char *INTRO[12];
	//- Secuencia de animacion (9), + info compilacion (3)
	char *MENU[9];
	//- 1*Clicker, 2*Base, 3*Eficiencia de Base, 4*Potencia, 5*Ran#, 6*Autom retraso, 7*Autom Efficiencia, 8*Opciones, 9*partida 
	char *SUBMENU[5];
	//- 1*Manual, 2*Autom, 3*Cargar, 4*Guardar, 5*Seguro

	
	
}FRAME = {
	
	.sCURSOR = EXIT,
	.CURSOR = Clicker,
	
	.INTRO = {
		[ 0] = "                                       ..\n",
		[ 1] = "                                      ....\n",
		[ 2] = "                                  ............\n",
		[ 3] = "                            ......................\n",
		[ 4] = "                                -Calculatoe I-\n",
		[ 5] = "                              ......................\n",
		[ 6] = "                                  ............\n",
		[ 7] = "                                      ....\n",
		[ 8] = "                                       ..\n\n\n",
		
		[ 9] = "Ver. 1.4.33.26+ \n",
		[10] = "By: XDemonKillX \n\n\n\n\n",
		[11] = "                       [Presione -Derecha- para Continuar] \n"
		
		
	},
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


void F_Intro(){ //Animacion de inicio

	system("cls");
	
	printf("\n\n\n\n\n");
	Sleep(150);
    
	for(int i = 0; i < 9; i++){
		printf("%s", FRAME.INTRO[i]);
		Sleep(250);
	}
	
    Sleep(350);

    for(int i = 9; i < 12; i++){
		printf("%s", FRAME.INTRO[i]);
		Sleep(100);
	}
	
	//Funcion que detecta pasar a Menu principal para salir del inicio
	while(getKEY() != 'R');

}

void F_Menu(){ //El menu mas importante OMG
	
	system("cls");

	printf("-Menu- -TAB para consultar Datos-\n\n");
	
	//Funcion de diseccion de todas las opciones del menu
	for(mF_Cursor i = Clicker; i < Partida; i++){
		
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

void C_Menu(char KEY){ //Calculo del menu

	switch(KEY){

		case 'U':
            

        break;

        case 'D':
            

        break;

        case 'L':
            

        break;

        case 'R':
            

        break;

        case 'T':
            

        break;

	}

}