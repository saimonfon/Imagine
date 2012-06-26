#ifndef REGLE_SEQ_H
#define REGLE_SEQ_H
#include "RegleGraphe.h"
/** Règle décrivant une séquence d'éléments du même type telle que deux éléments consécutifs vérifient un ensemble de conditions.*/
class RegleSequence : public RegleGraphe
{
	public :
	RegleSequence(string nom,string type);
	/** Retourne l'ensemble des séquences maximales possibles. Cela revient à chercher les chemins maximaux du graphe.*/
	vector<Noeud*> noeudsFromGraphe();
};
#endif