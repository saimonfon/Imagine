#ifndef REGLE_CYCLE_H
#define REGLE_CYCLE_H
#include <stack>
#include "RegleGraphe.h"
/** R�gle d�crivant un cycle d'�l�ments tels que deux �l�ments cons�cutifs (ainsi que le premier et le dernier, puisqu'il s'agit d'un cycle) v�rifient un ensemble de conditions.*/
class RegleCycle : public RegleGraphe
{
	public :
	/** Constructeur
	@param nom Le nom du non-terminal r�sultant de l'application de la r�gle.
	@param type Le type de non-terminal r�p�t�, i.e. apparaissant en partie droite de la r�gle.
	*/
	RegleCycle(string nom,string type);
	/** Renvoie les noeuds cr��s � partir du graphe dont les noeuds sont les noeuds de la for�t et une ar�te est pr�sente si la relation est v�rifi�e par deux noeuds.
	* Dans le cas d'un cycle, cela revient � chercher les cycles �l�mentaires du graphe.
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