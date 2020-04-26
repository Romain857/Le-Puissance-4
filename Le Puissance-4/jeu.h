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
	//void deroulement();
	void afficherJeu(int tab[7][6], int, int);
	//bool gagne(char, int, int, int, int, char tab[7][6]);
	//void initialiserJeu(int i, int j, int, int, int tab[7][6]);
	void choixJeton(int, int tab[7][6], int, string tabJoueur[2], int);
	void checkVictoire(int, int, int tab[7][6], int, int, string tabJoueur[2]);
	void victoire(string tabJoueur[2], int);

private:
	int choix;         
	int i = 0;					//colone
	int nombreJetons[7];
	/*int const largeur;
	int const hauteur;*/
	int tab[7][6];
	int ligne;
	int c;
	int g = -1;
	bool gagne = false;
	int j;
	
	int hauteur = 6;
	int  largeur = 7;
	
};

