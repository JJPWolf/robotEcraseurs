#include <iostream>
#include "terrain.h"
#include "debris.h"
#include "Personnage.h"
#include "joueur.h"
#include "robot1G.h"
#include "position.h"

#include "jeu.h"
#include <fstream>

using namespace std;

int choixLongueur()
{
    int choix;
    cout<<"Choisissez la longueur du terrain : ";
    cin>>choix;
    return choix;
}

int choixHauteur()
{
    int choix;
    cout<<"Choisissez la longueur du terrain : ";
    cin>>choix;
    return choix;
}

int main()
{
    terrain t=terrain(choixLongueur(),choixHauteur());
    jeu j=jeu(t);
    j.run();
    return 0;
}


