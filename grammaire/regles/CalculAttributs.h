#ifndef CALCUL_ATTRIBUTS_H
#define CALCUL_ATTRIBUTS_H
#include "../parsing/Noeud.h"
/** Classe virtuelle définissant un calcul customisé par l'utilisateur des attributs d'un noeud à partir de ceux de ses enfants. */
class CalculAttributs
{
	public:
	/** Calcule et modifie les attributs du noeud passé en paramètre.
	@param nouveau Le noeud dont les attributs sont calculés.*/
	virtual void calculAttrib(Noeud* nouveau) = 0;
};
#endif