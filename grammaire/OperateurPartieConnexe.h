#ifndef OPERATEUR_PARTIE_CONNEXE_HEADER
#define OPERATEUR_PARTIE_CONNEXE_HEADER

#include "Operateur.h"

class OperateurPartieConnexe : public Operateur
{
public:
	OperateurPartieConnexe(string nom, string tempname);
	OperateurPartieConnexe(Operateur* enfant, string tempname);
	set<Noeud*> noeudsFromGraphe();
private:
	bool exclusivite(Noeud* n, vector<Noeud*> &nodes);
};

#endif
