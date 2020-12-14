#include "Element.h"
#include "joueur.h"
#include "robot1G.h"

Element::Element(const position &pos):d_pos{pos}
{

}

Element::~Element()
{

}


position Element::pos() const
{
    return d_pos;
}

bool Element::collision(const Element *e)const
{
    return(d_pos==e->d_pos);
}



