#include "joueur.h"
#include "jeu.h"
joueur::joueur(const position &pos):Personnage{pos}
{}

char joueur::signe()const
{
    return SIGNE_JOUEUR;
}

void joueur::deplaceJoueur(char choixJoueur)
{
    switch(choixJoueur)
    {
        case HAUT:deplaceHaut();break;
        case BAS:deplaceBas();break;
        case GAUCHE:deplaceGauche();break;
        case DROITE:deplaceDroite();break;
        case HAUT_GAUCHE:deplaceHaut();deplaceGauche();break;
        case HAUT_DROITE:deplaceHaut();deplaceDroite();break;
        case BAS_GAUCHE:deplaceBas();deplaceGauche();break;
        case BAS_DROITE:deplaceBas();deplaceDroite();break;
    }

}

void joueur::deplace()
{
    deplaceJoueur(jeu::commandeJoueur());
}

bool joueur::estVivant()
{
    return d_estVivant;
}
