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
	//cout<<"Vérfiication de la contriante mur fenetre"<<endl;
	Noeud* mur = enfants[0];
	Noeud* rebord = enfants[1]->getEnfants()[1];
	vector<Noeud*> rebords = rebord->getEnfants();
	for(vector<Noeud*>::iterator it = rebords.begin();it!=rebords.end();++it)
	{
		if(p->adj[(Polygone*) (mur->getAttribut("primitive"))].count((Polygone*) ((*it)->getAttribut("primitive")))==0) //si un des rebords n'est pas adjacent au mur
			return false;
	}
	//cout<<"FIN Vérfiication de la contriante mur fenetre"<<endl;
	return true;
}
};