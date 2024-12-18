// Bibliothèques :

#include "Grille.h" // permet d'inclure la classe Grille pour réutiliser les méthodes publiques de la classe.
#include "Cellule.h" // permet d'inclure le fichier d'en tête.

using namespace std; // permet d'éviter de réécrite std à chaque utilisation de la bibliothèque standard dans notre cas.


// Méthode :

// Méthode permettant de gérer les changements etats, retournant une matrice mise à jour.
vector<vector<int>> Cellule::Cellule_changement_etat(const vector<vector<int>>& matrice) {
    int compteur = 0; // Compteur pour suivre l'evolution du nombre de cellules vivantes voisines.
    vector<vector<int>> temp = matrice;  // Permet de copier la matrice actuel dans une nouvelle matrice pour éviter d'écraser les valeurs.

    
    // Permet de parcourir toute la matrice.
    for (size_t i = 0; i < matrice.size(); i++) { 
        for (size_t j = 0; j < matrice[i].size(); j++) { 
            compteur = 0; // Initialise le compteur à 0;

            
            // Extension avec la grille thorique avec l'utilisation du modulo de la taille de la matrice.
            
            // Si la matrice en dessous est vivante on ajoute 1 au compteur.
            if (matrice[(i + 1) % matrice.size()][j] == 1) compteur++;  

            // Si la matrice au dessus est vivante on ajoute 1 au compteur.
            if (matrice[(i - 1 + matrice.size()) % matrice.size()][j] == 1) compteur++;  

            // Si la matrice à droite est vivante on ajoute 1 au compteur.
            if (matrice[i][(j + 1) % matrice[i].size()] == 1) compteur++; 

            // Si la matrice à gauche est vivante on ajoute 1 au compteur.
            if (matrice[i][(j - 1 + matrice[i].size()) % matrice[i].size()] == 1) compteur++;

            // Si la matrice en bas à gauche  est vivante on ajoute 1 au compteur.
            if (matrice[(i + 1) % matrice.size()][(j - 1 + matrice[i].size()) % matrice[i].size()] == 1) compteur++;  
            
            // Si la matrice en bas à droite  est vivante on ajoute 1 au compteur.
            if (matrice[(i + 1) % matrice.size()][(j + 1) % matrice[i].size()] == 1) compteur++; 
            
            // Si la matrice en haut à gauche est vivante on ajoute 1 au compteur.
            if (matrice[(i - 1 + matrice.size()) % matrice.size()][(j - 1 + matrice[i].size()) % matrice[i].size()] == 1) compteur++;  
            
            // Si la matrice en haut à droite  est vivante on ajoute 1 au compteur.
            if (matrice[(i - 1 + matrice.size()) % matrice.size()][(j + 1) % matrice[i].size()] == 1) compteur++;  

           
            // En fonction du compteur, la cellule change d'état.
            if (matrice[i][j] == 0) {
                if (compteur == 3) {  // La cellule morte devient vivante si elle a 3 voisins vivants.
                    temp[i][j] = 1;
                }
            } else {
                if (compteur < 2 || compteur > 3) {  // La cellule vivante meurt si elle a moins de 2 ou plus de 3 voisins vivants.
                    temp[i][j] = 0;
                }
            }
        }
    }

    return temp;  // permet de retourner la nouvelle matrice mise à jour.
}