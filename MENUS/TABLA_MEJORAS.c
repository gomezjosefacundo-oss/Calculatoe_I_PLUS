#include "Public.h"

//Prototipos
void F_TablaMejoras();
void C_TablaMejoras();

//Definiciones del menu (existe static struct FRAME, enums necesarios y otros)
typedef enum{
    Base,      // 0
    EffBase,   // 1
    Potencia,  // 2
    Ran,       // 3
    TAutom,    // 4
    EffAutom   // 5
} REF_MEJORA;

static struct{

    int CANTIDAD; //Por defecto de cantidad de mejoras de un tipo de mejora
    NIVEL *MEJORAS; //Puntero al arreglo de la mejora que toque
    float *BASE; //El valor de la mejora que toco en tu actual

    float ClickInicial;
    float ClickDelta; //Ambos sirven para ver la mejora resultante

    int BUY; //Aviso del C_ de que se compro algo

    char *TEXT_MEJORAS[6];

} FRAME = {

    .CANTIDAD = 0,
    .MEJORAS = NULL,
    .BASE = 0,

    .BUY = 0, //0.NADA 1.COMRPO 2.ERROR

    .ClickInicial = 0,
    .ClickDelta = 0,

    .TEXT_MEJORAS = {

        [ 0] = "Base",
		[ 1] = "Eficiencia de Base",
		[ 2] = "Potencia",
		[ 3] = "Ran#",
		[ 4] = "Tiempo Automatico",
		[ 5] = "Eficiencia Automatica",

    }

};

//Funcion inicializadora y loop del menu
void I_TablaMejoras(){

    switch(G_FRAME.DATA){ //Preparar datos...
        case Base:
            FRAME.CANTIDAD = GLOBAL_MEJORAS.CANTIDAD_TYPE.c_BASE;
            FRAME.MEJORAS = GLOBAL_MEJORAS.BASE;
            FRAME.BASE = &G_FRAME.GAME_VALUE->VALORES.Base;
        break;

        case EffBase:
            FRAME.CANTIDAD = GLOBAL_MEJORAS.CANTIDAD_TYPE.c_EFICIENCIA;
            FRAME.MEJORAS = GLOBAL_MEJORAS.EFICIENCIA;
            FRAME.BASE = &G_FRAME.GAME_VALUE->VALORES.Eficiencia;
        break;
        
        case Potencia:
            FRAME.CANTIDAD = GLOBAL_MEJORAS.CANTIDAD_TYPE.c_POTENCIA;
            FRAME.MEJORAS = GLOBAL_MEJORAS.POTENCIA;
            FRAME.BASE = &G_FRAME.GAME_VALUE->VALORES.Potencia;
        break;
            
        case Ran:
            FRAME.CANTIDAD = GLOBAL_MEJORAS.CANTIDAD_TYPE.c_RAN;
            FRAME.MEJORAS = GLOBAL_MEJORAS.RAN;
            FRAME.BASE = &G_FRAME.GAME_VALUE->VALORES.Ran;
        break;
        
        case TAutom:
            FRAME.CANTIDAD = GLOBAL_MEJORAS.CANTIDAD_TYPE.c_TI_AUTOM;
            FRAME.MEJORAS = GLOBAL_MEJORAS.TI_AUTOM;
            FRAME.BASE = &G_FRAME.GAME_VALUE->VALORES.Time_Autom;
        break;
        
        case EffAutom:
            FRAME.CANTIDAD = GLOBAL_MEJORAS.CANTIDAD_TYPE.c_EF_AUTOM;
            FRAME.MEJORAS = GLOBAL_MEJORAS.EF_AUTOM;
            FRAME.BASE = &G_FRAME.GAME_VALUE->VALORES.Eff_Autom;
        break;
        
    }

    if(G_FRAME.DATA == EffAutom) FRAME.ClickInicial = Click_Event(0, 1);
    else if(G_FRAME.DATA == TAutom) FRAME.ClickInicial = Click_Event(0, 1)*(3600/(G_FRAME.GAME_VALUE->VALORES.Time_Autom/1000));
    else FRAME.ClickInicial = Click_Event(0, 0);

    FRAME.ClickDelta = 0;

    while(G_FRAME.CURSOR == TABLA_MEJORAS){

        F_TablaMejoras();

        C_TablaMejoras();
    }

}

