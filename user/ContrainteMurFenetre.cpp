#ifndef CONTRAINTE_MUR_FENETRE_H
#define CONTRAINTE_MUR_FENETRE_H
#include "../grammaire/condition/ConditionGenerale.h"
#include "../grammaire/parsing/Noeud.h"
#include <vector>
#include <iostream>
//La contrainte entre le mur et la fenetre (tout le rebord doit être adjacent au mur)
class ContrainteMurFenetre : public ConditionGenerale
{
public: 
bool estVerifiee(vector<Noeud*> enfants, Parser* p)
{
cout<<"On vérifie la contrainte mur fenetre"<<endl;
cout<<enfants[0]->nom_parser<<" "<<enfants[1]->nom_parser<<endl;
float* p1 = (float*) (enfants[0]->getAttribut("plan")->ptrValue());
float* p2 = (float*) (enfants[1]->getAttribut("plan")->ptrValue());
cout<<"Ok après récup de p1 et p2"<<endl;
float norm = 0;
for(int i=0;i<4;i++)
	norm+=(p1[i]-p2[i])*(p1[i]-p2[i]);
cout<<enfants[0]->nom_parser<<" "<<enfants[1]->nom_parser<<" : "<<norm<<endl;
return norm<1;
}
};
#endif