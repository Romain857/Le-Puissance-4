#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include <Windows.h>
#include "jeu.h"
#include "plateau.h"


using namespace std;

int main() {


	cout << "\nBienvenue dans le Jeu Puissance 4" << endl;

	jeu* jeux = new jeu;
	jeux->afficherMenu();
	jeux->partie();

	plateau* Plateau = new plateau;

	Plateau->afficherJeu();

	}
