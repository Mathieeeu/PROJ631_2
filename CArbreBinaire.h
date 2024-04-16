#pragma once
#include <iostream>
#include <string>
using namespace std;

class CArbreBinaire
{
private:
	char m_cLabel;
	int m_nFrequence;
	CArbreBinaire* m_abrGauche;
	CArbreBinaire* m_abrDroite;
	void afficherArbre(int);

public:
	CArbreBinaire();
	CArbreBinaire(char, int);
	CArbreBinaire(char, int, CArbreBinaire&, CArbreBinaire&);
	CArbreBinaire(const CArbreBinaire&);
	~CArbreBinaire();
	void set_fils_droit(CArbreBinaire&);
	void set_fils_gauche(CArbreBinaire&);
	void set_label(char);
	void set_frequence(int);
	CArbreBinaire get_fils_droit();
	CArbreBinaire get_fils_gauche();
	char get_label();
	int get_frequence();
	void afficherArbre();

};

