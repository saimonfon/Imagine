#ifndef REGLE_H
#define REGLE_H
#include "../parsing/Noeud.h"
#include <Map>
#include <Vector>
#include "CalculAttributs.h"
class Parser;
/** Cette classe abstraite définit une règle de la grammaire. */
class Regle
{
	public:
	/** Applique la règle à l'état courant du parser passé en paramètre.
	@param p Le parser décrivant l'état courant du système.
	@return La liste des noeuds résultant de l'application de la règle.*/
	virtual vector<Noeud*> appliquer(Parser* p)=0;
	/** Objet décrivant un calcul personnalisé par l'utilisateur des attributs des noeuds nouvellement créés.*/
	CalculAttributs* calculAtt;
};
#endif