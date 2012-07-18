#include "../grammaire/condition/ConditionGenerale.h"
#include "../grammaire/parsing/Noeud.h"
#include "../grammaire/Parser.h"
#include <vector>
#include <iostream>
//La contrainte pour une fenetre adjacence exacte (égalité des sommets)
class ContrainteOrtho : public ConditionGenerale
{
public: 
bool estVerifiee(vector<Noeud*> enfants, Parser* p)
{
	Polygone* p1 = (*enfants[0])["primitive"]->polygoneValue();
	Polygone* p2 = (*enfants[1])["primitive"]->polygoneValue();
	Vec3 n1(p1->equation[0],p1->equation[1],p1->equation[2]);
	Vec3 n2(p2->equation[0],p2->equation[1],p2->equation[2]);
	return n1*n2<0.1;
}
};