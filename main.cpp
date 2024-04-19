// TEST PROJET HUFFMAN C++
// Faire une méthode "static" permet de pas avoir à créer un objet pour exec la méthode genre juste CClasse::Methode

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

    cout << "Code binaire de 'a' : " << abr.code_binaire('a') << endl;
    cout << "Code binaire de 'b' : " << abr.code_binaire('b') << endl;
    cout << "Code binaire de 'c' : " << abr.code_binaire('c') << endl;
    cout << "Code binaire de 'd' : " << abr.code_binaire('d') << endl;
    cout << "Code binaire de 'e' : " << abr.code_binaire('e') << endl;
    cout << "Code binaire de 'f' : " << abr.code_binaire('f') << endl;
    
    //occurences.ecritBinaire(filename, abr);
    const char* texte = "011";
    //ecriture du texte dans un fichier binaire
    ofstream fs("data/"+filename+"_comp.bin", ios::out | ios::binary);
    fs.write(texte, strlen(texte));
    fs.close();
    cout << "taille du fichier texte    : " << get_size("data/"+filename+".txt") << "o" << endl;
    cout << "taille du fichier binaire  : " << get_size("data/"+filename+"_comp.bin") << "o" << endl;
    cout << "taille du fichier freq     : " << get_size("data/"+filename+"_freq.txt") << "o" << endl;
    return 0;
}