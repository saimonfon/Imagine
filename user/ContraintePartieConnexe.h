#ifndef CONTRAINTE_PARTIE_CONNEXE
#define CONTRAINTE_PARTIE_CONNEXE

#include "../grammaire/condition/ConditionGenerale.h"
#include "ContrainteAdjacenceExacte.h"
#include "../grammaire/parsing/Noeud.h"
#include <vector>
#include <iostream>

//contrainte d'adjacence entre un mur et une partie connexe

class ContraintePartieConnexe : public ConditionGenerale
{
public:
	bool estVerifiee(vector<Noeud*> enfants, Parser* p)
	{
		ContrainteAdjacenceExacte* ce = new ContrainteAdjacenceExacte();
		Noeud* premur = enfants[0];
		Noeud* partieConnexe = enfants[1];

		//les elements de elts sont des polygones
		vector<Noeud*> elts = partieConnexe->getEnfants();

		//on cree une carte des polygones adjacents
		set<Polygone*> adj;

		for(vector<Noeud*>::iterator it = elts.begin(); it != elts.end(); it++)
		{
			adj.insert(((*(*it))["primitive"])->polygoneValue());
			set<Polygone*> voisins  = p->adj[((*(*it))["primitive"])->polygoneValue()];
			for(set<Polygone*>::iterator itset=voisins.begin(); itset!=voisins.end(); itset++){
				adj.insert(*itset);
			}
		}

		//on supprime maintenant tous les elements qui sont dans la partie connexe
		for(vector<Noeud*>::iterator it = elts.begin(); it != elts.end(); it++)
		{
			adj.erase(((*(*it))["primitive"])->polygoneValue());
		}

		//normalement il ne reste que le mur
		if(adj.size()==1 ){
			if(adj.count((*(premur->getEnfants())[0])["primitive"]->polygoneValue())>0){
				return true;
			}
			return false;
		}else{
			return false;
		}

	}
};

#endif
