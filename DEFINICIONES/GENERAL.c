/// *** ! Definicion de todas las variables globales de uso en todo el juego ! *** ///
#include "../HEADER/Public.h"

///@brief Inizializacion del FRAME general
GENERAL_FRAME G_FRAME = {
	
	.CURSOR = INTRO, //Apunta al intro
	.DATA = 0, //No hay dato extra

	.P_MENUS = {0},

	///@brief Inicializacion de los parametros de juego.
	.GAME_VALUE = {

		.VALORES = {

			.Base = 0.1,
			.Eficiencia = 0.001, //0.1%
			.Potencia = 1.0,
			
			.Ran = 0.4, //40%Med

			.Time_Autom = 10000, //En milis, 10Seg
			.Eff_Autom = 0.2, //20%

			.EXTRA_Base = 5,
			.EXTRA_Porcentual = 0.005, //0.5%
			.EXTRA_LvBase = 0,
			.EXTRA_LvPorc = 0,

			.secGUARDADO = 0, //No hay partida guardada al comienzo
			.Ans = 0, //No puntos(? :c

			.P_PARAMETROS = {0},

			/// @brief referencia de vercion de partida
			.PartidaVer = 1

		},

		.RELOJ = {

			.savedTIME = 0, //Almacenado en SEGUNDOS
			.TIME = 0 //Consulta en SEGUNDOS

		},

		.OPCIONES = {

			.ShowDelay = 0,  //DEF. No muestra retraso entre clicks autom
			.ShowClick = 0,  //DEF. No muestra el valor del click
			.ShowCostClick = 0, //DEF. NO muestra el coste o esfuerzo de clicks
			.P_OPCIONES = {0}

		}

	} 

};