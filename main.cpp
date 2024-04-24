// TEST PROJET HUFFMAN C++

#include <iostream>
#include <fstream>
#include <string>
#include "CListeOccurences.h"
#include "CArbreBinaire.h"
using namespace std;

int get_size(const string& filename)
{
    ifstream in(filename, ifstream::ate | ifstream::binary);
    return int(in.tellg());
}

int main()
{
    string filename;
    filename = "alice";

    CListeOccurences occurences;
    ifstream is("data/" + filename + ".txt", ios::in);
    string buffer;
    if (is) {
        while (getline(is, buffer)) {
            const char* line = buffer.data();
            for (int i = 0; i < strlen(line); i++) {
                occurences.ajouterCaractere(line[i]);
            }
        }
    }
    is.close();

    occurences.trierListe();
    ofstream os2("data/" + filename + "_freq.txt", ios::out);
    os2 << occurences;
    cout << occurences << endl;
    os2.close();


    char* liste_caracteres = new char[occurences.Get_taille()];
    int taille = occurences.Get_taille();
    for (int i = 0; i < taille; i++) {
		liste_caracteres[i] = occurences[i].Get_caractere();
	}

    cout << "Arbre binaire :" << endl;
    CArbreBinaire abr(occurences.creerArbre());

    
    for (int i = 0; i < taille; i++) {
        cout << liste_caracteres[i] << ":" << abr.code_binaire(liste_caracteres[i]) << endl;
    }
    

    abr.afficherArbre();


    occurences.ecritBinaire(filename, abr);

    double size_orig = get_size("data/" + filename + ".txt");
    double size_comp = get_size("data/" + filename + "_comp.bin");
    double size_freq = get_size("data/" + filename + "_freq.txt");

    cout << "Taille du fichier original : " << size_orig << " octets" << endl;
    cout << "Taille du fichier comp     : " << size_comp << " octets" << endl;
    cout << "Taille du fichier freq     : " << size_freq << " octets" << endl;

    double taux_comp = 1 - ((size_comp+size_freq) / size_orig);
    if (taux_comp < 0) {
		cout << "Compression impossible - le fichier original est trop petit (Taux : " << taux_comp << ")" << endl;
	}
    else {
        cout << "Taux de compression : " << taux_comp << endl;
    }

    double nb_moyen_bit = size_comp / size_orig * 8;
    cout << "Nombre moyen de bits par caract\212re : " << nb_moyen_bit << endl;

     return 0;
}