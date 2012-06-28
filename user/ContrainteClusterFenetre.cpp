#ifndef CONTRAINTE_CLUSTER_FENETRE_H
#define CONTRAINTE_CLUSTER_FENETRE_H
#include "../grammaire/condition/ConditionGenerale.h"
#include "../grammaire/parsing/Noeud.h"
#include "../geometrie/Vec3.h"
#include <vector>
#include <iostream>
//La contrainte pour que deux fenetres appartiennent au meme cluster : que leur "plan d'accroche" soit le même.
class ContrainteClusterFenetre : public ConditionGenerale
{
public: 
bool estVerifiee(vector<Noeud*> enfants, Parser* p)
{
	float* plan1 = (float*) (*enfants[0])["plan"];
	float* plan2 = (float*) (*enfants[1])["plan"];
	float norm = 0;
for(int i=0;i<4;i++)
	norm+=(plan1[i]-plan2[i])*(plan1[i]-plan2[i]);
	return norm<1;
}
};
#endif