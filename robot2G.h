#ifndef ROBOT2G_H_INCLUDED
#define ROBOT2G_H_INCLUDED
#include "robot1G.h"
class robot2G : public robot1G {

public :
    robot2G(const position &pos,joueur *joueurAElimine);
    virtual char signe()const override;
    virtual void deplace()override;
private:

};

#endif // ROBOT2G_H_INCLUDED
