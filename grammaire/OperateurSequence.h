#ifndef OPERATEURSEQUENCE_H
#define OPERATEURSEQUENCE_H
#include "Operateur.h"
class OperateurSequence : public Operateur
{
public :
OperateurSequence(string nom, string tempname);
set<Noeud*> noeudsFromGraphe();
};
#endif