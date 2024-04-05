// TEST PROJET HUFFMAN C++
// Faire une méthode "static" permet de pas avoir à créer un objet pour exec la méthode genre juste CClasse::Methode

#include <iostream>
#include <fstream>
#include <string>
#include "CListeOccurences.h"
using namespace std;

int get_size(const char* filename)
{
    ifstream in(filename, ifstream::ate | ifstream::binary);
    return int(in.tellg());
}

int main()
{
    const char* filename;
    filename = "fichier.txt";

    ofstream os(filename, ios::out);
    os << "pitié j'ai envie d'en gagner au\nmoins une sur valorant...";
    os.close();

    /*
    int filesize = get_size(filename);
    char* buffer = new char[filesize];
    ifstream is(filename, ios::in);
    is.read(buffer, filesize); //lire tout le fichier d'un coup
    is.close();
    buffer[filesize] = '\0'; //sinon il rajoute 4 caractères jsp pourquoi mdr
    cout << buffer << endl;

    //Comptage des occurences de chaque caractère puis tri 
    CListeOccurences occurences;
    for (int i = 0; i < filesize; i++) {
        occurences.ajouterCaractere(buffer[i]);
    }
    cout << occurences << endl;
    */

    CListeOccurences occurences;
    ifstream is(filename, ios::in);
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
    cout << occurences;
}