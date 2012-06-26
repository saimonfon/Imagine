#ifndef REGLE_CYCLE_H
#define REGLE_CYCLE_H
#include <stack>
#include "RegleGraphe.h"
/** Règle décrivant un cycle d'éléments tels que deux éléments consécutifs (ainsi que le premier et le dernier, puisqu'il s'agit d'un cycle) vérifient un ensemble de conditions.*/
class RegleCycle : public RegleGraphe
{
	public :
	/** Constructeur
	@param nom Le nom du non-terminal résultant de l'application de la règle.
	@param type Le type de non-terminal répété, i.e. apparaissant en partie droite de la règle.
	*/
	RegleCycle(string nom,string type);
	/** Renvoie les noeuds créés à partir du graphe dont les noeuds sont les noeuds de la forêt et une arête est présente si la relation est vérifiée par deux noeuds.
	* Dans le cas d'un cycle, cela revient à chercher les cycles élémentaires du graphe.
	*@return L'ensemble des affectations possibles.*/
	vector<Noeud*> noeudsFromGraphe();
	private :
	int s;
	stack<int> marked_stack; 
	Noeud** noeudsParNum;
	vector<Noeud*> res;
stack<int> point_stack;
bool* mark;
bool backtrack(int v);
map<int,set<int> > succ_num;
};
#endif