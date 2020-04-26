#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include "jeu.h"
#include "jeton.h"
#include "plateau.h"


using namespace std;

jeu::jeu(){

}
/*
jeu::largeur(){

}
jeu::hauteur() {

}*/

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
/*
void jeu::initialiserJeu(int i, int j, int const hauteur = 6, int const largeur = 7) {

    for (i = 0; i < largeur; i++) {
        for (j = 0; j < hauteur; j++) {
            tab[j][i] = ' ';
        }
    }
}*/


void jeu::afficherJeu(char tab[7][6], int j)
{
    
    system("cls");
    cout << endl << endl << endl;
    
    for (int hauteur = 6; hauteur >= 0; hauteur--)
    {
        cout << "          | ";
        for (int largeur = 0; largeur < 7; largeur++)
        {
            if (tab[j][i] != 0 && tab[j][i] != 1)
                cout << "  ";

            if (tab[j][i] == 0)
                cout << "X ";

            if (tab[j][i] == 1)
                cout << "O ";

            //cout << " ";
        }
        cout << "|" << endl << "          |---------------|" << endl;
    }
    cout << "          | 1 2 3 4 5 6 7 |" << endl;
    cout << "           ______________" << endl << endl;

    /*
    for (int hauteur = 6; hauteur >= 0; hauteur--)
    {
        cout << "          | ";
        for (int largeur = 0; largeur < 7; largeur++)
        {
            if (tab[largeur][hauteur] != 0 && tab[largeur][hauteur] != 1)
                cout << "  ";

            if (tab[largeur][hauteur] == 0)
                cout << "X";

            if (tab[largeur][hauteur] == 1)
                cout << "O";

            //cout << " ";
        }
        cout << endl << "          |---------------|" << endl;
    }
    cout << "          | 1 2 3 4 5 6 7 |" << endl;
    cout << "           _______________" << endl << endl;*/
}


void jeu::partie(){
    string tabJoueur[2];
    int g = -1, cases = 0;
    int l = ligne;
    int i;
    int j;
    char tab[7][6];
    bool place = false;//pas de gagnant pour l'instant
    system("cls");

    cout << "Voulez vous bien jouer au mode deux joueurs ? oui (0) ou non (1)" << endl;


    cout << "Quel est le nom du premier joueur ?" << endl;
    cin >> tabJoueur[0];
    cout << endl << endl << "Quel est le nom du second joueur ?" << endl;
    cin >> tabJoueur[1];
    system("cls");

    srand(time(NULL));
    //j = 0;
    j = rand() % 2;

    if (j == 0)
        cout << "C'est " << tabJoueur[0] << " qui debute" << endl;
    else
    {
        cout << "C'est " << tabJoueur[1] << " qui debute" << endl;

    }

    system("pause");

    
   
    while (g == -1) {


        afficherJeu(tab, j);

        if (j == 0) {
            cout << endl << "C'est ton tour " << tabJoueur[0] << " ! " << endl << "Dans quel colonne veux-tu placer ton jeton?(1 a 7)" << endl << "Tes jetons sont les ";
            if (j == 0) {
                cout << " X" << endl;
            }
            else {
                cout << " O" << endl;
            }
        }else if (j == 1) {
            cout << endl << "C'est ton tour " << tabJoueur[1] << " ! " << endl << "Dans quel colonne veux-tu placer ton jeton?(1 a 7)" << endl << "Tes jetons sont les ";
            if (j == 0) {
                cout << " X" << endl;
            }
            else {
                cout << " O" << endl;
            }
        }
        cin >> c;

        

            do {              

               /* while (place != true) {
                    if (i == -1 || choix < 0 || choix > 6) {
                        cout << "entrez un autre numero\n";
                        cin >> choix;
                        i = ligne;
                    }
                    if (tab[choix][i] != ' ')
                        i--;
                    else {
                        tab[choix][i] = c;
                        place = true;
                    }
                }*/

                if (nombreJetons[c] > 5)
                {
                    cout << "Pas la place" << endl;
                }
            } while (nombreJetons[c] > 5);
        
        
        cout << " J = a : " << j << endl;
        cout << "cases : " << cases;
        
        if (c > 7) {
            cout << endl << "Veuillez choisir un colone valide" << endl;
            cin >> c;
        }
        else {
            cout << endl << "Je place mon jeton dans la colonne " << c << endl;

            system("pause");

            if (j == 1) {
                j--;
            }
            else {
                j++;
            }
            cases++;
        }
    }
    
}



    /*
    while (nombreJetons[c] > 5) {
        do {

            cin >> c;
            if (nombreJetons[c] > 6) {
                cout << "La colone est pleine" << endl;
            }
        }*/
    



    /*while (c > 0 || c <= 7 && nombreJetons > 0) {
        cout << "vous pouvez jouer ici" << endl;

    }*/
    

    /*
void jeu::deroulement(int colone) {
   
    int colone;
    
    cout << "Je place mon jeton dans la colonne " << colone << endl;
    cin >> colone;
    while (colone > 0 && colone <= 7) {
        cout << "vous pouvez jouer ici" << endl;
    }
    
}*/