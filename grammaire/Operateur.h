#ifndef OPERATEUR_H
#define OPERATEUR_H
#include "MembreDroit.h"
#include <string>
#include "condition/ConditionUnique.h"
#include "condition/ConditionAdj.h"
#include "condition/ConditionAdj_Ext.h"
#include "condition/ConditionAdj_Int.h"
#include "condition/ConditionEgal.h"
#include "condition/ConditionGenerale.h"
#include "regles/CalculAttributs.h"
class Polygone;
typedef set<Noeud*> setNoeud;
class Operateur : public MembreDroit
{
	public :
	/** Initialise l'op�rateur.
@param nom Le nom de l'�l�ment r�p�t�.*/
	void init(string nom, string name);
	set<Noeud*> getAffectations(Parser* p,Noeud** affectation, int N);
	/** La fonction sp�cifique (cycle, s�quence...) : retourne les noeuds � partir du graphe de successeurs possibles */
	virtual set<Noeud*> noeudsFromGraphe()=0;
	/** Le parser correspondant � l'�tat courant.*/
	Parser * p;
	/** L'affectation partielle courante.*/
	Noeud** affectation;
	/** Le nom de l'�l�ment r�p�t�.*/
	string nom;
	string name;

	/** Les conditions portant sur le membre droit (par exemple, chaque marche doit mesurer plus de 30 cm).*/
	vector<ConditionUnique*> condUnique;
	/** Les conditions d'adjacence entre attributs de deux �l�ments cons�cutifs. */
	vector<ConditionAdj*> condAdj;
	vector<ConditionAdj_Ext*> condAdj_ext;
	vector<ConditionAdj_Int*> condAdj_int;

	/** Les conditions d'�galit� entre attributs de deux �l�ments cons�cutifs. */
	vector<ConditionEgal*> condEgal;
	/** Les conditions g�n�rales sur deux �l�ments cons�cutifs */
	vector<ConditionGenerale*> condGen;
	
	set<Noeud*> dejaTraites;
	map<Noeud*,set<Noeud*> > succ;
	map<ConditionAdj*,map<Polygone*,set<Noeud*> > > table_adj_i;
	map<ConditionAdj*,map<Polygone*,set<Noeud*> > > table_adj_j;
	map<ConditionAdj_Ext*,map<Polygone*,set<Noeud*> > > table_adj_ext_i;
	map<ConditionAdj_Ext*,map<Polygone*,set<Noeud*> > > table_adj_ext_j;
	map<ConditionAdj_Int*,map<Polygone*,set<Noeud*> > > table_adj_int_i;
	map<ConditionAdj_Int*,map<Polygone*,set<Noeud*> > > table_adj_int_j;
	
	//Le void* dans la map peut poser des probl�mes (�galit� entre pointeurs au lieu d'�galit� entre valeurs)
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_i;
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_j;
	
	/** Conditions d'adjacence entre chaque �l�ment de l'op�rateur et un �l�ment externe de la m�me r�gle.*/
	vector<ConditionAdj*> condAdjExt;

	CalculAttributs* calculAtt;
};
#endif
