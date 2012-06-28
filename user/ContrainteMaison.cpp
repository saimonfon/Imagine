#include "../grammaire/condition/ConditionGenerale.h"
#include "../grammaire/parsing/Noeud.h"
#include "../grammaire/Parser.h"
#include <vector>
#include <map>
#include <iostream>
//La contrainte pour une fenetre adjacence exacte (égalité des sommets)
class ContrainteMaison : public ConditionGenerale
{
public: 
bool estVerifiee(vector<Noeud*> enfants, Parser* p)
{
	Noeud* m = enfants[0];
	Noeud* t = enfants[1];
	Noeud* s = enfants[2];
	/*Chaque mur doit etre adjacent au sol*/
	vector<Noeud*> murs = m->getEnfants();
	for(vector<Noeud*>::iterator it = murs.begin();it!=murs.end();it++)
	{
		if(p->adj[(Polygone*) (s->getAttribut("primitive"))].count((Polygone*) ((*it)->getAttribut("primitive")))==0) //si un des mur n'est pas adjacent au sol
			return false;
	}
	//Gérer le toit ici
	vector<Noeud*> toits = t->getEnfants();
	int nm=murs.size(),nt=toits.size();
	bool* toitOK = new bool[nt];
	for(int i=0;i<nt;i++)
		toitOK[i]=false;
	for(int i=0;i<nm;i++)
	{
		bool murOK = false;
		for(int j=0;j<nt;j++)
		{
			if(p->adj[(Polygone*) (toits[j]->getAttribut("primitive"))].count((Polygone*) (murs[i]->getAttribut("primitive")))>0)
			{
				toitOK[j]=true;
				murOK = true;
			}
		}
		if(!murOK)
			return false;
	}
	
	for(int i=0;i<nt;i++)
		if(!toitOK[i]) //si un toit n'est adjacent à aucun mur
			return false;
	return true;
}
};