#ifndef ROBOT1G_H_INCLUDED
#define ROBOT1G_H_INCLUDED
#include "Personnage.h"
#include "joueur.h"
#include "debris.h"

class robot1G : public Personnage {

public :
    robot1G(const position &pos, joueur* joueurAElimine);
    virtual char signe()const override;
    bool detecteJoueurPlusHaut()const;
    bool detecteJoueurPlusBas() const;
    bool detecteJoueurAGauche()const;
    bool detecteJoueurADroite()const;
    virtual void deplace()override;


private:
    joueur* d_joueurAElimine;


};


#endif // ROBOT1G_H_INCLUDED
