#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include "jeu.h"
#include "jeton.h"


using namespace std;

jeu::jeu() {

}


void jeu::afficherMenu() {

    int choix;
    bool gameOn = true;
    while (gameOn != false) {


        cout << endl << " 1 - Commencer une nouvelle partie" << endl;
        cout << " 2 - Regles " << endl;
        cout << " 3 - A propos " << endl;
        cout << " 4 - Quittez ce magnifique jeu" << endl;
        cout << endl << "Choisissez une option valide : ";

        cin >> choix;

        switch (choix)
        {
        case 1:
            cout << "La partie va bientot commencer " << endl;
            gameOn = false;
            system("pause");
            system("cls");
            break;
        case 2:
            cout << endl << "Le but du jeu, il faut aligner quatre jetons de la même couleur plus rapidement que ton adversaire" << endl;
            cout << "Il faut aligner 4 fois son chiffre soit en horizontal, en vertical ou en diagonale" << endl;
            cout << "Vous jouez en 1 VS 1" << endl << endl;
            cout << "La partie va commencer" << endl;
            cout << endl << "Que le meilleur gagne" << endl;
            break;
        case 3:
            cout << endl << "Fait par Romain Martineau" << endl;

            break;
        case 4:
            cout << "Fin du jeu";
            exit(EXIT_FAILURE);
            break;
        default:
            cout << "Veuillez choisir une option valide";
            cout << "Recomencez s'il vous plait";
            cin >> choix;
            break;
        }

    }
}

void jeu::partie()
{
    string tabJoueur[2];
    
    int j;
    system("cls");

    cout << "Voulez vous bien jouer au mode deux joueurs ? oui (0) ou non (1)" << endl;
    cin >> j;
    
        cout << "Quel est le nom du premier joueur ?" << endl;
        cin >> tabJoueur[0];
        cout << endl << endl << "Quel est le nom du second joueur ?" << endl;
        cin >> tabJoueur[1];
        system("cls");

    srand(time(NULL));

    j = rand() % 2;
    
    if (j == 0)
        cout << "C'est " << tabJoueur[0] << " qui debute" << endl;
    else
    {
        cout << "C'est " << tabJoueur[1] << " qui debute" << endl;

    }

    system("pause");

    if (j == 0)
    {
        cout << endl << "C'est ton tour " << tabJoueur[j] << " ! " << endl << "Dans quel colonne veux-tu placer ton jeton?(1 a 7)" << endl << "Tes jetons sont les ";
        if (j == 0)
            cout << " X" << endl;
        else
            cout << " O" << endl;
    }


}

void jeu::deroulement() {

    cout << "Je place mon jeton dans la colonne " << std::endl;
    
}