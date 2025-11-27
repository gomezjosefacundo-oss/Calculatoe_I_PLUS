//Definiciones de la animacion inicial

#include "../HEADER/Public.h"

/// @brief Prototipo funcion FRAME
void F_Intro();
/// @brief Prototipo funcion CALCULADORA
void C_Intro(char);


/// @brief Definicion de constantes de animacion.
static struct{ 

    
    /// @brief Cadenas de caracteres de animacion (0-8) + vercion, autor y final (9-11)
    char *INTRO[12];
    char VERCION[20];
    char AUTOR[20];
    
} FRAME = {

    .AUTOR = "Signal oH",
    .VERCION = "1.4.43.34+24",

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

void F_Intro(){

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