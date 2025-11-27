/// *** ! MODO ADMIN PARA PREPROGRAMAR LA PARTIDA SOLO INCLUIR PARA CASOS ESPECIALES ! *** ///
//#define ADMIN
#include "../HEADER/Public.h"

#ifdef ADMIN

void ModificarValores(){

    VALORES_T *REF_Valores = &G_FRAME.GAME_VALUE.VALORES;
    RELOJ_T *REF_Reloj = &G_FRAME.GAME_VALUE.RELOJ;

    system("cls");

    printf("INGRESE LA BASE: ");
    scanf(" %f", &REF_Valores->Base);

    printf("INGRESE LA EFF.BASE: ");
    scanf(" %f", &REF_Valores->Eficiencia);

    printf("INGRESE LA POTEN: ");
    scanf(" %f", &REF_Valores->Potencia);

    printf("INGRESE LA RAN: ");
    scanf(" %f", &REF_Valores->Ran);

    printf("INGRESE LA TI.AUTOM: ");
    scanf(" %f", &REF_Valores->Time_Autom);

    printf("INGRESE LA EF.AUTOM: ");
    scanf(" %f", &REF_Valores->Eff_Autom);

    printf("INGRESE LA savedTIME: ");
    scanf(" %ld", &REF_Reloj->savedTIME);

    actTIME(); //Actualiza referencia de tiempo TIME
    for(int i = 0; i < 50; i++){
        actEXTRA(); //Actualiza los parametros de mejoras por tiempo
    }

}
#endif