#include <iostream>
#include <string>
#include <vector>

using namespace std;

class jeu
{
public:

	jeu();
	~jeu();

	void partie(/*int i, int j, char tab[7][6]*/);
	void afficherMenu();
	//void deroulement();
	void afficherJeu(char tab[7][6], int j);
	/*void initialiserJeu(int a, int b, int const hauteur = 6, int const largeur = 7);*/

private:
	int choix;         
	int i = 0;					//colone
	int nombreJetons[7];
	/*int const largeur;
	int const hauteur;*/
	char tab[7][6];
	int ligne;
	int c;

	int j;
	
	int const hauteur = 6;
	int const largeur = 7;
	
};

