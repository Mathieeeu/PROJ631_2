Compression de données par codage de Huffman
=======
Introduction
-----------
Le codage de Huffman est une méthode de compression de données sans perte. Elle a été développée par David A. Huffman en 1952. Cette méthode est basée sur la fréquence d'apparition des symboles dans le texte à compresser. Les symboles les plus fréquents sont codés sur moins de bits que les symboles les moins fréquents, alors qu'habituellement, chaque symbole est codé sur huit bits.
J'ai choisi de réaliser ce projet en C++ car c'est un langage que j'apprécie et que nous n'avons pas encore utilisé cette année. De plus, il est bien adapté pour la manipulation de fichiers.

Features
-----------
- Choix d'un fichier texte à compresser
- Compression du fichier texte
- Affichage de la table de fréquence des symboles
- Affichage de l'arbre de Huffman
- Affichage du codage de chaque symbole
- Affichage du taux de compression

Utilisation
-----------
Pour compresser un fichier texte, il faut executer l'application `huffman.exe` ou lancer le programme `main.cpp` avec un compilateur C++.
Une fois le programme lancé, il faut choisir le fichier texte à compresser. Celui-ci doit se trouver dans un répertoire nommé `data` à la racine du projet.
Les fichiers renvoyés (table de fréquence, texte binaire) se trouvent dans le répertoire `output` à la racine du projet. 
Il est possible de visualiser la table de fréquence, l'arbre de Huffman, le codage de chaque symbole et la performance de la compression en modifiant les variables booléennes dans la fonction principale du fichier `main.cpp`.

Algorithme
-----------
1. Détermination de l'alphabet et des fréquences d'apparition des caractères
2. Construction de l'arbre de codage
3. Codage et compression du texte initial
4. Détermination et affichage du taux de compression obtenu
5. Détermination et affichage du nombre moyen de bits par caractère dans le texte codé

Classes
-----------
- **COccurrence** : classe permettant de stocker les informations sur une occurrence d'un caractère
- **CListeOccurrences** : classe permettant de stocker une liste d'occurrences, cette classe est utilisée pour construire l'arbre de Huffman et pour coder le texte
- **CArbreBinaire** : classe permettant de gérer un arbre binaire

Fonctions principales
-----------
- **compresser_fichier** : fonction permettant de compresser un fichier texte dont le nom est passé en paramètre. Elle prend aussi des booléens en paramètres pour l'affichage dans la console.
- **creerArbre** : méthode de la classe CListeOccurrences permettant de construire l'arbre de Huffman à partir de la liste des occurrences. Elle crée une liste de noeuds et les fusionne jusqu'à obtenir un seul noeud racine.
- **code_binaire** : méthode de la classe CArbreBinaire renvoyant le code binaire d'un caractère donné en paramètre selon l'arbre de Huffman. Elle fait appel à la méthode `chemin_existe` qui renvoie le chemin de la racine à un noeud donné, en mettant un 0 si on va à gauche et un 1 si on va à droite jusqu'à atteindre le caractère recherché.
- **ecritBinaire** : méthode de la classe CLiseOccurrences permettant d'écrire le texte compressé dans un fichier binaire. Elle prend en paramètre le nom du fichier texte et l'arbre de Huffman construit précédemment. Pour chaque caractère de chaque ligne du fichier texte, elle appelle la méthode `code_binaire` pour obtenir le code du caractère et l'écrit dans le fichier binaire.

-----------
_DOCHER Mathieu - IDU3 - Polytech Annecy_
