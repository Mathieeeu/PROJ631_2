#include "CArbreBinaire.h"


CArbreBinaire::CArbreBinaire()
	:m_cLabel(NULL),m_nFrequence(0),m_abrGauche(NULL),m_abrDroite(NULL)
{
}

CArbreBinaire::CArbreBinaire(char label, int f)
	:m_cLabel(label), m_nFrequence(f), m_abrGauche(NULL), m_abrDroite(NULL)
{
}

CArbreBinaire::CArbreBinaire(char label, int f, CArbreBinaire& gauche, CArbreBinaire& droite)
	:m_cLabel(label), m_nFrequence(f), m_abrGauche(NULL), m_abrDroite(NULL)
{
	this->m_abrDroite=&droite;
	this->m_abrGauche = &gauche;
}

CArbreBinaire::CArbreBinaire(const CArbreBinaire& abr)
	:m_cLabel(abr.m_cLabel), m_nFrequence(abr.m_nFrequence), m_abrGauche(abr.m_abrGauche), m_abrDroite(abr.m_abrDroite)
{
}

CArbreBinaire::~CArbreBinaire()
{
	/*
	if (m_abrGauche != NULL) {
		delete m_abrGauche;
		m_abrGauche = NULL;
	}
	if (m_abrDroite != NULL) {
		delete m_abrDroite;
		m_abrDroite = NULL;
	}
	*/
}

void CArbreBinaire::set_fils_droit(CArbreBinaire& abr)
{
	this->m_abrDroite = &abr;
}

void CArbreBinaire::set_fils_gauche(CArbreBinaire& abr)
{
	this->m_abrGauche = &abr;
}

void CArbreBinaire::set_label(char c)
{
		this->m_cLabel = c;
}

void CArbreBinaire::set_frequence(int f)
{
	this->m_nFrequence = f;
}

CArbreBinaire CArbreBinaire::get_fils_droit()
{
	return *m_abrDroite;
}

CArbreBinaire CArbreBinaire::get_fils_gauche()
{
	return *m_abrGauche;
}

char CArbreBinaire::get_label()
{
	return m_cLabel;
}

int CArbreBinaire::get_frequence()
{
	return m_nFrequence;
}

void CArbreBinaire::afficherArbre()
{
	afficherArbre(0);
}

void CArbreBinaire::afficherArbre(int indent)
{
	for (int i = 0; i < indent; i++)
	{
		cout << "  | ";
	}

	cout << m_cLabel << "(" << m_nFrequence << ")" << endl;

	if (m_abrGauche != NULL)
	{
		m_abrGauche->afficherArbre(indent + 1);
	}

	if (m_abrDroite != NULL)
	{
		m_abrDroite->afficherArbre(indent + 1);
	}
	
	if (indent == 0)
	{
		cout << endl;
	}
}

