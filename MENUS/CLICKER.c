#include "Public.h"

//Prototipos
void F_Clicker();
void C_Clicker();

//Defino enum para data
typedef enum{
    MANUAL = 1,
    AUTOMATICO = 2

} DATA;

typedef enum{

    NADA,        //0 - No aplica
    TABABULADOR,         //1 - Espera un UP
    BLOQUEADO,   //2 - BLoqueado
    DESBLOQUEADO //3- Desbloqueado 

}TAB_UP_ENUM;

//Definiciones del menu (existe static struct FRAME, enums necesarios y otros)
static struct{
    int First; //Verificador de mensaje de entrada 1-Escribre 0-Ignora
    int Verify_C; //Indicador de click dado por el C_
    int Verify_T; //Accion de mostrar valor de CLick con TAB
    int Verify_TAB_UP; //Para bloquear el modo autom y que no se salga sin querer
    int BLOQUEO; //Estado absoluto
    int BLOQUEOdelta; //Detecta cuando cambia de estado el bloqueo
    float Click; //Valo pasado por C_ del click
    int Time_Autom; //Memoria de espera para un click automatico
    int Time_Trans; //Contador de tiempo

} FRAME = {
    .First = 1,
    .Verify_C = 0,
    .Verify_TAB_UP = NADA,
    .BLOQUEO = DESBLOQUEADO,
    .BLOQUEOdelta = 0,
    .Click = 0,
    .Time_Autom = 10000,
    .Time_Trans = 0

};


//Funcion inicializadora y loop del menu
void I_Clicker(){

    FRAME.First = 1; //Habilita el mensaje de entrada
    FRAME.Time_Autom = G_FRAME.GAME_VALUE->VALORES.Time_Autom; //Recupera referencia de delay de click

    while(G_FRAME.CURSOR == CLICKER){

        F_Clicker();

        C_Clicker();   

    }

}

//El generador del frame en si
void F_Clicker(){

    if(FRAME.First == 1){
        system("cls");
        printf("Apreta TAB para ver el valor de cuanto ganaras");
        if(G_FRAME.DATA == MANUAL) printf(" por 500 clicks! \nApreta derecha para Sumar!\n");
        if(G_FRAME.DATA == AUTOMATICO) printf(" por 1 hora! \nTu delay es %.2f por click!\n", (float)FRAME.Time_Autom/1000);
        
        printf("\nApreta TAB + UP para bloquear el menu y no salir sin querer!\n\n");


        Sleep(300);

        FRAME.First = 0;
    }

    
    if(FRAME.Verify_C == 1){
        
        FRAME.Verify_C = 0;
        
        printf("\nAns = %.7g \n", G_FRAME.GAME_VALUE->VALORES.Ans);
        
        if(G_FRAME.GAME_VALUE->OPCIONES.ShowClick) printf("Click = %.7g\n", FRAME.Click); //Mostrar valor click
        
        printf("\n");
    }

    if(FRAME.BLOQUEOdelta == 1){
        FRAME.BLOQUEOdelta = 0;

        if(FRAME.BLOQUEO == DESBLOQUEADO) printf("[! ESTAS DESBLOQUEADO !]");
        if(FRAME.BLOQUEO == BLOQUEADO) printf("[! ESTAS BLOQUEADO !]");
    }
    
    if(G_FRAME.DATA == AUTOMATICO){
        
        if(G_FRAME.GAME_VALUE->OPCIONES.ShowDelay){
            
            printf("-> %.7gs ", (float)FRAME.Time_Trans/1000); //Muestra delay
        } 
    }

    if(FRAME.Verify_T == 1){ //Mostrar TABABULADOR

        if(G_FRAME.DATA == MANUAL){
            printf("\n\n!Ganaras > %.7gp < con 500 clicks!\n\n", Click_Event(0, 0)*500);

        }
        if(G_FRAME.DATA == AUTOMATICO){
            printf("\n\n!Ganaras > %.7gp < en 1 hora!\n\n", Click_Event(0, 1)*(3600/((float)FRAME.Time_Autom/1000)));
        }

        Sleep(1000);
        FRAME.Verify_T = 0; //Leido

        FRAME.Verify_TAB_UP = TABABULADOR; //TEMPORAL PARA LEER UP y bloquear o desbloquear
    }

}

//El que evalua a que llamar o que hacer con cada accion
void C_Clicker(){
    
    char KEY;

    if(G_FRAME.DATA == MANUAL || kbhit()){ //Lee tecla si esta en manual (para click) o para salir del clicker en Automatico
        
        
        while(GetAsyncKeyState(VK_RIGHT)){
            Sleep(30);
        }
        KEY = getKEY();
        

    }else{
        KEY = 'A';
    }

    switch(KEY){
        case 'R': //Click indicado
            if(G_FRAME.DATA != AUTOMATICO){ // Prevencion de clicks manuales en modo automatico
               
                actEXTRA(); //Actualiza referencia del extra tras un click manual

                FRAME.Verify_C = 1;
    
                FRAME.Click = Click_Event(1, 0);
    
                G_FRAME.GAME_VALUE->VALORES.Ans += FRAME.Click;
            }

        break;

        case 'L': //Deja el menu
            
            if(FRAME.BLOQUEO == DESBLOQUEADO){

                G_FRAME.CURSOR = MENU;
                G_FRAME.DATA = 0; //Mata el dato
            }

        break;

        case 'U':

            if(FRAME.Verify_TAB_UP == TABABULADOR){
                if(FRAME.BLOQUEO == DESBLOQUEADO){
                    FRAME.BLOQUEO = BLOQUEADO;
                }else{
                    FRAME.BLOQUEO = DESBLOQUEADO;
                }

                FRAME.BLOQUEOdelta = 1;
            }

        break;

        case 'T':
            FRAME.Verify_T = 1; //Habilita leer TAB

        break;

        case 'A': //Tecla de automatico
            
            Sleep(100);
            FRAME.Time_Trans += 100;

            if(FRAME.Time_Trans >= FRAME.Time_Autom){

                actEXTRA(); //Actualiza referencia del extra tras un click autom

                FRAME.Verify_C = 1;
    
                FRAME.Click = Click_Event(1, 1);
                G_FRAME.GAME_VALUE->VALORES.Ans += FRAME.Click;

                FRAME.Time_Trans = 0;
            }


        break;

    }

    FRAME.Verify_TAB_UP = NADA;
}