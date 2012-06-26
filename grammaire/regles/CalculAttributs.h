#ifndef CALCUL_ATTRIBUTS_H
#define CALCUL_ATTRIBUTS_H
#include "../parsing/Noeud.h"
/** Classe virtuelle d�finissant un calcul customis� par l'utilisateur des attributs d'un noeud � partir de ceux de ses enfants. */
class CalculAttributs
{
	public:
	/** Calcule et modifie les attributs du noeud pass� en param�tre.
	@param nouveau Le noeud dont les attributs sont calcul�s.*/
	virtual void calculAttrib(Noeud* nouveau) = 0;
};
#endif