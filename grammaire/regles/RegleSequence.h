#ifndef REGLE_SEQ_H
#define REGLE_SEQ_H
#include "RegleGraphe.h"

class RegleSequence : public RegleGraphe
{
	public :
	RegleSequence(string nom,string type);
	vector<Noeud*> noeudsFromGraphe();
};
#endif