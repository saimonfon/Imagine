#ifndef REGLE_H
#define REGLE_H
#include "../parsing/Noeud.h"
#include <Map>
#include <Vector>
#include "CalculAttributs.h"
class Parser;
/** Cette classe abstraite d�finit une r�gle de la grammaire. */
class Regle
{
	public:
	/** Applique la r�gle � l'�tat courant du parser pass� en param�tre.
	@param p Le parser d�crivant l'�tat courant du syst�me.
	@return La liste des noeuds r�sultant de l'application de la r�gle.*/
	virtual vector<Noeud*> appliquer(Parser* p)=0;
	/** Objet d�crivant un calcul personnalis� par l'utilisateur des attributs des noeuds nouvellement cr��s.*/
	CalculAttributs* calculAtt;
};
#endif