#include "condition/ConditionGenerale.h"
#include "parsing/Noeud.h"
#include <vector>
#include <iostream>
//La contrainte pour une fenetre complete (tout le rebord doit etre adjacent à la fenetre)
class ContrainteFenetreComplete : public ConditionGenerale
{
public: 
bool estVerifiee(vector<Noeud*> enfants, Parser* p)
{
	//cout<<"Vérfiication de la contriante rebordvrerve fenetre"<<p<<endl;
	//cout<<"Taille des enfants "<<enfants.size()<<endl;
	Noeud* fenetre = enfants[0];
	Noeud* rebord = enfants[1];
	//cout<<"Ok ciic"<<endl;
	vector<Noeud*> rebords = rebord->getEnfants();
	//cout<<rebords.size()<<endl;
	for(vector<Noeud*>::iterator it = rebords.begin();it!=rebords.end();it++)
	{
		//cout<<"Ok au début de l'itération"<<endl;
		if(p->adj[(Polygone*) (fenetre->getAttribut("primitive"))].count((Polygone*) ((*it)->getAttribut("primitive")))==0) //si un des rebords n'est pas adjacent à la fenetre
			return false;
	}
	//cout<<"FIN Vérfiication de la contriante rebord fenetre"<<endl;
	return true;
}
};