#include "../HEADER/Public.h"

/// @brief Prototipo funcion FRAME
void F_TablaMejoras();
/// @brief Prototipo funcion CALCULADORA
void C_TablaMejoras();

//Definiciones del menu (existe static struct FRAME, enums necesarios y otros)

#define D_Base     0  // 0
#define D_EffBase  1  // 1
#define D_Potencia 2  // 2
#define D_Ran      3  // 3
#define D_TAutom   4  // 4
#define D_EffAutom 5  // 5


static struct{

    float ClickInicial;
    float ClickDelta; //Ambos sirven para ver la mejora resultante

    float HrClickInicial;
    float HrClickDelta; //Segundo parametro de mejoras visibles

    int BUY; //Aviso del C_ de que se compro algo

    char *TEXT_MEJORAS[6];

} FRAME = {

    .BUY = 0, //0.NADA 1.COMRPO 2.ERROR

    .ClickInicial = 0,
    .ClickDelta = 0,

    .HrClickInicial = 0,
    .HrClickDelta = 0,

    .TEXT_MEJORAS = {

        [ 0] = "Base",
		[ 1] = "Eficiencia de Base",
		[ 2] = "Potencia",
		[ 3] = "Ran#",
		[ 4] = "Tiempo Automatico",
		[ 5] = "Eficiencia Automatica",

    }

};



///@brief Funcion inicializadora y loop del menu
void I_TablaMejoras(){

    FRAME.HrClickInicial = Click_Event(0, 1)*(3600/(G_FRAME.GAME_VALUE.VALORES.Time_Autom/1000));

    if(G_FRAME.DATA == D_EffAutom || G_FRAME.DATA == D_TAutom) FRAME.ClickInicial = Click_Event(0, 1);
    else FRAME.ClickInicial = Click_Event(0, 0);

    FRAME.ClickDelta = 0;
    FRAME.HrClickDelta = 0;

    while(G_FRAME.CURSOR == TABLA_MEJORAS){

        F_TablaMejoras();

        C_TablaMejoras();
    }

}

///@brief El generador del frame en si
void F_TablaMejoras(){

    VALORES_T *REF_valores = &G_FRAME.GAME_VALUE.VALORES;
    CANTIDAD_T *REF_cantidad = &GLOBAL_MEJORAS.CANTIDAD_TYPE;
    OPCIONES_T *REF_opciones = &G_FRAME.GAME_VALUE.OPCIONES;

    int *Cantidad = REF_cantidad->P_CANTIDAD[G_FRAME.DATA];
    NIVEL *Mejora = GLOBAL_MEJORAS.P_MEJORAS[G_FRAME.DATA];
    float *Base = REF_valores->P_PARAMETROS[G_FRAME.DATA];
 
    char* TEXT = FRAME.TEXT_MEJORAS[G_FRAME.DATA];

    system("cls");

    switch(FRAME.BUY){
        case 1:
            printf("\n\n!MEJORA HECHA CON EXITO!");

        break;

        case 2:
            printf("\n\n!NO ES POSIBLE LA MEJORA!");

        break;
    }

    if(FRAME.BUY != 0){
        Sleep(2500);
        system("cls");
    }

    printf("-Mejoras de %s- \n\n", TEXT);
    printf("Escriba el Numero de la mejora que desee.\n -1 = Salir || 0..%d = Seleccionar \n\n", *Cantidad - 1);
    printf(" ID ->       Limite |         Coste |      Mejora \n");
    
    for(int i = 0; i < *Cantidad; i++){

        printf(" %02d -> %12.6g | %12.6gp | %+11.6g", i, Mejora[i].MAX, Mejora[i].PRECIO, Mejora[i].MEJORA);
    
        //Que no sea una mejora superada y que no sea absurdamente cara \\ ademas verifica que la opcion este activada
        if(REF_opciones->ShowCostClick){

            if( Mejora[i].PRECIO / FRAME.ClickInicial <= 10000 ){
            
                int print = 0;
                //Valida el tipo de texto a aparecer segun el parametro
                if(G_FRAME.DATA != D_TAutom){
                    if(*Base < Mejora[i].MAX) print = 1;
                }
                else {
                    if(*Base > Mejora[i].MAX) print = 1;
                }
                
                if(print == 1) 
                    printf(" -> %.0fClk (%.0fHr-Clk)", Mejora[i].PRECIO / FRAME.ClickInicial, Mejora[i].PRECIO / FRAME.HrClickInicial); 
            }
        }

        printf("\n");
    }

    printf("\nAns = %.6gp || %s = %.6g \n", REF_valores->Ans, TEXT, *Base);

    if(G_FRAME.DATA == D_EffAutom || G_FRAME.DATA == D_TAutom) printf("AUTO");

    printf("Click = %.6gp || Hr-Click = %.6gp/Hr", FRAME.ClickInicial, FRAME.HrClickInicial);

    if(FRAME.BUY == 1){

        printf(" +%.6gp (+%.6gp/Hr)", FRAME.ClickDelta, FRAME.HrClickDelta);
    }
    
    printf("\n\n");

    printf("MEJORA -> ");

    FRAME.BUY = 0;
}

