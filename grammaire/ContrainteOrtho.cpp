#include "condition/ConditionGenerale.h"
#include "parsing/Noeud.h"
#include <vector>
#include <iostream>
//La contrainte pour une fenetre adjacence exacte (égalité des sommets)
class ContrainteOrtho : public ConditionGenerale
{
public: 
bool estVerifiee(vector<Noeud*> enfants, Parser* p)
{
	Polygone* p1 = (Polygone*) (*enfants[0])["primitive"];
	Polygone* p2 = (Polygone*) (*enfants[1])["primitive"];
	Vec3 n1(p1->equation[0],p1->equation[1],p1->equation[2]);
	Vec3 n2(p2->equation[0],p2->equation[1],p2->equation[2]);
	return n1*n2<0.1;
}
};