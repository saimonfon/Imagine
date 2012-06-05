#ifndef REGLE_GRAPHE
#define REGLE_GRAPHE
#include "../Parser.h"
#include "../condition/ConditionUnique.h"
#include "../condition/ConditionAdj.h"
#include "../condition/ConditionEgal.h"
#include "../condition/ConditionGenerale.h"
class RegleGraphe : public Regle
{
public :
	void construct(string nom, string type);
	vector<Noeud*> appliquer(Parser* p);
	void init();
	/** Les conditions portant sur le membre droit (par exemple, chaque marche doit mesurer plus de 30 cm).*/
	vector<ConditionUnique*> conditions;
	/** Les conditions d'adjacence entre attributs de deux �l�ments cons�cutifs. */
	vector<ConditionAdj*> condAdj;
	/** Les conditions d'�galit� entre attributs de deux �l�ments cons�cutifs. */
	vector<ConditionEgal*> condEgal;
	/** Les conditions g�n�rales sur deux �l�ments cons�cutifs */
	vector<ConditionGenerale*> condGen;
	/** La fonction sp�cifique (cycle, s�quence...) : retourne les noeuds � partir du graphe de successeurs possibles */
	virtual vector<Noeud*> noeudsFromGraphe()=0;
protected :
	string type;
	string nom;
	set<Noeud*> dejaTraites;
	map<Noeud*,set<Noeud*> > succ;
	map<ConditionAdj*,map<Polygone*,set<Noeud*> > > table_adj_i;
	map<ConditionAdj*,map<Polygone*,set<Noeud*> > > table_adj_j;
	
	//Le void* dans la map peut poser des probl�mes (�galit� entre pointeurs au lieu d'�galit� entre valeurs)
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_i;
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_j;
};
#endif