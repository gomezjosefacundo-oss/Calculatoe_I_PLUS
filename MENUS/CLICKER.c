#include "Public.h"

//Prototipos
void F_Clicker();
void C_Clicker(char);

//Definiciones del menu (existe static struct FRAME, enums necesarios y otros)
static struct{
    int First; //Verificador de mensaje de entrada 1-Escribre 0-Ignora
    int Verify_C; //Indicador de click dado por el C_
    float Click; //Valo pasado por C_ del click

} FRAME = {
    .First = 1,
    .Verify_C = 0,
    .Click = 0

};


//Funcion inicializadora y loop del menu
void I_Clicker(){

    FRAME.First = 1; //Habilita el mensaje de entrada

    while(G_FRAME.CURSOR == CLICKER){

        F_Clicker();

        C_Clicker(getKEY());
    }

}

//El generador del frame en si
void F_Clicker(){

    if(FRAME.First == 1){
        system("cls");
        printf("Apreta derecha para Sumar!\n");

        FRAME.First = 0;
    }

    if(FRAME.Verify_C == 1){
        
        FRAME.Verify_C = 0;
        
        printf("Ans = %f \n\n", G_FRAME.GAME_VALUE->VALORES.Ans);

    }

}

//El que evalua a que llamar o que hacer con cada accion
void C_Clicker(char KEY){

    switch(KEY){
        case 'R': //Click indicado
            FRAME.Verify_C = 1;

            FRAME.Click = Click_Event(1, 0);

            G_FRAME.GAME_VALUE->VALORES.Ans += FRAME.Click;

        break;

        case 'L': //Deja el menu
            G_FRAME.CURSOR = MENU;
            G_FRAME.DATA = 0; //Mata el dato

        break;


    }

}