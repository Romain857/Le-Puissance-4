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

/*void jeu::initialiserJeu(int i, int j, int hauteur, int largeur, int tab[7][6]) {

    for (i = 0; i < largeur; i++) {
        for (j = 0; j < hauteur; j++) {
            tab[j][i] = ' ';
        }
    }
}*/


/*
bool jeu::gagne(char c, char tab[7][6], int largeur, int hauteur, int i, int j) {

        for (int i = 0; i < largeur; i++) {
            for (int j = 0; j < hauteur; j++) {
                if (i < 3) {
                    if (tab[j][i] == c && tab[j][i + 1] == c
                        && tab[j][i + 2] == c && tab[j][i + 3] == c)
                        return true;
                }
                if (j < 4) {
                    if (tab[j][i] == c && tab[j + 1][i] == c
                        && tab[j + 2][i] == c && tab[j + 3][i] == c)
                        return true;
                }
                if (j < 4 && i < 3) {
                    if (tab[j][i] == c && tab[j + 1][i + 1] == c
                        && tab[j + 2][i + 2] == c && tab[j + 3][i + 3] == c)
                        return true;
                }
                if (j < 4 && i > 2) {
                    if (tab[j][i] == c && tab[j + 1][i - 1] == c
                        && tab[j + 2][i - 2] == c && tab[j + 3][i - 3] == c)
                        return true;
                }
            }
        }
    }*/



void jeu::afficherJeu(int tab[7][6], int hauteur, int largeur)
{

    system("cls");


    
    cout << endl << endl << endl;
    
    for (hauteur = 5; hauteur >= 0; hauteur--)
    {
        cout << "          | ";
        for ( largeur = 0; largeur <= 6; largeur++)
        {
            if (tab[largeur][hauteur] != 0 && tab[largeur][hauteur] != 1)
                cout << "  ";

            if (tab[largeur][hauteur] == 0)
                cout << "X ";

            if (tab[largeur][hauteur] == 1)
                cout << "O ";

            //cout << " ";
        }
        cout << "|" << endl << "          |---------------|" << endl;
    }
    cout << "          | 1 2 3 4 5 6 7 |" << endl;
    cout << "           ______________" << endl << endl;

}


