#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "Personnage.h"

#include <iostream>
class joueur: public Personnage{

public :

    joueur(const position &pos);
    joueur();
    virtual char signe()const override;
    void deplaceJoueur(char choixJoueur);
    virtual void deplace()override;
    bool estVivant();



private :
    bool d_estVivant=true;
};


#endif // JOUEUR_H_INCLUDED
