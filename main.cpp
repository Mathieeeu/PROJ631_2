// TEST PROJET HUFFMAN C++
// Faire une méthode "static" permet de pas avoir à créer un objet pour exec la méthode genre juste CClasse::Methode

#include <iostream>
#include <fstream>
#include <string>
#include "CListeOccurences.h"
#include "CArbreBinaire.h"
using namespace std;

int get_size(const char* filename)
{
    ifstream in(filename, ifstream::ate | ifstream::binary);
    return int(in.tellg());
}

int main()
{
    string filename;
    filename = "texto";

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

    cout << "Arbre binaire :" << endl;
    CArbreBinaire abr(occurences.creerArbre());
    abr.afficherArbre();
    return 0;
}