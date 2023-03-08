#include <iostream>
#include "Crypto.h"
#include <windows.h>

using namespace std;


int main()
{
    Crypto crypto;

    /* Phase d'initialisation (juste pour la forme) */

    cout << "Initialisation " << endl;
    Sleep(500);
    cout << ". " << endl;
    Sleep(1000);
    cout << ". " << endl;
    Sleep(1000);
    cout << ". " << endl;
    Sleep(500);
    cout << "Program ready \a" << endl;
    Sleep(1500);
    system("cls");
    Sleep(1000);

    /* Fin de phase d'initialisation */

    /* Permet de rester dans le programme jusqu'à ce que l'on décide de le quitter */
    bool sortie;
    do
    {
        sortie = crypto.init(); //lancement du programme qui renverra 'vrai' une fois terminé
    }while(sortie!=TRUE); // Tant que sortie n'est pas 'vrai', on reste dans le programme


}

