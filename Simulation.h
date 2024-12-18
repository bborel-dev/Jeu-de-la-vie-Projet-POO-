#ifndef SIMULATION_H
#define SIMULATION_H

#include "Grille.h" // Permet d'inclure la classe Grille.
#include "Vue.h" // Permet d'inclure la classe Vue.

// On définit la classe simulation.
class Simulation {


private:
// Accessible seulement par les méthodes de la classe.
    Grille grille; // Permet de creer une instance de la classe Grille.
    Vue vue; // Permet de creer une instance de la classe Vue.
    int max_iterations; // Permet de creer une variable représentant le nombre maximum d'itération.

//Méthodes :

    

public:
// Accessible partout.
    
    // Constucteur :
    Simulation();// Initialiser une instance avec une matrice par défaut.
    
    // Méthode :
    
    void lancer(); // Permet de démarrer la simulation.
    // Permet de gérer l'éxécution de la simulation dans la console.
    void interfaceConsole();  
    // Permet de gérer l'éxécution de la simulation dans l'interface graphique.
    void interfaceGraphique();
    // Méthode de test unitaire permettant de vérifier si la grille est valide.
    void testerGrille(const Grille& grille);

    // Accesseurs : 
    int get_max_iterations(); // Permet de récupérer le nombre maximum d'itération.
    void set_max_iterations(int max_iterations); // Permet de modifier le nombre maximum d'itération.
};

#endif
