#ifndef VUE_H
#define VUE_H

#include "Grille.h" //permet d'inclure la classe Grille pour réutiliser les méthodes publiques de la classe.


// On définit la classe Vue.
class Vue {
// Accessible partout.
public:

// Méthodes :

    // Permet d'afficher la matrice dans la console.
    void afficheGrilleConsole(const Grille& grille);
    // Permet d'afficher la matrice dans l'interface graphique.
    void afficheGrilleGraphique(Grille& grille, int iterationsMax, int tempsEntreIterations);
};

#endif
