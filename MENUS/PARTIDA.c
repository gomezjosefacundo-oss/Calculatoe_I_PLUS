#define REF_BD_ELEMENT

#include "../HEADER/Public.h"

/// @brief Prototipo funcion FRAME
void F_Partida();
/// @brief Prototipo funcion CALCULADORA
void C_Partida();

typedef struct{
    
    unsigned char ID;
    unsigned char TYPE;
    size_t SIZE;

    union {
        void* PVOID;
        long LONG;
        unsigned char UCHAR;
        float FLOAT;
    } VALUE;

} BD_ELEM_T;


/*
TABLA DE REFERENCIAS (Si un elemento se añade NO se puede cambiar su ID)
0. BASE
1. EFICIENCIA
2. POTENCIA
3. RAN
4. TIAUTOM
5. EFATUOM
6. TIME
7. ANS
8. SHOWDELAY
9. SHOWCLICK
10. COSTCLICK


*/

//Definiciones del menu (existe static struct FRAME, enums necesarios y otros)

void extractVALUE(BD_ELEM_T*, FILE*);
int loadVALUE(BD_ELEM_T*);
void printVALUE(BD_ELEM_T*);
void LoadInVALUE(BD_ELEM_T*, void*);

#define MAX_LOAD 11 //Cantidad maxima de elementos a cargar

typedef enum{
    NADA,       // 0
    CARGANDO,   // 1
    GUARDANDO,  // 2
    ER_CARGAR,  // 3
    ER_GUARDAR, // 4
    RESULTADO   // 5


} ESTADO_T;

static struct{

    /// @brief Sistemas de estados para las pantallas y etapas del guardado o cargado
    int ESTADO;
    /// @brief Para el delta de cargado
    int Verify;
    /// @brief Para el total cargado
    int CounterVerify;
    /// @brief Handcap para el largo de la variable leida, o, a cargar
    size_t Size;

    /// @brief Referencia puntual del dato que se exta extrallendo
    BD_ELEM_T Element;

    char *TEXTO[6];

} FRAME = {

    .ESTADO = NADA,
    .Verify = 0,
    .CounterVerify = 0,
    .Size = 0,

    .TEXTO = {

        [ 0] = "Espere...",
        [ 1] = "Cargando... (Verificando elementos)",
        [ 2] = "Guardando... (Verificando elementos)",
        [ 3] = "NO SE PUDO CARGAR! NO EXISTE PARTIDA GUARDADA \n    O YA SE CARGO UNA PARTIDA (EN ESTE CASO REINICIE)",
        [ 4] = "NO SE PUDO GUARDAR! NO HAY ACCESO PARA CREAR EL ARCHIVO O MODIFICARLO",
        [ 5] = "Elementos cargados correctamente:",
    },

    .Element = {
        .ID = 0,
        .TYPE = 0,
        .SIZE = 0,
        .VALUE = {0}

    }
};

//Funcion inicializadora y loop del menu
void I_Partida(){

    FRAME.ESTADO = 0;
    FRAME.Verify = 0; 
    FRAME.CounterVerify = 0; 

    while(G_FRAME.CURSOR == PARTIDA){

        F_Partida();

        C_Partida();
    }

}

//El generador del frame en si
void F_Partida(){

    system("cls");
    printf("\n\n  %s\n", FRAME.TEXTO[FRAME.ESTADO]);

    if(FRAME.ESTADO == RESULTADO){
        printf("\t%d/%d ", FRAME.CounterVerify, MAX_LOAD);
        if(FRAME.CounterVerify < MAX_LOAD){
            printf("-> La algun dato es CORRUPTO. Cuidado.");
        }
    } 


}

