#include "terrain.h"

terrain::terrain(int longueur, int hauteur):d_longueur{longueur},d_hauteur{hauteur},d_element{}
{

}


vector<vector<char>> terrain::terrainInit()
{
    vector<vector<char>> terrainChar(d_hauteur, vector<char> (d_longueur, '.'));
    return terrainChar;

}

vector<vector<char>> terrain::terrainAvecElem()
{
    vector<vector<char>> terrainChar = terrainInit();
    for(unsigned int i=0;i<d_element.size();i++)
    {
        terrainChar[d_element[i]->pos().y()][d_element[i]->pos().x()]=d_element[i]->signe();
    }
    return terrainChar;
}

void terrain::ajouteElement(Element *elem)
{
    d_element.push_back(elem);
}
int terrain::longueur()const
{
    return d_longueur;
}

int terrain::hauteur()const
{
    return d_hauteur;
}


void terrain::affiche(std::ostream &ost, const vector<vector<char>> &terrainCaract)const
{
    for(unsigned int  i=0; i<terrainCaract.size();++i)
    {
        for(unsigned int j=0;j<terrainCaract[i].size();++j)
        {
            ost<<terrainCaract[i][j]<<' ';
        }
        ost<<"\n"<<"\n";
    }
}

ostream& operator<<(ostream& os,terrain &t)
{
    t.affiche(os,t.terrainAvecElem());
    return os;
}

void terrain::sauver(const std::string &nomFichier)
{
    ofstream fichier(nomFichier+".txt");
    fichier<<d_longueur<<"\n"<<d_hauteur<<"\n";
    fichier<<d_element.size()<<"\n";
    for(unsigned int i=0;i<d_element.size();++i)
    {
        fichier<<d_element[i]->signe()<<" "<<d_element[i]->pos().x()<<" "<<d_element[i]->pos().y()<<" ";
    }
}

void terrain::charger(const std::string &nomFichier,joueur &leJoueur)
{
    std::ifstream fichier(nomFichier+".txt");
    int longueur,hauteur,x,y,tailleTableau;
    char signe;
    d_element.clear();
    fichier>>longueur>>hauteur>>tailleTableau;
    d_longueur=longueur;
    d_hauteur=hauteur;
    fichier>>signe>>x>>y;
    leJoueur=joueur({x,y});
    ajouteElement(&leJoueur);
    Element *e;
    for(int i = 1;i<tailleTableau;++i)
    {
                fichier>>signe>>x>>y;
                position posCase=position(x,y);
                switch(signe)
                    {
                        case SIGNE_ROBOT1G : e=new robot1G(posCase,&leJoueur);break;
                        case SIGNE_ROBOT2G : e=new robot2G(posCase,&leJoueur);break;
                        case SIGNE_DEBRIS : e=new debris(posCase);break;

                    }
                ajouteElement(e);
    }
}

int terrain::nbElements()const
{
    return d_element.size();
}

vector<Element*> terrain::listeElements()const
{
    return d_element;
}

void terrain::miseAJour(bool& joueurEstVivant)
{
    for(unsigned int i=0;i<d_element.size();++i)
    {
        for(unsigned int j=i+1;j<d_element.size();++j)
        {
            if(d_element[i]->collision(d_element[j]))
                switch(d_element[i]->signe())
            {
                case SIGNE_JOUEUR: joueurEstVivant=false ;break;
                case SIGNE_ROBOT1G:ajouteElement(new debris{d_element[i]->pos()});d_element.erase(d_element.begin()+i);break;
                case SIGNE_ROBOT2G:ajouteElement(new debris{d_element[i]->pos()});d_element.erase(d_element.begin()+i);break;
                case SIGNE_DEBRIS:break;


            }
        }
    }
}


