#ifndef REGLE_GRAPHE
#define REGLE_GRAPHE
#include "../Parser.h"
#include "../condition/ConditionUnique.h"
#include "../condition/ConditionAdj.h"
#include "../condition/ConditionEgal.h"
#include "../condition/ConditionGenerale.h"
/** Classe abstraite décrivant une règle (cycle, séquence, ensemble) d'éléments du même type répétés dont le calcul passe par la construction du graphe
dont les noeuds sont les noeuds de la forêt du type répété et une arête relie deux noeuds si une certaine relation est vérifiée par ceux-ci.*/
class RegleGraphe : public Regle
{
public :
	void construct(string nom, string type);
	vector<Noeud*> appliquer(Parser* p);
	void init();
	/** Les conditions portant sur le membre droit (par exemple, chaque marche doit mesurer plus de 30 cm).*/
	vector<ConditionUnique*> conditions;
	/** Les conditions d'adjacence entre attributs de deux éléments consécutifs. */
	vector<ConditionAdj*> condAdj;
	/** Les conditions d'égalité entre attributs de deux éléments consécutifs. */
	vector<ConditionEgal*> condEgal;
	/** Les conditions générales sur deux éléments consécutifs */
	vector<ConditionGenerale*> condGen;
	/** La fonction spécifique (cycle, séquence...) : retourne les noeuds à partir du graphe de successeurs possibles */
	virtual vector<Noeud*> noeudsFromGraphe()=0;
protected :
	string type;
	string nom;
	Parser* parser;
	set<Noeud*> dejaTraites;
	map<Noeud*,set<Noeud*> > succ;
	map<ConditionAdj*,map<Polygone*,set<Noeud*> > > table_adj_i;
	map<ConditionAdj*,map<Polygone*,set<Noeud*> > > table_adj_j;
	
	//Le void* dans la map peut poser des problèmes (égalité entre pointeurs au lieu d'égalité entre valeurs)
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_i;
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_j;
};
#endif