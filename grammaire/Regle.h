#ifndef REGLE_H
#define REGLE_H
#include "regles/CalculAttributs.h"
#include "MembreDroit.h"
#include "condition/ConditionUnique.h"
#include "condition/ConditionAdj.h"
#include "condition/ConditionEgal.h"
#include "condition/ConditionGenerale.h"
#include <vector>
class Parser;
class Polygone;
class Regle
{
	public:
	/**Constructeur.
	@param nom Le nom du non-terminal correspondant à la règle.
	@param membresDroits Le vecteur des membres droits de la règle.
	*/
	Regle(string nom, vector<MembreDroit*> membresDroits);
	/** Applique la règle à l'état courant du parser passé en paramètre.
	@param p Le parser décrivant l'état courant du système.
	@return La liste des noeuds résultant de l'application de la règle.*/
	vector<Noeud*> appliquer(Parser* p);
	/** Objet décrivant un calcul personnalisé par l'utilisateur des attributs des noeuds nouvellement créés.*/
	CalculAttributs* calculAtt;
	/** Membres droits de la règle (terminaux/non-terminaux) ou opérateurs */
	vector<MembreDroit*> membresDroits;
	/** Parser correspondant à l'état actuel du système.*/
	Parser* p;
	/** Nom du non-terminal correspondant à la règle. */
	string nom;
	/** Nombre de membres droits. */
	int N;
	/**L'ordre dans lequel les variables doivent être affectées (de la plus contrainte à la moins contrainte) */
	int* order;
	/** Les conditions portant sur un membre droit (par exemple, chaque marche doit mesurer plus de 30 cm).*/
	vector<ConditionUnique*> condUnique;
	/** Les conditions d'adjacence entre attributs de deux éléments consécutifs. */
	vector<ConditionAdj*> condAdj;
	/** Les conditions d'égalité entre attributs de deux éléments consécutifs. */
	vector<ConditionEgal*> condEgal;
	/** Les conditions générales (à vérifier sur une affectation complète. */
	vector<ConditionGenerale*> condGen;
	
	map<ConditionAdj*,map<Polygone*,set<Noeud*> > > table_adj_i;
	map<ConditionAdj*,map<Polygone*,set<Noeud*> > > table_adj_j;
	
	//Le void* dans la map peut poser des problèmes (égalité entre pointeurs au lieu d'égalité entre valeurs)
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_i;
	map<ConditionEgal*,map<void*,set<Noeud*> > > table_eg_j;
	
	/** Résolution du problème d'affectation.
	@param affectPart Affectation partielle courante.
	@param curInd Indice de la variable sur laquelle boucler.*/
	void solveCSP(Noeud** affectPart, int curInd);
	//RAJOUTER LES TABLES DE HACHAGE DE LA REGLE
	
	private :
	vector<Noeud*> resultat; //Résultats, pour éviter de le passer en argument de la fonction récursive à chaque fois.
};
#endif