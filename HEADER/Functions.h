// *** FUNCIONES GLOBALES DE MENU *** //

/// @brief INTRO.c "0" || Data["0"]
void I_Intro(); 

/// @brief MENU.c "1" || Data["0"]
void I_Menu(); 

/// @brief CLICKER.c "2" || Data["1" Manual o "2" Autom]
void I_Clicker();

/// @brief TALBA_MEJORAS.c "3" || Data["0" Base || "1" EffBase || "2" Potencia || "3" Ran || "4" TimeAutom || "5" EffAutom]
void I_TablaMejoras(); 

/// @brief OPCIONES.c "4" || Data["0"]
void I_Opciones(); 

/// @brief PARTIDA.c "5" || Data["1" Cargar o "2" Guardar]
void I_Partida(); 

/// @brief TAB.c "6" || Data["0"]
void I_Tab(); 



// *** FUNCIONES GLOBALES ***

/// @brief Funcion de detector de tecla
/// @return Tecla apretada 'char' (U.arriba D.abajo L.izquierda R.derecha T.tabulador)
/// @exception Si no apreto ninguna tecla referida suelta '0'
char getKEY(); 

/// @brief Para imprimir el tiempo en TAB
/// @param  Tiempo en segundos.
/// @return Tiempo formateado en HH.hr MM.min SS.seg en pantalla 
void ImprimirTiempo(reloj_s tiempo); 

/// @brief Actualiza los parametros EXTRA 
void actEXTRA(); 

/// @brief Actualiza el tiempo total para TIME
void actTIME(); 

/// @brief Funcion generalizadora de todos los posibles clicks.
/// @param EVENTO 0-Promedio(numero) || 1-Real+!TEXTO!
/// @param AUTOM 0-Manual || 1-Autom
/// @return Un valor 'float' del numero del click generado
float Click_Event(int EVENTO, int AUTOM); 

/// @brief Inclusion didactica de cuan avanzado se esta en el juego :)
/// @return Barra de progrecion y valor porcentual de todas las mejoras, imprime en pantalla
void BarraProgrecion(); 

/// @brief Funcion auxiliar para definir elementos dinamicos de estructuras, NO definibles en su comienzo
void normalizarDinamicos();

/// @brief Funcion que genera las referencias dinamicas de los elementos a cargar y guardar en una base de datos
void LoadBD_REF();

/// @brief Funcion auxiliar para decodificar el largo de un tipo de dato a escribir o recuperar
/// @param  0- LONG 1-UCHAR 2-FLOAT
/// @return zise_t del largo detectado
size_t Decod_TYPE(unsigned char);

/*
/// @brief Permite la igualacion dinamica entre el dato EXTRAIDO y a donde ira a ser guardado el dato
/// @param  void* A donde se guardara
/// @param  void* El dato desde la BD
/// @param  char El tipo del que viene de la BD.
int Asignador_BD(void*, void*, char);*/

/// @brief Copia elementos del arreglo A -> B
/// @param A > primer arreglo
/// @param B > segundo arreglo
/// @param SizeArr_A > Largo del arreglo A
void COPYArr(void* A[], void* B[], int SizeArr_A);

/// @brief ADMIN 8) 
void ModificarValores();