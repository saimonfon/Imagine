#ifndef CALCULATTFCREEL_H
#define CALCULATTFCREEL_H
#include "../grammaire/regles/CalculAttributs.h"
#include "../geometrie/Polygone.h"
#include "../grammaire/attributs/Attribut.h"
class CalculAttFenetreCompleteReel : public CalculAttributs
{
//Trouver le plan d'accroche au mur
void calculAttrib(Noeud* nouveau){
cout<<"Début du calcul des attributs"<<endl;
cout<<"Taille de eefenfants"<<nouveau->getEnfants().size()<<endl;
cout<<nouveau->getEnfants()[0]->nom_parser<<endl;
cout<<(*(nouveau->getEnfants()[0]))["primitive"]<<endl;
Polygone* f = (nouveau->getEnfants()[0])->getAttribut("primitive")->polygoneValue();
cout<<"Ok fenetre"<<endl;
Noeud* rebord = nouveau->getEnfants()[1];
//Prendre deux rebords opposés.
cout<<"Taille de rebord :"<<rebord->getEnfants().size()<<endl;
Polygone* r1 = (rebord->getEnfants()[0])->getAttribut("primitive")->polygoneValue();
nouveau->setAttribut("primitive",new AttributPoly(r1));
return;
}
};
#endif