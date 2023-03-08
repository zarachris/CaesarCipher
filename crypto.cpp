#include <iostream>
#include <string>
#include "Crypto.h"
#include <windows.h>


Crypto::Crypto() {
	c = 'a';
}

string Crypto::LireMessage(string fileName) {
	string message = "";
	fichier_in.open(fileName);

	if (fichier_in.fail()) {
		cout << "Erreur a l'ouverture du fichier..." << endl;
	}
	else {
		string line;

		while (std::getline(fichier_in, line)) {
			message.append(line + "\n"); // on ajoute chaque ligne au message + un saut de ligne
		}
	}
	fichier_in.close();
	return message;
}

void Crypto::Chiffrer(int key) {
	string origine = LireMessage("origine.txt");
	string output = "";


	for (int i = 0; i < origine.length(); i++)
	{
		// vérifier si la lettre est une lettre alphabétique...
		if (isalpha(origine[i]))
		{
			c = origine[i];

			if (isupper(c)) {
				// décaler la lettre :
				// on utilise le code ASCII du caractère pour effectuer des opérations arithmétiques
				// c - 'A' est l'index dans l'alphabet de la lettre à l'index i (ex : 'I' - 'A' = 73 - 65 = 8)
				// on ajoute le décalage key
				// le modulo 26 permet d'assurer que l'index sera un index valide de l'alphabet
				// ex pour décaler Z de 3 : (25 + 3) % 26 = 2 ce qui correspond à C
				// on rajoute 'A' pour obtenir le code ASCII de la lettre chiffrée
				c = ((c - 'A') + key) % 26 + 'A';
			}
			else {
				// même chose pour lettres minuscules
				c = ((c - 'a') + key) % 26 + 'a';
			}
			output += c;

		}
		// ...sinon ajouter la lettre telle quelle au message chiffré
		else
		{
			output += origine[i];
		}
	}

	// enregistrer dans le fichier message.txt
	if (output.length() != 0) {
		fichier_out.open("message.txt");
		if (fichier_out.fail()) {
			cout << "Erreur a l'ouverture du fichier..." << endl;
		}
		else {
			fichier_out << output;
		}
		fichier_out.close();
	}
}

void Crypto::Dechiffrer(int key) {
	string message = LireMessage("message.txt");
	string decodedMsg;

	for (int i = 0; i < message.length(); i++)
	{

		if (isalpha(message[i]))
		{
			c = message[i];

			if (isupper(c)) {
				// algorithme semblable à celui de Chiffrer mais on enlève key au lieu de l'ajouter
				int index = ((c - 'A') - key) % 26;
				if (index < 0) index += 26; // ajustement pour les index négatifs
				c = index + 'A';
			}
			else {
				int index = ((c - 'a') - key) % 26;
				if (index < 0) index += 26;
				c = index + 'a';
			}

			decodedMsg += c;
		}
		else
		{
			decodedMsg += message[i];
		}
	}

	// imprimer le message décodé
	cout << decodedMsg << endl;
}

bool Crypto::init()

{
    Crypto crypto;

    char choix; //choix de l'utilisateur, soit chiffrer, soit déchiffrer, soit quitter
    bool retour;//permet de quitter le programme, voir main()
    int input;//permet de vérifier si l'input de l'utilisateur est la bonne clé ou non

    retour = false;

    system("cls");
    cout << "Faites votre choix :\n"<< endl;
    cout << "Pour chiffrer un message : tapez (1)\n"<< endl;
    cout << "Pour dechiffrer un message : tapez (2)\n"<< endl;
    cout << "Pour quitter le programme : tapez (q ou Q)\n"<< endl;
    Sleep(1000);
    printf("Saisissez votre choix : ");

    cin >> choix;
    cin.clear();

    switch(choix)
    {
        case '1'://Chiffrement

            system("cls");
            cout << "Vous avez choisi de chiffrer un message."<< endl;
            getchar();
            cout << "Il faut tout d'abord choisir une cle qui permettra de chiffrer et dechiffrer le message." << endl;
            getchar();

            /* Début saisie clé
            L'utilisateur saisit la clé qui va permettre de chiffrer le message et de le déchiffrer ensuite.
            La clé 'key' est par défaut de 3 ( voir dans crypto.h )*/

            cout << "Saisissez la cle :" << endl;
            cin >> key;
            cin.clear();
            system("cls");
            cout << "Cle saisie avec succes. Ne l'oubliez pas." << endl;
            getchar();

            /*Fin saisie clé */

            system("cls");
            cout << "Assurez vous d'avoir saisi le message a chiffrer dans le fichier 'origine.txt'." << endl;
            getchar();
            cout << "Ce fichier doit se trouver dans le meme dossier que le programme." << endl;
            getchar();
            system("cls");
            cout << "Chargement du message en cours" << endl;
            Sleep(2000);
            cout << "." << endl;
            Sleep(2000);
            cout << "." << endl;
            Sleep(1000);
            system("cls");

            crypto.Chiffrer(key);//lance la fonction chiffrer

            cout << "Le message a ete chiffre avec succes.\a" << endl;
            Sleep(1000);
            cout << "Vous trouverez le message dans le fichier 'message.txt'." << endl;
            getchar();
            system("cls");

            break;

        case '2'://Dechiffrement

            system("cls");
            cout << "Vous avez choisi de dechiffrer un message."<< endl;
            getchar();

            /* Vérification clé */

            cout << "Veuillez saisir la cle secrete :"<< endl;
            cin >> input;

            if(input == key) //La clé saisie est la bonne
            {
                system("cls");
                cout << "Cle saisie avec succes." << endl;
                Sleep(1500);
                system("cls");
                cout << "Assurez vous que le message chiffre soit bien dans le fichier 'message.txt'." << endl;
                getchar();
                cout << "Ce fichier doit se trouver dans le meme dossier que le programme." << endl;
                getchar();
                system("cls");
                cout << "Dechiffrement du message en cours" << endl;
                Sleep(2000);
                cout << "." << endl;
                Sleep(2000);
                cout << "." << endl;
                Sleep(1000);
                system("cls");
                cout << "Le message a ete dechiffre avec succes.\a\n" << endl;
                Sleep(1000);
                cout << "Voici un apercu de ce message :\n" << endl;

                crypto.Dechiffrer(key);//lance la fonction dechiffrer

                getchar();
                system("cls");

                break;
            }

            else //La clé saisie n'est pas la bonne
            {
                cout << "Erreur. Procedure de securite enclenche." << endl;
                Sleep(1500);
                cout << "Fermeture du programme."<< endl;
                Sleep(1000);

                retour = true;//Va stopper la boucle dans main()

                break;
            }

        case 'Q':
        case 'q'://Quitter le programme
                retour = true;//Va stopper la boucle dans main()
                cout <<"Fermeture du programme.\f"<< endl;
                break;
        default : cout <<"Erreur de saisie. Veuillez recommencer. \n"<< endl;cin.clear();Sleep(1800);//Si l'utilisateur se 'trompe' dans la saisie
    }
    getchar();
    return retour;



}
