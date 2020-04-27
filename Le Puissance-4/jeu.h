#include <iostream>
#include <string>
#include <vector>

using namespace std;

class jeu
{
public:

	jeu();
	~jeu();

	void partie();
	void afficherMenu();
	
	void afficherJeu(int tab[7][6], int, int, int);
	
	//void initialiserJeu(int i, int j, int, int, int tab[7][6]);
	void choixJeton(int, int tab[7][6], int, string tabJoueur[2], int);
	void checkVictoire(int, int, int tab[7][6], int, int, string tabJoueur[2]);
	void victoire(string tabJoueur[2], int);

private:

	int choix;         
	int i = 0;					//colone
	int nombreJetons[7];
	
	int tab[7][6];
	int c;
	int g = -1;
	int j;
	int tours;
	
	int hauteur = 6;
	int  largeur = 7;
	
};

