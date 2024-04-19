#include "CListeOccurences.h"

#pragma region CONSTRUCTEURS
CListeOccurences::CListeOccurences()
	:m_nTaille(0),m_pListeOccurences(NULL)
{
}

CListeOccurences::CListeOccurences(int n,COccurence* pOccurences)
	:m_nTaille(n), m_pListeOccurences(pOccurences)
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


COccurence CListeOccurences::operator[](int i)
{	
	return m_pListeOccurences[i];
}

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

bool CListeOccurences::dansListe(COccurence o)
{
	bool res = false;
	for (int i = 0; i < m_nTaille; i++) {
		if (m_pListeOccurences[i].Get_caractere() == o.Get_caractere()) {
			res = true;
		}
	}
	return res;
}

void CListeOccurences::trierListe()
{
	COccurence* pOccurences = new COccurence[m_nTaille];
	CListeOccurences liste_triee(m_nTaille,pOccurences);
	for (int i = 0; i < m_nTaille; i++) {
		COccurence min;
		for (int j = 0; j < m_nTaille; j++) {
			if (!liste_triee.dansListe(m_pListeOccurences[j])) {
				if (m_pListeOccurences[j].Get_frequence() < min.Get_frequence()
					|| (m_pListeOccurences[j].Get_frequence() == min.Get_frequence() && (int)m_pListeOccurences[j].Get_caractere() < (int)min.Get_caractere())
					|| min.Get_frequence() == 0) {
					min = m_pListeOccurences[j];
				}
			}
		}
		liste_triee.m_pListeOccurences[i] = min;
	}
	if (this != &liste_triee) {
		for (int i = 0; i < liste_triee.m_nTaille; i++) {
			m_pListeOccurences[i] = liste_triee.m_pListeOccurences[i];
		}
	}
}

void CListeOccurences::fusionner()
{
	COccurence* temp = new COccurence[m_nTaille - 1];
	COccurence o(m_pListeOccurences[0].Get_caractere()+ m_pListeOccurences[1].Get_caractere(), m_pListeOccurences[0].Get_frequence() + m_pListeOccurences[1].Get_frequence());

	for (int i = 2; i < m_nTaille; i++) {
		temp[i - 2] = m_pListeOccurences[i];
	}

	temp[m_nTaille - 2] = o;

	delete[] m_pListeOccurences;
	m_pListeOccurences = temp;
	m_nTaille--;
	
	trierListe();
}

COccurence* CListeOccurences::getMin()
{
	COccurence* pOccurences = new COccurence[2];
	pOccurences[0] = m_pListeOccurences[0];
	pOccurences[1] = m_pListeOccurences[1];

	return pOccurences;
}


CArbreBinaire CListeOccurences::creerArbre()
{
	CArbreBinaire* liste_arbres = new CArbreBinaire[m_nTaille - 1];
	int i = 0;
	while (m_nTaille > 1) {
		COccurence* occurences_min = new COccurence[2];
		occurences_min = getMin();
		CArbreBinaire* pArbreGauche = new CArbreBinaire(occurences_min[0].Get_caractere(), occurences_min[0].Get_frequence());
		CArbreBinaire* pArbreDroite = new CArbreBinaire(occurences_min[1].Get_caractere(), occurences_min[1].Get_frequence());
		CArbreBinaire abr(NULL, occurences_min[0].Get_frequence() + occurences_min[1].Get_frequence());
		//CArbreBinaire abr(occurences_min[0].Get_caractere()+occurences_min[1].Get_caractere(), occurences_min[0].Get_frequence() + occurences_min[1].Get_frequence());
		abr.set_fils_gauche(*pArbreGauche);
		abr.set_fils_droit(*pArbreDroite);

		fusionner();

		liste_arbres[i] = abr;
		i++;
	}
	int nbSousArbres = i - 1;
	for (int i = nbSousArbres; i >= 0; i--) {
		for (int j = 0; j < nbSousArbres; j++) {
			if (i != j) {
				if (liste_arbres[i].get_fils_droit().get_frequence() == liste_arbres[j].get_frequence()) {
					liste_arbres[i].set_fils_droit(liste_arbres[j]);
				}
				if (liste_arbres[i].get_fils_gauche().get_frequence() == liste_arbres[j].get_frequence()) {
					liste_arbres[i].set_fils_gauche(liste_arbres[j]);
				}
			}
		}
	}
	return liste_arbres[nbSousArbres];
}

void CListeOccurences::encode(string buffer,string filename)
{
	int buffsize = buffer.length();
	ofstream fs("data/" + filename + "_comp.bin", ios::out | ios::binary);
	int i = 0, j = 0;
	string fullStr = "";
	for (i = 0; i < buffsize; i++)
		fullStr += buffer[i];
	for (i = 0; i < fullStr.length(); i += 8)
	{
		unsigned char byte = 0;
		string str8 = "";
		if (i + 8 < fullStr.length())
			str8 = fullStr.substr(i, i + 8);
		else
			str8 = fullStr.substr(i, fullStr.length());
		for (unsigned b = 0; b != 8; ++b)
		{
			if (b < str8.length())
				byte |= (str8[b] & 1) << b;
			else
				byte |= 1 << b;
		}
		fs.put(byte);
	}
	int filelen = fs.tellp();
	fs.close();
}

void CListeOccurences::ecritBinaire(string filename, CArbreBinaire abr)
{
	ifstream is("data/" + filename + ".txt", ios::in);
	string buffer;
	string line;
	if (is) {
		while (getline(is, line)) {
			for (int i = 0; i < line.length(); i++) {
				buffer += abr.code_binaire(line[i]);
			}
		}
		is.close();
		cout << "buffer: " << buffer << endl;
		encode(buffer, filename);
		cout << "\nFichier binaire cr\202\202" << endl;
	}
	else {
		cerr << "Erreur lors de l'ouverture du fichier" << endl;
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

