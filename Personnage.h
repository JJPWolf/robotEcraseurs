#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include "Element.h"
#include <iostream>
class Personnage : public Element{

public:
    Personnage(const position &pos);
    virtual ~Personnage();
    virtual char signe()const=0;
    virtual position pos() const;
    void deplaceHaut();
    void deplaceBas();
    void deplaceGauche();
    void deplaceDroite();
    virtual void deplace()=0;

private:


};


#endif // PERSONNAGE_H_INCLUDED
