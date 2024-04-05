#pragma once
#include "COccurence.h"
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
	CListeOccurences(COccurence*);
	CListeOccurences(const CListeOccurences&);
	~CListeOccurences();
	friend ostream& operator<<(ostream&, const CListeOccurences&);
	friend ofstream& operator<< (ofstream&, const CListeOccurences&);
	void ajouterCaractere(char);
};

