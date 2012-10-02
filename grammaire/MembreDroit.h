#ifndef MEMBREDROIT_H
#define MEMBREDROIT_H
#include <set>
#include <string>
class Parser;
class Regle;
class Noeud;
using namespace std;
class MembreDroit
{
public :
	/** Renvoie les affectations possibles (un sur-ensemble des affectations réelles) étant donné l'état courant et une affectation partielle des autres membres droits de la règle.
	*@param p Le parser décrivant l'état courant.
	*@param affectation L'affectation partielle des autres membres droits de la règle (NULL si le membre n'est pas encore affecté).
	*@return Les noeuds candidats.
	*/
	virtual set<Noeud*> getAffectations(Parser* p,Noeud** affectation, int N) = 0;
	/** Règle à laquelle appartient le membre droit.*/
	Regle* parent;
	/** Position du membre droit dans la règle à laquelle il appartient.*/
	int position;
	/** Initialise le membre droit.
	@param parent La règle à laquelle appartient le membre droit.
	@param position Losition du membre droit dans la règle parent.
	*/
	string name;
	virtual void init (Regle* parent, int position);
};
#endif