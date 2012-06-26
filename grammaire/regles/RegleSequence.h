#ifndef REGLE_SEQ_H
#define REGLE_SEQ_H
#include "RegleGraphe.h"
/** R�gle d�crivant une s�quence d'�l�ments du m�me type telle que deux �l�ments cons�cutifs v�rifient un ensemble de conditions.*/
class RegleSequence : public RegleGraphe
{
	public :
	RegleSequence(string nom,string type);
	/** Retourne l'ensemble des s�quences maximales possibles. Cela revient � chercher les chemins maximaux du graphe.*/
	vector<Noeud*> noeudsFromGraphe();
};
#endif