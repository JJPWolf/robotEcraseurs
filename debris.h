#ifndef DEBRIS_H_INCLUDED
#define DEBRIS_H_INCLUDED
#include "Element.h"

class debris : public Element{

public :
    debris(const position &pos);
    virtual char signe()const;
    virtual void deplace()override;

private:

};

#endif // DEBRIS_H_INCLUDED
