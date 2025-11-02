//FUNCIONES PUBLICAS DE INICIAL DE MENUS

// *** LIBRERIAS GLOBALES ***
#include <stdio.h> //Libreria estandar
#include <stdlib.h> //Para el system("pause")
#include <windows.h> //Para el Sleep(.)
#include <conio.h> //Para el getch(.)
#include <time.h> //Para los datos clock_t y el uso de clock(); //Retornan en milis
#include <math.h> //Para calcular la pow() de un numero

// *** TYPEDEF GLOBALES ***
typedef long reloj_s;

typedef enum{

    INTRO,         // 0
    MENU,          // 1
    CLICKER,       // 2
    TABLA_MEJORAS, // 3
    OPCIONES,      // 4
    PARTIDA,       // 5
    TAB            // 6

} DEF_MENU;

typedef struct{
    struct{ //Valores actuales de juego
        float Base;
        float Eficiencia;
        float Potencia;
        float Ran;

        float Time_Autom;
        float Eff_Autom;

        float EXTRA_Base;
        float EXTRA_Porcentual;

        float Click;
        float Ans;

    } VALORES;

    struct{
        int ShowDelay; //Opcion de mostrar retraso de Autom.
        int ShowClick; //Muestra el valor de tu click actual

    } OPCIONES;

    struct{ //RECORDAR DIVIDIR POR "CLOCKS_PER_SEC" YA QUE SOLO USARE EL DATO EN SEGUNDOS
        reloj_s TIME; //Timepo de referencia desde comienzo del juego 
        reloj_s INIT; //Tiempo referencia de EJECUCION ACTUAL
        reloj_s NOW; //Tiempo de actualizacion y referencia

    } RELOJ;

} DEF_GAME_VALUE;

typedef struct{

	DEF_MENU CURSOR;
	int DATA;
    DEF_GAME_VALUE *GAME_VALUE;

} GENERAL_FRAME;

// *** FUNCIONES GLOBALES DE MENU ***

void I_Intro(); //Prototipo desde INTRO.c "0" 
//Data["0"]

void I_Menu(); //Prototipo desde MENU.c "1" 
//Data["0"]

void I_Clicker(); //Prototipo desde CLICKER.c "2" 
//Data["1" Manual o "2" Autom]

//void I_TablaMejoras(); //Prototipo desde TALBA_MEJORAS.c "3" 
//Data["0" Base || "1" EffBase || "2" Potencia || "3" Ran || "4" TAutom || "5" EffAutom]

//void I_Opciones(); //Prototipo desde OPCIONES.c "4"
//Data["0"]

//void I_Partida(); //Prototipo desde PARTIDA.c "5"
//Data["1" Cargar o "2" Guardar]

// void I_Tab(); //Prototipo desde TAB.c "6"
//Data["0"]




// *** FUNCIONES GLOBALES ***

char getKEY(); //Funcion de detector de tecla

reloj_s Tiempo_s(); //Consulta de clock(), pero en Segundos

float Click_Event(int EVENTO, int AUTOM); //EVETO "0"-Promedio(numero) "1"-Real+!TEXTO! //AUTOM "0"-Manual "1"-Autom


// *** ESTRUCTURAS GLOBALES ***
extern DEF_GAME_VALUE GAME_VALUE;

extern GENERAL_FRAME G_FRAME;