void jeu::partie() {
    string tabJoueur[2];
    int g = -1, cases = 0;
    int l = largeur;
    int i;
    int j;
    int tab[7][6];
    bool place = false;     //pas de gagnant pour l'instant

    system("cls");

    //cout << "Voulez vous bien jouer au mode deux joueurs ? oui (0) ou non (1)" << endl;

    //assigne un nom aux deux joueurs dans le tableau
    cout << "Quel est le nom du premier joueur ?" << endl;
    cin >> tabJoueur[0];
    cout << endl << endl << "Quel est le nom du second joueur ?" << endl;
    cin >> tabJoueur[1];
    system("cls");

    srand(time(NULL));
    //j = 0;
    j = rand() % 2;
    // random joueur qui débute
    if (j == 0)
        cout << "C'est " << tabJoueur[0] << " qui debute" << endl;
    else
    {
        cout << "C'est " << tabJoueur[1] << " qui debute" << endl;

    }

    system("pause");



    while (g == -1) {

        afficherJeu(tab, largeur, hauteur);
        //assigne un jeton au joueur dans le tour

        choixJeton(c, tab, j, tabJoueur, g);


        //cout << " J = a : " << j << endl;
         //cout << "cases : " << cases << endl;

         /*if (c > 7) {
             cout << endl << "Veuillez choisir un colone valide" << endl;
             cin >> c;
         }
         else {
             cout << endl << "Je place mon jeton dans la colonne " << c << endl;*/

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


void jeu::choixJeton(int choix , int tab[7][6], int j, string tabJoueur[2], int g){

    retourne:

    if (j == 0) {
            cout << endl << "C'est ton tour " << tabJoueur[0] << " ! " << endl << "Dans quel colonne veux-tu placer ton jeton?(1 a 7)" << endl << "Tes jetons sont les ";
            if (j == 0) {
                cout << " X" << endl;
            }

        }else if (j == 1) {
            cout << endl << "C'est ton tour " << tabJoueur[1] << " ! " << endl << "Dans quel colonne veux-tu placer ton jeton?(1 a 7)" << endl << "Tes jetons sont les ";
            if (j == 1) {
                cout << " O" << endl;
            }
      
        }

        cin >> choix;

    int hauteur = 0;
    if (j == 1){
        
        while(tab[choix-1][hauteur] == 1 || tab[choix-1][hauteur] == 0){
            hauteur ++;
            if(hauteur == 6){
                cout <<" tu ne peux pas"<< endl;
                goto retourne;
			}

		}
            tab[choix-1][hauteur] = 1;
            checkVictoire(choix -1, hauteur, tab, j, g, tabJoueur);

    }

	else{
     while(tab[choix-1][hauteur] == 1 || tab[choix-1][hauteur] == 0){
            hauteur ++;
            if(hauteur == 6){
                cout <<" tu ne peux pas"<< endl;
                goto retourne;
                }
		}
         tab[choix-1][hauteur] = 0;
         checkVictoire(choix -1, hauteur, tab, j, g, tabJoueur);
    }
	
   


}

void jeu::checkVictoire(int choix, int hauteur, int tab[7][6], int j, int g, string tabJoueur[2])
{
    int verifLarge = 1 ;
    int verifHauteur = 1;
    
    if (j == 1){   

    /*int test = tab[verifLarge][verifHauteur];
    int test2 = tab[choix][hauteur];
    cout << "le test 1 "<< test<< " le test 2 "<< test2 << endl;*/

        while(tab[choix+verifLarge][hauteur] == 1){
            verifLarge ++;
            cout<< verifLarge<< endl;                                                                //horizontal O
            if(verifLarge == 4 ){
                cout << "ca marche YOUPI"; 
                g = 1; 
                victoire(tabJoueur, g);
		    }
	    }
            while(tab[choix-verifLarge][hauteur] == 1){
            verifLarge ++;
            cout<< verifLarge<< endl;
            if(verifLarge == 4 ){
                cout << "ca marche YOUPI";  
                g = 1;
                victoire(tabJoueur, g);
		    }

	    }
            while(tab[choix][hauteur-verifHauteur] == 1){                                              //Vertical O

            verifHauteur ++;
            cout<< verifLarge<< endl;
            if(verifHauteur == 4 ){
                cout << "ca marche YOUPI";  
                g = 1;
                victoire(tabJoueur, g);
		    }
	    }
            while(tab[choix+verifLarge][hauteur+verifHauteur] == 1){                                    //Diagonales O

            verifHauteur ++;
            verifLarge ++;
            cout<< verifLarge<< endl;
            if(verifHauteur == 4 && verifLarge == 4){
                cout << "ca marche YOUPI";  
                g = 1;
                victoire(tabJoueur, g);
		    }
	    }
            while(tab[choix-verifLarge][hauteur+verifHauteur] == 1){

            verifHauteur ++;
            verifLarge ++;
            cout<< verifLarge<< endl;
            if(verifHauteur == 4 && verifLarge ==4){
                cout << "ca marche YOUPI"; 
                 g = 1;
                 victoire(tabJoueur, g);
		    }
	    }
            while(tab[choix+verifLarge][hauteur-verifHauteur] == 1){

            verifHauteur ++;
            verifLarge ++;
            cout<< verifLarge<< endl;
            if(verifHauteur == 4 && verifLarge ==4){
                cout << "ca marche YOUPI";  
                g = 1;
                victoire(tabJoueur, g);
		    }
	    }
            while(tab[choix-verifLarge][hauteur-verifHauteur] == 1){

            verifHauteur ++;
            verifLarge ++;
            cout<< verifLarge<< endl;
            if(verifHauteur == 4 && verifLarge ==4){
                cout << "ca marche YOUPI";  
                g = 1;
                victoire(tabJoueur, g);
		    }
	    }

   }
   if(j == 0){

       while(tab[choix+verifLarge][hauteur] == 0){

        verifLarge ++;
        cout<< verifLarge<< endl;                                                                //Horizontal X
        if(verifLarge == 4 ){
            cout << "ca marche YOUPI";  
            g = 0;
            victoire(tabJoueur, g);
		}

	}
        while(tab[choix-verifLarge][hauteur] == 0){

        verifLarge ++;
        cout<< verifLarge<< endl;
        if(verifLarge == 4 ){
            cout << "ca marche YOUPI";  
            g = 0;
            victoire(tabJoueur, g);
		}

	}
        while(tab[choix][hauteur-verifHauteur] == 0){                                            // Vertical X

        verifHauteur ++;
        cout<< verifLarge<< endl;
        if(verifHauteur == 4 ){
            cout << "ca marche YOUPI";  
            g = 0;
            victoire(tabJoueur, g);
		}
	}
        while(tab[choix+verifLarge][hauteur+verifHauteur] == 0){                                  //Diagonales X

        verifHauteur ++;
        verifLarge ++;
        cout<< verifLarge<< endl;
        if(verifHauteur == 4 && verifLarge ==4){
            cout << "ca marche YOUPI";  
            g = 0;
            victoire(tabJoueur, g);
		}
	}
        while(tab[choix-verifLarge][hauteur+verifHauteur] == 0){

        verifHauteur ++;
        verifLarge ++;
        cout<< verifLarge<< endl;
        if(verifHauteur == 4 && verifLarge ==4){
            cout << "ca marche YOUPI";  
            g = 0;
            victoire(tabJoueur, g);
		}
	}
        while(tab[choix+verifLarge][hauteur-verifHauteur] == 0){

        verifHauteur ++;
        verifLarge ++;
        cout<< verifLarge<< endl;
        if(verifHauteur == 4 && verifLarge ==4){
            cout << "ca marche YOUPI";  
            g = 0;
            victoire(tabJoueur, g);
		}
	}
        while(tab[choix-verifLarge][hauteur-verifHauteur] == 0){

        verifHauteur ++;
        verifLarge ++;
        cout<< verifLarge<< endl;
        if(verifHauteur == 4 && verifLarge ==4){
            cout << "ca marche YOUPI";  
            g = 0;
            victoire(tabJoueur, g);
		}
	}

   }

   
}

void jeu::victoire(string tabJoueur[2], int g) {

    switch (g)
    {

    case 0: cout << endl << "Bravo ! Tu as gagne " << tabJoueur[0] << endl;
        exit(EXIT_FAILURE);
        break;

    case 1: cout << endl << "Bravo ! Tu as gagne " << tabJoueur[1] << endl;
        exit(EXIT_FAILURE);
        break;
    }
    system("pause");
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