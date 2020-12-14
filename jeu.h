#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include "terrain.h"
#include "Element.h"
#include "robot1G.h"
#include "robot2G.h"
#include "joueur.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
using std::ostream;
using std::vector;



class jeu{

public :
    jeu(const terrain &t);
    int score()const;
    static char commandeJoueur();
    static bool verifChoixJoueur(char commande);
    void deplaceJoueur(char choixJoueur,joueur &j);
    void enoncerRegles()const;
    void jouer();
    void initDebris();
    void initRobots();
    void ajouteJoueur();
    void ChoixMenuPrincipal(int& choice);
    void MenuPrincipalLoop();
    void run();

private :
    int d_score;
    terrain d_terrain;
    joueur d_leJoueur;

};


#endif // JEU_H_INCLUDED
