// *** TYPEDEF GLOBALES *** //

/// @brief Tipo de dato retornado por actTIME
typedef long reloj_s;

/// @brief Numeraciones de los menus
typedef enum{

    INTRO,         // 0
    MENU,          // 1
    CLICKER,       // 2
    TABLA_MEJORAS, // 3
    OPCIONES,      // 4
    PARTIDA,       // 5
    TAB            // 6

} DEF_MENU;

/// @brief Estructura de mejoras internas
typedef struct{ //Valores actuales de juego
        float Base;               //0
        float Eficiencia;         //1
        float Potencia;           //2
        float Ran;                //3

        float Time_Autom;         //4
        float Eff_Autom;          //5

        float EXTRA_Base;         
        float EXTRA_Porcentual;   
        int EXTRA_LvBase;         
        int EXTRA_LvPorc;         

        float Ans;                //9

        int secGUARDADO;


        /// @brief Arreglo de puntero a los parametros jugables
        ///@param INDEX 0-BASE | 1-EFICIENCIA | 2-POTENCIA | 3-RAN | 4-TI_EUTOM | 5-EF_AUTOM | 6-TIME | 7-OP1 | 8-OP2 | 9-Ans
        void* P_PARAMETROS[10];


        /// @brief Parametro fundamental para determinar el tipo de base de datos de partida esperada
        unsigned char PartidaVer;

} VALORES_T;

/// @brief Estructura de Opciones internas
typedef struct{
        unsigned char ShowDelay; //7     //Opcion1 - Mostra el retraso de Autom.
        unsigned char ShowClick; //8      //Opcion2 - Muestra el valor de tu click actual
        unsigned char ShowCostClick;

        unsigned char *P_OPCIONES[3];

} OPCIONES_T;

/// @brief Estructura de RELOJES internos
typedef struct{
        reloj_s savedTIME; //Timepo de referencia desde comienzo del juego 
        reloj_s TIME;           //6    //Tiempo referencia de EJECUCION ACTUAL

} RELOJ_T;

/// @brief Definicion de la estructura generalizadora de la informacion del juego
typedef struct{
    
    VALORES_T VALORES;

    OPCIONES_T OPCIONES;

    RELOJ_T RELOJ;

} DEF_GAME_VALUE;


/// @brief Definicion del Cursor GENERAL de todo el juego
typedef struct{ 

	DEF_MENU CURSOR;
	int DATA;

    void (*P_MENUS[7])(void);

    DEF_GAME_VALUE GAME_VALUE;

} GENERAL_FRAME;


/// @brief Definicion de la Estructura de cada nivel
typedef struct { 
	float MAX;
	float PRECIO;
	float MEJORA;
	
} NIVEL;

/// @brief Estructura con cantidad de niveles
typedef struct{ 

    int c_BASE;
	int c_EFICIENCIA;
	int c_POTENCIA;
	int c_RAN;
	int c_EF_AUTOM;
    int c_TI_AUTOM;

    /// @brief Arreglo de puntero a cantidad de mejoras
    ///@param INDEX 0-BASE | 1-EFICIENCIA | 2-POTENCIA | 3-RAN | 4-TI_EUTOM | 5-EF_AUTOM
    int* P_CANTIDAD[6];

} CANTIDAD_T;

/// @brief Estructura de datos por cantidad y datos de mejoras + puntero iterable
typedef struct{
	CANTIDAD_T CANTIDAD_TYPE;

	NIVEL BASE[30];
	NIVEL EFICIENCIA[21];
	NIVEL POTENCIA[12];
	NIVEL RAN[10];
    NIVEL TI_AUTOM[10];
	NIVEL EF_AUTOM[10];

    /// @brief Arreglo de puntero a arreglo de mejoras
    ///@param INDEX 0-BASE | 1-EFICIENCIA | 2-POTENCIA | 3-RAN | 4-TI_EUTOM | 5-EF_AUTOM 
    NIVEL* P_MEJORAS[6];
	
} MEJORAS_T;



typedef struct {

    /// @brief Referencia numerica y inmutable de un elemento en la base de datos
    unsigned char ID;

    /// @brief referencia por bytes del largo de bytes almacenados para este elemento.
    unsigned char TYPE;

    /// @brief puntero a void del valor del elemento.
    void* VALUE;

} ELEMENT_T;

typedef struct {

    ELEMENT_T BASE;        //0
    ELEMENT_T EFICIENCIA;  //1
    ELEMENT_T POTENCIA;    //2
    ELEMENT_T RAN;         //3
    ELEMENT_T TI_AUTOM;    //4
    ELEMENT_T EF_AUTOM;    //5

    ELEMENT_T TIME;        //6
    ELEMENT_T ANS;         //7

    ELEMENT_T SHOW_DELAY;  //8
    ELEMENT_T SHOW_CLICK;  //9
    ELEMENT_T SHOW_COSTCLICK;  //10

    ELEMENT_T *P_BD[11];
} BD_T;

//Para solo añadir Definiciones si se las usa (evitar info basura)
#ifdef REF_BD_ELEMENT

#define REF_BASE 0
#define REF_EFICIENCIA 1
#define REF_POTENCIA 2
#define REF_RAN 3
#define REF_TIAUTOM 4
#define REF_EFATUOM 5
#define REF_TIME 6
#define REF_ANS 7
#define REF_SHOWDELAY 8
#define REF_SHOWCLCIK 9
#define REF_COSTCLICK 10

#define T_REF_LONG 0
#define T_REF_UCHAR 1
#define T_REF_FLOAT 2

#endif

