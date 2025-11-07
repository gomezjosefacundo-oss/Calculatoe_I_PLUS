//Definiciones de la animacion inicial

#include "Public.h"


//Prototipos
void F_Intro();
void C_Intro(char);


static struct{ //Definicion de constantes de animacion.
    //Punteros a cadenas constantes - - -
    char *INTRO[12];
    char VERCION[20];
    char AUTOR[20];
    //- Secuencia de animacion (9), + info compilacion (3)	
    
} FRAME = {
    
    .VERCION = "1.4.37.28+11", //Vercion TOTAL | Grandes añadidos | Pequeños añadidos | Bugs
    .AUTOR = "Signal oH",

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
        
        [ 9] = "Ver.",
        [10] = "By:",
        [11] = "                       [Presione -Derecha- para Continuar] \n"
        
        
    }

};

void I_Intro(){

    while(G_FRAME.CURSOR == INTRO){

        F_Intro();

        C_Intro(getKEY());
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

    printf("%s %s \n", FRAME.INTRO[9], FRAME.VERCION);
    Sleep(100);
    
    printf("%s %s \n\n\n\n\n", FRAME.INTRO[10], FRAME.AUTOR);
    Sleep(100);

    printf("%s", FRAME.INTRO[11]);
}

void C_Intro(char KEY){

    switch(KEY){

        case 'R':
            G_FRAME.CURSOR = MENU; //Cambio al menu principal

        break;


    }

}