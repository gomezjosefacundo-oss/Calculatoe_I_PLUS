//Definicion de todas las funciones globales de uso en todo el juego
#include "MENUS/Public.h"



float Click_Event(int EVENTO, int AUTOM){ //EVETO "0"-Promedio(numero) "1"-Real+!TEXTO! //AUTOM "0"-Manual "1"-Autom

    DEF_GAME_VALUE *TEMP_GAME = G_FRAME.GAME_VALUE; //Acorte de sintaxis

    float Base = TEMP_GAME->VALORES.Base;
    float EffBase = TEMP_GAME->VALORES.Eficiencia;
    float Potencia = TEMP_GAME->VALORES.Potencia;

    float Ran = TEMP_GAME->VALORES.Ran;

    float EffAutom = TEMP_GAME->VALORES.Eff_Autom;
    
    float EXTRA_Base = TEMP_GAME->VALORES.EXTRA_Base;
    float EXTRA_Porcentual = TEMP_GAME->VALORES.EXTRA_Porcentual; 

    float Click = (float)pow(Base*EffBase, Potencia);

    //CLICK CON PROMEDIOS
    if(EVENTO == 0){
        Click *= (Ran + 0.2); //Promedia con Ran fijo
    }
    else{ //De rand real
        Click *= (Ran + (float)(rand() % 41)/100);
    }

    //CLICK EN AUTOM O MANUAL
    if(AUTOM == 0){
        //No toca el numero...

    }else{
        Click *= EffAutom;
    }

    //GENERADOR DE EVENTOS
    if(EVENTO == 0){
        //No toca el numero...
    }
    else{ //De rand real
        
        if( (float)(rand() % 101)/100 <= EXTRA_Porcentual){

            float EXTRAt = EXTRA_Base + rand() % 27;

            Click *= EXTRAt;

            printf("[!EXTRA! -> x%.0f]\n", EXTRAt);
        }

    }

    return Click;

}

reloj_s Tiempo_s(){ //Consulta de clock(), pero en segundos.

    return clock()/CLOCKS_PER_SEC;
}

char getKEY(){ //Detrector de tecla, retornando de forma global la tecla usada.

    enum TECLAS{ //Por getch
    NULO = 0,
    ARRIBA = 72,
    ABAJO = 80,
    IZQUIERDA = 75,
    DERECHA = 77,
    TAB = 9

    };

    char KEY = 0; //0 - Nada || U D L R - Flechas (Click igual a R) || T - El tabulador

    while(KEY == 0){
    
        KEY = getch();

        switch(KEY){
            case ARRIBA:
                KEY = 'U';

            break;

            case ABAJO:
                KEY = 'D';

            break;

            case IZQUIERDA:
                KEY = 'L';

            break;

            case DERECHA:
                KEY = 'R';

            break;

            case TAB:
                KEY = 'T';

            break;

            default:
                KEY = 0;

            break;


        }
    }
    return KEY;

}