/// *** ! Definicion de todas las funciones globales de uso en todo el juego ! ***///
#include "../HEADER/Public.h"

float Click_Event(int EVENTO, int AUTOM){ //EVETO "0"-Promedio(numero) "1"-Real+!TEXTO! //AUTOM "0"-Manual "1"-Autom

    DEF_GAME_VALUE *TEMP_GAME = &G_FRAME.GAME_VALUE; //Acorte de sintaxis

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
        Click *= Ran; //Promedia con Ran fijo
    }
    else{ //De rand real
        Click *= (Ran + ((float)(rand() % 41) - 20)/100);
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
    
    RELOJ_T *REF_tiempo = &G_FRAME.GAME_VALUE.RELOJ;
    VALORES_T *REF_valores = &G_FRAME.GAME_VALUE.VALORES;

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

    G_FRAME.GAME_VALUE.RELOJ.TIME = clock()/CLOCKS_PER_SEC + G_FRAME.GAME_VALUE.RELOJ.savedTIME;
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

    VALORES_T *REF_valores = &G_FRAME.GAME_VALUE.VALORES;

    float PONDERADO = 0;

    PONDERADO += REF_valores->Base / GLOBAL_MEJORAS.BASE[GLOBAL_MEJORAS.CANTIDAD_TYPE.c_BASE-1].MAX;
    PONDERADO += REF_valores->Eficiencia / GLOBAL_MEJORAS.EFICIENCIA[GLOBAL_MEJORAS.CANTIDAD_TYPE.c_EFICIENCIA-1].MAX;
    PONDERADO += REF_valores->Potencia / GLOBAL_MEJORAS.POTENCIA[GLOBAL_MEJORAS.CANTIDAD_TYPE.c_POTENCIA-1].MAX;
    PONDERADO += REF_valores->Ran / GLOBAL_MEJORAS.RAN[GLOBAL_MEJORAS.CANTIDAD_TYPE.c_RAN-1].MAX;
    PONDERADO += GLOBAL_MEJORAS.TI_AUTOM[GLOBAL_MEJORAS.CANTIDAD_TYPE.c_TI_AUTOM-1].MAX / REF_valores->Time_Autom;
    PONDERADO += REF_valores->Eff_Autom / GLOBAL_MEJORAS.EF_AUTOM[GLOBAL_MEJORAS.CANTIDAD_TYPE.c_EF_AUTOM-1].MAX;
    PONDERADO += REF_valores->EXTRA_LvBase / (float)8;
    PONDERADO += REF_valores->EXTRA_LvPorc / (float)50;

    PONDERADO /= (float)8;

    PONDERADO -= 0.12508349; //Sale de la minima posible de las mejoras iniciales

    PONDERADO *= 1.142968 * 100; //Sale de restar 1-MIN y se eso la inversa para compensar

    printf("%.3f%% ", PONDERADO);

    printf("[");

    int BAR = 0;
    while(PONDERADO >= 12.5 && BAR < 8){
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

void COPYArr(void* A[], void* B[], int SizeArr_A){

    for(int i = 0; i < SizeArr_A; i++){

        B[i] = A[i];

    }

}

void COPYFunc(void (*A[])(), void (*B[])(), int SizeArr_A){

    for(int i = 0; i < SizeArr_A; i++){

        B[i] = A[i];

    }

}


void normalizarDinamicos(){

    VALORES_T *REF_Valores = &G_FRAME.GAME_VALUE.VALORES;
    OPCIONES_T *REF_Opciones = &G_FRAME.GAME_VALUE.OPCIONES;
    RELOJ_T *REF_Reloj = &G_FRAME.GAME_VALUE.RELOJ;

    CANTIDAD_T *REF_Cantidad = &GLOBAL_MEJORAS.CANTIDAD_TYPE;

    
    /*DEFINICION PUNTEROS, EN MEJORAS GLOBALES*/

    //Para copiar las mejoras
    COPYArr((void *[]){
        GLOBAL_MEJORAS.BASE, 
        GLOBAL_MEJORAS.EFICIENCIA, 
        GLOBAL_MEJORAS.POTENCIA, 
        GLOBAL_MEJORAS.RAN, 
        GLOBAL_MEJORAS.TI_AUTOM,
        GLOBAL_MEJORAS.EF_AUTOM}
        , 
        (void *)GLOBAL_MEJORAS.P_MEJORAS, 6);

    //Para copiar las cantidades de mejoras
    COPYArr((void *[]){
        &REF_Cantidad->c_BASE, 
        &REF_Cantidad->c_EFICIENCIA, 
        &REF_Cantidad->c_POTENCIA, 
        &REF_Cantidad->c_RAN, 
        &REF_Cantidad->c_TI_AUTOM, 
        &REF_Cantidad->c_EF_AUTOM}
        , 
        (void *)GLOBAL_MEJORAS.CANTIDAD_TYPE.P_CANTIDAD, 6);


        //Para copiar las cantidades de mejoras
    COPYArr((void *[]){
        &REF_Valores->Base, 
        &REF_Valores->Eficiencia, 
        &REF_Valores->Potencia, 
        &REF_Valores->Ran, 
        &REF_Valores->Time_Autom,
        &REF_Valores->Eff_Autom, 
        &REF_Reloj->TIME,
        &REF_Opciones->ShowDelay,
        &REF_Opciones->ShowClick,
        &REF_Valores->Ans}
        , 
        (void *)G_FRAME.GAME_VALUE.VALORES.P_PARAMETROS, 10);

        COPYArr((void *[]){
            &REF_Opciones->ShowDelay,
            &REF_Opciones->ShowClick,
            &REF_Opciones->ShowCostClick
        }
        , 
        (void *)G_FRAME.GAME_VALUE.OPCIONES.P_OPCIONES, 3);

    COPYFunc((void (*[])(void)){
        I_Intro,
        I_Menu,
        I_Clicker,
        I_TablaMejoras,
        I_Opciones,
        I_Partida,
        I_Tab

    }
    ,
    G_FRAME.P_MENUS, 7);

    LoadBD_REF(); //Para cargar las referencias de base de datos desde la misma funcion XD

}