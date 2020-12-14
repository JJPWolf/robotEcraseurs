#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED


#include "Element.h"
#include "joueur.h"
#include "debris.h"
#include "robot1G.h"
#include "robot2G.h"

#include <vector>
#include <fstream>
#include <iostream>

using std::vector;
using std::ostream;
using std::ofstream;
using std::cout;
using std::cin;

class terrain {

public :

    terrain(int longueur, int hauteur);
    vector<vector<char>> terrainInit();
    vector<vector<char>> terrainAvecElem();
    void ajouteElement(Element *elem);
    int longueur() const;
    int hauteur() const;
    void affiche(ostream &ost, const vector<vector<char>> &terrainCaract)const;
    friend ostream& operator<<(ostream& os,terrain &t);
    void sauver(const std::string &nomFichier);
    void charger(const std::string &nomFichier,joueur &leJoueur);
    int nbElements()const;
    vector<Element*> listeElements()const;
    void miseAJour(bool& joueurEstVivant);
    void choixLongueur();
    void choixHauteur();


private :
    int d_longueur;
    int d_hauteur;
    vector<Element*> d_element;
};


#endif // TERRAIN_H_INCLUDED
