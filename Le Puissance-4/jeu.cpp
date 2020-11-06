#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include "jeu.h"
#include "plateau.h"


using namespace std;

jeu::jeu(){

}

void jeu::afficherMenu() {                                                                          //menu du jeu
    
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
                cout << endl << "Le but du jeu, il faut aligner quatre jetons de la meme couleur plus rapidement que ton adversaire" << endl;
                cout << "Il faut aligner 4 fois son chiffre soit en horizontal, en vertical ou en diagonale" << endl;
                cout << "Vous jouez en 1 VS 1" << endl << endl;
                cout << "La partie va commencer" << endl;
                cout << endl << "Que le meilleur gagne" << endl;
                break;
            case 3:
                cout << endl << "Fait par Romain Martineau dans le cadre de notre module C++" << endl;

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
            tab[largeur][hauteur] = ' ';
        }
    }
}*/

void jeu::afficherJeu(int tab[7][6], int hauteur, int largeur, int tours)
{
                                                                                                //plateau de 7 colone sur 6 lignes
    system("cls");


    
    cout << endl << endl << endl;
    cout << "       ------ Jetons : " << tours << " ------" << endl << endl;
    cout << "          #  Puissance 4  #       " << endl << endl;
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

        }
        cout << "|" << endl << "          |---------------|" << endl;
    }
    cout << "          | 1 2 3 4 5 6 7 |" << endl;
    cout << "           ______________" << endl << endl;

}


void jeu::partie() {
    string tabJoueur[2];
    int g = -1, tours = 0;
    int i;
    int j;
    int tab[7][6];

    system("cls");

                                                                                                         //assigne un nom aux deux joueurs dans le tableau
    cout << "Quel est le nom du premier joueur ?" << endl;
    cin >> tabJoueur[0];
    cout << endl << endl << "Quel est le nom du second joueur ?" << endl;
    cin >> tabJoueur[1];
    system("cls");

    cout << endl << "La partie opposera le joueur " << tabJoueur[0] << " au joueur " << tabJoueur[1] << endl;
    cout << endl << "Que le meilleur gagne !" << endl;

    srand(time(NULL));
    
    j = rand() % 2;
                                                                                                            // random joueur qui débute la partie
    if (j == 0)
        cout << endl << "C'est " << tabJoueur[0] << " qui sera le premier a jouer" << endl << endl;
    else
    {
        cout << endl << "C'est " << tabJoueur[1] << " qui sera le premier a jouer" << endl << endl;

    }

    system("pause");

    while (g == -1) {                                                                  //tant que g (gagnant) n'est pas égal à 0 ou 1 en fonction du joueur qui gagne

        afficherJeu(tab, largeur, hauteur, tours);
                                            
        choixJeton(c, tab, j, tabJoueur, g);


        //cout << " J = a : " << j << endl;
        //cout << "cases : " << cases << endl;

         //system("pause");

        if (j == 1) {                                                                                           //boucle de joueurs
            j--;
        }                                                                                                       
        else {
            j++;
        }
        tours++;
        
        if (tours == 42) {                                                                                      //Easter Eggs pour que les deux joueurs gagnent ensemble

            cout << endl << endl << "            # Easter Eggs #" << endl;

            cout << endl << tabJoueur[0] << " et " << tabJoueur[1] << " ont tout les deux gagnes !" << endl << endl;

            system("pause");

                                            
        }

        if (g == 0 || g == 1) {
            
            break;

        }
    }

}


void jeu::choixJeton(int choix , int tab[7][6], int j, string tabJoueur[2], int g){
                                                                                                             //assigne un jeton au joueur dans le tour

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

    retourne:
                                                                                                                //place son jeton dans le tableau
        cout << endl << "Je place mon jeton dans la colone : ";                                                             
        cin >> choix;
                                                                                                                 //colone existante requise
        if (choix < 1 || choix > 7) {
            cout << endl << "La colone saisie n'est pas correcte" << endl << "Choisi une autre colone valide" << endl;
            goto retourne;
        }

    int hauteur = 0;                                                                                    
    if (j == 1){
        
        while(tab[choix-1][hauteur] == 1 || tab[choix-1][hauteur] == 0){                                                        //si plus de palces dans la colone
            hauteur ++;
            if(hauteur == 6){
                cout << endl << "Plus de place dans cette colone" << endl << "Choisi une autre colone valide" << endl;
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
                cout << endl << "Plus de place dans cette colone" << endl << "Choisi une autre colone valide" << endl;
                goto retourne;
                }
		}

         tab[choix-1][hauteur] = 0;
         checkVictoire(choix -1, hauteur, tab, j, g, tabJoueur);
    }
	

}
    

                                                                                                        //On check largeur et hauteur jusqu'au puissance 4 
