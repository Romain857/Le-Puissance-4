#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <Windows.h>
#include "jeu.h"
#include "plateau.h"


using namespace std;

int main() {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout << endl << "      ************************************************************************ " << endl;
    cout << "                                                                               " << endl;
    cout << "       zzzzzzz  zz   zz  zz   zzzzzz  zzzzzz  zzzzzzz  zzz  zz  zzzzzz  zzzzzz " << endl;
    cout << "       zz   zz  zz   zz       z       z       zz   zz  zz z zz  zz      zz     " << endl;
    cout << "       zzzzzzz  zz   zz  zz   zzzzzz  zzzzzz  zzzzzzz  zz z zz  zz      zzzz   " << endl;
    cout << "       zz       zz   zz  zz        z       z  zz   zz  zz z zz  zz      zz     " << endl;
    cout << "       zz       zzzzzzz  zz   zzzzzz  zzzzzz  zz   zz  zz  zzz  zzzzzz  zzzzzz " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "                                                                               " << endl;
    cout << "                                      zz   zz                                  " << endl;
    cout << "                                      zz   zz                                  " << endl;
    cout << "                                      zzzzzzz                                  " << endl;
    cout << "                                           zz                                  " << endl;
    cout << "                                           zz                                  " << endl;
    cout << "                                                                               " << endl;
    cout << "      ************************************************************************ " << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    jeu* jeux = new jeu;

    jeux->afficherMenu();

    jeux->partie();
   
    return 0;
}
