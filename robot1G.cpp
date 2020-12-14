#include "robot1G.h"

robot1G::robot1G(const position &pos,joueur *joueurAElimine):Personnage{pos},d_joueurAElimine{joueurAElimine}
{

}

char robot1G::signe()const
{
    return SIGNE_ROBOT1G;
}

 void robot1G::deplace()
{
    if(detecteJoueurPlusBas())
    {
        deplaceBas();
        return;
    }
    else if(detecteJoueurPlusHaut())
    {
        deplaceHaut();
        return;
    }
    else if(detecteJoueurAGauche())
    {
        deplaceGauche();
        return;
    }
    else if (detecteJoueurADroite())
    {
        deplaceDroite();
        return;
    }
}

bool robot1G::detecteJoueurPlusHaut()const
{
    return (pos().y()>d_joueurAElimine->pos().y());
}

bool robot1G::detecteJoueurPlusBas()const
{
    return (pos().y()<d_joueurAElimine->pos().y());
}

bool robot1G::detecteJoueurAGauche()const
{
    return (pos().x()>d_joueurAElimine->pos().x());
}

bool robot1G::detecteJoueurADroite()const
{
    return (pos().x()<d_joueurAElimine->pos().x());
}

