//Definiciones de la animacion inicial

#include "Public.h"

static struct{ //Definicion de constantes de animacion.
    //Punteros a cadenas constantes - - -
    char *INTRO[12];
    //- Secuencia de animacion (9), + info compilacion (3)	
    
} FRAME = {
    
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
        
        
    }

};

//Prototipos
void F_Intro();
void C_Intro(char, int *);

void I_Intro(int *GENERAL_CURSOR){

    while(*GENERAL_CURSOR == 0){

        F_Intro();

        C_Intro(getKEY(), GENERAL_CURSOR);
    }

}

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

}

void C_Intro(char KEY, int *GENERAL_CURSOR){

    switch(KEY){

        case 'R':
            *GENERAL_CURSOR = 1; //Cambio al menu principal

        break;


    }

}