#include "OperateurPartieConnexe.h"
#include <iostream>
#include <list>
#include "parsing/NonTerminal.h"
#include <algorithm>
#include <map>
#include "Parser.h"

OperateurPartieConnexe::OperateurPartieConnexe(string nom, string tempname)
{
	init(nom, tempname);
}

OperateurPartieConnexe::OperateurPartieConnexe(Operateur* enfant, string tempname)
{
	init(enfant, tempname);
}

bool OperateurPartieConnexe::exclusivite(Noeud* n_to_test, vector<Noeud*> &nodes){

	bool ok=true;
	for(vector<Noeud*>::iterator itc = nodes.begin();itc!=nodes.end();itc++)
	{
		if(p->exclusivite[*itc].count(n_to_test)>0)
		{
			ok=false;
			break;
		}
	}
	return ok;
}



/** trouver les parties connexes dans le graphe d'adjacence
 */

set<Noeud*> OperateurPartieConnexe::noeudsFromGraphe(){
	set<Noeud*> res;

	map<Polygone*, Noeud*> correspondances;
	for(set<Noeud*>::iterator it=dejaTraites.begin();it!=dejaTraites.end();it++)
	{
		correspondances[(**it)["primitive"]->polygoneValue()] = *it;
	}


	set<Noeud*> marque;
	for(set<Noeud*>::iterator it=dejaTraites.begin();it!=dejaTraites.end();it++)
	{
		Noeud* cur = *it;
		if(marque.count(cur)>0){
			continue;
		}

		vector<Noeud*> partConnexe;
		vector<Noeud*> aVoir;
		aVoir.push_back(cur);
		while(!aVoir.empty()){

			Noeud* n = aVoir.back();
			aVoir.pop_back();

			//on verifie si il n'est pas exclusif du reste de la partie Connexe
			if(!exclusivite(n, partConnexe)){continue;}

			//on ajoute le noeud a la partie connexe et on le note comme utilise
			partConnexe.push_back(n);
			marque.insert(n);

			//on recupere ses voisins
			set<Polygone*> voisins = p->adj[(*n)["primitive"]->polygoneValue()];
			for(set<Polygone*>::iterator it2 = voisins.begin(); it2 != voisins.end(); it2++){
				map<Polygone*, Noeud*>::iterator itmap = correspondances.find(*it2);
				if(itmap == correspondances.end()){continue;}
				if(marque.count(itmap->second)>0){continue;}
				aVoir.push_back(itmap->second);
			}
		}

		NonTerminal* new_node = new NonTerminal(name, partConnexe);
		new_node->setAttribut("size", new AttributInt(partConnexe.size()));
		cout << "Partie Connexe trouvee" << endl;
		if(calculAtt!=NULL)
			calculAtt->calculAttrib(new_node);
		//INTEGRER L'EXCLUSIVITE !!!!!!
		res.insert(new_node);

	}
	if(res.size()==0){
		res.insert(p->ajouterNoeud(new NonTerminal("EnsembleVide",vector<Noeud*>()))); //Important d'avoir un noeud correspondant � l'ensemble vide, doit �tre trait� diff�rement dans le calcul de l'exclusivit�.
	}



	return res;
}
