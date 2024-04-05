#include "COccurence.h"

#pragma region CONSTRUCTEURS
COccurence::COccurence()
	:m_cCaractere(NULL),m_nFrequence(0)
{
}

COccurence::COccurence(char c, int f)
	:m_cCaractere(c), m_nFrequence(f)
{
}

COccurence::COccurence(const COccurence& o)
	:m_cCaractere(o.m_cCaractere), m_nFrequence(0)
{
}

COccurence::~COccurence()
{
}
#pragma endregion

char COccurence::Get_caractere()
{
	return m_cCaractere;
}

int COccurence::Get_frequence()
{
	return m_nFrequence;
}


void COccurence::Incremente()
{
	++m_nFrequence;
}

ostream& operator<<(ostream& os, const COccurence& o)
{
	os << o.m_cCaractere << " : " << o.m_nFrequence << endl;
	return os;
}

ofstream& operator<<(ofstream& fs, const COccurence& o)
{
	fs << o.m_cCaractere << " " << o.m_nFrequence << endl;
	return fs;
}