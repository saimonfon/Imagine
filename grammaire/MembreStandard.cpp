#include "MembreStandard.h"
#include "condition/ConditionUnique.h"
#include "Parser.h"
#include <algorithm>
set<Noeud*> MembreStandard::getAffectations(Parser* p,Noeud** affectation, int N)
{
	/* Utilisation des conditions unitaires pour réduire le domaine */
	/* Doit être fait au début, une fois pour toute, et pas à chaque appel de cette fonction... */
	/* Les conditions uniques peuvent être redirigées du parser vers les membres directement.*/
	set_noeud res = p->noeudsParType[this->name];
	set<Noeud*> resultats;
	resultats.insert(res.begin(),res.end());
	for(vector<ConditionUnique*>::iterator it_cond = parent->condUnique.begin();it_cond!=parent->condUnique.end();it_cond++)
	{
         cout<<"Traitement de la condition unique "<<(*it_cond)->indice<<" et this->position vaut "<<this->position<<endl;
		if((*it_cond)->indice !=this->position)
			continue;
		set<Noeud*> toErase;
		for(set<Noeud*>::iterator it = resultats.begin();it!=resultats.end();it++)
		if(!(*it_cond)->estVerifiee(*it))
		toErase.insert(*it);
		for(set<Noeud*>::iterator it = toErase.begin();it!=toErase.end();it++)
		resultats.erase(*it);
	}
	//cout<<"Taille du domaine a priori pour l'indice "<<position<<" "<<resultats.size()<<endl;
	
	/* Traitement des conditions d'adjacence et égalité */
	if(parent->condAdj.size()>0)
	//cout<<"Taille des tables de hachage :"<<parent->table_adj_i[parent->condAdj[0]].size()<<endl;
	for(vector<ConditionAdj*>::iterator it = parent->condAdj.begin();it!=parent->condAdj.end();it++)
		{
			ConditionAdj* cadj = *it;
			if(cadj->i==this->position && affectation[cadj->j]!=NULL)
			{
			//cout<<"Prise en comppte d'une condition d'adjacence"<<endl;
			set<Polygone*> adj = p->adj[affectation[cadj->j]->getAttribut(cadj->att_j)->polygoneValue()];
			//cout<<"Nombre d'éléments adjacents :"<<adj.size()<<endl;
			set<Noeud*> adj_elem;
			for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
				adj_elem.insert(parent->table_adj_i[cadj][*it2].begin(),parent->table_adj_i[cadj][*it2].end());
			set<Noeud*> new_set;
				set_intersection(resultats.begin(),resultats.end(),adj_elem.begin(),adj_elem.end(),std::inserter(new_set, new_set.begin()));
				resultats = new_set;
				
			//cout<<"Nombre de successsuers :"<<new_set.size()<<endl;
			}
			else if(cadj->j==this->position && affectation[cadj->i]!=NULL)
			{
			//cout<<"Prise en comppte d'une condition d'adjacence pour j"<<endl;
			set<Polygone*> adj = p->adj[affectation[cadj->i]->getAttribut(cadj->att_i)->polygoneValue()];
			//cout<<"Nombre d'éléments adjacents :"<<adj.size()<<endl;
			/*for(set<Polygone*>::iterator it= adj.begin();it!=adj.end();it++)
				cout<<(*it)->number<<" ";*/
			//cout<<endl;
			set<Noeud*> adj_elem;
			for(set<Polygone*>::iterator it2 = adj.begin();it2!=adj.end();it2++)
			{
				adj_elem.insert(parent->table_adj_j[cadj][*it2].begin(),parent->table_adj_j[cadj][*it2].end());
				//cout<<"Nombre de noeuds adjacents à "<<(*it2)->number<<" : "<<parent->table_adj_i[cadj][*it2].size()<<endl;
			}
			set<Noeud*> new_set;
				set_intersection(resultats.begin(),resultats.end(),adj_elem.begin(),adj_elem.end(),std::inserter(new_set, new_set.begin()));
				resultats = new_set;
			//cout<<"Nombre de successsuers :"<<new_set.size()<<endl;
			//cout<<"RESTENT EN LICE"<<resultats.size()<<endl;
			}
		}
		
		/* Le == marche plus, il faut modifier la classe Attribut pour redéfinir l'égalité (ou plutot l'inégalité*/
		for(vector<ConditionEgal*>::iterator it = parent->condEgal.begin();it!=parent->condEgal.end();it++)
		{
			ConditionEgal* ceg = *it;
			if(ceg->i==this->position && affectation[ceg->j]!=NULL)
			{
				set<Noeud*> eg_elem=parent->table_eg_j[ceg][affectation[ceg->j]->getAttribut(ceg->att_j)];
				set<Noeud*> new_set;
				set_intersection(resultats.begin(),resultats.end(),eg_elem.begin(),eg_elem.end(),std::inserter(new_set, new_set.begin()));
				resultats = new_set;
			}
			else if(ceg->j==this->position && affectation[ceg->i]!=NULL)
			{
				set<Noeud*> eg_elem=parent->table_eg_i[ceg][affectation[ceg->i]->getAttribut(ceg->att_i)];
				set<Noeud*> new_set;
				set_intersection(resultats.begin(),resultats.end(),eg_elem.begin(),eg_elem.end(),std::inserter(new_set, new_set.begin()));
				resultats = new_set;
			}
		}
		
		//Relation d'exclusivité
		for(int i=0;i<N;i++)
		{
			if(affectation[i]==NULL|| i == this->position)
				continue;
			set<Noeud*> exclu = p->exclusivite[affectation[i]];
			//cout<<"Suppression du domaines "<<i<<" de taille "<<new_domaines[i].size()<<endl;
			//cout<<exclu.size()<<endl;
			for(set<Noeud*>::iterator it_exclu = exclu.begin();it_exclu!=exclu.end();it_exclu++)
			{
				resultats.erase(*it_exclu);
			//cout<<"On supprime "<<(*it_exclu)->nom_parser<<" des résultats car "<<parent->membresDroits[i]->name<<" vaut "<<affectation[i]->nom_parser<<endl;
			}
			//cout<<"Nouvelle taille "<<new_domaines[i].size()<<endl;
		}
	//cout<<"Taille du domaine apres traitements des contraintes pour "<<position<<" : "<<resultats.size()<<endl;
		
	set<Noeud*> res2;
	res2.insert(resultats.begin(),resultats.end());
	return res2;
}

MembreStandard::MembreStandard(string nom)
{
	this->name = nom;
}
