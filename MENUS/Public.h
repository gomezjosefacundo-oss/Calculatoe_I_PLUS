//FUNCIONES PUBLICAS DE INICIAL DE MENUS

// *** LIBRERIAS GLOBALES ***
#include <stdio.h> //Libreria estandar
#include <stdlib.h> //Para el system("pause") y system("cls")
#include <windows.h> //Para el Sleep(.)
#include <conio.h> //Para el getch(.) y kbhit()
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

typedef struct{ //Valores actuales de juego
        float Base;
        float Eficiencia;
        float Potencia;
        float Ran;

        float Time_Autom; //Milisegundos
        float Eff_Autom;

        int EXTRA_Base;
        float EXTRA_Porcentual;
        int EXTRA_LvBase;
        int EXTRA_LvPorc;

        int secGUARDADO;

        float Ans;

} VALORES_T;

typedef struct{
        int ShowDelay; //Opcion de mostrar retraso de Autom.
        int ShowClick; //Muestra el valor de tu click actual

} OPCIONES_T;

typedef struct{
        reloj_s savedTIME; //Timepo de referencia desde comienzo del juego 
        reloj_s TIME; //Tiempo referencia de EJECUCION ACTUAL

} RELOJ_T;

typedef struct{
    
    VALORES_T VALORES;

    OPCIONES_T OPCIONES;

    RELOJ_T RELOJ;

} DEF_GAME_VALUE;

typedef struct{ //Cursor GENERAL de todo el juego

	DEF_MENU CURSOR;
	int DATA;
    DEF_GAME_VALUE *GAME_VALUE;

} GENERAL_FRAME;

typedef struct { //Estructura de cada nivel
	float MAX;
	float PRECIO;
	float MEJORA;
	
} NIVEL;

typedef struct{ //Estructura de camntidad de niveles

    int c_BASE;
	int c_EFICIENCIA;
	int c_POTENCIA;
	int c_RAN;
	int c_EF_AUTOM;
    int c_TI_AUTOM;

} CANTIDAD_T;

typedef struct{
	CANTIDAD_T CANTIDAD_TYPE;

	NIVEL BASE[30];
	NIVEL EFICIENCIA[21];
	NIVEL POTENCIA[12];
	NIVEL RAN[10];
	NIVEL EF_AUTOM[10];
    NIVEL TI_AUTOM[10];
	
} MEJORAS_T;

// *** FUNCIONES GLOBALES DE MENU ***

void I_Intro(); //Prototipo desde INTRO.c "0" 
//Data["0"]

void I_Menu(); //Prototipo desde MENU.c "1" 
//Data["0"]

void I_Clicker(); //Prototipo desde CLICKER.c "2" 
//Data["1" Manual o "2" Autom]

void I_TablaMejoras(); //Prototipo desde TALBA_MEJORAS.c "3" 
//Data["0" Base || "1" EffBase || "2" Potencia || "3" Ran || "4" TAutom || "5" EffAutom]

void I_Opciones(); //Prototipo desde OPCIONES.c "4"
//Data["0"]

void I_Partida(); //Prototipo desde PARTIDA.c "5"
//Data["1" Cargar o "2" Guardar]

void I_Tab(); //Prototipo desde TAB.c "6"
//Data["0"]




// *** FUNCIONES GLOBALES ***

char getKEY(); //Funcion de detector de tecla

void ImprimirTiempo(reloj_s tiempo); //Para imprimir el tiempo en TAB

void actEXTRA(); //Actualiza los parametros EXTRA

void actTIME(); //Actualiza el tiempo total para TIME

float Click_Event(int EVENTO, int AUTOM); //EVETO "0"-Promedio(numero) "1"-Real+!TEXTO! //AUTOM "0"-Manual "1"-Autom

void BarraProgrecion(); // Inclusion didactica de cuan avanzado se esta en el juego :)

void cappaDelay(); //Un limitador para desincentivar al uso de autoclickers, de forma modesta no brusca


// *** ESTRUCTURAS GLOBALES ***
extern DEF_GAME_VALUE GAME_VALUE;

extern GENERAL_FRAME G_FRAME;

extern MEJORAS_T GLOBAL_MEJORAS;