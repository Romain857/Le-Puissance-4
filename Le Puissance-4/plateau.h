#include <iostream>
#include <string>
#include <vector>

using namespace std;

class plateau
{
public:
	plateau();
	~plateau();

	//void afficherJeu(int tab[7][6]);

	void setColone();
	void getColone();
private:

	int largeur[7];
	int hauteur[6];
	int tab[7][6];
};