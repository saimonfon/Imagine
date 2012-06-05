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
		vector<Regle*> regles; /** Les r�gles de la grammaire*/
		vector<Noeud*> foret; /** La for�t des non-terminaux reconnus */
		map<string,set<Noeud*> > noeudsParType; /** A chaque type, l'ensemble des noeuds correspondants */
		void generateDot(string filename, bool axiomeSeulement);
		//map<Regle*,set<Noeud*> > seqDejaTraitees; /** Pour chaque r�gle de s�quence, listes � 1 �l�ment d�j� construites */
		map<Noeud*,set<Noeud*> > exclusivite ; /** Relation d'exclusivit�. A chaque noeud est associ� la liste des noeuds qui ne peuvent appara�tre dans le m�me arbre. */
		//map<string,set<RegleSequence*> >  reglesSequence; /** Associe � chaque non-terminal les r�gles s�quence dans lesquelles il apparait. */ 
		void afficherMeilleur();
		};
#endif