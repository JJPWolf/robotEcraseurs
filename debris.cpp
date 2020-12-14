#include "debris.h"

debris::debris(const position &pos):Element{pos}
{

}

char debris::signe()const
{
    return SIGNE_DEBRIS;
}

void debris::deplace()
{
    return;
}

