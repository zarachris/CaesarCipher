#ifndef CRYPTO_H
#define CRYPTO_H

#include <fstream>
using namespace std;

class Crypto
{
	char c;
	int key=3;


public:
	Crypto();
	void Chiffrer(int);
	void Dechiffrer(int);
	string LireMessage(string);
	ofstream fichier_out;
	ifstream fichier_in;
	bool init(void);
};


#endif
