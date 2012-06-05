#ifndef PARSER_H
#define PARSER_H
#include <Vector>
#include <Set>
#include <Map>
#include "../geometrie/Polygone.h"
#include "parsing/Noeud.h"
#include "regles/Regle.h"
using namespace std;
class Parser
{
	public :
		Parser();
		void parse(vector<Polygone*> terminaux);
		void ajouterNoeud(Noeud* n);
		vector<Polygone*> terminaux;
		void computeAdjacencies();
		void ajouterRegle(Regle* r);
		//void ajouterRegle(RegleSequence* r);
		map<Polygone*, set<Polygone*> > adj;/** La matrice d'adjacence entre polygones*/
		vector<Regle*> regles; /** Les règles de la grammaire*/
		vector<Noeud*> foret; /** La forêt des non-terminaux reconnus */
		map<string,set<Noeud*> > noeudsParType; /** A chaque type, l'ensemble des noeuds correspondants */
		void generateDot(string filename, bool axiomeSeulement);
		//map<Regle*,set<Noeud*> > seqDejaTraitees; /** Pour chaque règle de séquence, listes à 1 élément déjà construites */
		map<Noeud*,set<Noeud*> > exclusivite ; /** Relation d'exclusivité. A chaque noeud est associé la liste des noeuds qui ne peuvent apparaître dans le même arbre. */
		//map<string,set<RegleSequence*> >  reglesSequence; /** Associe à chaque non-terminal les règles séquence dans lesquelles il apparait. */ 
		void afficherMeilleur();
		};
#endif