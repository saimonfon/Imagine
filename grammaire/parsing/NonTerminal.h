#ifndef NONTERMINAL_H
#define NONTERMINAL_H
#include "Noeud.h"
#include <map>
using namespace std;
/** Classe décrivant un non-terminal reconnu.*/
class NonTerminal : public Noeud
{
	public :
	/** Constructeur.
	@param type Le type du noeud.
	@param enfants La liste des enfants du noeud.*/
	NonTerminal(string type, vector<Noeud*> enfants);
	vector<Noeud*> getEnfants() const;
	string getType() const;
	bool equals(const Noeud* n2) const;
	private :
	string type;
};
#endif
