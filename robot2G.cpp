#include "robot2G.h"

robot2G::robot2G(const position &pos,joueur *joueurAElimine):robot1G{pos,joueurAElimine}
{

}

char robot2G::signe()const
{
    return SIGNE_ROBOT2G;
}

 void robot2G::deplace()
{
    if(detecteJoueurPlusHaut() && detecteJoueurADroite())
    {
        deplaceHaut();
        deplaceDroite();
        return;
    }
    else if(detecteJoueurPlusHaut() && detecteJoueurAGauche())
    {
        deplaceHaut();
        deplaceGauche();
        return;
    }
    else if(detecteJoueurPlusBas() && detecteJoueurADroite())
    {
        deplaceBas();
        deplaceDroite();
        return;
    }
    else if(detecteJoueurPlusBas() && detecteJoueurAGauche())
    {
        deplaceBas();
        deplaceGauche();
        return;
    }
    else robot1G::deplace();
}


