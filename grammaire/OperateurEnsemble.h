#ifndef OPERATEURENSEMBLE_H
#define OPERATEURENSEMBLE_H
#include "Operateur.h"
class OperateurEnsemble : public Operateur
{
public:
OperateurEnsemble(string nom, string tempname);
set<Noeud*> noeudsFromGraphe();
private :
void bk_recursive(setNoeud combination, setNoeud intersection, setNoeud possible, vector<setNoeud>* res);
};
#endif