//El generador del frame en si
void F_TablaMejoras(){

    system("cls");

    switch(FRAME.BUY){
        case 1:
            printf("\n\n!MEJORA HECHA CON EXITO!");

        break;

        case 2:
            printf("\n\n!NO ES POSIBLE LA MEJORA!");

        break;
    }
    if(FRAME.BUY > 0){
        Sleep(2500);
        system("cls");
    }

    printf("-Mejoras de %s- \n\n", FRAME.TEXT_MEJORAS[G_FRAME.DATA]);
    printf("Escriba el Numero de la mejora que desee.\n -1 = Salir || 0..%d = Seleccionar \n\n", FRAME.CANTIDAD - 1);
    printf("Indice | Limite   | Coste       | Mejora \n");
    
    for(int i = 0; i < FRAME.CANTIDAD; i++){

        printf(" %02d -> %10.7g | %10.7gp | %+8.7g \n", i, FRAME.MEJORAS[i].MAX, FRAME.MEJORAS[i].PRECIO, FRAME.MEJORAS[i].MEJORA);
    }

    printf("\nAns = %.7gp || %s = %.7g \n", G_FRAME.GAME_VALUE->VALORES.Ans, FRAME.TEXT_MEJORAS[G_FRAME.DATA], *FRAME.BASE);

    if(G_FRAME.DATA == EffAutom) printf("AUTO");
    if(G_FRAME.DATA == TAutom) printf("Hr-");

    printf("Click = %.7gp", FRAME.ClickInicial);

    if(FRAME.BUY == 1){

        printf(" +%.7gp\n", FRAME.ClickDelta);
    }else printf("\n\n");

    printf("MEJORA -> ");

    FRAME.BUY = 0;
}

//El que evalua a que llamar o que hacer con cada accion
void C_TablaMejoras(){

    int KEY = 0;

    scanf(" %d", &KEY);

    if(KEY == -1){
        G_FRAME.CURSOR = MENU; //Vuelve al menu principal
        G_FRAME.DATA = 0;
    }
    else if(KEY >= 0 && KEY < FRAME.CANTIDAD){

        int MAXcond = 0;
        if(G_FRAME.DATA == TAutom){ //Condicion especial por el negativo de Las mejora de tiempo
            if(*FRAME.BASE > FRAME.MEJORAS[KEY].MAX) MAXcond = 1;
             
        }else{
            if(*FRAME.BASE < FRAME.MEJORAS[KEY].MAX) MAXcond = 1;
        }
        
        if(G_FRAME.GAME_VALUE->VALORES.Ans >= FRAME.MEJORAS[KEY].PRECIO && MAXcond){ //Verifico si alcanza a comprar

            MAXcond = 0; //Reset

            G_FRAME.GAME_VALUE->VALORES.Ans -= FRAME.MEJORAS[KEY].PRECIO; //Resta puntos

            *FRAME.BASE += FRAME.MEJORAS[KEY].MEJORA; //Da la mejora

            if(G_FRAME.DATA == EffAutom){
                
                FRAME.ClickDelta =  Click_Event(0, 1) - FRAME.ClickInicial; //Variacion con el click anterior
                FRAME.ClickInicial = Click_Event(0, 1); //Nuevo valor de click
            }
            else if(G_FRAME.DATA == TAutom){
                FRAME.ClickDelta =  Click_Event(0, 1)*(3600/(G_FRAME.GAME_VALUE->VALORES.Time_Autom/1000)) - FRAME.ClickInicial;
                FRAME.ClickInicial = Click_Event(0, 1)*(3600/(G_FRAME.GAME_VALUE->VALORES.Time_Autom/1000)); 
            }
            else{
                FRAME.ClickDelta = Click_Event(0, 0) - FRAME.ClickInicial; 
                FRAME.ClickInicial = Click_Event(0, 0); 
            }

            FRAME.BUY = 1; //Compra efectiva

        }else{
            FRAME.BUY = 2; //La mejora no es posible
        }

    }else{
        FRAME.BUY = 2; //La mejora no existe
    }


}