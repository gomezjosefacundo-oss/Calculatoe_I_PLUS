/// *** ! REFERENCIA DEL PUNTERO A CARGAR Y RECIBIR LOS DATOS ! *** ///

//Incluyo referencia de Base de datos
#define REF_BD_ELEMENT

#include "../HEADER/Public.h"

/// @brief Referencia de ID de los elementos que se conocen en la BASE de datos a enviar y recibir
BD_T BD_REF = {

    .BASE = {

        .ID = REF_BASE,
        .TYPE = T_REF_FLOAT,
        .VALUE = NULL

    },

    .EFICIENCIA = {

        .ID = REF_EFICIENCIA,
        .TYPE = T_REF_FLOAT,
        .VALUE = NULL

    },

    .POTENCIA = {

        .ID = REF_POTENCIA,
        .TYPE = T_REF_FLOAT,
        .VALUE = NULL

    },

    .RAN = {

        .ID = REF_RAN,
        .TYPE = T_REF_FLOAT,
        .VALUE = NULL

    },

    .TI_AUTOM = {

        .ID = REF_TIAUTOM,
        .TYPE = T_REF_FLOAT,
        .VALUE = NULL

    },

    .EF_AUTOM = {

        .ID = REF_EFATUOM,
        .TYPE = T_REF_FLOAT,
        .VALUE = NULL

    },

    .TIME = {

        .ID = REF_TIME,
        .TYPE = T_REF_LONG,
        .VALUE = NULL

    },

    .ANS = {

        .ID = REF_ANS,
        .TYPE = T_REF_FLOAT,
        .VALUE = NULL

    },

    .SHOW_DELAY = {

        .ID = REF_SHOWDELAY,
        .TYPE = T_REF_UCHAR,
        .VALUE = NULL

    },

    .SHOW_CLICK = {

        .ID = REF_SHOWCLCIK,
        .TYPE = T_REF_UCHAR,
        .VALUE = NULL

    },

    .SHOW_COSTCLICK = {

        .ID = REF_COSTCLICK,
        .TYPE = T_REF_UCHAR,
        .VALUE = NULL

    },

    .P_BD = {0}
};

void LoadBD_REF(){

    VALORES_T *REF_Valores = &G_FRAME.GAME_VALUE.VALORES;
    OPCIONES_T *REF_Opciones = &G_FRAME.GAME_VALUE.OPCIONES;
    RELOJ_T *REF_Reloj = &G_FRAME.GAME_VALUE.RELOJ;

    //Reserva las direcciones de memoria de las variables
    BD_REF.BASE.VALUE = &REF_Valores->Base;
    BD_REF.EFICIENCIA.VALUE = &REF_Valores->Eficiencia;
    BD_REF.POTENCIA.VALUE = &REF_Valores->Potencia;
    BD_REF.RAN.VALUE = &REF_Valores->Ran;
    BD_REF.TI_AUTOM.VALUE = &REF_Valores->Time_Autom;
    BD_REF.EF_AUTOM.VALUE = &REF_Valores->Eff_Autom;
    BD_REF.TIME.VALUE = &REF_Reloj->TIME;
    BD_REF.ANS.VALUE = &REF_Valores->Ans;
    
    BD_REF.SHOW_DELAY.VALUE = &REF_Opciones->ShowDelay;
    BD_REF.SHOW_CLICK.VALUE = &REF_Opciones->ShowClick;
    BD_REF.SHOW_COSTCLICK.VALUE = &REF_Opciones->ShowCostClick;

    COPYArr((void *[]){
        &BD_REF.BASE,
        &BD_REF.EFICIENCIA,
        &BD_REF.POTENCIA,
        &BD_REF.RAN,
        &BD_REF.TI_AUTOM,
        &BD_REF.EF_AUTOM,
        &BD_REF.TIME,
        &BD_REF.ANS,
        &BD_REF.SHOW_DELAY,
        &BD_REF.SHOW_CLICK,
        &BD_REF.SHOW_COSTCLICK

    }
    ,
    (void *)BD_REF.P_BD, 11);

}

size_t Decod_TYPE(unsigned char TYPE){

    switch(TYPE){
        case T_REF_LONG: return sizeof(long);
        case T_REF_UCHAR: return sizeof(unsigned char);
        case T_REF_FLOAT: return sizeof(float);
        
        default: return 0;

    }
}