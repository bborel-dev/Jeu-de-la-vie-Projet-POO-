
// Implementation des bibliothèques :

#include "Grille.h" // permet d'inclure le fichier d'en tête.
#include <fstream> // permet de manipuler un fichier.
#include <sstream> // permet de diviser la ligne du fichier en élément.
#include <iostream> // permet d'afficher du texte dans la console.

using namespace std; // permet d'éviter de réécrite std à chaque utilisation de la bibliothèque standard dans notre cas.


// Constructeurs :

Grille::Grille(){ // permet creer une instance avec une matrice par défaut 
    matrice = {};  // initialise une matrice vide
}

Grille::Grille(vector<vector<int>> matrice) { // permet de creer une instance avec une matrice personnalisé.
    this->matrice = matrice;  // permet de remplacer la matrice par défaut par la nouvelle matrice, utilisation de this pour différencier les deux matrices.
}

// Méthodes principales : 

void Grille::implementation_valeurs() {
    
    ifstream fichier;
   
    cout << "Entrez le nom de votre fichier d'entrée avec l'extension : "; 
    cin >> fichier_source; // demande à l'utilisateur de rentrer le nom du fichier d'entrée.
    fichier.open(fichier_source); // permet d'ouvrir le fichier d'entrée.
   
    while (!fichier) { // Tant que le fichier ne peut pas être ouvert on redemande à l'utilisateur de rentrer un fichier valide.
        cerr << "Erreur : Impossible d'ouvrir le fichier " << fichier_source << ". Veuillez réessayer." << endl;
        cout << "Entrez le nom de votre fichier d'entrée avec l'extension : ";
        cin >> fichier_source;
        fichier.open(fichier_source);
    }


    // permet de redimensionner la matrice avec les nouvelles dimensions à la première ligne du fichier. 
    int lignes, colonnes;
    fichier >> lignes >> colonnes; // Utilisation de la biliothèque sstream.
    matrice.resize(lignes, vector<int>(colonnes));


    // Permet de remplir la matrice en parcourant les lignes et colonnes du fichier.
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < colonnes; ++j) {
            fichier >> matrice[i][j];
        }
    }
    fichier.close(); // Permet de fermer le fichier.
    cout << "Fichier chargé avec succès." << endl;
}

// permet de récupérer le nom du fichier source.
string Grille::getFichierSource() const {
    return fichier_source;  // Retourne le nom du fichier source.
}

// Méthode pour afficher la grille dans la console.
void Grille::affiche_grille() const {
    for (const auto& ligne : matrice) {
        for (int cell : ligne) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Accesseurs :

// permet de récupérer la matrice.
vector<vector<int>> Grille::getMatrice() const {
    return matrice;
}

// permet de modifier la matrice.
void Grille::setMatrice(const vector<vector<int>>& nouvelle_matrice) {
    matrice = nouvelle_matrice;
}