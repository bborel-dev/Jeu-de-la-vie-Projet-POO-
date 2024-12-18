#ifndef GRILLE_H
#define GRILLE_H

#include <vector> // permet de manipuler des vecteurs .
#include <string> // permet de manipuler des chaînes de caractères.

using namespace std; // permet d'éviter de réécrite std à chaque utilisation de la bibliothèque standard dans notre cas.

// On définit la classe Grille.
class Grille {
// Accessibles uniquement par les méthodes de la classes.
private:
    vector<vector<int>> matrice;  // Matrice sous forme de tableau dynamique.
    string fichier_source;        // Chaine de caractères permettant de stocker le nom du fichier source.

public:
// Accessible partout.
    // Constructeurs
    Grille(); // Permet d'initialiser une instance avec une matrice par défaut.
    Grille(vector<vector<int>> matrice); // Permet d'initialiser une instance avec une matrice choisie.

    // Méthodes principales
    void implementation_valeurs();// permet d'implémenter les valeurs du fichier source dans une matrice vectorielle.
    void affiche_grille() const; // permet d'afficher la matrice dans la console.

    // Accesseurs
    vector<vector<int>> getMatrice() const; // permet de récupérer la matrice vectorielle.
    void setMatrice(const vector<vector<int>>& nouvelle_matrice); // permet de modifier la matrice vectorielle.

    string getFichierSource() const;  // Permet de récupérer le nom du source.
};

#endif
