#include "Public.h"

//Prototipos
void F_Tab();
void C_Tab();

//Definiciones del menu (existe static struct FRAME, enums necesarios y otros)
static struct{} FRAME = {};

//Funcion inicializadora y loop del menu
void I_Tab(){

    while(G_FRAME.CURSOR == TAB){

        F_Tab();

        C_Tab();
    }

}

//El generador del frame en si
void F_Tab(){

    VALORES_T *REF_mejoras = &G_FRAME.GAME_VALUE->VALORES;
    RELOJ_T *REF_tiempo = &G_FRAME.GAME_VALUE->RELOJ;

    actTIME(); //Actualiza referencia de tiempo TIME

    system("cls");

    printf("-Estado del juego-\n");

    printf("\n\n=> PARAMETROS MEJORABLES <=\n");

    printf("Base = %.7g \n", REF_mejoras->Base);
    printf("Eficiencia de Base = %.7g \n", REF_mejoras->Eficiencia);
    printf("Potencia = %.7g \n", REF_mejoras->Potencia);
    printf("Ran# = %.7g \n", REF_mejoras->Ran);
    printf("Tiempo Automatico = %.7g \n", REF_mejoras->Time_Autom);
    printf("Eficiencia Automatica = %.7g \n", REF_mejoras->Eff_Autom);

    printf("\n\n=> PARAMETROS EXTRA <=     #Estos se mejoran por jugar!\n");
    printf("EXTRA Base = %d - %d  (Lv%d/8)", REF_mejoras->EXTRA_Base, REF_mejoras->EXTRA_Base + 26, REF_mejoras->EXTRA_LvBase);
    if(REF_mejoras->EXTRA_LvBase < 8){
        printf(" [Mejora en -> ");
        ImprimirTiempo((REF_mejoras->EXTRA_LvBase + 1)*22500 - REF_tiempo->TIME);
        printf("]");
    }
    printf("\n");


    printf("EXTRA Probabilidad = %.4f (1 en %d)  (Lv%d/50)", REF_mejoras->EXTRA_Porcentual, (int)(1/REF_mejoras->EXTRA_Porcentual), REF_mejoras->EXTRA_LvPorc);
    if(REF_mejoras->EXTRA_LvPorc < 50){
        printf(" [Mejora en -> ");
        ImprimirTiempo((REF_mejoras->EXTRA_LvPorc + 1)*3600 - REF_tiempo->TIME);
        printf("]");
    }
    printf("\n");

    printf("\n\n=> PUNTOS <=\n");
    printf("Ans = %.7gp\n", REF_mejoras->Ans);
    printf("Click = %.7gp\n\n", Click_Event(0, 0));

    printf("Ecuacion -> (Base*EffBase)^Pot * (Ran# + Rand()) * <EffAutom>\n");
    
    printf("\n\n=> PROGRECION <=\n");
    BarraProgrecion(); //Muestra la progrecion del juego
    printf("\n");
    printf("Tiempo de juego -> "); ImprimirTiempo(REF_tiempo->TIME);



}

//El que evalua a que llamar o que hacer con cada accion
void C_Tab(){

    actEXTRA(); //Actualiza referencia del extra por segundo

    int Second = 0;
    while(!(kbhit() || Second > 1000)){
        Sleep(100);
        Second += 100;
    }
    
    if(kbhit()){ //Lee tecla si eixste una tecla apretada

        switch(getKEY()){
            case 'T':
                G_FRAME.CURSOR = MENU;

            break;


        }

    }


}