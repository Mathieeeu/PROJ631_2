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

void compresser_fichier(string filename, bool afficher_occurences, bool afficher_arbre, bool afficher_binaires, bool afficher_resultats)
{
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
    else {
        cerr << "Erreur lors de l'ouverture du fichier " << filename << ".txt - V\202rifiez le chemin d'acc\212s." << endl;
        return;
    }
    is.close();

    occurences.trierListe();
    ofstream os2("output/"+ filename + "_freq.txt", ios::out);
    os2 << occurences;
    if (afficher_occurences) {
        cout << occurences << endl;
    }
    os2.close();


    char* liste_caracteres = new char[occurences.Get_taille()];
    int taille = occurences.Get_taille();
    for (int i = 0; i < taille; i++) {
        liste_caracteres[i] = occurences[i].Get_caractere();
    }

    CArbreBinaire abr(occurences.creerArbre());

    if (afficher_arbre) {
        cout << "Arbre binaire :" << endl;
        abr.afficherArbre();
    }

    if (afficher_binaires) {
        for (int i = 0; i < taille; i++) {
            cout << liste_caracteres[i] << ":" << abr.code_binaire(liste_caracteres[i]) << endl;
        }
    }

    occurences.ecritBinaire(filename, abr);

    if (afficher_resultats) {
        double size_orig = get_size("data/" + filename + ".txt");
        double size_comp = get_size("output/" + filename + "_comp.bin");
        double size_freq = get_size("output/" + filename + "_freq.txt");

        cout << "Taille du fichier original : \033[38;5;37m" << size_orig << "\033[0m octets" << endl;
        cout << "Taille du fichier comp     : \033[38;5;37m" << size_comp << "\033[0m octets" << endl;
        cout << "Taille du fichier freq     : \033[38;5;37m" << size_freq << "\033[0m octets" << endl;

        double taux_comp = 1 - ((size_comp + size_freq) / size_orig);
        if (taux_comp < 0) {
            cout << "\033[5m\033[38;5;52mCompression impossible\033[0m - le fichier original est trop petit (Taux : \033[38;5;37m" << taux_comp << "\033[0m)" << endl;
        }
        else {
            cout << "Taux de compression : \033[38;5;37m" << taux_comp << "\033[0m" << endl;
        }

        double nb_moyen_bit = size_comp / size_orig * 8;
        cout << "Nombre moyen de bits par caract\212re : \033[38;5;37m" << nb_moyen_bit << "\033[0m" << endl;
    }
}

int main()
{
    string filename;
    //filename = "extraitalice";
    cout << "Entrez le nom du fichier \205 compresser (sans l'extension .txt) : \033[38;5;220m";
    cin >> filename;
    cout << "\033[0m";

 // -- Modifier les variables ci-dessous pour afficher les différents résultats intermédiaires -- //
    bool afficher_occurences    = false;
    bool afficher_arbre         = false;
    bool afficher_binaires      = false;
    bool afficher_resultats     = true ;
// ---------------------------------------------------------------------------------------------- //

    compresser_fichier(filename, afficher_occurences, afficher_arbre, afficher_binaires, afficher_resultats);

    cout << "\n\nAppuyez sur n'importe quelle touche pour quitter... ";
    cin.ignore();
    cin.ignore();

    return 0;
}