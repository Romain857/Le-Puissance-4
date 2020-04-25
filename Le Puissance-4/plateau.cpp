#include <iostream>
#include <string>
#include <Windows.h>
#include "plateau.h"


using namespace std;

plateau::plateau() {

}

void plateau::afficherJeu()
{
    int tab[7][6];
    system("cls");
    cout << endl << endl << endl;
    for (int i = 5; i >= 0; i--)
    {
        cout << "          | ";
        for (int j = 0; j < 7; j++)
        {
            if (tab[j][i] == -1)
                cout << " ";
            if (tab[j][i] == 0)
                cout << "X";
            if (tab[j][i] == 1)
                cout << "O";
            cout << " ";
        }
        cout << "              | " << endl << "          |---------------|" << endl;
    }
    cout << "          | 1 2 3 4 5 6 7 |" << endl;
    cout << "           _______________" << endl << endl;
}