#include "condition/ConditionGenerale.h"
#include "parsing/Noeud.h"
#include <vector>
#include <iostream>
//La contrainte pour une fenetre adjacence exacte (égalité des sommets)
class ContrainteAdjacenceExacte : public ConditionGenerale
{
public: 
bool estVerifiee(vector<Noeud*> enfants, Parser* p)
{
	Polygone* p1 = (Polygone*) enfants[0]->getAttribut("primitive");
	Polygone* p2 = (Polygone*) enfants[1]->getAttribut("primitive");
		//S'ils ont une arête en commun c'est bon.
		for(int k=0;k<p1->points3D.size();k++)
			for(int l=0;l<p2->points3D.size();l++)
			{
				Vec3 a = p1->points3D[k];
				Vec3 b = p1->points3D[(k+1)%p1->points3D.size()];
				Vec3 c = p2->points3D[l];
				Vec3 d = p2->points3D[(l+1)%p2->points3D.size()];
				if(((a-c).norm()<0.1 && (b-d).norm()<0.1)||((a-d).norm()<0.1&&(b-c).norm()<0.1))
				{
					return true;
				}
			}
	return false;
}
};