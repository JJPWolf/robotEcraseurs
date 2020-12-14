#include "jeu.h"

using std::cout;
using std::cin;
using std::endl;

jeu::jeu(const terrain &t):d_score{0},d_terrain{t},d_leJoueur({d_terrain.longueur()/2,d_terrain.hauteur()/2})
{

}

char jeu::commandeJoueur()
{
    char choix;
    cout<<"Que souhaitez-vous faire ?"<<endl<<"z pour haut"<<endl<<"s pour bas"<<endl<<"q pour gauche"<<endl<<"d pour droite"<<endl<<"a pour haut-gauche"<<endl<<"e pour haut-droite"<<endl<<"w pour bas-gauche"<<endl<<"x pour bas-droite"<<endl;
    cin>>choix;
    while(!verifChoixJoueur(choix))
    {
        cout<<"Veuillez entrer une commande valide"<<endl;
        choix=commandeJoueur();
    }
    return choix;
}

bool jeu::verifChoixJoueur(char commande)
{
    return(commande=='z' ||commande== 's' ||commande== 'q' ||commande== 'd' ||commande== 'a' ||commande== 'e' ||commande== 'w' ||commande== 'x' );
}




void jeu::jouer()
{
    enoncerRegles();
    cout<<d_terrain;
    bool joueurEstVivant=true;
    while(joueurEstVivant)
    {
        for(unsigned int i=0;i<d_terrain.listeElements().size();++i)
        {
            d_terrain.listeElements()[i]->deplace();
        }
        d_terrain.miseAJour(joueurEstVivant);
        cout<<d_terrain;
        d_score+=500;

    }
    cout<<"PERDU ! \n";
    cout<<"Votre score est de "<<d_score;
}


void jeu::initDebris()
{
    srand (time(NULL));
    for(int i=1;i<d_terrain.hauteur()-1;++i)
    {
        debris *d=new debris({rand()%(d_terrain.longueur()-1) + 1,i});
        if(d->pos()!=d_leJoueur.pos())
        d_terrain.ajouteElement(d);
    }
}

void jeu::initRobots()
{
    robot2G *r21=new robot2G({0,0},&d_leJoueur);
    robot2G *r22=new robot2G({d_terrain.longueur()-1,0},&d_leJoueur);
    robot2G *r23=new robot2G({0,d_terrain.hauteur()-1},&d_leJoueur);
    robot2G *r24=new robot2G({d_terrain.longueur()-1,d_terrain.hauteur()-1},&d_leJoueur);

    robot1G *r11=new robot1G({d_terrain.longueur()/2,0},&d_leJoueur);
    robot1G *r12=new robot1G({0,d_terrain.hauteur()/2},&d_leJoueur);
    robot1G *r13=new robot1G({d_terrain.longueur()-1,d_terrain.hauteur()/2},&d_leJoueur);
    robot1G *r14=new robot1G({d_terrain.longueur()/2,d_terrain.hauteur()-1},&d_leJoueur);

    d_terrain.ajouteElement(r21);
    d_terrain.ajouteElement(r22);
    d_terrain.ajouteElement(r23);
    d_terrain.ajouteElement(r24);

    d_terrain.ajouteElement(r11);
    d_terrain.ajouteElement(r12);
    d_terrain.ajouteElement(r13);
    d_terrain.ajouteElement(r14);
}

void jeu::ajouteJoueur()
{
    d_terrain.ajouteElement(&d_leJoueur);
}

void jeu::ChoixMenuPrincipal(int& choice)
{
  do
  {
    cout<<"Menu Principal\n";
    cout<<"Voulez-vous :\n";
    cout<<"(1) Jouer au jeu\n";
    cout<<"(2) Sauvegarder le terrain\n";
    cout<<"(3) Charger un terrain\n";
    cout<<"(4) Quitter\n";
    cout<<"Votre choix : ";
    cin>>choice;
  }
  while (choice<1 || choice >4);
}

void jeu::MenuPrincipalLoop()
{
    int choice;
    ChoixMenuPrincipal(choice);
    switch (choice)
    {
      case 1: jouer();    break;
      case 2: d_terrain.sauver("sauvegarde");MenuPrincipalLoop(); break;
      case 3: d_terrain.charger("sauvegarde",d_leJoueur);MenuPrincipalLoop(); break;
      default : break;
    }
}


void jeu::run()
{
    d_terrain=terrain(d_terrain.longueur(),d_terrain.hauteur());
    ajouteJoueur();
    initRobots();
    initDebris();
    cout<<d_terrain;
    MenuPrincipalLoop();
}

void jeu::enoncerRegles()const
{
    cout<<"Bienvenue dans le jeu des robots ecraseurs : vous devez echapper aux robots et rester en vie le plus longtemps possible ! \nPour cela vous devez vous deplacer sur le terrain de façon a faire s'auto detruire les robots en provoquant leurs collisions entre eux ou avec des debris \nVous etes represente par un J sur le terrain \nLes robots de 1ere generation sont representes par un 1 : ils ne se deplacent qu'horizontalement et verticalement \nLes robots de 2eme generation sont representes par un 2 : ils se deplacent horizontalement, verticalement et en diagonale \nLes debris sont representes par un X \nVotre score tient compte du nombre de tours que vous avez passes, vous pouvez cependant gagner le jeu en detruisant tous les robots \nBon jeu ! \n\n";
}
