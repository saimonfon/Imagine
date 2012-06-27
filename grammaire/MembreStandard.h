#ifndef MEMBRESTANDARD_H
#define MEMBRESTANDARD_H
#include "MembreDroit.h"
#include <string>
/** Membre droit standard, correspondant à un terminal ou un non-terminal.*/
class MembreStandard : public MembreDroit
{
public :
MembreStandard(string nom);
set<Noeud*> getAffectations(Parser* p,Noeud** affectation, int N);
private :
/** Le nom du terminal ou du non-terminal correspondant. */
string nom;
};
#endif