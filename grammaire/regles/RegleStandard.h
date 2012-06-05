#ifndef REGLE_STAND_H
#define REGLE_STAND_H
#include "Regle.h"
#include "../condition/ConditionUnique.h"
#include "../condition/ConditionAdj.h"
#include "../condition/ConditionEgal.h"
#include "../condition/ConditionGenerale.h"
#include "../../geometrie/Polygone.h"
#include<set>
class Parser;
class RegleStandard : public Regle
{
	public : 
	RegleStandard(string nom, vector<string> membresDroits);
	vector<Noeud*> appliquer(Parser* p);
	void init();
	//private :
	Parser* p;
	string nom;
	vector<string> membresDroits;
	int N;
	/** Les conditions portant sur le membre droit (par exemple, chaque marche doit mesurer plus de 30 cm).*/
	vector<ConditionUnique*> condUnique;
	/** Les conditions d'adjacence entre attributs de deux éléments consécutifs. */
	vector<ConditionAdj*> condAdj;
	/** Les conditions d'égalité entre attributs de deux éléments consécutifs. */
	vector<ConditionEgal*> condEgal;
	/** Les conditions générales (à vérifier sur une affectation complète. */
	vector<ConditionGenerale*> condGen;
	/**L'ordre dans lequel les variables doivent être affectées (de la plus contrainte à la moins contrainte) */
	int* order;
	
	map<ConditionAdj*,map<Polygone*,set<Noeud*> > > table_adj_i;
	map<ConditionAdj*,map<Polygone*,set<Noeud*> > > table_adj_j;
	
	//Le void* dans la map peut poser des problèmes (égalité entre pointeurs au lieu d'égalité entre valeurs)
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_i;
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_j;
	/*Domaine des variables */
	set<Noeud*>* domaines;
	int* nb_contraintes;
	vector<Noeud*> resultat;
	void solveCSP(Noeud** affectPart, int curInd, vector<set<Noeud*> > domaines);
};
#endif