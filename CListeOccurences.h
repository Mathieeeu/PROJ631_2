#pragma once
#include "COccurence.h"
#include "CArbreBinaire.h"
#include <iostream>
#include <fstream>
using namespace std;

class CListeOccurences
{
private:
	int m_nTaille;
	COccurence* m_pListeOccurences;
public:
	CListeOccurences();
	CListeOccurences(int,COccurence*);
	CListeOccurences(const CListeOccurences&);
	~CListeOccurences();
	friend ostream& operator<<(ostream&, const CListeOccurences&);
	friend ofstream& operator<< (ofstream&, const CListeOccurences&);
	COccurence operator[](int);
	int Get_taille();
	void ajouterCaractere(char);
	bool dansListe(COccurence);
	void trierListe();
	void fusionner(); // fusionne les deux occurences les moins fréquentes (=>les deux premieres)
	COccurence* getMin(); // Renvoie les deux occurences les moins fréquentes
	CArbreBinaire creerArbre();
	static void encode(string, string);
	void ecritBinaire(string, CArbreBinaire);
};

