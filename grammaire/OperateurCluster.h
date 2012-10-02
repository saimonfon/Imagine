#ifndef OPERATEURCLUSTER_H
#define OPERATEURCLUSTER_H
#include "Operateur.h"
class OperateurCluster : public Operateur
{
public:
OperateurCluster(string nom, string tempname);
OperateurCluster(Operateur* enfant, string tempname);
set<Noeud*> noeudsFromGraphe();
};
#endif