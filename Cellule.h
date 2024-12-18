#ifndef CELLULE_H
#define CELLULE_H

#include <vector> // permet de manipuler des vecteurs .

using namespace std;  // permet d'éviter de réécrite std à chaque utilisation de la bibliothèque standard dans notre cas.


// On définit la classe Cellule.
class Cellule {

// Accessible partout.
public:
    // Méthode permettant de gérer les changements etats, retournant une matrice mise à jour.
    vector<vector<int>> Cellule_changement_etat(const vector<vector<int>>& matrice);
};

#endif
