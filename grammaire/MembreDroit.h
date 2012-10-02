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
	/** Renvoie les affectations possibles (un sur-ensemble des affectations r�elles) �tant donn� l'�tat courant et une affectation partielle des autres membres droits de la r�gle.
	*@param p Le parser d�crivant l'�tat courant.
	*@param affectation L'affectation partielle des autres membres droits de la r�gle (NULL si le membre n'est pas encore affect�).
	*@return Les noeuds candidats.
	*/
	virtual set<Noeud*> getAffectations(Parser* p,Noeud** affectation, int N) = 0;
	/** R�gle � laquelle appartient le membre droit.*/
	Regle* parent;
	/** Position du membre droit dans la r�gle � laquelle il appartient.*/
	int position;
	/** Initialise le membre droit.
	@param parent La r�gle � laquelle appartient le membre droit.
	@param position Losition du membre droit dans la r�gle parent.
	*/
	string name;
	virtual void init (Regle* parent, int position);
};
#endif