///@brief El que evalua a que llamar o que hacer con cada accion
void C_TablaMejoras(){

    VALORES_T *REF_valores = &G_FRAME.GAME_VALUE.VALORES;
    CANTIDAD_T *REF_cantidad = &GLOBAL_MEJORAS.CANTIDAD_TYPE;

    int* Cantidad = REF_cantidad->P_CANTIDAD[G_FRAME.DATA];
    NIVEL* Mejora = GLOBAL_MEJORAS.P_MEJORAS[G_FRAME.DATA];
    float* Base = REF_valores->P_PARAMETROS[G_FRAME.DATA];

    int KEY = 0;

    scanf(" %d", &KEY);

    if(KEY == -1){
        G_FRAME.CURSOR = MENU; //Vuelve al menu principal
        G_FRAME.DATA = 0;
    }
    else if(KEY >= 0 && KEY < *Cantidad){

        int MAXcond = 0;
        if(G_FRAME.DATA == D_TAutom){ //Condicion especial por el negativo de Las mejora de tiempo
            if(*Base > Mejora[KEY].MAX) MAXcond = 1;

        }else{
            if(*Base < Mejora[KEY].MAX) MAXcond = 1;
        }
        
        if(REF_valores->Ans >= Mejora[KEY].PRECIO && MAXcond){ //Verifico si alcanza a comprar

            MAXcond = 0; //Reset

            REF_valores->Ans -= Mejora[KEY].PRECIO; //Resta puntos

            *Base += Mejora[KEY].MEJORA; //Da la mejora

            //Si el valor base de mejora es mayor que la maxima de todas, clipea a la maxima...
            if(G_FRAME.DATA != D_TAutom){
                if(*Base > Mejora[*Cantidad-1].MAX) *Base = Mejora[*Cantidad-1].MAX;

            }
            else{ //Exclusivo para el tiempo autom que recude en lugar de aumentar
                if(*Base < Mejora[*Cantidad-1].MAX) *Base = Mejora[*Cantidad-1].MAX;
                
            } 

            // COMO CALCULAR LA GANANCIA RESULTANTE DE LA MEJORA
            if(G_FRAME.DATA == D_EffAutom || G_FRAME.DATA == D_TAutom){
                
                FRAME.ClickDelta =  Click_Event(0, 1) - FRAME.ClickInicial; //Variacion con el click anterior
                FRAME.ClickInicial = Click_Event(0, 1); //Nuevo valor de click
            }
            else{
                FRAME.ClickDelta = Click_Event(0, 0) - FRAME.ClickInicial; 
                FRAME.ClickInicial = Click_Event(0, 0); 
            }
            
            FRAME.HrClickDelta =  Click_Event(0, 1)*(3600/(REF_valores->Time_Autom/1000)) - FRAME.HrClickInicial;
            FRAME.HrClickInicial = Click_Event(0, 1)*(3600/(REF_valores->Time_Autom/1000)); 
        
            FRAME.BUY = 1; //Compra efectiva

        }
        else{
            FRAME.BUY = 2; //La mejora no es posible
        }

    }
    else{
        FRAME.BUY = 2; //La mejora no existe

    }


}