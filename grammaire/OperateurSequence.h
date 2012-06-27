#ifndef OPERATEURSEQUENCE_H
#define OPERATEURSEQUENCE_H
#include "Operateur.h"
class OperateurSequence : public Operateur
{
public :
OperateurSequence(string nom);
set<Noeud*> noeudsFromGraphe();
};
#endif