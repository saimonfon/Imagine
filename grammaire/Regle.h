#ifndef REGLE_H
#define REGLE_H
#include "regles/CalculAttributs.h"
#include "MembreDroit.h"
#include "condition/ConditionUnique.h"
#include "condition/ConditionAdj.h"
#include "condition/ConditionAdj_Ext.h"
#include "condition/ConditionAdj_Int.h"
#include "condition/ConditionEgal.h"
#include "condition/ConditionGenerale.h"
#include <vector>
class Parser;
class Polygone;
class Regle
{
	public:
	/**Constructeur.
	@param nom Le nom du non-terminal correspondant � la r�gle.
	@param membresDroits Le vecteur des membres droits de la r�gle.
	*/
	Regle(string nom, vector<MembreDroit*> membresDroits);
	/** Applique la r�gle � l'�tat courant du parser pass� en param�tre.
	@param p Le parser d�crivant l'�tat courant du syst�me.
	@return La liste des noeuds r�sultant de l'application de la r�gle.*/
	vector<Noeud*> appliquer(Parser* p);
	/** Objet d�crivant un calcul personnalis� par l'utilisateur des attributs des noeuds nouvellement cr��s.*/
	CalculAttributs* calculAtt;
	/** Membres droits de la r�gle (terminaux/non-terminaux) ou op�rateurs */
	vector<MembreDroit*> membresDroits;
	/** Parser correspondant � l'�tat actuel du syst�me.*/
	Parser* p;
	/** Nom du non-terminal correspondant � la r�gle. */
	string nom;
	/** Nombre de membres droits. */
	int N;
	/**L'ordre dans lequel les variables doivent �tre affect�es (de la plus contrainte � la moins contrainte) */
	int* order;
	/** Les conditions portant sur un membre droit (par exemple, chaque marche doit mesurer plus de 30 cm).*/
	vector<ConditionUnique*> condUnique;
	/** Les conditions d'adjacence entre attributs de deux �l�ments cons�cutifs. */
	vector<ConditionAdj*> condAdj;
	/** les conditions d'adjacence exterieure entre attributs de deux elements */
	vector<ConditionAdj_Ext*> condAdj_ext;
	/** les conditions d'adjacence inetrieure entre attributs de deux elements */
	vector<ConditionAdj_Int*> condAdj_int;
	/** Les conditions d'�galit� entre attributs de deux �l�ments cons�cutifs. */
	vector<ConditionEgal*> condEgal;
	/** Les conditions g�n�rales (� v�rifier sur une affectation compl�te. */
	vector<ConditionGenerale*> condGen;
	
	map<ConditionAdj*    , map<Polygone*, set<Noeud*> > > table_adj_i;
	map<ConditionAdj*    , map<Polygone*, set<Noeud*> > > table_adj_j;
	map<ConditionAdj_Ext*, map<Polygone*, set<Noeud*> > > table_adj_ext_i;
	map<ConditionAdj_Ext*, map<Polygone*, set<Noeud*> > > table_adj_ext_j;
	map<ConditionAdj_Int*, map<Polygone*, set<Noeud*> > > table_adj_int_i;
	map<ConditionAdj_Int*, map<Polygone*, set<Noeud*> > > table_adj_int_j;

	//Le void* dans la map peut poser des probl�mes (�galit� entre pointeurs au lieu d'�galit� entre valeurs)
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_i;
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_j;
	
	/** R�solution du probl�me d'affectation.
	@param affectPart Affectation partielle courante.
	@param curInd Indice de la variable sur laquelle boucler.*/
	void solveCSP(Noeud** affectPart, int curInd);
	//RAJOUTER LES TABLES DE HACHAGE DE LA REGLE
	
	private :
	vector<Noeud*> resultat; //R�sultats, pour �viter de le passer en argument de la fonction r�cursive � chaque fois.
};
#endif