void jeu::checkVictoire(int choix, int hauteur, int tab[7][6], int j, int g, string tabJoueur[2])
{
    int verifLarge = 1 ;
    int verifHauteur = 1;
    
    if (j == 1){   

        verifHauteur = 1;
        verifLarge = 1;
        while(tab[choix+verifLarge][hauteur] == 1){
            verifLarge ++;
                                                                                                    //horizontal O
            if(verifLarge == 4 ){
                g = 1; 
                victoire(tabJoueur, g);
		    }
	    }
        verifHauteur = 1;
        verifLarge = 1;
            while(tab[choix-verifLarge][hauteur] == 1){
            verifLarge ++;

            if(verifLarge == 4 ){  
                g = 1;

                victoire(tabJoueur, g);
		    }

	    }  
            verifHauteur = 1;
            verifLarge = 1;
            while(tab[choix][hauteur-verifHauteur] == 1){                                              //Vertical O

            verifHauteur ++;
            
            if(verifHauteur == 4 ){ 
                g = 1;
                victoire(tabJoueur, g);
		    }
	    }
            verifHauteur = 1;
            verifLarge = 1;
            while(tab[choix+verifLarge][hauteur+verifHauteur] == 1){                                    //Diagonales O

            verifHauteur ++;
            verifLarge ++;
            
            if(verifHauteur == 4 && verifLarge == 4){
                                                                                                  //marche descend de droite
                g = 1;
                victoire(tabJoueur, g);
		    }
	    }
            verifHauteur = 1;
            verifLarge = 1;
            while(tab[choix-verifLarge][hauteur+verifHauteur] == 1){

            verifHauteur ++;
            verifLarge ++;
            
            if(verifHauteur == 4 && verifLarge ==4){                                              //marche descend de gauche
                
                 g = 1;
                 victoire(tabJoueur, g);
		    }
	    }
            verifHauteur = 1;
            verifLarge = 1;
            while(tab[choix+verifLarge][hauteur-verifHauteur] == 1){

            verifHauteur ++;
            verifLarge ++;
            
            if(verifHauteur == 4 && verifLarge ==4){                                                     //marche monte de droite
                  
                g = 1;
                victoire(tabJoueur, g);
		    }
	    }
            verifHauteur = 1;
            verifLarge = 1;
            while(tab[choix-verifLarge][hauteur-verifHauteur] == 1){

            verifHauteur ++;                                                                            //marche monte de gauche
            verifLarge ++;
            
            if(verifHauteur == 4 && verifLarge ==4){
                
                g = 1;
                victoire(tabJoueur, g);
		    }
	    }

    }
   
        if(j == 0){
           verifHauteur = 1;
           verifLarge = 1;
           while(tab[choix+verifLarge][hauteur] == 0){

            verifLarge ++;
                                                                                                    //Horizontal X
            if(verifLarge == 4 ){  
                g = 0;
                victoire(tabJoueur, g);
		    }

	    }
           verifHauteur = 1;
           verifLarge = 1;
            while(tab[choix-verifLarge][hauteur] == 0){

            verifLarge ++;
        
            if(verifLarge == 4 ){ 
                g = 0;
                victoire(tabJoueur, g);
		    }

	    }
            verifHauteur = 1;
            verifLarge = 1;
            while(tab[choix][hauteur-verifHauteur] == 0){                                            // Vertical X

            verifHauteur ++;

            if(verifHauteur == 4 ){            
                g = 0;
                victoire(tabJoueur, g);
		    }
	    }
            verifHauteur = 1;
            verifLarge = 1;
            while(tab[choix+verifLarge][hauteur+verifHauteur] == 0){                                  //Diagonales X

            verifHauteur ++;
            verifLarge ++;
        
            if(verifHauteur == 4 && verifLarge ==4){                                                    //marche descend de droite
            
                g = 0;
                victoire(tabJoueur, g);
		    }
	    }
            verifHauteur = 1;
            verifLarge = 1;
            while(tab[choix-verifLarge][hauteur+verifHauteur] == 0){

            verifHauteur ++;
            verifLarge ++;
       
            if(verifHauteur == 4 && verifLarge ==4){
                                                                                                      //marche descend de gauche
                g = 0;
                victoire(tabJoueur, g);
		    }
	    }
            verifHauteur = 1;
            verifLarge = 1;
            while(tab[choix+verifLarge][hauteur-verifHauteur] == 0){

            verifHauteur ++;
            verifLarge ++;
                                                                                                //marche monte de droite
            if(verifHauteur == 4 && verifLarge ==4){
            
                g = 0;
                victoire(tabJoueur, g);
		    }
	    }
            verifHauteur = 1;
            verifLarge = 1;
            while(tab[choix-verifLarge][hauteur-verifHauteur] == 0){

            verifHauteur ++;
            verifLarge ++;
        
            if(verifHauteur == 4 && verifLarge ==4){
                                                                                               //marche monte de gauche
                g = 0;
                victoire(tabJoueur, g);
		    }
	    }

   }

   
}

void jeu::victoire(string tabJoueur[2], int g) {                                                    //Vainqueur si g est égal à 0 où 1

    switch (g)
    {

    case 0: cout << endl << "Bravo ! Tu as gagne " << tabJoueur[0] << " !" << endl << endl;
        system("pause");
        exit(EXIT_FAILURE);
        break;

    case 1: cout << endl << "Bravo ! Tu as gagne " << tabJoueur[1] << " !" << endl << endl;
        system("pause");
        exit(EXIT_FAILURE);
        break;

    }
    
}