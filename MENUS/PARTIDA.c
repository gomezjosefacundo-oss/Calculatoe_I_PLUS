#include "Public.h"

//Prototipos
void F_Partida();
void C_Partida();

//Definiciones del menu (existe static struct FRAME, enums necesarios y otros)

typedef enum{
    NADA,       // 0
    CARGANDO,   // 1
    GUARDANDO,  // 2
    ER_CARGAR,  // 3
    ER_GUARDAR, // 4
    EXITOS      // 5


} ESTADO_T;

static struct{

    int ESTADO;

    char *TEXTO[6];

} FRAME = {

    .ESTADO = NADA,

    .TEXTO = {

        [ 0] = "Espere...",
        [ 1] = "Cargando... (Si ve algun '0' fallo la carga en un dato)",
        [ 2] = "Guardando... (Si ve algun '0' fallo la carga en un dato)",
        [ 3] = "NO SE PUDO CARGAR! NO EXISTE PARTIDA GUARDADA \n    O YA SE CARGO UNA PARTIDA (EN ESTE CASO REINICIE)",
        [ 4] = "NO SE PUDO GUARDAR! NO HAY ACCESO PARA CREAR EL ARCHIVO O MODIFICARLO",
        [ 5] = "!TODO CORRECTO!",
    }

};

//Funcion inicializadora y loop del menu
void I_Partida(){

    FRAME.ESTADO = 0;

    while(G_FRAME.CURSOR == PARTIDA){

        F_Partida();

        C_Partida();
    }

}

//El generador del frame en si
void F_Partida(){

    system("cls");
    printf("\n\n  %s\n\n", FRAME.TEXTO[FRAME.ESTADO]);


}

//El que evalua a que llamar o que hacer con cada accion
void C_Partida(){

    DEF_GAME_VALUE *REF_juego = G_FRAME.GAME_VALUE;

    FILE *file;

    switch(FRAME.ESTADO){
        case NADA:
            if(G_FRAME.DATA == 1) FRAME.ESTADO = CARGANDO;
            else FRAME.ESTADO = GUARDANDO;
            
            Sleep(1000);

        break;

        case CARGANDO:

            file = fopen("BD.InfntdI", "rb");

            if(file != NULL && G_FRAME.GAME_VALUE->RELOJ.savedTIME == 0 &&  G_FRAME.GAME_VALUE->VALORES.secGUARDADO == 0){ //Pudo crear el archivo o abrirlo

                printf(" BASE? %d \n", fread(&REF_juego->VALORES.Base, sizeof(float), 1, file));
                printf(" EFICIENCIA? %d \n", fread(&REF_juego->VALORES.Eficiencia, sizeof(float), 1, file));
                printf(" POTENCIA? %d \n", fread(&REF_juego->VALORES.Potencia, sizeof(float), 1, file));
                printf(" RAN? %d \n", fread(&REF_juego->VALORES.Ran, sizeof(float), 1, file));
                printf(" TIEMPO A? %d \n", fread(&REF_juego->VALORES.Time_Autom, sizeof(float), 1, file));
                printf(" EFICIE A? %d \n", fread(&REF_juego->VALORES.Eff_Autom, sizeof(float), 1, file));
               
                printf(" TIME REF? %d \n", fread(&REF_juego->RELOJ.savedTIME, sizeof(long), 1, file));
                
                printf(" OP1? %d \n", fread(&REF_juego->OPCIONES.ShowDelay, sizeof(int), 1, file));
                printf(" OP2? %d \n", fread(&REF_juego->OPCIONES.ShowClick, sizeof(int), 1, file));
                
                printf(" ANS? %d \n", fread(&REF_juego->VALORES.Ans, sizeof(float), 1, file));



                fclose(file);

                FRAME.ESTADO = EXITOS;

            }
            else{
                FRAME.ESTADO = ER_CARGAR;
            }

            Sleep(1500);



        break;

        case GUARDANDO:

            file = fopen("BD.InfntdI", "wb");

            if(file != NULL){ //Pudo crear el archivo o abrirlo

                printf(" BASE? %d \n", fwrite(&REF_juego->VALORES.Base, sizeof(float), 1, file));
                printf(" EFICIENCIA? %d \n", fwrite(&REF_juego->VALORES.Eficiencia, sizeof(float), 1, file));
                printf(" POTENCIA? %d \n", fwrite(&REF_juego->VALORES.Potencia, sizeof(float), 1, file));
                printf(" RAN? %d \n", fwrite(&REF_juego->VALORES.Ran, sizeof(float), 1, file));
                printf(" TIEMPO A? %d \n", fwrite(&REF_juego->VALORES.Time_Autom, sizeof(float), 1, file));
                printf(" EFICIE A? %d \n", fwrite(&REF_juego->VALORES.Eff_Autom, sizeof(float), 1, file));
                
                actTIME();
                printf(" TIME REF? %d \n", fwrite(&REF_juego->RELOJ.TIME, sizeof(long), 1, file));
                
                printf(" OP1? %d \n", fwrite(&REF_juego->OPCIONES.ShowDelay, sizeof(int), 1, file));
                printf(" OP2? %d \n", fwrite(&REF_juego->OPCIONES.ShowClick, sizeof(int), 1, file));
                
                printf(" ANS? %d \n", fwrite(&REF_juego->VALORES.Ans, sizeof(float), 1, file));

                fclose(file); 

                G_FRAME.GAME_VALUE->VALORES.secGUARDADO = 1;

                FRAME.ESTADO = EXITOS;

            }
            else{
                FRAME.ESTADO = ER_GUARDAR;
            }

            Sleep(1500);

        break;

        case ER_CARGAR:
            G_FRAME.DATA = 0;
            G_FRAME.CURSOR = MENU;
            Sleep(3000);
            
        break;

        case ER_GUARDAR:
            G_FRAME.DATA = 0;
            G_FRAME.CURSOR = MENU;
            Sleep(3000);

        break;

        case EXITOS:
            G_FRAME.DATA = 0;
            G_FRAME.CURSOR = MENU;
            Sleep(3000);
        break;


    }



   



}