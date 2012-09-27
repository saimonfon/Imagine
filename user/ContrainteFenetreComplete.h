#ifndef CONTRAINTE_FENETRE_COMPLETE_H
#define CONTRAINTE_FENETRE_COMPLETE_H
#include "../grammaire/condition/ConditionGenerale.h"
#include "ContrainteAdjacenceExacte.h"
#include "../grammaire/parsing/Noeud.h"
#include <vector>
#include <iostream>
//La contrainte pour une fenetre complete (tout le rebord doit etre adjacent � la fenetre)
class ContrainteFenetreComplete : public ConditionGenerale
{
public: 
bool estVerifiee(vector<Noeud*> enfants, Parser* p)
{
	ContrainteAdjacenceExacte* ce = new ContrainteAdjacenceExacte(); //DEGUEULASSE
	//cout<<"Verifs condition fenetre complete"<<endl;
	Noeud* fenetre = enfants[0];
	Noeud* rebord = enfants[1];
	vector<Noeud*> rebords = rebord->getEnfants();
	for(vector<Noeud*>::iterator it = rebords.begin();it!=rebords.end();it++)
	{
		if(p->adj[((*fenetre)["primitive"])->polygoneValue()].count(((*(*it))["primitive"])->polygoneValue())==0) //si un des rebords n'est pas adjacent � la fenetre
			return false;
		vector<Noeud*> v;
		v.push_back(rebord);
		v.push_back(fenetre);
		if(!ce->estVerifiee(v,p))
			return false;
	}
	//cout<<"OK condition fenetre complete"<<endl;
	return true;
}
};
#endif
