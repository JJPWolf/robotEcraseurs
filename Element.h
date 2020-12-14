#ifndef ELEMENT_H_INCLUDED
#define ELEMENT_H_INCLUDED
#include "position.h"
#include <iostream>

const char SIGNE_JOUEUR = 'J';
const char SIGNE_ROBOT1G= '1';
const char SIGNE_ROBOT2G= '2';
const char SIGNE_DEBRIS= 'X';

const char HAUT = 'z';
const char BAS = 's';
const char GAUCHE = 'q';
const char DROITE = 'd';
const char HAUT_GAUCHE = 'a';
const char HAUT_DROITE = 'e';
const char BAS_GAUCHE = 'w';
const char BAS_DROITE = 'x';

class Element{

public:
    Element(const position &pos);
    virtual ~Element();
    virtual position pos() const;
    bool collision(const Element *e)const;
    virtual char signe()const=0;
    virtual void deplace()=0;

protected:
    position d_pos;
};


#endif // ELEMENT_H_INCLUDED
