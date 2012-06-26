#ifndef CONTRAINTE_ADJACENCE_EXACTE
#define CONTRAINTE_ADJACENCE_EXACTE
#include "condition/ConditionGenerale.h"
#include "parsing/Noeud.h"
#include <vector>
#include <iostream>
//La contrainte pour une fenetre adjacence exacte (�galit� des sommets)
class ContrainteAdjacenceExacte : public ConditionGenerale
{
public: 
bool estVerifiee(vector<Noeud*> enfants, Parser* p)
{
	Polygone* p1 = (Polygone*) (*enfants[0])["primitive"];
	Polygone* p2 = (Polygone*) (*enfants[1])["primitive"];
		//S'ils ont une ar�te en commun c'est bon.
		for(int k=0;k<p1->size();k++)
			for(int l=0;l<p2->size();l++)
			{
				Vec3 a = (*p1)[k];
				Vec3 b = (*p1)[(k+1)%p1->size()];
				Vec3 c = (*p2)[l];
				Vec3 d = (*p2)[(l+1)%p2->size()];
				if(((a-c).norm()<0.1 && (b-d).norm()<0.1)||((a-d).norm()<0.1&&(b-c).norm()<0.1))
				{
					return true;
				}
			}
	return false;
}
};
#endif