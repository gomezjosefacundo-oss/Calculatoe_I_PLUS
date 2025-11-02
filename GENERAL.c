//Definicion de todas las variables globales de uso en todo el juego
#include "MENUS/Public.h"

//Inicializacion de los parametros de juego.
DEF_GAME_VALUE GAME_VALUE = {

	.VALORES = {

		.Base = 0.1,
		.Eficiencia = 0.001, //0.1%
		.Potencia = 1.0,
		
		.Ran = 0.2, //20%

		.Time_Autom = 10000, //En milis, 10Seg
		.Eff_Autom = 0.2, //20%

		.EXTRA_Base = 5,
		.EXTRA_Porcentual = 0.005, //0.5%

        .Click = 0, //Valor constante del click
		.Ans = 0 //No puntos(? :c

	},

	.RELOJ = {

		.TIME = 0, //Almacenado en SEGUNDOS
		.INIT = 0, //Desde ahora en SEGUNDOS
		.NOW = 0 //Consulta en SEGUNDOS

	},

	.OPCIONES = {

		.ShowClick = 0,  //DEF. No muestra el valor del click
		.ShowDelay = 0  //DEF. No muestra retraso entre clicks autom

	}

};

//Inizializacion del FRAME general
GENERAL_FRAME G_FRAME = {
	
	.CURSOR = INTRO, //Apunta al intro
	.DATA = 0, //No hay dato extra

	.GAME_VALUE = &GAME_VALUE //Puntero a la estructura de valores del juego

}; //Defino cursor de menu