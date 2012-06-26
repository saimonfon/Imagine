#ifndef CONTRAINTE_MUR_FENETRE_H
#define CONTRAINTE_MUR_FENETRE_H
#include "condition/ConditionGenerale.h"
#include "parsing/Noeud.h"
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
float* p1 = (float*)(*(enfants[0]))["plan"];
float* p2 = (float*)(*(enfants[1]))["plan"];
cout<<"Ok après récup de p1 et p2"<<endl;
float norm = 0;
for(int i=0;i<4;i++)
	norm+=(p1[i]-p2[i])*(p1[i]-p2[i]);
cout<<enfants[0]->nom_parser<<" "<<enfants[1]->nom_parser<<" : "<<norm<<endl;
return norm<1;
/*	//cout<<"Vérfiication de la contriante mur fenetre"<<endl;
	Noeud* mur = enfants[0];
	Noeud* rebord = enfants[1]->getEnfants()[1];
	vector<Noeud*> rebords = rebord->getEnfants();
	for(vector<Noeud*>::iterator it = rebords.begin();it!=rebords.end();++it)
	{
		if(p->adj[(Polygone*) (mur->getAttribut("primitive"))].count((Polygone*) ((*it)->getAttribut("primitive")))==0) //si un des rebords n'est pas adjacent au mur
			return false;
	}
	//cout<<"FIN Vérfiication de la contriante mur fenetre"<<endl;
	return true;*/
}
};
#endif