//El que evalua a que llamar o que hacer con cada accion
void C_Partida(){

    VALORES_T *REF_Valores = &G_FRAME.GAME_VALUE.VALORES;
    RELOJ_T *REF_Reloj = &G_FRAME.GAME_VALUE.RELOJ;
    
    FILE *file;

    switch(FRAME.ESTADO){
        case NADA:
            if(G_FRAME.DATA == 1) FRAME.ESTADO = CARGANDO;
            else FRAME.ESTADO = GUARDANDO;
            
            Sleep(1000);

        break;

        case CARGANDO:

            file = fopen("BD.InfntdI", "rb");

            BD_REF.TIME.VALUE = &REF_Reloj->savedTIME; //Cuando carga, debe cargar en el absoluto de partida.

            if(file != NULL && REF_Reloj->savedTIME == 0 &&  REF_Valores->secGUARDADO == 0){ //Pudo crear el archivo o abrirlo

                for(unsigned char i = 0; i < MAX_LOAD; i++){

                    fread(&FRAME.Element.ID, sizeof(unsigned char), 1, file);
                    printf(" ID: %d ", FRAME.Element.ID);
                    
                    fread(&FRAME.Element.TYPE, sizeof(unsigned char), 1, file);
                    printf(" TYPE: %d ", FRAME.Element.TYPE);

                    FRAME.Element.SIZE = Decod_TYPE(FRAME.Element.TYPE);
                    
                    extractVALUE(&FRAME.Element, file);
                    printVALUE(&FRAME.Element);
                    
                    FRAME.Verify = loadVALUE(&FRAME.Element);

                    FRAME.CounterVerify += FRAME.Verify;
                    printf(" LOAD? %d \n", FRAME.Verify);

                    Sleep(250);
                }

                fclose(file);

                FRAME.ESTADO = RESULTADO;

            }
            else{
                FRAME.ESTADO = ER_CARGAR;
            }

            Sleep(1500);



        break;

        case GUARDANDO:

            file = fopen("BD.InfntdI", "wb");

            if(file != NULL){ //Pudo crear el archivo o abrirlo

                actTIME();
                BD_REF.TIME.VALUE = &REF_Reloj->TIME; //Cuando guarda tiene que enviar el Tiempo total transcurrido


                for(unsigned char i = 0; i < MAX_LOAD; i++){

                    FRAME.Element.ID = BD_REF.P_BD[i]->ID;
                    FRAME.Element.TYPE = BD_REF.P_BD[i]->TYPE;
                    FRAME.Element.VALUE.PVOID = BD_REF.P_BD[i]->VALUE;

                    fwrite(&FRAME.Element.ID, sizeof(unsigned char), 1, file);
                    printf(" ID: %d ", FRAME.Element.ID);
                    
                    fwrite(&FRAME.Element.TYPE, sizeof(unsigned char), 1, file);
                    printf(" TYPE: %d ", FRAME.Element.TYPE);

                    FRAME.Element.SIZE = Decod_TYPE(FRAME.Element.TYPE);

                    FRAME.Verify = fwrite(FRAME.Element.VALUE.PVOID, FRAME.Element.SIZE, 1, file);
                    LoadInVALUE(&FRAME.Element, BD_REF.P_BD[i]->VALUE); //-> Funcion AUXILIAR para cambiar el dato de carga visto XDD
                    printVALUE(&FRAME.Element);
                    
                
                    FRAME.CounterVerify += FRAME.Verify;
                    printf(" LOAD? %d \n", FRAME.Verify);

                    Sleep(250);
                }
                
                fclose(file); 

                REF_Valores->secGUARDADO = 1;

                FRAME.ESTADO = RESULTADO;

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

        case RESULTADO:
            G_FRAME.DATA = 0;
            G_FRAME.CURSOR = MENU;

            actTIME(); //Actualiza referencia de tiempo TIME
            for(int i = 0; i < 50; i++){
                actEXTRA(); //Actualiza los parametros de mejoras por tiempo
            } 

            Sleep(3000);
        break;


    }

}

/// @brief Funcion aparte para decodificar el dato en BD
/// @param Element Referencia al objeto
/// @param file puntero al archivo
void extractVALUE(BD_ELEM_T* Element, FILE* file){

         if(Element->TYPE == T_REF_LONG)  fread(&Element->VALUE.LONG , Element->SIZE, 1, file);
    else if(Element->TYPE == T_REF_UCHAR) fread(&Element->VALUE.UCHAR, Element->SIZE, 1, file);
    else if(Element->TYPE == T_REF_FLOAT) fread(&Element->VALUE.FLOAT, Element->SIZE, 1, file);

}

/// @brief Funcion aparte para almacenar el dato en el juego
/// @param Element Referencia al objeto
/// @return verificacion de si pudo almacenar el dato
int loadVALUE(BD_ELEM_T* Element){

    int R = 1;

         if(Element->TYPE == T_REF_LONG)  *(long*)BD_REF.P_BD[Element->ID]->VALUE = Element->VALUE.LONG;
    else if(Element->TYPE == T_REF_UCHAR) *(unsigned char*)BD_REF.P_BD[Element->ID]->VALUE = Element->VALUE.UCHAR;
    else if(Element->TYPE == T_REF_FLOAT) *(float*)BD_REF.P_BD[Element->ID]->VALUE = Element->VALUE.FLOAT;
    else R = 0;

    return R;

}

/// @brief Funcion aparte para almacenar mostrar el dato almacenado o cargado
/// @param Element Referencia al objeto
void printVALUE(BD_ELEM_T* Element){

    printf("DATO : ");

         if(Element->TYPE == T_REF_LONG)  printf("%ld ", Element->VALUE.LONG);
    else if(Element->TYPE == T_REF_UCHAR) printf("%u ", Element->VALUE.UCHAR);
    else if(Element->TYPE == T_REF_FLOAT) printf("%f ", Element->VALUE.FLOAT);
    else                                  printf("NULL ");
}

/// @brief Funcion auxiliar para cambiar el valor de VALOR
/// @param Element Referencia al elemento temporal
/// @param InVALUE Valor a guardar
void LoadInVALUE(BD_ELEM_T* Element, void* InVALUE){

         if(Element->TYPE == T_REF_LONG)  Element->VALUE.LONG  = *(long*)InVALUE;
    else if(Element->TYPE == T_REF_UCHAR) Element->VALUE.UCHAR = *(unsigned char*)InVALUE;
    else if(Element->TYPE == T_REF_FLOAT) Element->VALUE.FLOAT = *(float*)InVALUE;


}

