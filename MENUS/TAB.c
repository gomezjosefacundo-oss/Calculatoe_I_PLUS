/*
#include "Public.h"

//Prototipos
void F_();
void C_(char, GENERAL_FRAME *);

//Definiciones del menu (existe static struct FRAME, enums necesarios y otros)
static struct{} FRAME = {};

//Funcion inicializadora y loop del menu
void I_(GENERAL_FRAME *G_FRAME){

    while(G_FRAME->CURSOR == "<SELF>"){

        F_();

        C_(getKEY(), G_FRAME);
    }

}

//El generador del frame en si
void F_(){}

//El que evalua a que llamar o que hacer con cada accion
void C_(char KEY, GENERAL_FRAME *G_FRAME){}

*/