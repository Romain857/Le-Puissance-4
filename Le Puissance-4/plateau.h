#include <iostream>
#include <string>


using namespace std;

class plateau
{
public:
	plateau();
	~plateau();

	void afficherPlateau( int , int);

	
private:

	int largeur[7];
	int hauteur[6];
	int tab[7][6];
};