#include "Vue.h" // permet d'inclure le fichier d'en tête.
#include "Grille.h" // permet d'inclure la classe Grille pour réutiliser les méthodes publiques de la classe.
#include "Cellule.h" // permet d'inclure la classe Cellule pour réutiliser les méthodes publiques de la classe.
#include <iostream> // permet d'afficher du texte dans la console.
#include <thread> // permet d'introduire des délais.
#include <chrono> // permet d'introduire une unité de temps.
#include <SFML/Graphics.hpp> // permet de gérer une interface graphique.


using namespace std; // permet d'éviter de réécrite std à chaque utilisation de la bibliothèque standard dans notre cas.

// Méthodes :

// Méthode pour afficher la matrice dans la console.
void Vue::afficheGrilleConsole(const Grille& grille) {
    grille.affiche_grille(); // Fait appel à la méthode d'affichage de la classe grille.
}

// Méthode pour afficher la matrice sur une interface graphique.
void Vue::afficheGrilleGraphique(Grille& grille, int iterationsMax, int tempsEntreIterations) {
    
    // Permet de configuer l'affichage.
    int lignes = grille.getMatrice().size();
    int colonnes = grille.getMatrice()[0].size();
    int taille_case = 10;

    // Permet de creer la fenêtre graphique.
    sf::RenderWindow window(sf::VideoMode(colonnes * taille_case, lignes * taille_case), "Simulation de la grille");
    sf::Color couleur_vivante = sf::Color::White;
    sf::Color couleur_morte = sf::Color::Black;

    // Boucle pour les itérations
    for (int iteration = 0; iteration < iterationsMax; ++iteration) {
        sf::Event event;
        
        // permet de fermer la fenêtre si l'utilisateur clique sur la croix.
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Permet de mettre à jour l'interface graphique.
        window.clear();
        for (int i = 0; i < lignes; ++i) {
            for (int j = 0; j < colonnes; ++j) {
                sf::RectangleShape case_rect(sf::Vector2f(taille_case - 1, taille_case - 1));
                case_rect.setPosition(j * taille_case, i * taille_case);
                case_rect.setFillColor(grille.getMatrice()[i][j] == 1 ? couleur_vivante : couleur_morte);
                window.draw(case_rect);
            }
        }
        window.display(); // Permet d'afficher le contenu.

        // Utilisation des méthodes de la classe Cellule pour appliquer les règles du changement d'état.
        Cellule cellule;
        auto nouvelleMatrice = cellule.Cellule_changement_etat(grille.getMatrice());
        grille.setMatrice(nouvelleMatrice);

        // Permet de gérer le délais entre chaque itération.
        this_thread::sleep_for(chrono::milliseconds(tempsEntreIterations));
    }
}
