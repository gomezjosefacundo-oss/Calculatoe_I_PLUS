#include <iostream>

#include <windows.h>

#include <math.h>

#include <stdlib.h>

#include <time.h>
#include <ctime>
#include <fstream>
#include <iomanip>


using namespace std;


unsigned exp0, exp1; //tiempo de mejora %%
    unsigned exm0, exm1; //tiempo de mejora **

void GuardarPARTIDA(double B, double Fp, double P, double Rx, double Ap, double As, double Ans, double EXplus, double EXp, double Last_exm, double Last_exp, double Niv_exm, double Niv_exp, bool Op1, bool Op2, double _ExpDinero, double SignoExpDinero, double exp, double exm);
double Answer(double B, double Fp, double P, double Rx, double Ap, double As, double Rand, int Autom, bool Op1, double TotalAutom);


int main()
{
    uint64_t _Base, _Eficiencia, _Potencia, _Ran, _AutoM, _AutoS, _Dinero, _ExpDinero, SignoExpDinero, _Op, _Op1, _Op2, _EXm, _EXp, _EXmt, _EXpt, _EXml, _EXpl;
    double _ExpDineroD; //Variables EXTRA!!

    uint64_t CODIGO1, CODIGO2, CODIGO3;

    double exp, exm; //Sarcar el total de tiempo de cada
    int Lim_exp = 50; // limites de mejora
    int Lim_exm = 8;
    int Niv_exp = 0;  //Nivel actual de cada
    int Niv_exm = 0;

    int Last_exp = 0;
    int Last_exm = 0;

    int TIEMPO_exp, TIEMPO_exm;

    exp0 = clock();
    exm0 = clock();

    int Sure = 0;

   //Datos de TODAS las mejoras
   double DATOM[15][30];
   //1-Limite 2- Coste 3-Mejora

   if("BASE" == "BASE"){
   //Mejoras Base
   DATOM[0][0] = 0.2;
   DATOM[1][0] = 0.05;
   DATOM[2][0] = 0.005;
   DATOM[0][1] = 0.3;
   DATOM[1][1] = 0.1;
   DATOM[2][1] = 0.005;
   DATOM[0][2] = 0.5;
   DATOM[1][2] = 0.15;
   DATOM[2][2] = 0.01;

   DATOM[0][3] = 1;
   DATOM[1][3] = 0.25;
   DATOM[2][3] = 0.025;
   DATOM[0][4] = 1.5;
   DATOM[1][4] = 0.5;
   DATOM[2][4] = 0.025;
   DATOM[0][5] = 2;
   DATOM[1][5] = 0.75;
   DATOM[2][5] = 0.025;

   DATOM[0][6] = 3;
   DATOM[1][6] = 1;
   DATOM[2][6] = 0.05;
   DATOM[0][7] = 5;
   DATOM[1][7] = 1.5;
   DATOM[2][7] = 0.1;
   DATOM[0][8] = 7;
   DATOM[1][8] = 2.5;
   DATOM[2][8] = 0.1;

   DATOM[0][9] = 12;
   DATOM[1][9] = 175;
   DATOM[2][9] = 0.25;
   DATOM[0][10] = 20;
   DATOM[1][10] = 300;
   DATOM[2][10] = 0.4;
   DATOM[0][11] = 30;
   DATOM[1][11] = 500;
   DATOM[2][11] = 0.5;

   DATOM[0][12] = 80;
   DATOM[1][12] = 3750;
   DATOM[2][12] = 2;
   DATOM[0][13] = 150;
   DATOM[1][13] = 10000;
   DATOM[2][13] = 2.8;
   DATOM[0][14] = 300;
   DATOM[1][14] = 18800;
   DATOM[2][14] = 6;

   DATOM[0][15] = 500;
   DATOM[1][15] = 67500;
   DATOM[2][15] = 8;
   DATOM[0][16] = 1200;
   DATOM[1][16] = 113000;
   DATOM[2][16] = 28;
   DATOM[0][17] = 2300;
   DATOM[1][17] = 270000;
   DATOM[2][17] = 44;

   DATOM[0][18] = 3800;
   DATOM[1][18] = 1550000;
   DATOM[2][18] = 50;
   DATOM[0][19] = 5600;
   DATOM[1][19] = 12900000;
   DATOM[2][19] = 60;
   DATOM[0][20] = 7700;
   DATOM[1][20] = 110000000;
   DATOM[2][20] = 70;

   DATOM[0][21] = 9950;
   DATOM[1][21] = 637000000;
   DATOM[2][21] = 75;
   DATOM[0][22] = 12350;
   DATOM[1][22] = 5860000000;
   DATOM[2][22] = 80;
   DATOM[0][23] = 15050;
   DATOM[1][23] = 55100000000;
   DATOM[2][23] = 90;

   DATOM[0][24] = 19050;
   DATOM[1][24] = 362000000000;
   DATOM[2][24] = 100;
   DATOM[0][25] = 23850;
   DATOM[1][25] = 4340000000000;
   DATOM[2][25] = 120;
   DATOM[0][26] = 29450;
   DATOM[1][26] = 55700000000000;
   DATOM[2][26] = 140;

   DATOM[0][27] = 38000;
   DATOM[1][27] = 499000000000000;
   DATOM[2][27] = 171;
   DATOM[0][28] = 50000;
   DATOM[1][28] = 8540000000000000;
   DATOM[2][28] = 240;
   DATOM[0][29] = 75500;
   DATOM[1][29] = 172000000000000000;
   DATOM[2][29] = 510;

   }

   if("EFICIENCIA" == "EFICIENCIA"){
   //Mejoras Eficiencicia
   DATOM[3][9] = 0.05;
   DATOM[4][9] = 6;
   DATOM[5][9] = 0.0098;
   DATOM[3][10] = 0.15;
   DATOM[4][10] = 300;
   DATOM[5][10] = 0.02;
   DATOM[3][11] = 0.2;
   DATOM[4][11] = 900;
   DATOM[5][11] = 0.01;

   DATOM[3][12] = 0.25;
   DATOM[4][12] = 8000;
   DATOM[5][12] = 0.01;
   DATOM[3][13] = 0.3;
   DATOM[4][13] = 10000;
   DATOM[5][13] = 0.01;
   DATOM[3][14] = 0.4;
   DATOM[4][14] = 12000;
   DATOM[5][14] = 0.02;

   DATOM[3][15] = 0.45;
   DATOM[4][15] = 100000;
   DATOM[5][15] = 0.01;
   DATOM[3][16] = 0.5;
   DATOM[4][16] = 113000;
   DATOM[5][16]= 0.01;
   DATOM[3][17] = 0.6;
   DATOM[4][17] = 125000;
   DATOM[5][17] = 0.02;

   DATOM[3][18] = 0.65;
   DATOM[4][18] = 2470000;
   DATOM[5][18] = 0.01;
   DATOM[3][19] = 0.7;
   DATOM[4][19] = 12900000;
   DATOM[5][19] = 0.01;
   DATOM[3][20] = 0.8;
   DATOM[4][20] = 68600000;
   DATOM[5][20] = 0.02;

   DATOM[3][21] = 0.85;
   DATOM[4][21] = 872000000;
   DATOM[5][21] = 0.01;
   DATOM[3][22] = 0.9;
   DATOM[4][22] = 5860000000;
   DATOM[5][22] = 0.01;
   DATOM[3][23] = 1;
   DATOM[4][23] = 40100000000;
   DATOM[5][23] = 0.02;

   DATOM[3][24] = 1.1;
   DATOM[4][24] = 486000000000;
   DATOM[5][24] = 0.02;
   DATOM[3][25] = 1.2;
   DATOM[4][25] = 4340000000000;
   DATOM[5][25] = 0.02;
   DATOM[3][26] = 1.3;
   DATOM[4][26] = 39500000000000;
   DATOM[5][26] = 0.02;

   DATOM[3][27] = 1.4;
   DATOM[4][27] = 799000000000000;
   DATOM[5][27] = 0.02;
   DATOM[3][28] = 1.45;
   DATOM[4][28] = 8540000000000000;
   DATOM[5][28] = 0.01;
   DATOM[3][29] = 1.5;
   DATOM[4][29] = 83600000000000000;
   DATOM[5][29] = 0.01;

   }

   if("POTENCIA" == "POTENCIA"){
   //Mejoras Potencia
   DATOM[6][17] = 5;
   DATOM[8][17] = 2;
   DATOM[6][18] = 1.1;
   DATOM[7][18] = 2840000;
   DATOM[8][18] = 0.1;
   DATOM[6][19] = 1.3;
   DATOM[7][19] = 25700000;
   DATOM[8][19] = 0.1;
   DATOM[6][20] = 1.5;
   DATOM[7][20] = 245000000;
   DATOM[8][20] = 0.1;

   DATOM[6][21] = 1.6;
   DATOM[7][21] = 1160000000;
   DATOM[8][21] = 0.1;
   DATOM[6][22] = 1.8;
   DATOM[7][22] = 11700000000;
   DATOM[8][22] = 0.1;
   DATOM[6][23] = 2;
   DATOM[7][23] = 124000000000;
   DATOM[8][23] = 0.1;

   DATOM[6][24] = 2.1;
   DATOM[7][24] = 593000000000;
   DATOM[8][24] = 0.1;
   DATOM[6][25] = 2.3;
   DATOM[7][25] = 8690000000000;
   DATOM[8][25] = 0.1;
   DATOM[6][26] = 2.5;
   DATOM[7][26] = 139000000000000;
   DATOM[8][26] = 0.1;

   DATOM[6][27] = 2.6;
   DATOM[7][27] = 824000000000000;
   DATOM[8][27] = 0.1;
   DATOM[6][28] = 2.8;
   DATOM[7][28] = 17100000000000000;
   DATOM[8][28] = 0.1;
   DATOM[6][29] = 3;
   DATOM[7][29] = 381000000000000000; //La mejora mas cara de TODO el juego!!!
   DATOM[8][29] = 0.1;

   }

   if("RAN" == "RAN"){
   //Mejoras Ran#
   DATOM[9][1] = 0.25;
   DATOM[10][1] = 0.04;
   DATOM[11][1] = 0.05;

   DATOM[9][4] = 0.3;
   DATOM[10][4] = 0.2;
   DATOM[11][4] = 0.05;

   DATOM[9][7] = 0.35;
   DATOM[10][7] = 0.6;
   DATOM[11][7] = 0.05;

   DATOM[9][10] = 0.4;
   DATOM[10][10] = 120;
   DATOM[11][10] = 0.05;

   DATOM[9][13] = 0.45;
   DATOM[10][13] = 4000;
   DATOM[11][13] = 0.05;

   DATOM[9][16] = 0.5;
   DATOM[10][16] = 45000;
   DATOM[11][16] = 0.05;

   DATOM[9][19] = 0.6;
   DATOM[10][19] = 1080000;
   DATOM[11][19] = 0.1;

   DATOM[9][22] = 0.7;
   DATOM[10][22] = 384000000;
   DATOM[11][22] = 0.1;

   DATOM[9][25] = 0.8;
   DATOM[10][25] = 238000000000;
   DATOM[11][25] = 0.1;

   DATOM[9][28] = 1;
   DATOM[10][28] = 388000000000000;
   DATOM[11][28] = 0.2;

   }

   if("AUTOM" == "AUTOM"){
   //Mejoras del modo Automatico seg./per%
   DATOM[12][0] = 7200;
   DATOM[13][0] = 0.00325;
   DATOM[14][0] = 1400;
   DATOM[12][1] = 0.42;
   DATOM[13][1] = 0.000325;
   DATOM[14][1] = 0.22;

   DATOM[12][3] = 5760;
   DATOM[13][3] = 0.014;
   DATOM[14][3] = 720;
   DATOM[12][4] = 0.62;
   DATOM[13][4] = 0.0014;
   DATOM[14][4] = 0.2;

   DATOM[12][6] = 4880;
   DATOM[13][6] = 0.0525;
   DATOM[14][6] = 440;
   DATOM[12][7] = 0.8;
   DATOM[13][7] = 0.00525;
   DATOM[14][7] = 0.18;

   DATOM[12][9] = 4240;
   DATOM[13][9] = 48;
   DATOM[14][9] = 320;
   DATOM[12][10] = 0.96;
   DATOM[13][10] = 4.8;
   DATOM[14][10] = 0.16;

   DATOM[12][12] = 3680;
   DATOM[13][12] = 1020;
   DATOM[14][12] = 280;
   DATOM[12][13] = 1.1;
   DATOM[13][13] = 102;
   DATOM[14][13] = 0.14;

   DATOM[12][15] = 3200;
   DATOM[13][15] = 12400;
   DATOM[14][15] = 240;
   DATOM[12][16] = 1.22;
   DATOM[13][16] = 1240;
   DATOM[14][16] = 0.12;

   DATOM[12][18] = 2800;
   DATOM[13][18] = 4830000;
   DATOM[14][18] = 200;
   DATOM[12][19] = 1.32;
   DATOM[13][19] = 483000;
   DATOM[14][19] = 0.1;

   DATOM[12][21] = 2480;
   DATOM[13][21] = 2490000000;
   DATOM[14][21] = 160;
   DATOM[12][22] = 1.4;
   DATOM[13][22] = 249000000;
   DATOM[14][22] = 0.08;

   DATOM[12][24] = 2240;
   DATOM[13][24] = 3440000000000;
   DATOM[14][24] = 120;
   DATOM[12][25] = 1.46;
   DATOM[13][25] = 344000000000;
   DATOM[14][25] = 0.06;

   DATOM[12][27] = 2000;
   DATOM[13][27] = 20300000000000000;
   DATOM[14][27] = 120;
   DATOM[12][28] = 1.5;
   DATOM[13][28] = 2030000000000000;
   DATOM[14][28] = 0.04;

   }

    //declaracion de Datos comunes
    int i = 1;
    double B = 0.1;    //Base
    double Fp = 0.001; //0,1% (ef. de Base)
    double As = 10000; //Vel. del Click Autom.(milisegundos)
    double Ap = 0.20;  //Ef% total del Autom.
    double Rx = 0.2;   //40�%ef (ej. 0.2~0.6)
    double P = 1.0;
    double Ans = 0.0000001;
    int Autom = 0;
    double Valor = 0;
    double TotalAutom = 0;
    double OldValor = 0;
    double NewValor = 0;

    double EXTRA = 100; //Valor aleat. de bonus
    double EXp = 0.5; // Equivalente a 1 en 200
    int EXr = 1; //Numero generado para multiplicar

    int EXmin = 5;//minimo y maximo random a multiplicar
    int EXmax = 31;
    int EXplus = 0; //multiplicador extra Asegurado

    bool Op1 = false; //Mostrar tiempo de Autom. faltante
    bool Op2 = true; //Muestra el valor del click actual

    //Sistema de numeros Aleatorios
    double Rand = rand() % (0 - 40);

    int Pos = 1;
    bool Cambio = true;
    bool Back = false;
    int w = 1;
    bool Conteo = false;
    int Select = 0;



   if(1 == 1){ //Intro
    Sleep(150);
    cout<<"\n\n\n\n\n";
    cout<<"                                       ..\n";
    Sleep(250);
    cout<<"                                      ....\n";
    Sleep(250);
    cout<<"                                  ............\n";
    Sleep(250);
    cout<<"                            ......................\n";
    Sleep(250);
    cout<<"                                -Calculatoe I-\n";
    Sleep(250);
    cout<<"                              ......................\n";
    Sleep(250);
    cout<<"                                  ............\n";
    Sleep(250);
    cout<<"                                      ....\n";
    Sleep(250);
    cout<<"                                       ..\n\n\n";
    Sleep(350);

    cout<<"Ver. 1.4.33.26 \n";
    //Ver. Grandes cambios.a�adidos.cosas menores.bugs
    cout<<"By: XDemonKillX \n\n\n\n\n";

    cout<<"                       [Presione -Derecha- para Continuar]";

    bool Enter = false;

    while(Enter == false){

        if(GetAsyncKeyState(VK_RIGHT)){
        Sleep(30);
        if(false == GetAsyncKeyState(VK_RIGHT)){
            Enter = true;

            system("cls");
            Sleep(400);
        }}
    }
   }


    while(1 == 1){ //Inicio del Juego

    w = 1;
    Back = false;

    GetAsyncKeyState(VK_RIGHT);
    GetAsyncKeyState(VK_LEFT);

/*if(GetAsyncKeyState(VK_RIGHT)){
        Sleep(30);
        if(false == GetAsyncKeyState(VK_RIGHT)){
         //Actualizar valores de prueva
         system("cls");
    cout << "\nBase? \n";
    cin >> B;
    cout << "Porcentaje Eficiencia? \n";
    cin >> Fp;
    cout << "Ran# valor total? \n";
    cin >> Rx;
    cout << "Potencia? \n";
    cin >> P;
    cout << "Automatico (0,off ~ 1,on)? \n";
    cin >> Autom;

    //Actualiza datos del modo Automatico
    if (Autom == 1)
    {
        cout << "\nAutomatico Porcentaje? \n";
        cin >> Ap;
        cout << "Automatico Delay(milisegundo)? \n";
        cin >> As;

    }
        system("cls");
        Cambio = true;

        while(GetAsyncKeyState(VK_RETURN)){ Sleep(30);}
        }}*/



    if(GetAsyncKeyState(VK_UP)){
    Sleep(30);
    if(false == GetAsyncKeyState(VK_UP)){
    Pos = Pos - 1;
    Cambio = true;
    }
    }

    if(GetAsyncKeyState(VK_DOWN)){
    Sleep(30);
    if(false == GetAsyncKeyState(VK_DOWN)){
    Pos = Pos + 1;
    Cambio = true;
    }
    }

    if(Cambio == true){ //Cambia el texto en Pantalla

    switch(Pos){

    case 0: //caso 7
    system("cls");
    Pos = 8;
    break;

    case 1: //clicker
    system("cls");
    cout<<"-Menu- -F12 para consultar Datos-\n\n [Clicker] \n -Mej. Base- \n -Mej. Eficiencia Base- \n -Mej. Potencia- \n -Mej. Ran#- \n -Mej. Automatico- \n\n -Opciones- \n -Partida-";
    Cambio = false;
    break;

    case 2: //Mejora de Base
    system("cls");
    cout<<"-Menu- -F12 para consultar Datos-\n\n -Clicker- \n [Mej. Base] \n -Mej. Eficiencia Base- \n -Mej. Potencia- \n -Mej. Ran#- \n -Mej. Automatico- \n\n -Opciones-  \n -Partida-";
    Cambio = false;
    break;

    case 3: //Mejora de Eficiencia de base
    system("cls");
    cout<<"-Menu- -F12 para consultar Datos-\n\n -Clicker- \n -Mej. Base- \n [Mej. Eficiencia Base] \n -Mej. Potencia- \n -Mej. Ran#- \n -Mej. Automatico- \n\n -Opciones-  \n -Partida-";
    Cambio = false;
    break;

    case 4: //Mejora de Potencia
    system("cls");
    cout<<"-Menu- -F12 para consultar Datos-\n\n -Clicker- \n -Mej. Base- \n -Mej. Eficiencia Base- \n [Mej. Potencia] \n -Mej. Ran#- \n -Mej. Automatico- \n\n -Opciones-  \n -Partida-";
    Cambio = false;
    break;

    case 5: //Mejora de Base Aleatorio
    system("cls");
    cout<<"-Menu- -F12 para consultar Datos-\n\n -Clicker- \n -Mej. Base- \n -Mej. Eficiencia Base- \n -Mej. Potencia- \n [Mej. Ran#] \n -Mej. Automatico- \n\n -Opciones-  \n -Partida-";
    Cambio = false;
    break;

    case 6: //Mejora de Automatico
    system("cls");
    cout<<"-Menu- -F12 para consultar Datos-\n\n -Clicker- \n -Mej. Base- \n -Mej. Eficiencia Base- \n -Mej. Potencia- \n -Mej. Ran#- \n [Mej. Automatico]  \n\n -Opciones-  \n -Partida-";
    Cambio = false;
    break;

    case 7: //Opciones
    system("cls");
    cout<<"-Menu- -F12 para consultar Datos-\n\n -Clicker- \n -Mej. Base- \n -Mej. Eficiencia Base- \n -Mej. Potencia- \n -Mej. Ran#- \n -Mej. Automatico-  \n\n [Opciones]  \n -Partida-";
    Cambio = false;
    break;

    case 8: //Opciones
    system("cls");
    cout<<"-Menu- -F12 para consultar Datos-\n\n -Clicker- \n -Mej. Base- \n -Mej. Eficiencia Base- \n -Mej. Potencia- \n -Mej. Ran#- \n -Mej. Automatico-  \n\n -Opciones-  \n [Partida]";
    Cambio = false;
    break;

    case 9: //caso 1
    system("cls");
    Pos = 1;
    break;
    }
    
    if(B>=7500 && Fp >= 1.5 && P >= 3 && Rx >= 1 && As <= 2000 && Ap >= 1.5){
cout<<"\n\n            ----\n";
    cout<<"          --    --\n";
    cout<<"          - Win! -\n";
    cout<<"          --    --\n";
    cout<<"           ------\n";
    cout<<"          --   --\n";
    cout<<"         --     --\n";
    cout<<"        --      --\n";}
    }

    if(GetAsyncKeyState(VK_F12)){ //Mostrar datos del Juego.
    Sleep(30);
    if(false == GetAsyncKeyState(VK_F12)){
    system("cls");

    //muestra TODOS los datos de mejora
    cout << "\nB= " << B << "*";
    cout << "\nF%= " << (Fp * 100) << "%" << " (x" << Fp <<")";
    cout << "\nR#= " << (Rx * 100) << "%ef" << " (x" << Rx <<")" ;
    cout << "\nP= " << P << "^";

    cout << "\n \nAs= " << (As/1000) << "seg." << " (" << As <<"mili.)";
    cout << "\nA%= " << (Ap*100) << "%" << " (x" << Ap <<")";

    cout <<"\n\nAns = " << Ans << "p\n";
    Autom = 2;
    cout <<"Click= " << Answer(B,Fp,P,Rx,Ap,As,Rand,Autom,Op1,TotalAutom) << "p \n\n";
    //
    exp1 = clock();
    exm1 = clock();
    //
    exp = (double(exp1-exp0)/CLOCKS_PER_SEC)+Last_exp;
    exm = (double(exm1-exm0)/CLOCKS_PER_SEC)+Last_exm;
    //
    cout<<"EX%= " << EXp << "%";
    cout<<" |Mejora en: ";
    
    if(exp < 180000){
    TIEMPO_exp = ((1+Niv_exp)*(-3600)+(exp))*-1;
    cout<<TIEMPO_exp;
    }
	else{
	cout<<"MAXIMO";
	}


    cout<< "seg.| (" << Niv_exp << "L/50L) \n";
    
    cout<<"EX*= " << EXmin << "~" << EXmax;
    /////////////

    cout<<" |Mejora en: ";
    
    if(exm < 180000){
    TIEMPO_exm = ((1+Niv_exm)*(-22500)+(exm))*-1;
    cout<<TIEMPO_exm;
    }
	else{
	cout<<"MAXIMO";
	}

    
    cout<< "seg.| (" << Niv_exm << "L/8L) \n";
    

    cout<<"EX+= +" << EXplus;


    cout<<"\n\n*Ganaras una medalla de victoria si mejoras todo!";






    /*cout << "\n\nTruco Activado \n";
    Ans*=10;*/

    Sleep(4500);
    Cambio = true;
    Autom = 1;
    }}

    if(GetAsyncKeyState(VK_RIGHT)){ //det. enter
    Sleep(30);
    if(false == GetAsyncKeyState(VK_RIGHT)){

    switch(Pos){

    case 1: //clicker
    system("cls");

    while(Back == false){

    if(w == 1){
       Cambio = true;
       w = 0;
    }

    if(GetAsyncKeyState(VK_UP)){
    Sleep(30);
    if(false == GetAsyncKeyState(VK_UP)){
    Autom = 0;
    Cambio = true;
    }}

    if(GetAsyncKeyState(VK_DOWN)){
    Sleep(30);
    if(false == GetAsyncKeyState(VK_DOWN)){
    Autom = 1;
    Cambio = true;
    }}


    if(Autom == 0 && Cambio == true){ // Seleccion a modo manual
    system("cls");
    cout<<"-Menu- \n\n -Clicker- [Manual] || -Autom.- \n -Mej. Base- \n -Mej. Eficiencia Base- \n -Mej. Potencia- \n -Mej. Ran#- \n -Mej. Automatico- \n\n -Opciones-  \n -Partida-";
    Cambio = false;
    }
    if(Autom == 1 && Cambio == true){ //Seleccion a modo Automatico
    system("cls");
    cout<<"-Menu- \n\n -Clicker- -Manual- || [Autom.] \n -Mej. Base- \n -Mej. Eficiencia Base- \n -Mej. Potencia- \n -Mej. Ran#- \n -Mej. Automatico- \n\n -Opciones-  \n -Partida-";
    Cambio = false;
    }


    if(GetAsyncKeyState(VK_LEFT)){ //Cambias al menu principal
    Sleep(30);
    if(false == GetAsyncKeyState(VK_LEFT)){
        Back = true;
        Cambio = true;
        }}


     if(GetAsyncKeyState(VK_RIGHT)){ //Apretas Enter para empezar el Clicker
        Sleep(30);
        if(false == GetAsyncKeyState(VK_RIGHT)){
        Conteo = true;
        system("cls");

        if(Autom == 0){
        cout<<"Apreta el Click Izquierdo para Sumar!";
        }
        else{
        TotalAutom = 0;
        cout<<"El modo Automatico Activado... " << (As/1000) << "seg. \n" << "-Apreta F12 para consultar datos-";
        }
        }}

        while(Conteo == true){


         Valor = Answer(B,Fp,P,Rx,Ap,As,Rand,Autom,Op1, TotalAutom);
         if(Autom == 1){TotalAutom += Valor;}

            exp1 = clock();
            exm1 = clock();
            //
            exp = (double(exp1-exp0)/CLOCKS_PER_SEC)+Last_exp;
            exm = (double(exm1-exm0)/CLOCKS_PER_SEC)+Last_exm;

            if( ((1+Niv_exp)*(-3600)+(exp))*-1 <= 0 && Niv_exp < Lim_exp){
            Niv_exp = Niv_exp + 1;
            EXp = EXp + 0.015;
            }

            if( ((1+Niv_exm)*(-22500)+(exm))*-1 <= 0 && Niv_exm < Lim_exm){
            Niv_exm = Niv_exm + 1;
            EXplus = EXplus + 1;
            }

            if(Valor == -1){ // salir del modo Automatico
                Valor = 0;
                Conteo = false;
                Back = true;
                Cambio = true;
                Sleep(30);
                }



            //Funcion BONUS
            if(Valor > 0){
            EXTRA = rand() % (0 - 10000);
            EXTRA = EXTRA / 100;

            }

            if(Autom == 0 && EXTRA <= EXp){
             EXr = EXmin + rand()%(EXmax-EXmin);
             EXr = EXr + EXplus;
             Valor = Valor * EXr;
             cout<< "Extra Click: x" << EXr;
             EXTRA = 100;
             srand(time(NULL));
            }
            if(Autom == 1 && EXTRA <= (EXp * 1.0666)){
             EXr = EXmin + rand()%(EXmax-EXmin);
             EXr = EXr + EXplus;
             Valor = Valor * EXr;
             cout<< "Extra Click: x" << EXr;
             EXTRA = 100;
             srand(time(NULL));
            }


            if(Valor > 0){
            Ans = Ans + Valor;

            cout << "\n[Ans= " << Ans << "]\n";
            //Valor del click
            if(Op2 == true){
            cout << "Click= " << Valor << "\n\n";
            }}

        if(GetAsyncKeyState(VK_LEFT)){ //Apretas Back para salir del Clicker...
        Sleep(30);
        if(false == GetAsyncKeyState(VK_LEFT)){
        Conteo = false;
        Back = true;
        Cambio = true;
        }}
        }
    }

    case 2: //Mejora Base
  system("cls");
    Autom = 2;
    OldValor = Answer(B,Fp,P,Rx,Ap,As,Rand,Autom,Op1,TotalAutom);
    Autom = 1;
    while(Back == false){

    if(w == 1){
    system("cls");
    w = 0;

    cout<<"-Mejora de Base- \n";
    cout<<"Escriba el Numero de la mejora que desee.\n [0 = Salir] - [1..30 = Seleccionar] \n\n";

    cout<<"-Tanta 1-\n";
    cout<<"Limite|Coste|Mejora \n";
    cout<<"1- " << DATOM[0][0] << " | " << DATOM[1][0] << " | " << DATOM[2][0] << "\n";
    cout<<"2- " << DATOM[0][1] << " | " << DATOM[1][1] << " | " << DATOM[2][1] << "\n";
    cout<<"3- " << DATOM[0][2] << " | " << DATOM[1][2] << " | " << DATOM[2][2] << "\n\n";

    cout<<"-Tanta 2-\n";
    cout<<"4- " << DATOM[0][3] << " | " << DATOM[1][3] << " | " << DATOM[2][3] << "\n";
    cout<<"5- " << DATOM[0][4] << " | " << DATOM[1][4] << " | " << DATOM[2][4] << "\n";
    cout<<"6- " << DATOM[0][5] << " | " << DATOM[1][5] << " | " << DATOM[2][5] << "\n\n";

    cout<<"-Tanta 3-\n";
    cout<<"7- " << DATOM[0][6] << " | " << DATOM[1][6] << " | " << DATOM[2][6] << "\n";
    cout<<"8- " << DATOM[0][7] << " | " << DATOM[1][7] << " | " << DATOM[2][7] << "\n";
    cout<<"9- " << DATOM[0][8] << " | " << DATOM[1][8] << " | " << DATOM[2][8] << "\n\n";

    cout<<"-Tanta 4-\n";
    cout<<"10- " << DATOM[0][9] << " | " << DATOM[1][9] << " | " << DATOM[2][9] << "\n";
    cout<<"11- " << DATOM[0][10] << " | " << DATOM[1][10] << " | " << DATOM[2][10] << "\n";
    cout<<"12- " << DATOM[0][11] << " | " << DATOM[1][11] << " | " << DATOM[2][11] << "\n\n";

    cout<<"-Tanta 5-\n";
    cout<<"13- " << DATOM[0][12] << " | " << DATOM[1][12] << " | " << DATOM[2][12] << "\n";
    cout<<"14- " << DATOM[0][13] << " | " << DATOM[1][13] << " | " << DATOM[2][13] << "\n";
    cout<<"15- " << DATOM[0][14] << " | " << DATOM[1][14] << " | " << DATOM[2][14] << "\n\n";

    cout<<"-Tanta 6-\n";
    cout<<"16- " << DATOM[0][15] << " | " << DATOM[1][15] << " | " << DATOM[2][15] << "\n";
    cout<<"17- " << DATOM[0][16] << " | " << DATOM[1][16] << " | " << DATOM[2][16] << "\n";
    cout<<"18- " << DATOM[0][17] << " | " << DATOM[1][17] << " | " << DATOM[2][17] << "\n\n";

    cout<<"-Tanta 7-\n";
    cout<<"19- " << DATOM[0][18] << " | " << DATOM[1][18] << " | " << DATOM[2][18] << "\n";
    cout<<"20- " << DATOM[0][19] << " | " << DATOM[1][19] << " | " << DATOM[2][19] << "\n";
    cout<<"21- " << DATOM[0][20] << " | " << DATOM[1][20] << " | " << DATOM[2][20] << "\n\n";

    cout<<"-Tanta 8-\n";
    cout<<"22- " << DATOM[0][21] << " | " << DATOM[1][21] << " | " << DATOM[2][21] << "\n";
    cout<<"23- " << DATOM[0][22] << " | " << DATOM[1][22] << " | " << DATOM[2][22] << "\n";
    cout<<"24- " << DATOM[0][23] << " | " << DATOM[1][23] << " | " << DATOM[2][23] << "\n\n";

    cout<<"-Tanta 9-\n";
    cout<<"25- " << DATOM[0][24] << " | " << DATOM[1][24] << " | " << DATOM[2][24] << "\n";
    cout<<"26- " << DATOM[0][25] << " | " << DATOM[1][25] << " | " << DATOM[2][25] << "\n";
    cout<<"27- " << DATOM[0][26] << " | " << DATOM[1][26] << " | " << DATOM[2][26] << "\n\n";

    cout<<"-Tanta 10-\n";
    cout<<"28- " << DATOM[0][27] << " | " << DATOM[1][27] << " | " << DATOM[2][27] << "\n";
    cout<<"29- " << DATOM[0][28] << " | " << DATOM[1][28] << " | " << DATOM[2][28] << "\n";
    cout<<"30- " << DATOM[0][29] << " | " << DATOM[1][29] << " | " << DATOM[2][29] << "\n\n";

    cout<<"Ans: "<< Ans << "|| Base: " << B << endl;
    Autom = 2;
    NewValor = Answer(B,Fp,P,Rx,Ap,As,Rand,Autom,Op1,TotalAutom);
    Autom = 1;
    cout<<"Click= " << NewValor << "p ";
    
    if(NewValor > OldValor){
    cout<<"(+" << (NewValor-OldValor) << ")";
    OldValor = NewValor;
    }
    cout<<endl;
    
    
    }

    cin>>Select;

    switch(Select){
        case 0:
    Sleep(350);
    system("cls");
    Back = true;
    Cambio = true;
    break;

        case 1:
    if(Ans >= DATOM[1][0] && B < DATOM[0][0]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][0];//quitar puntaje
        B = B + DATOM[2][0]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 2:
    if(Ans >= DATOM[1][1] && B < DATOM[0][1]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][1];//quitar puntaje
        B = B + DATOM[2][1]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 3:
    if(Ans >= DATOM[1][2] && B < DATOM[0][2]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][2];//quitar puntaje
        B = B + DATOM[2][2]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 4:
    if(Ans >= DATOM[1][3] && B < DATOM[0][3]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][3];//quitar puntaje
        B = B + DATOM[2][3]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 5:
    if(Ans >= DATOM[1][4] && B < DATOM[0][4]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][4];//quitar puntaje
        B = B + DATOM[2][4]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;
    case 6:
    if(Ans >= DATOM[1][5] && B < DATOM[0][5]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][5];//quitar puntaje
        B = B + DATOM[2][5]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 7:
    if(Ans >= DATOM[1][6] && B < DATOM[0][6]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][6];//quitar puntaje
        B = B + DATOM[2][6]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 8:
    if(Ans >= DATOM[1][7] && B < DATOM[0][7]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][7];//quitar puntaje
        B = B + DATOM[2][7]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 9:
    if(Ans >= DATOM[1][8] && B < DATOM[0][8]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][8];//quitar puntaje
        B = B + DATOM[2][8]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 10:
    if(Ans >= DATOM[1][9] && B < DATOM[0][9]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][9];//quitar puntaje
        B = B + DATOM[2][9]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 11:
    if(Ans >= DATOM[1][10] && B < DATOM[0][10]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][10];//quitar puntaje
        B = B + DATOM[2][10]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 12:
    if(Ans >= DATOM[1][11] && B < DATOM[0][11]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][11];//quitar puntaje
        B = B + DATOM[2][11]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 13:
    if(Ans >= DATOM[1][12] && B < DATOM[0][12]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][12];//quitar puntaje
        B = B + DATOM[2][12]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 14:
    if(Ans >= DATOM[1][13] && B < DATOM[0][13]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][13];//quitar puntaje
        B = B + DATOM[2][13]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 15:
    if(Ans >= DATOM[1][14] && B < DATOM[0][14]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][14];//quitar puntaje
        B = B + DATOM[2][14]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 16:
    if(Ans >= DATOM[1][15] && B < DATOM[0][15]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][15];//quitar puntaje
        B = B + DATOM[2][15]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 17:
    if(Ans >= DATOM[1][16] && B < DATOM[0][16]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][16];//quitar puntaje
        B = B + DATOM[2][16]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 18:
    if(Ans >= DATOM[1][17] && B < DATOM[0][17]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][17];//quitar puntaje
        B = B + DATOM[2][17]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 19:
    if(Ans >= DATOM[1][18] && B < DATOM[0][18]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][18];//quitar puntaje
        B = B + DATOM[2][18]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 20:
    if(Ans >= DATOM[1][19] && B < DATOM[0][19]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][19];//quitar puntaje
        B = B + DATOM[2][19]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 21:
    if(Ans >= DATOM[1][20] && B < DATOM[0][20]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][20];//quitar puntaje
        B = B + DATOM[2][20]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 22:
    if(Ans >= DATOM[1][21] && B < DATOM[0][21]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][21];//quitar puntaje
        B = B + DATOM[2][21]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 23:
    if(Ans >= DATOM[1][22] && B < DATOM[0][22]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][22];//quitar puntaje
        B = B + DATOM[2][22]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 24:
    if(Ans >= DATOM[1][23] && B < DATOM[0][23]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][23];//quitar puntaje
        B = B + DATOM[2][23]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 25:
    if(Ans >= DATOM[1][24] && B < DATOM[0][24]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][24];//quitar puntaje
        B = B + DATOM[2][24]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 26:
    if(Ans >= DATOM[1][25] && B < DATOM[0][25]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][25];//quitar puntaje
        B = B + DATOM[2][25]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 27:
    if(Ans >= DATOM[1][26] && B < DATOM[0][26]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][26];//quitar puntaje
        B = B + DATOM[2][26]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 28:
    if(Ans >= DATOM[1][27] && B < DATOM[0][27]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][27];//quitar puntaje
        B = B + DATOM[2][27]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 29:
    if(Ans >= DATOM[1][28] && B < DATOM[0][28]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][28];//quitar puntaje
        B = B + DATOM[2][28]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 30:
    if(Ans >= DATOM[1][29] && B < DATOM[0][29]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[1][29];//quitar puntaje
        B = B + DATOM[2][29]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    }}

    case 3: //Mejora Eficiencia
    system("cls");
    Autom = 2;
    OldValor = Answer(B,Fp,P,Rx,Ap,As,Rand,Autom,Op1,TotalAutom);
    Autom = 1;    

    while(Back == false){

    if(w == 1){
    system("cls");
    w = 0;

    cout<<"-Mejora de Eficiencia- \n";
    cout<<"Escriba el Numero de la mejora que desee.\n [0 = Salir] - [10..30 = Seleccionar] \n\n";

    cout<<"-Tanta 4-\n";
    cout<<"Limite|Coste|Mejora \n";
    cout<<"10- " << DATOM[3][9] << " | " << DATOM[4][9] << " | " << DATOM[5][9] << "\n";
    cout<<"11- " << DATOM[3][10] << " | " << DATOM[4][10] << " | " << DATOM[5][10] << "\n";
    cout<<"12- " << DATOM[3][11] << " | " << DATOM[4][11] << " | " << DATOM[5][11] << "\n\n";

    cout<<"-Tanta 5-\n";
    cout<<"13- " << DATOM[3][12] << " | " << DATOM[4][12] << " | " << DATOM[5][12] << "\n";
    cout<<"14- " << DATOM[3][13] << " | " << DATOM[4][13] << " | " << DATOM[5][13] << "\n";
    cout<<"15- " << DATOM[3][14] << " | " << DATOM[4][14] << " | " << DATOM[5][14] << "\n\n";

    cout<<"-Tanta 6-\n";
    cout<<"16- " << DATOM[3][15] << " | " << DATOM[4][15] << " | " << DATOM[5][15] << "\n";
    cout<<"17- " << DATOM[3][16] << " | " << DATOM[4][16] << " | " << DATOM[5][16] << "\n";
    cout<<"18- " << DATOM[3][17] << " | " << DATOM[4][17] << " | " << DATOM[5][17] << "\n\n";

    cout<<"-Tanta 7-\n";
    cout<<"19- " << DATOM[3][18] << " | " << DATOM[4][18] << " | " << DATOM[5][18] << "\n";
    cout<<"20- " << DATOM[3][19] << " | " << DATOM[4][19] << " | " << DATOM[5][19] << "\n";
    cout<<"21- " << DATOM[3][20] << " | " << DATOM[4][20] << " | " << DATOM[5][20] << "\n\n";

    cout<<"-Tanta 8-\n";
    cout<<"22- " << DATOM[3][21] << " | " << DATOM[4][21] << " | " << DATOM[5][21] << "\n";
    cout<<"23- " << DATOM[3][22] << " | " << DATOM[4][22] << " | " << DATOM[5][22] << "\n";
    cout<<"24- " << DATOM[3][23] << " | " << DATOM[4][23] << " | " << DATOM[5][23] << "\n\n";

    cout<<"-Tanta 9-\n";
    cout<<"25- " << DATOM[3][24] << " | " << DATOM[4][24] << " | " << DATOM[5][24] << "\n";
    cout<<"26- " << DATOM[3][25] << " | " << DATOM[4][25] << " | " << DATOM[5][25] << "\n";
    cout<<"27- " << DATOM[3][26] << " | " << DATOM[4][26] << " | " << DATOM[5][26] << "\n\n";

    cout<<"-Tanta 10-\n";
    cout<<"28- " << DATOM[3][27] << " | " << DATOM[4][27] << " | " << DATOM[5][27] << "\n";
    cout<<"29- " << DATOM[3][28] << " | " << DATOM[4][28] << " | " << DATOM[5][28] << "\n";
    cout<<"30- " << DATOM[3][29] << " | " << DATOM[4][29] << " | " << DATOM[5][29] << "\n\n";

    cout<<"Ans: "<< Ans << "|| Eficiencia: " << Fp << endl;
    
    Autom = 2;
    NewValor = Answer(B,Fp,P,Rx,Ap,As,Rand,Autom,Op1,TotalAutom);
    Autom = 1;
    cout<<"Click= " << NewValor << "p ";
    
    if(NewValor > OldValor){
    cout<<"(+" << (NewValor-OldValor) << ")";
    OldValor = NewValor;
    }
    cout<<endl;
}

    cin>>Select;
    cin.ignore();

    switch(Select){
        case 0:
    Sleep(350);
    system("cls");
    Back = true;
    Cambio = true;
    break;

    case 10:
    if(Ans >= DATOM[4][9] && Fp < DATOM[3][9]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][9];//quitar puntaje
        Fp = Fp + DATOM[5][9]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 11:
    if(Ans >= DATOM[4][10] && Fp < DATOM[3][10]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][10];//quitar puntaje
        Fp = Fp + DATOM[5][10]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 12:
    if(Ans >= DATOM[4][11] && Fp < DATOM[3][11]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][11];//quitar puntaje
        Fp = Fp + DATOM[5][11]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 13:
    if(Ans >= DATOM[4][12] && Fp < DATOM[3][12]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][12];//quitar puntaje
        Fp = Fp + DATOM[5][12]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 14:
    if(Ans >= DATOM[4][13] && Fp < DATOM[3][13]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][13];//quitar puntaje
        Fp = Fp + DATOM[5][13]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 15:
    if(Ans >= DATOM[4][14] && Fp < DATOM[3][14]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][14];//quitar puntaje
        Fp = Fp + DATOM[5][14]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 16:
    if(Ans >= DATOM[4][15] && Fp < DATOM[3][15]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][15];//quitar puntaje
        Fp = Fp + DATOM[5][15]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 17:
    if(Ans >= DATOM[4][16] && Fp < DATOM[3][16]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][16];//quitar puntaje
        Fp = Fp + DATOM[5][16]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 18:
    if(Ans >= DATOM[4][17] && Fp < DATOM[3][17]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][17];//quitar puntaje
        Fp = Fp + DATOM[5][17]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 19:
    if(Ans >= DATOM[4][18] && Fp < DATOM[3][18]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][18];//quitar puntaje
        Fp = Fp + DATOM[5][18]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 20:
    if(Ans >= DATOM[4][19] && Fp < DATOM[3][19]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][19];//quitar puntaje
        Fp = Fp + DATOM[5][19]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 21:
    if(Ans >= DATOM[4][20] && Fp < DATOM[3][20]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][20];//quitar puntaje
        Fp = Fp + DATOM[5][20]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 22:
    if(Ans >= DATOM[4][21] && Fp < DATOM[3][21]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][21];//quitar puntaje
        Fp = Fp + DATOM[5][21]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 23:
    if(Ans >= DATOM[4][22] && Fp < DATOM[3][22]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][22];//quitar puntaje
        Fp = Fp + DATOM[5][22]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 24:
    if(Ans >= DATOM[4][23] && Fp < DATOM[3][23]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][23];//quitar puntaje
        Fp = Fp + DATOM[5][23]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 25:
    if(Ans >= DATOM[4][24] && Fp < DATOM[3][24]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][24];//quitar puntaje
        Fp = Fp + DATOM[5][24]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 26:
    if(Ans >= DATOM[4][25] && Fp < DATOM[3][25]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][25];//quitar puntaje
        Fp = Fp + DATOM[5][25]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 27:
    if(Ans >= DATOM[4][26] && Fp < DATOM[3][26]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][26];//quitar puntaje
        Fp = Fp + DATOM[5][26]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";

        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 28:
    if(Ans >= DATOM[4][27] && Fp < DATOM[3][27]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][27];//quitar puntaje
        Fp = Fp + DATOM[5][27]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 29:
    if(Ans >= DATOM[4][28] && Fp < DATOM[3][28]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][28];//quitar puntaje
        Fp = Fp + DATOM[5][28]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 30:
    if(Ans >= DATOM[4][29] && Fp < DATOM[3][29]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[4][29];//quitar puntaje
        Fp = Fp + DATOM[5][29]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    }}

    case 4: //Potencia
    system("cls");
    Autom = 2;
    OldValor = Answer(B,Fp,P,Rx,Ap,As,Rand,Autom,Op1,TotalAutom);
    Autom = 1;

    while(Back == false){

    if(w == 1){

    w = 0;
    system("cls");
    cout<<"-Mejora de Potencia- \n";
    cout<<"Escriba el Numero de la mejora que desee.\n [0 = Salir] - [19..31 = Seleccionar] \n\n";

    cout<<"-Tanta 7-\n";
    cout<<"Limite|Coste|Mejora \n";
    cout<<"19- " << DATOM[6][18] << " | " << DATOM[7][18] << " | " << DATOM[8][18] << "\n";
    cout<<"20- " << DATOM[6][19] << " | " << DATOM[7][19] << " | " << DATOM[8][19] << "\n";
    cout<<"21- " << DATOM[6][20] << " | " << DATOM[7][20] << " | " << DATOM[8][20] << "\n\n";

    cout<<"-Tanta 8-\n";
    cout<<"22- " << DATOM[6][21] << " | " << DATOM[7][21] << " | " << DATOM[8][21] << "\n";
    cout<<"23- " << DATOM[6][22] << " | " << DATOM[7][22] << " | " << DATOM[8][22] << "\n";
    cout<<"24- " << DATOM[6][23] << " | " << DATOM[7][23] << " | " << DATOM[8][23] << "\n\n";

    cout<<"-Tanta 9-\n";
    cout<<"25- " << DATOM[6][24] << " | " << DATOM[7][24] << " | " << DATOM[8][24] << "\n";
    cout<<"26- " << DATOM[6][25] << " | " << DATOM[7][25] << " | " << DATOM[8][25] << "\n";
    cout<<"27- " << DATOM[6][26] << " | " << DATOM[7][26] << " | " << DATOM[8][26] << "\n\n";

    cout<<"-Tanta 10-\n";
    cout<<"28- " << DATOM[6][27] << " | " << DATOM[7][27] << " | " << DATOM[8][27] << "\n";
    cout<<"29- " << DATOM[6][28] << " | " << DATOM[7][28] << " | " << DATOM[8][28] << "\n";
    cout<<"30- " << DATOM[6][29] << " | " << DATOM[7][29] << " | " << DATOM[8][29] << "\n\n";

    cout<<"Ans: "<< Ans << "|| Potencia: " << P << endl;
    
    Autom = 2;
    NewValor = Answer(B,Fp,P,Rx,Ap,As,Rand,Autom,Op1,TotalAutom);
    Autom = 1;
    cout<<"Click= " << NewValor << "p ";
    
    if(NewValor > OldValor){
    cout<<"(+" << (NewValor-OldValor) << ")";
    OldValor = NewValor;
    }
    cout<<endl;

}
    cin>>Select;
    cin.ignore();

    switch(Select){
        case 0:
    Sleep(350);
    system("cls");
    Back = true;
    Cambio = true;
    break;

    case 19:
    if(Ans >= DATOM[7][18] && P < DATOM[6][18]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[7][18];//quitar puntaje
        P = P + DATOM[8][18]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 20:
    if(Ans >= DATOM[7][19] && P < DATOM[6][19]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[7][19];//quitar puntaje
        P = P + DATOM[8][19]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 21:
    if(Ans >= DATOM[7][20] && P < DATOM[6][20]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[7][20];//quitar puntaje
        P = P + DATOM[8][20]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 22:
    if(Ans >= DATOM[7][21] && P < DATOM[6][21]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[7][21];//quitar puntaje
        P = P + DATOM[8][21]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 23:
    if(Ans >= DATOM[7][22] && P < DATOM[6][22]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[7][22];//quitar puntaje
        P = P + DATOM[8][22]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 24:
    if(Ans >= DATOM[7][23] && P < DATOM[6][23]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[7][23];//quitar puntaje
        P = P + DATOM[8][23]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 25:
    if(Ans >= DATOM[7][24] && P < DATOM[6][24]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[7][24];//quitar puntaje
        P = P + DATOM[8][24]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 26:
    if(Ans >= DATOM[7][25] && P < DATOM[6][25]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[7][25];//quitar puntaje
        P = P + DATOM[8][25]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 27:
    if(Ans >= DATOM[7][26] && P < DATOM[6][26]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[7][26];//quitar puntaje
        P = P + DATOM[8][26]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 28:
    if(Ans >= DATOM[7][27] && P < DATOM[6][27]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[7][27];//quitar puntaje
        P = P + DATOM[8][27]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 29:
    if(Ans >= DATOM[7][28] && P < DATOM[6][28]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[7][28];//quitar puntaje
        P = P + DATOM[8][28]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 30:
    if(Ans >= DATOM[7][29] && P < DATOM[6][29]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[7][29];//quitar puntaje
        P = P + DATOM[8][29]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    }}

    case 5: //Mejora ran#
    system("cls");
    Autom = 2;
    OldValor = Answer(B,Fp,P,Rx,Ap,As,Rand,Autom,Op1,TotalAutom);
    Autom = 1;

    while(Back == false){

    if(w == 1){
    system("cls");
    w = 0;

    cout<<"-Mejora de Ran#- \n";
    cout<<"Escriba el Numero de la mejora que desee.\n [0 = Salir] - [2..~..29 = Seleccionar] \n\n";

    cout<<"-Tanta 1-\n";
    cout<<"Limite|Coste|Mejora \n";
    cout<<"2- " << DATOM[9][1] << " | " << DATOM[10][1] << " | " << DATOM[11][1] << "\n\n";

    cout<<"-Tanta 2-\n";
    cout<<"5- " << DATOM[9][4] << " | " << DATOM[10][4] << " | " << DATOM[11][4] << "\n\n";

    cout<<"-Tanta 3-\n";
    cout<<"8- " << DATOM[9][7] << " | " << DATOM[10][7] << " | " << DATOM[11][7] << "\n\n";

    cout<<"-Tanta 4-\n";
    cout<<"11- " << DATOM[9][10] << " | " << DATOM[10][10] << " | " << DATOM[11][10] << "\n\n";

    cout<<"-Tanta 5-\n";
    cout<<"14- " << DATOM[9][13] << " | " << DATOM[10][13] << " | " << DATOM[11][13] << "\n\n";

    cout<<"-Tanta 6-\n";
    cout<<"17- " << DATOM[9][16] << " | " << DATOM[10][16] << " | " << DATOM[11][16] << "\n\n";

    cout<<"-Tanta 7-\n";
    cout<<"20- " << DATOM[9][19] << " | " << DATOM[10][19] << " | " << DATOM[11][19] << "\n\n";

    cout<<"-Tanta 8-\n";
    cout<<"23- " << DATOM[9][22] << " | " << DATOM[10][22] << " | " << DATOM[11][22] << "\n\n";

    cout<<"-Tanta 9-\n";
    cout<<"26- " << DATOM[9][25] << " | " << DATOM[10][25] << " | " << DATOM[11][25] << "\n\n";

    cout<<"-Tanta 10-\n";
    cout<<"29- " << DATOM[9][28] << " | " << DATOM[10][28] << " | " << DATOM[11][28] << "\n\n";

    cout<<"Ans: "<< Ans << "|| Ran#: " << Rx << endl;
    
    Autom = 2;
    NewValor = Answer(B,Fp,P,Rx,Ap,As,Rand,Autom,Op1,TotalAutom);
    Autom = 1;
    cout<<"Click= " << NewValor << "p ";
    
    if(NewValor > OldValor){
    cout<<"(+" << (NewValor-OldValor) << ")";
    OldValor = NewValor;
    }
    cout<<endl;

}

    cin>>Select;
    cin.ignore();

    switch(Select){
        case 0:
    Sleep(350);
    system("cls");
    Back = true;
    Cambio = true;
    break;

    case 2:
    if(Ans >= DATOM[10][1] && Rx < DATOM[9][1]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[10][1];//quitar puntaje
        Rx = Rx + DATOM[11][1]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 5:
    if(Ans >= DATOM[10][4] && Rx < DATOM[9][4]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[10][4];//quitar puntaje
        Rx = Rx + DATOM[11][4]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 8:
    if(Ans >= DATOM[10][7] && Rx < DATOM[9][7]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[10][7];//quitar puntaje
        Rx = Rx + DATOM[11][7]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 11:
    if(Ans >= DATOM[10][10] && Rx < DATOM[9][10]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[10][10];//quitar puntaje
        Rx = Rx + DATOM[11][10]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 14:
    if(Ans >= DATOM[10][13] && Rx < DATOM[9][13]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[10][13];//quitar puntaje
        Rx = Rx + DATOM[11][13]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 17:
    if(Ans >= DATOM[10][16] && Rx < DATOM[9][16]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[10][16];//quitar puntaje
        Rx = Rx + DATOM[11][16]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 20:
    if(Ans >= DATOM[10][19] && Rx < DATOM[9][19]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[10][19];//quitar puntaje
        Rx = Rx + DATOM[11][19]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 23:
    if(Ans >= DATOM[10][22] && Rx < DATOM[9][22]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[10][22];//quitar puntaje
        Rx = Rx + DATOM[11][22]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 26:
    if(Ans >= DATOM[10][25] && Rx < DATOM[9][25]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[10][25];//quitar puntaje
        Rx = Rx + DATOM[11][25]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 29:
    if(Ans >= DATOM[10][28] && Rx < DATOM[9][28]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[10][28];//quitar puntaje
        Rx = Rx + DATOM[11][28]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    }}

    case 6://Mejora m. Automatico
     system("cls");
    Autom = 3;
    OldValor = Answer(B,Fp,P,Rx,Ap,As,Rand,Autom,Op1,TotalAutom);
    Autom = 1;

    while(Back == false){

    if(w == 1){
    system("cls");
    w = 0;

    cout<<"-Mejora de Autom. - (de velocidad y eficiencia) \n";
    cout<<"Mil. = Velocidad del modo || x = Eficiencia del modo\n\n";
    cout<<"Escriba el Numero de la mejora que desee.\n [0 = Salir] - [1..~..29 = Seleccionar] \n\n";


    cout<<"-Tanta 1-\n";
    cout<<"Limite|Coste|Mejora \n";
    cout<<"1- " << DATOM[12][0] << "mil. | " << DATOM[13][0] << " | -" << DATOM[14][0] << "mil.\n";
    cout<<"2- " << DATOM[12][1] << "x | " << DATOM[13][1] << " | " << DATOM[14][1] << "x\n\n";

    cout<<"-Tanta 2-\n";
    cout<<"4- " << DATOM[12][3] << "mil. | " << DATOM[13][3] << " | -" << DATOM[14][3] << "mil.\n";
    cout<<"5- " << DATOM[12][4] << "x | " << DATOM[13][4] << " | " << DATOM[14][4] << "x\n\n";

    cout<<"-Tanta 3-\n";
    cout<<"7- " << DATOM[12][6] << "mil. | " << DATOM[13][6] << " | -" << DATOM[14][6] << "mil.\n";
    cout<<"8- " << DATOM[12][7] << "x | " << DATOM[13][7] << " | " << DATOM[14][7] << "x\n\n";

    cout<<"-Tanta 4-\n";
    cout<<"10- " << DATOM[12][9] << "mil. | " << DATOM[13][9] << " | -" << DATOM[14][9] << "mil.\n";
    cout<<"11- " << DATOM[12][10] << "x | " << DATOM[13][10] << " | " << DATOM[14][10] << "x\n\n";

    cout<<"-Tanta 5-\n";
    cout<<"13- " << DATOM[12][12] << "mil. | " << DATOM[13][12] << " | -" << DATOM[14][12] << "mil.\n";
    cout<<"14- " << DATOM[12][13] << "x | " << DATOM[13][13] << " | " << DATOM[14][13] << "x\n\n";

    cout<<"-Tanta 6-\n";
    cout<<"16- " << DATOM[12][15] << "mil. | " << DATOM[13][15] << " | -" << DATOM[14][15] << "mil.\n";
    cout<<"17- " << DATOM[12][16] << "x | " << DATOM[13][16] << " | " << DATOM[14][16] << "x\n\n";

    cout<<"-Tanta 7-\n";
    cout<<"19- " << DATOM[12][18] << "mil. | " << DATOM[13][18] << " | -" << DATOM[14][18] << "mil.\n";
    cout<<"20- " << DATOM[12][19] << "x | " << DATOM[13][19] << " | " << DATOM[14][19] << "x\n\n";

    cout<<"-Tanta 8-\n";
    cout<<"22- " << DATOM[12][21] << "mil. | " << DATOM[13][21] << " | -" << DATOM[14][21] << "mil.\n";
    cout<<"23- " << DATOM[12][22] << "x | " << DATOM[13][22] << " | " << DATOM[14][22] << "x\n\n";

    cout<<"-Tanta 9-\n";
    cout<<"25- " << DATOM[12][24] << "mil. | " << DATOM[13][24] << " | -" << DATOM[14][24] << "mil.\n";
    cout<<"26- " << DATOM[12][25] << "x | " << DATOM[13][25] << " | " << DATOM[14][25] << "x\n\n";

    cout<<"-Tanta 10-\n";
    cout<<"28- " << DATOM[12][27] << "mil. | " << DATOM[13][27] << " | -" << DATOM[14][27] << "mil.\n";
    cout<<"29- " << DATOM[12][28] << "x | " << DATOM[13][28] << " | " << DATOM[14][28] << "x\n\n";

    cout<<"Ans: "<< Ans << "|| Autom.Seg.: " << As << " || Autom.x: "  << Ap << endl;
    
    Autom = 3;
    NewValor = Answer(B,Fp,P,Rx,Ap,As,Rand,Autom,Op1,TotalAutom);
    Autom = 1;
    cout<<"Click= " << NewValor << "pHr~ ";
    
    if(NewValor > OldValor){
    cout<<"(+" << (NewValor-OldValor) << "pHr~)";
    OldValor = NewValor;
    }
    cout<<endl;

}

    cin>>Select;
    cin.ignore();

    switch(Select){
        case 0:
    Sleep(350);
    system("cls");
    Back = true;
    Cambio = true;
    break;

        case 1:
    if(Ans >= DATOM[13][0] && As > DATOM[12][0]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][0];//quitar puntaje
        As = As - DATOM[14][0]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 2:
    if(Ans >= DATOM[13][1] && Ap < DATOM[12][1]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][1];//quitar puntaje
        Ap = Ap + DATOM[14][1]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 4:
    if(Ans >= DATOM[13][3] && As > DATOM[12][3]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][3];//quitar puntaje
        As = As - DATOM[14][3]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 5:
    if(Ans >= DATOM[13][4] && Ap < DATOM[12][4]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][4];//quitar puntaje
        Ap = Ap + DATOM[14][4]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;
    case 7:
    if(Ans >= DATOM[13][6] && As > DATOM[12][6]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][6];//quitar puntaje
        As = As - DATOM[14][6]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 8:
    if(Ans >= DATOM[13][7] && Ap < DATOM[12][7]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][7];//quitar puntaje
        Ap = Ap + DATOM[14][7]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 10:
    if(Ans >= DATOM[13][9] && As > DATOM[12][9]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][9];//quitar puntaje
        As = As - DATOM[14][9]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 11:
    if(Ans >= DATOM[13][10] && Ap < DATOM[12][10]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][10];//quitar puntaje
        Ap = Ap + DATOM[14][10]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 13:
    if(Ans >= DATOM[13][12] && As > DATOM[12][12]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][12];//quitar puntaje
        As = As - DATOM[14][12]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 14:
    if(Ans >= DATOM[13][13] && Ap < DATOM[12][13]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][13];//quitar puntaje
        Ap = Ap + DATOM[14][13]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 16:
    if(Ans >= DATOM[13][15] && As > DATOM[12][15]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][15];//quitar puntaje
        As = As - DATOM[14][15]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 17:
    if(Ans >= DATOM[13][16] && Ap < DATOM[12][16]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][16];//quitar puntaje
        Ap = Ap + DATOM[14][16]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 19:
    if(Ans >= DATOM[13][18] && As > DATOM[12][18]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][18];//quitar puntaje
        As = As - DATOM[14][18]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 20:
    if(Ans >= DATOM[13][19] && Ap < DATOM[12][19]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][19];//quitar puntaje
        Ap = Ap + DATOM[14][19]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 22:
    if(Ans >= DATOM[13][21] && As > DATOM[12][21]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][21];//quitar puntaje
        As = As - DATOM[14][21]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 23:
    if(Ans >= DATOM[13][22] && Ap < DATOM[12][22]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][22];//quitar puntaje
        Ap = Ap + DATOM[14][22]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 25:
    if(Ans >= DATOM[13][24] && As > DATOM[12][24]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][24];//quitar puntaje
        As = As - DATOM[14][24]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 26:
    if(Ans >= DATOM[13][25] && Ap < DATOM[12][25]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][25];//quitar puntaje
        Ap = Ap + DATOM[14][25]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 28:
    if(Ans >= DATOM[13][27] && As > DATOM[12][27]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][27];//quitar puntaje
        As = As - DATOM[14][27]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    case 29:
    if(Ans >= DATOM[13][28] && Ap < DATOM[12][28]){ //Puntos necesarios y Limite
        Ans = Ans - DATOM[13][28];//quitar puntaje
        Ap = Ap + DATOM[14][28]; //Sumar mejora
        system("cls");
        cout<<"Mejora COMPLETADA!";
        Sleep(1000);
        w = 1;
    }
    else{
        system("cls");
        cout<<"No se cumplen las condiciones!";
        Sleep(1000);
        w = 1;
    }
    break;

    }}

    case 7: //opciones
    system("cls");
    Cambio = true;

    if(w == 1){
    w = 0;
    Pos = 1;
    }

    while(Back == false){
    if(GetAsyncKeyState(VK_UP)){
    Sleep(30);
    if(false == GetAsyncKeyState(VK_UP)){
    Cambio = true;
    Pos = Pos - 1;
    }}

    if(GetAsyncKeyState(VK_DOWN)){
    Sleep(30);
    if(false == GetAsyncKeyState(VK_DOWN)){
    Cambio = true;
    Pos = Pos + 1;
    }}


    if(Cambio == true){
    system("cls");
    cout<<"-Opciones- \n\n";

    switch(Pos){
    case 0: // caso 3
    system("cls");
    Pos = 2;
    break;

    case 1:
    cout<<"[Mostrar Tiempo de Autom.] || " << Op1 << "\n";
    cout<<"-Mostrar Valor del Click Actual- || " << Op2 << "\n";
    Cambio = false;
    break;

    case 2:
    cout<<"-Mostrar Tiempo de Autom.- || " << Op1 << "\n";
    cout<<"[Mostrar Valor del Click Actual] || " << Op2 << "\n";
    Cambio = false;
    break;

    case 3: //caso 1
    system("cls");
    Pos = 1;
    break;
    }
    }

    if(GetAsyncKeyState(VK_RIGHT)){ //Detecta enter
    Sleep(30);
    if(false == GetAsyncKeyState(VK_RIGHT)){

    switch(Pos){
case 1:
if(Op1 == false){
    Op1 = true;
    Cambio = true;
}
else{
    Op1 = false;
    Cambio = true;
}
    break;

    case 2:
    if(Op2 == false){
    Op2 = true;
    Cambio = true;
}
else{
    Op2 = false;
    Cambio = true;
}
    break;

    }

    }}


     if(GetAsyncKeyState(VK_LEFT)){
    Sleep(30);
    if(false == GetAsyncKeyState(VK_LEFT)){
    Back = true;
    Cambio = true;
    }}

    }
    break;

    case 8:
    system("cls");

    while(Back == false){

    if(w == 1){
       Cambio = true;
       w = 0;
    }

    if(GetAsyncKeyState(VK_UP)){
    Sleep(30);
    if(false == GetAsyncKeyState(VK_UP)){
    Autom = 0;
    Sure = 0;
    Cambio = true;
    }}

    if(GetAsyncKeyState(VK_DOWN)){
    Sleep(30);
    if(false == GetAsyncKeyState(VK_DOWN)){
    Autom = 1;
    Cambio = true;
    Sure = 0;
    }}


    if(Autom == 0 && Cambio == true){ // Seleccion de Guardar partida
    system("cls");
    cout<<"-Menu- \n\n -Clicker- \n -Mej. Base- \n -Mej. Eficiencia Base- \n -Mej. Potencia- \n -Mej. Ran#- \n -Mej. Automatico- \n\n -Opciones-  \n -Partida- [Guardar] || -Cargar-";
    if(Sure == 1){
        cout<<" Seguro?";
    }
    Cambio = false;
    }
    if(Autom == 1 && Cambio == true){ //Seleccion de Cargar partida
    system("cls");
    cout<<"-Menu- \n\n -Clicker- \n -Mej. Base- \n -Mej. Eficiencia Base- \n -Mej. Potencia- \n -Mej. Ran#- \n -Mej. Automatico- \n\n -Opciones-  \n -Partida- -Guardar- || [Cargar]";
    if(Sure == 1){
        cout<<" Seguro?";
    }
    Cambio = false;
    }


    if(GetAsyncKeyState(VK_LEFT)){ //Cambias al menu principal
    Sleep(30);
    if(false == GetAsyncKeyState(VK_LEFT)){
        Back = true;
        Cambio = true;
        Sure = 0;
        }}

        if(GetAsyncKeyState(VK_RIGHT)){
        Sleep(30);
        if(false == GetAsyncKeyState(VK_RIGHT)){
            Sure +=1;
            Cambio = true;
            if(Sure == 2){
                if(Autom == 0){ //Guardar partida

        if(B > 75500){B = 75500;}
        if(Fp > 1.5){Fp = 1.5;}
        if(P > 5){P = 5;}
        if(Rx > 1){Rx = 1;}
        if(As < 2000){As = 2000;}
        if(Ap > 1.5){Ap = 1.5;}
        if(EXplus > 8){EXplus = 8;}
        if(EXp > 1.25){EXp = 1.25;}

        exp1 = clock();
        exm1 = clock();


        exp = (double(exp1-exp0)/CLOCKS_PER_SEC)+Last_exp;
        exm = (double(exm1-exm0)/CLOCKS_PER_SEC)+Last_exm;

	if(exp > 180000){exp = 180000;}
	if(exm > 180000){exm = 180000;}

        GuardarPARTIDA(B, Fp, P,  Rx, Ap, As, Ans, EXplus, EXp, Last_exm, Last_exp, Niv_exm, Niv_exp, Op1, Op2, _ExpDinero, SignoExpDinero, exp, exm);

        Back = true;
        Cambio = true;
        }

            if(Autom == 1){ //Cargar Partida
        system("cls");
        cout<<"Pege el CODIGO1: ";
        cin>>CODIGO1;
        cin.ignore();
        cout<<"\nPege el CODIGO2: ";
        cin>>CODIGO2;
        cin.ignore();
        cout<<"\nPege el CODIGO3: ";
        cin>>CODIGO3;
        cin.ignore();
if("Cargar" == "Cargar"){
_Ran = CODIGO1;
_Ran %= 1000;
CODIGO1 = CODIGO1 / 1000;
Rx = _Ran;
Rx /= 100;

_Potencia = CODIGO1;
_Potencia %= 100;
CODIGO1 = CODIGO1 / 100;
P = _Potencia;
P /= 10;

_Eficiencia = CODIGO1;
_Eficiencia %= 100000;
CODIGO1 = CODIGO1 / 100000;
Fp = _Eficiencia;
Fp /= 10000;

_Base = CODIGO1;
_Base %= 100000000;
CODIGO1 = CODIGO1 / 100000000;
B = _Base;
B /= 1000;

SignoExpDinero = CODIGO2;
SignoExpDinero %= 10;
CODIGO2 = CODIGO2 / 10;

_EXm = CODIGO2;
_EXm %= 10;
CODIGO2 = CODIGO2 / 10;
EXplus = _EXm;
EXplus /= 1;

_Op = CODIGO2;
_Op %= 10;
CODIGO2 = CODIGO2 / 10;
if(_Op == 0){
Op1 = false;
Op2 = false;
}
if(_Op == 1){
Op1 = true;
Op2 = false;
}
if(_Op == 2){
Op1 = false;
Op2 = true;
}
if(_Op == 3){
Op1 = true;
Op2 = true;
}

_ExpDinero = CODIGO2;
_ExpDinero %= 100;
CODIGO2 = CODIGO2 / 100;
_ExpDineroD = _ExpDinero;
_ExpDineroD = pow(10,_ExpDineroD);


_Dinero = CODIGO2;
_Dinero %= 10000;
CODIGO2 = CODIGO2 / 10000;

Ans = _Dinero;
Ans /= 1000;
if(SignoExpDinero == 1){
Ans = Ans * _ExpDineroD;
}
else{
Ans = Ans / _ExpDineroD;
}

_AutoS = CODIGO2;
_AutoS %= 100000;
CODIGO2 = CODIGO2 / 100000;
As = _AutoS;
As /= 1;

_AutoM = CODIGO2;
_AutoM %= 1000;
CODIGO2 = CODIGO2 / 1000;
Ap = _AutoM;
Ap /= 100;

_EXpl = CODIGO3;
_EXpl %= 100;
CODIGO3 = CODIGO3 / 100;
Niv_exp = _EXpl;
Niv_exp /= 1;

_EXml = CODIGO3;
_EXml %= 10;
CODIGO3 = CODIGO3 / 10;
Niv_exm = _EXml;
Niv_exm /= 1;

_EXpt = CODIGO3;
_EXpt %= 1000000;
CODIGO3 = CODIGO3 / 1000000;
Last_exp = _EXpt;
Last_exp /= 1;

_EXmt = CODIGO3;
_EXmt %= 1000000;
CODIGO3 = CODIGO3 / 1000000;
Last_exm = _EXmt;
Last_exm /= 1;

_EXp = CODIGO3;
_EXp %= 10000;
CODIGO3 = CODIGO3 / 10000;
EXp = _EXp;
EXp /= 1000;

        Sleep(750);
        system("cls");
        cout<<"Partida Cargada!";
        Sleep(1500);

        Back = true;
        Cambio = true;
        }
        }
            Sure = 0;
            }
        }}
    }}
    }
    }
    }


    return 0;
}

double Answer(double B, double Fp, double P, double Rx, double Ap, double As, double Rand, int Autom, bool Op1, double TotalAutom)
{

double a = 0;
double b = 0;
double c = 0;
double d = 0;
double f = 0;

if (Autom == 0){//calculo TOTAL de Ans

if(GetAsyncKeyState(VK_LBUTTON)){
        Sleep(30);
if(false == GetAsyncKeyState(VK_LBUTTON)){
Sleep(10);

    a = B * Fp;
    b = pow(a, P);
    Rand = rand() % (0 - 40);
    Rand = Rand / 100;
    c = b * (Rx + Rand);

    return c;
}}
    return c;
}

    if (Autom == 1)
    {
          double Bucle = As / 100;


            a = B * Fp;
            b = pow(a, P);
            Rand = rand() % (0 - 40);
            Rand = Rand / 100;
            c = b * (Rx + Rand);
            d = c * Ap;

        for(Bucle ; Bucle > 0 ; Bucle--){//calculo TOTAL de Ans con automatico

        if(Op1 == true){
        cout<<"\n" << (Bucle / 10) << "Seg.";
        }

        Sleep(100);

        if(GetAsyncKeyState(VK_F12) && Autom == 1){ //Consultar Puntos obtenidos en modo automatico...
        Sleep(50);

        cout<<"\nAns Obtenido= " << TotalAutom;

        a = B * Fp;
        b = pow(a, P);
        c = b * (Rx + 0.2);
        f = c * Ap;
        cout<<"\nAns*Hr = " << (f*(3600000/As)) << " Aprox.~\n";

        Sleep(2500);
        }

            if(GetAsyncKeyState(VK_LEFT)){
        Bucle = 0;
        d = -1;
        }
        }
            return d;
        }

        if (Autom == 2){//Valor automatico
    a = B * Fp;
    b = pow(a, P);
    c = b * (Rx + 0.2);

    return c;
}

if (Autom == 3){//Valor automatico
    a = B * Fp;
        b = pow(a, P);
        c = b * (Rx + 0.2);
        f = c * Ap;
        f = f*(3600000/As);

        return f;
}

}

void GuardarPARTIDA(double B, double Fp, double P, double Rx, double Ap, double As, double Ans, double EXplus, double EXp, double Last_exm, double Last_exp, double Niv_exm, double Niv_exp, bool Op1, bool Op2, double _ExpDinero, double SignoExpDinero, double exp, double exm){
    ofstream Partida;

    Partida.open("PartidaGuardada.txt",ios::out); //Abrir archivo para guardar datos...

    if(Partida.fail()){
    cout<<"Eror: No se pudo Abrir el Archivo";

    }
    _ExpDinero = 0;

    Partida<<"CODIGO1: ";
    Partida<< setprecision(0) << fixed << B*1000;
    if(Fp*10000 < 100 ){Partida<<"0";}
    if(Fp*10000 < 1000){Partida<<"0";}
    if(Fp*10000 < 10000){Partida<<"0";}
    
Partida<< Fp*10000;
    Partida<<P*10;
    if(Rx*100 < 100){Partida<<"0";}
    Partida<<Rx*100<<endl;
///////////////////
    Partida<<"CODIGO2: ";
    Partida<<Ap*100;
    if(As < 10000){Partida<<"0";}
    Partida<<As;

    while(Ans < 1){
    Ans *= 10;
    _ExpDinero += 1;
    SignoExpDinero = 0;
    }
    while(Ans > 10){
    Ans /= 10;
    _ExpDinero += 1;
    SignoExpDinero = 1;
    }

    Partida<<Ans*1000;
    if(_ExpDinero < 1){Partida<<"0";}
    if(_ExpDinero < 10){Partida<<"0";}
    Partida<<_ExpDinero;

    if(Op1 == false && Op2 == false){Partida<<"0";}
    if(Op1 == true && Op2 == false){Partida<<"1";}
    if(Op1 == false && Op2 == true){Partida<<"2";}
    if(Op1 == true && Op2 == true){Partida<<"3";}

    Partida<<EXplus;

    Partida<<SignoExpDinero<<endl;


    Partida<<"CODIGO3: ";
    if(EXp*1000 < 1000){Partida<<"0";}
    Partida<<EXp*1000;

    if(exm < 10){Partida<<"0";}
    if(exm < 100){Partida<<"0";}
    if(exm < 1000){Partida<<"0";}
    if(exm < 10000){Partida<<"0";}
    if(exm < 100000){Partida<<"0";}
    Partida<<exm;

    if(exp < 10){Partida<<"0";}
    if(exp < 100){Partida<<"0";}
    if(exp < 1000){Partida<<"0";}
    if(exp < 10000){Partida<<"0";}
    if(exp < 100000){Partida<<"0";}
    Partida<<exp;

    Partida<<Niv_exm;

    if(Niv_exp < 10){Partida<<"0";}
    Partida<<Niv_exp;

    Partida.close(); // Cerrar el archivo

    system("cls");
    cout<<"Partida Guardada!";
    Sleep(1500);
    }
