#include "CListeOccurences.h"

#pragma region CONSTRUCTEURS
CListeOccurences::CListeOccurences()
	:m_nTaille(0),m_pListeOccurences(NULL)
{
}

CListeOccurences::CListeOccurences(COccurence* pOccurences)
	:m_nTaille(0), m_pListeOccurences(pOccurences)
{
}

CListeOccurences::CListeOccurences(const CListeOccurences& l)
	:m_nTaille(l.m_nTaille), m_pListeOccurences(l.m_pListeOccurences)
{
}

CListeOccurences::~CListeOccurences()
{
	if (m_pListeOccurences != NULL) {
		delete[] m_pListeOccurences;
	}
}
#pragma endregion


void CListeOccurences::ajouterCaractere(char c)
{
	bool char_trouve = false;
	for (int i = 0; i < m_nTaille; i++) {
		if (m_pListeOccurences[i].Get_caractere() == c) {
			m_pListeOccurences[i].Incremente();
			char_trouve = true;
		}
	}
	if (!char_trouve) {
		COccurence o(c, 1);
		COccurence* temp = new COccurence[m_nTaille + 1];
		for (int i = 0; i < m_nTaille; i++) {
			temp[i] = m_pListeOccurences[i];
		}
		temp[m_nTaille] = o;
		m_nTaille++;
		delete[] m_pListeOccurences;
		m_pListeOccurences = temp;
	}
}

ostream& operator<<(ostream& os, const CListeOccurences& l)
{
	for (int i = 0; i < l.m_nTaille; i++) {
		os << l.m_pListeOccurences[i];
	}
	return os;
}

ofstream& operator<<(ofstream& fs, const CListeOccurences& l)
{
	for (int i = 0; i < l.m_nTaille; i++) {
		fs << l.m_pListeOccurences[i];
	}
	return fs;
}
