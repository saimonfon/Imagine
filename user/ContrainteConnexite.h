#ifndef CONTRAINTE_CONNEXITE_HEADER
#define CONTRAINTE_CONNEXITE_HEADER

#include "../grammaire/condition/ConditionGenerale.h"
#include "ContrainteAdjacenceExacte.cpp"
#include "../grammaire/parsing/Noeud.h"
#include <vector>
#include <iostream>

//la contrainte de connexite pour un ensemble de primitive (les primitives doivent former une composante connexe)

class ContrainteConnexite : public ConditionGenerale
{
public:
	bool estVerifiee(vector<Noeud*> enfants, Parser* p)
	{
		ContrainteAdjacenceExacte* ce = new ContrainteAdjacenceExacte();
		Noeud* ensemble = enfants[0];
		vector<Noeud*> elements = ensemble->getEnfants();

		if(elements.size()==0){return false;}
		if(elements.size()==1){return true;}

		vector<bool> used(elements.size());
		for(int i=0;i<used.size(); i++){used[i] = false;}

		map<Polygone*, int> position_polygone;
		for(int i=0; i<elements.size(); i++){
			position_polygone[((*elements[i])["primitive"])->polygoneValue()] = i;
		}

		vector<int> aVoir;
		aVoir.push_back(0);
		while(!aVoir.empty()){
			int current = aVoir.back();
			aVoir.pop_back();
			used[current] = true;
			Noeud* currentNode = elements[current];
			for(set<Polygone*>::iterator it=p->adj[(*currentNode)["primitive"]->polygoneValue()].begin();
					it != p->adj[(*currentNode)["primitive"]->polygoneValue()].end(); it++){
				if(position_polygone.find(*it) != position_polygone.end()){
					int new_pos = position_polygone[*it];
					if(! used[new_pos]){
						aVoir.push_back(new_pos);
					}
				}
			}
		}

		bool test = true;
		for(int i=0; i<used.size(); i++){
			test = test && used[i];
		}

		if(test){
			return true;
		}else{
			return false;
		}

	}
};


#endif
