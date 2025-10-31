//Definicion de todas las funciones globales de uso en todo el juego





char getKEY(){ //Detrector de tecla, retornando de forma global la tecla usada.

    enum TECLAS{ //Por getch
    NULO = 0,
    ARRIBA = 72,
    ABAJO = 80,
    IZQUIERDA = 75,
    DERECHA = 77,
    TAB = 9

    };

    char KEY = 0; //0 - Nada || U D L R - Flechas (Click igual a R) || T - El tabulador

    while(KEY == 0){
    
        KEY = getch();

        switch(KEY){
            case ARRIBA:
                KEY = 'U';

            break;

            case ABAJO:
                KEY = 'D';

            break;

            case IZQUIERDA:
                KEY = 'L';

            break;

            case DERECHA:
                KEY = 'R';

            break;

            case TAB:
                KEY = 'T';

            break;

            default:
                KEY = 0;

            break;


        }
    }
    return KEY;

}