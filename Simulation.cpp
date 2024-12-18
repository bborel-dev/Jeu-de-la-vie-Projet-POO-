// Bibliothèques :

#include "Simulation.h" // permet d'inclure le fichier d'en tête.
#include "Cellule.h" // permet d'inclure la classe Cellule pour réutiliser les méthodes publiques de la classe.
#include <iostream> // permet d'afficher du texte dans la console.
#include <filesystem> // permet gérer le système de fichiers comme créer un répertoire
#include <fstream> // permet de manipuler un fichier.
#include <thread> // permet d'introduire des délais.
#include <chrono> // permet d'introduire une unité de temps.


using namespace std; // permet d'éviter de réécrite std à chaque utilisation de la bibliothèque standard dans notre cas.

// Constructeur :

Simulation::Simulation(){ // permet creer une instance avec un max d'itération de 0.
    max_iterations = 0;
}

// Méthodes : 

// permet de démarrer la simulation.
void Simulation::lancer() {
    grille.implementation_valeurs(); // On remplit la matrice en utilisant la méthode de la classe cellule.
    
    // Permet de savoir si la matrice est vide :
    if (grille.getMatrice().empty()) {
        cerr << "Erreur : La matrice est vide !" << endl;
        return;
    }

    // Permet à l'utilisateur de choisir son interface.
    cout << "Choisissez l'interface :\n";
    cout << "1. Interface console\n";
    cout << "2. Interface graphique\n";
    cout << "Votre choix : ";
    int choix;
    cin >> choix;

    // Permet à l'utilisateur de rentrer le nombre d'itération maximum souhaité.
    cout << "Entrez le nombre d'iterations : ";
    cin >> max_iterations;

    // Fait appelle aux méthodes d'interface en fonction du choix.
    
    if (choix == 1) {
        interfaceConsole();
    } else if (choix == 2) {
        interfaceGraphique();
    } else {
        cerr << "Erreur : Choix invalide !" << endl;
    }
}

// Permet de gérer l'éxécution de la simulation dans la console.
void Simulation::interfaceConsole() {
    
    grille.getMatrice();
    testerGrille(grille);

    // Permet de récupérer le nom du fichier source
    string fichier_source = grille.getFichierSource();

    // Permer d'initialise la chaine de caractère du dossier_sortie avec le nom du fichier source puis _out
    string dossier_sortie = fichier_source.substr(0, fichier_source.find('.')) + "_out";
    
    // Si ce fichier n'existe pas alors on le crée.
    if (!filesystem::exists(dossier_sortie)) {
        filesystem::create_directory(dossier_sortie);
    }

    // Boucle permettant d'augmenter les itérations.
    for (int iteration = 0; iteration < max_iterations; ++iteration) {
        
        // Affiche la grille dans la console à chaque itération.
        vue.afficheGrilleConsole(grille);

        // Sauvegarde l'itération dans le fichier de sortie.
        string nom_fichier_sortie = dossier_sortie + "/iteration_" + to_string(iteration + 1) + ".txt";
        ofstream fichier_sortie(nom_fichier_sortie);
        if (fichier_sortie) {
            for (const auto& ligne : grille.getMatrice()) {
                for (int valeur : ligne) {
                    fichier_sortie << valeur << " ";
                }
                fichier_sortie << endl;
            }
        }
        fichier_sortie.close();


        // Utilisation des méthodes de la classe Cellule pour appliquer les règles du changement d'état.
        Cellule cellule;
        auto nouvelleMatrice = cellule.Cellule_changement_etat(grille.getMatrice());
        // Mise à jour de la grille.
        grille.setMatrice(nouvelleMatrice);
        testerGrille(nouvelleMatrice);


        // Permet de mettre un délais entre chaque itération.
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

// Permet de gérer l'éxécution de la simulation dans l'interface graphique.
void Simulation::interfaceGraphique() {

    // Permet à l'utilisateur d'entrée le temps souhaité entre chaque itération.
    int temps;
    cout << "Entrez le temps entre deux itérations en millisecondes : ";
    cin >> temps;

    // Permet d'afficher la grille avec l'interface graphique.
    vue.afficheGrilleGraphique(grille, max_iterations, temps);
}

// Méthode de test unitaire permettant de vérifier si la grille est valide.
void Simulation::testerGrille(const Grille& grille) {
    bool valide = true;
    for (const auto& ligne : grille.getMatrice()) {
        for (int valeur : ligne) {
            if (valeur != 0 && valeur != 1) {
                cerr << "Erreur : La grille contient une valeur invalide (" << valeur << ")." << endl;
                valide = false;
            }
        }
    }

    if (valide) {
        cout << "La grille est valide." << endl;
    } else {
        cerr << "La grille n'est pas valide." << endl;
        exit(1); // Arrête l'exécution du programme si une valeur invalide est trouvée.
    }
}



// Accesseurs :

// Permet de récupérer le nombre maximum d'itération.
int Simulation ::  get_max_iterations(){
    return max_iterations;
}

// Permet de modifier le nombre maximum d'itération.
void Simulation :: set_max_iterations(int max_iterations){
    this->max_iterations = max_iterations;
}