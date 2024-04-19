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

bool CArbreBinaire::est_feuille()
{
	if (m_abrGauche == NULL && m_abrDroite == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CArbreBinaire::chemin_existe(char c,char* code,int i)
{
	if (m_cLabel == c)
	{
		code[i] = '\0';
		return true;
	}
	else
	{
		if (m_abrGauche != NULL)
		{
			if (m_abrGauche->chemin_existe(c, code,i+1))
			{
				code[i] = '0';
				return true;
			}
		}
		if (m_abrDroite != NULL)
		{
			if (m_abrDroite->chemin_existe(c, code,i+1))
			{
				code[i] = '1';
				return true;
			}
		}
	}
	return false;
}

const char* CArbreBinaire::code_binaire(char c)
{
	char* code = new char[24];
	chemin_existe(c,code,0);
	int i = 0;
	while (code[i] != '\0')
	{
		i++;
	}
	char* temp = new char[i];
	for (int j = 0; j < i; j++)
	{
		temp[j] = code[j];
	}
	temp[i] = '\0';
	return temp;
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

