//Definicion de todas las funciones globales de uso en todo el juego
#include "MENUS/Public.h"

void cappaDelay(){ //Genera un retraso en ms segun la persistencia y la velocidad de clicks por segundo....

    static float T_out = 0, T_in = 0, CPS = 0; /*Clics por segundo*/ //Referencias de tiempo internas
    static int cappa = 0, warning = 0; /*memoria de limite*/; 
    
    T_in = (float)clock()/CLOCKS_PER_SEC; //Medida de llegada
    
    CPS = 1/(T_in - T_out); //Parametro de referencia de velocidad
    
    //printf("\n\nCPS : %.4fseg. cappa = %d warining = %d\n\n", CPS, cappa, warning);
    
    if(CPS > 13) cappa += 10; //10ms mas de delay siempre que se tenga mas de 7 clicks por segundo
    else if (CPS < 9 && cappa >= 5) cappa -= 5; // Si exite limite resta cuando haya ido muy rapido 

    if(cappa >= 75 && warning >= 0){
        warning += 1;
    }else if(warning >= 0){
        warning = 0;  
    } 

    if (warning >= 20){
        cappa = 1500;
        warning = -1;
        printf("\n\n[ SI USA TRAMPAS SEA MENOS DESCARADO :D ]\n\n");
    }

    if(warning == -1){

        cappa -= 25;

        if(cappa < 75) {
            warning = 0;
            printf("\n\n[ BUENO... ESTAS LIBRE, PERO QUE NO SE REPITA XD ]\n\n");

            while(kbhit()){ //Gasta todos los clicks acumulados sin querer
                getKEY();
            }
        }

    }

    Sleep(cappa); //Delay base + Limite

    T_out = T_in; //t1 alamacena el tiempo justo antes de salir

}

float Click_Event(int EVENTO, int AUTOM){ //EVETO "0"-Promedio(numero) "1"-Real+!TEXTO! //AUTOM "0"-Manual "1"-Autom

    DEF_GAME_VALUE *TEMP_GAME = G_FRAME.GAME_VALUE; //Acorte de sintaxis

    float Base = TEMP_GAME->VALORES.Base;
    float EffBase = TEMP_GAME->VALORES.Eficiencia;
    float Potencia = TEMP_GAME->VALORES.Potencia;

    float Ran = TEMP_GAME->VALORES.Ran;

    float EffAutom = TEMP_GAME->VALORES.Eff_Autom;
    
    int EXTRA_Base = TEMP_GAME->VALORES.EXTRA_Base;
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

            int EXTRAt = EXTRA_Base + rand() % 27;

            Click *= EXTRAt;

            printf("\n[!EXTRA! -> x%d]", EXTRAt);
        }

    }

    return Click;

}

void actEXTRA(){ //Revisa y actualiza los parametros de EXTRA
    
    RELOJ_T *REF_tiempo = &G_FRAME.GAME_VALUE->RELOJ;
    VALORES_T *REF_valores = &G_FRAME.GAME_VALUE->VALORES;

    if(REF_tiempo->TIME - (REF_valores->EXTRA_LvBase + 1)*22500 >= 0 && REF_valores->EXTRA_LvBase < 8){

        REF_valores->EXTRA_LvBase += 1;

        REF_valores->EXTRA_Base += 1;

    }

    if(REF_tiempo->TIME - (REF_valores->EXTRA_LvPorc + 1)*3600 >= 0 && REF_valores->EXTRA_LvPorc < 50){

        REF_valores->EXTRA_LvPorc += 1;

        REF_valores->EXTRA_Porcentual += 0.00015;

    }

}

void ImprimirTiempo(reloj_s tiempo){ //Para mostrar tiempo en TAB

    float TIME = (float)tiempo;

    long horas = (long)floor(TIME/3600);
    TIME -= (float)horas*3600;
    
    long minutos = (long)floor(TIME/60);
    TIME -= (float)minutos*60;

    long segundos = (long)TIME;

    printf("%02ldhr %02ldm %02lds", horas, minutos, segundos);


}

void actTIME(){ //Consulta de clock(), pero en segundos.

    G_FRAME.GAME_VALUE->RELOJ.TIME = clock()/CLOCKS_PER_SEC + G_FRAME.GAME_VALUE->RELOJ.savedTIME;
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

void BarraProgrecion(){ //Muestra la progrecion del juego

    VALORES_T *REF_valores = &G_FRAME.GAME_VALUE->VALORES;

    float PONDERADO = 0;

    PONDERADO += REF_valores->Base / GLOBAL_MEJORAS.BASE[29].MAX;
    PONDERADO += REF_valores->Eficiencia / GLOBAL_MEJORAS.EFICIENCIA[20].MAX;
    PONDERADO += REF_valores->Potencia / GLOBAL_MEJORAS.POTENCIA[11].MAX;
    PONDERADO += REF_valores->Ran / GLOBAL_MEJORAS.RAN[9].MAX;
    PONDERADO += GLOBAL_MEJORAS.TI_AUTOM[9].MAX / REF_valores->Time_Autom;
    PONDERADO += REF_valores->Eff_Autom / GLOBAL_MEJORAS.EF_AUTOM[9].MAX;
    PONDERADO += REF_valores->EXTRA_LvBase / (float)8;
    PONDERADO += REF_valores->EXTRA_LvPorc / (float)50;

    PONDERADO /= (float)8;
    PONDERADO *= 112.159; //Valor porcentual

    PONDERADO -= 12.159;

    printf("%.2f%% ", PONDERADO);

    printf("[");

    int BAR = 0;
    while(PONDERADO >= 12.5){
         BAR++;
         PONDERADO -= 12.5;
         printf("/");
     }
     while(BAR < 8){
         BAR++;
         printf(".");
     }

     printf("]");

    //EN ESTE SENTIDO CADA FULL DE UNA SOLA MEJORA SOLO DA UN 12.5% DEL TODO.

}