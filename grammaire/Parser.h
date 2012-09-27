#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <set>
#include <map>
#include "../geometrie/Polygone.h"
#include "../geometrie/Modele.h"
#include "parsing/Noeud.h"
#include "Regle.h"
//#include<unordered_set>
using namespace std;

class NoeudEq{
public:
/** Egalit� entre deux noeuds. Utilis� pour la hashmap. */
bool operator ()(const Noeud* n1,const Noeud* n2) const
{
	return n1->equals(n2);
}
};

/*class hashNoeud{
public:
  size_t operator()(const Noeud* n){
	size_t val = 0x345678;
	vector<Noeud*> e = n->getEnfants();
	for(vector<Noeud*>::iterator it = e.begin();it!=e.end();it++)
		val = (val<<1)^ hash<Noeud*>()(*it);
    return hash<string>()(n->getType())^val;
  }
};*/

//typedef unordered_set<Noeud*,hashNoeud,NoeudEq> set_noeud;
typedef set<Noeud*> set_noeud;

class Parser
{
	public :
		Parser();
		void parse(Modele* modele,int max_iter=0);
		void tous(string axiome);
		Noeud* ajouterNoeud(Noeud* n);
		vector<Polygone*> terminaux;
		void computeAdjacencies();
		void ajouterRegle(Regle* r);
		//void ajouterRegle(RegleSequence* r);

		map<Polygone*, set<Polygone*> > adj;/** La matrice d'adjacence entre polygones*/
		map<Polygone*, set<Polygone*> > adj_ext; /** La matrice d'adjacence exterieure*/
		map<Polygone*, set<Polygone*> > adj_int; /** La matrice d'adjacence interieure*/
		float echelle;

		vector<Regle*> regles; /** Les r�gles de la grammaire*/
		vector<Noeud*> foret; /** La for�t des non-terminaux reconnus */
		map<string,set_noeud> noeudsParType; /** A chaque type, l'ensemble des noeuds correspondants */
		void generateDot(string filename, bool axiomeSeulement);
		//map<Regle*,set<Noeud*> > seqDejaTraitees; /** Pour chaque r�gle de s�quence, listes � 1 �l�ment d�j� construites */
		map<Noeud*,set<Noeud*> > exclusivite ; /** Relation d'exclusivit�. A chaque noeud est associ� la liste des noeuds qui ne peuvent appara�tre dans le m�me arbre. */
		//map<string,set<RegleSequence*> >  reglesSequence; /** Associe � chaque non-terminal les r�gles s�quence dans lesquelles il apparait. */ 
		void afficherMeilleur(string axiome);
		void generateDot(string filename, Noeud* racine);
		};
#endif
