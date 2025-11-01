/*
#include "Public.h"

//Definiciones del menu (existe static struct FRAME, enums necesarios y otros)

//Prototipos
void F_();
void C_(char, int *);

//Funcion inicializadora y loop del menu
void I_(int *GENERAL_CURSOR){

    while(*GENERAL_CURSOR == "<SELF>"){

        F_();

        C_(getKEY(), GENERAL_CURSOR);
    }

}

//El generador del frame en si
void F_(){}

//El que evalua a que llamar o que hacer con cada accion
void C_(char KEY, int *GENERAL_CURSOR){}

*/