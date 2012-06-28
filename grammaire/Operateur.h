#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "MembreDroit.h"
#include <string>
#include "condition/ConditionUnique.h"
#include "condition/ConditionAdj.h"
#include "condition/ConditionEgal.h"
#include "condition/ConditionGenerale.h"
#include "regles/CalculAttributs.h"
class Polygone;
class Operateur : public MembreDroit
{
	public :
	/** Initialise l'opérateur.
@param nom Le nom de l'élément répété.*/
	void init(string nom, string name);
	set<Noeud*> getAffectations(Parser* p,Noeud** affectation, int N);
	/** La fonction spécifique (cycle, séquence...) : retourne les noeuds à partir du graphe de successeurs possibles */
	virtual set<Noeud*> noeudsFromGraphe()=0;
	/** Le parser correspondant à l'état courant.*/
	Parser * p;
	/** L'affectation partielle courante.*/
	Noeud** affectation;
	/** Le nom de l'élément répété.*/
	string nom;
	string name;

	/** Les conditions portant sur le membre droit (par exemple, chaque marche doit mesurer plus de 30 cm).*/
	vector<ConditionUnique*> conditions;
	/** Les conditions d'adjacence entre attributs de deux éléments consécutifs. */
	vector<ConditionAdj*> condAdj;
	/** Les conditions d'égalité entre attributs de deux éléments consécutifs. */
	vector<ConditionEgal*> condEgal;
	/** Les conditions générales sur deux éléments consécutifs */
	vector<ConditionGenerale*> condGen;
	
	set<Noeud*> dejaTraites;
	map<Noeud*,set<Noeud*> > succ;
	map<ConditionAdj*,map<Polygone*,set<Noeud*> > > table_adj_i;
	map<ConditionAdj*,map<Polygone*,set<Noeud*> > > table_adj_j;
	
	//Le void* dans la map peut poser des problèmes (égalité entre pointeurs au lieu d'égalité entre valeurs)
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_i;
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_j;
	
	/** Conditions d'adjacence entre chaque élément de l'opérateur et un élément externe de la même règle.*/
	vector<ConditionAdj*> condAdjExt;

	CalculAttributs* calculAtt;
};
#endif