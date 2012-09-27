#include "Regle.h"
#include "Parser.h"
#include <algorithm>
#include "parsing/NonTerminal.h"
bool comparator ( const pair<int,float>& l, const pair<int,float>& r) { return l.second < r.second; }

Regle::Regle(string nom, vector<MembreDroit*> membresDroits)
{
	this->nom = nom;
	this->membresDroits = membresDroits;
	for(int i=0;i<membresDroits.size();i++)
		membresDroits[i]->init(this,i);
	this->calculAtt=NULL;
}

vector<Noeud*> Regle::appliquer(Parser* p)
{
	this->p=p;

	/* Remplissage des tables de hachage */
	for(vector<ConditionAdj*>::iterator it = condAdj.begin();it!=condAdj.end();it++)
	{
		ConditionAdj* cadj = *it;
		for(set_noeud::iterator ite = p->noeudsParType[membresDroits[cadj->i]->name].begin();ite!=p->noeudsParType[membresDroits[cadj->i]->name].end();ite++)
		{
			table_adj_i[cadj][(*ite)->getAttribut(cadj->att_i)->polygoneValue()].insert(*ite);
			//cout<<"Inserting "<<(*ite)->nom_parser<<" for key" <<((Polygone*)(*ite)->getAttribut(cadj->att_i))->number<<endl;
		}
		for(set_noeud::iterator ite = p->noeudsParType[membresDroits[cadj->j]->name].begin();ite!=p->noeudsParType[membresDroits[cadj->j]->name].end();ite++)
		{
			Polygone* p =(*ite)->getAttribut(cadj->att_j)->polygoneValue();
			table_adj_j[cadj][p].insert(*ite);
			//cout<<"Inserting "<<(*ite)->nom_parser<<" for key" <<((Polygone*)(*ite)->getAttribut(cadj->att_j))->number<<endl;
		}
	}

	for(vector<ConditionAdj_Ext*>::iterator it=condAdj_ext.begin(); it != condAdj_ext.end(); it++){
		ConditionAdj_Ext* cadj = *it;
		for(set_noeud::iterator ite = p->noeudsParType[membresDroits[cadj->i]->name].begin();ite!=p->noeudsParType[membresDroits[cadj->i]->name].end();ite++)
		{
			table_adj_ext_i[cadj][(*ite)->getAttribut(cadj->att_i)->polygoneValue()].insert(*ite);
			//cout<<"Inserting "<<(*ite)->nom_parser<<" for key" <<((Polygone*)(*ite)->getAttribut(cadj->att_i))->number<<endl;
		}
		for(set_noeud::iterator ite = p->noeudsParType[membresDroits[cadj->j]->name].begin();ite!=p->noeudsParType[membresDroits[cadj->j]->name].end();ite++)
		{
			Polygone* p =(*ite)->getAttribut(cadj->att_j)->polygoneValue();
			table_adj_ext_j[cadj][p].insert(*ite);
			//cout<<"Inserting "<<(*ite)->nom_parser<<" for key" <<((Polygone*)(*ite)->getAttribut(cadj->att_j))->number<<endl;
		}
	}

	for(vector<ConditionAdj_Int*>::iterator it=condAdj_int.begin(); it != condAdj_int.end(); it++){
		ConditionAdj_Int* cadj = *it;
		for(set_noeud::iterator ite = p->noeudsParType[membresDroits[cadj->i]->name].begin();ite!=p->noeudsParType[membresDroits[cadj->i]->name].end();ite++)
		{
			table_adj_int_i[cadj][(*ite)->getAttribut(cadj->att_i)->polygoneValue()].insert(*ite);
			//cout<<"Inserting "<<(*ite)->nom_parser<<" for key" <<((Polygone*)(*ite)->getAttribut(cadj->att_i))->number<<endl;
		}
		for(set_noeud::iterator ite = p->noeudsParType[membresDroits[cadj->j]->name].begin();ite!=p->noeudsParType[membresDroits[cadj->j]->name].end();ite++)
		{
			Polygone* p =(*ite)->getAttribut(cadj->att_j)->polygoneValue();
			table_adj_int_j[cadj][p].insert(*ite);
			//cout<<"Inserting "<<(*ite)->nom_parser<<" for key" <<((Polygone*)(*ite)->getAttribut(cadj->att_j))->number<<endl;
		}
	}


	for(vector<ConditionEgal*>::iterator it = condEgal.begin();it!=condEgal.end();it++)
	{
		ConditionEgal* ceg = *it;
		for(set_noeud::iterator ite = p->noeudsParType[membresDroits[ceg->i]->name].begin();ite!=p->noeudsParType[membresDroits[ceg->i]->name].end();ite++)
			table_eg_i[ceg][(*ite)->getAttribut(ceg->att_i)].insert(*ite);
		for(set_noeud::iterator ite = p->noeudsParType[membresDroits[ceg->j]->name].begin();ite!=p->noeudsParType[membresDroits[ceg->j]->name].end();ite++)
			table_eg_j[ceg][(*ite)->getAttribut(ceg->att_j)].insert(*ite);
	}

	/* A modifier : ordre de parcours 
	Pour l'instant, ordre dans lequel sont fournis les membres.*/
	this->N = membresDroits.size();
	order = new int[N];
	vector<pair<int,float> > v;
	for(int i=0;i<N;i++)
		v.push_back(pair<int,float>(i,i)); //Ici qu'il faut modifier
	sort(v.begin(),v.end(),comparator);
	order = new int[N];
	for(int i=0;i<v.size();i++)
		order[i] = v[i].first;

	Noeud** affect = new Noeud*[N];
	for(int i=0;i<N;i++)
		affect[i] = NULL;
	resultat.clear();
	//cout<<"Ok avant CSP"<<endl;
	solveCSP(affect,0);
	//cout<<"Ok apr�s le CSP"<<endl;
	/*Aplatir les r�sultats.*/
	for(vector<Noeud*>::iterator it = resultat.begin();it!=resultat.end();it++)
	{
		vector<Noeud*> e;
		vector<Noeud*> e2  = (*it)->getEnfants();
		for(vector<Noeud*>::iterator it2 = e2.begin();it2!=e2.end();it2++)
		{
			if((*it2)->getType().compare("OPE")!=0)
				e.push_back(*it2);
			else
				e.push_back(p->ajouterNoeud(*it2));
		}
		(*it)->enfants = e;
	}
	return resultat;
}

void Regle::solveCSP(Noeud** affectPart, int curInd)
{
	if(curInd==N) //On a une affectation compl�te
	{
		//cout<<"Ok on a une affectation compl�te, on v�rifie les contraintes"<<endl;
		vector<Noeud*> enfants;
		for(int i=0;i<N;i++)
			enfants.push_back(affectPart[i]);
		//cout<<"Ok on a une affectation compl�te, on v�rifie les contraintes (part 2)"<<endl;
		//On v�rifie ici que les conditions g�n�rales soient satisfaites
		for(vector<ConditionGenerale*>::iterator it = condGen.begin();it!=condGen.end();it++)
		{
			if(!((*it)->estVerifiee(enfants,this->p)))
				return;
		}
		//cout<<"Ok on a une affectation compl�te, on a  v�rifi���� les contraintes"<<endl;
		NonTerminal* new_node = new NonTerminal(nom,enfants);
		if(calculAtt!=NULL)
		{
			//cout<<"Ok calcul des attributs"<<endl;
			calculAtt->calculAttrib(new_node);
		}

		//cout<<"Ok on a calcul� les attributs"<<endl;
		resultat.push_back(new_node);
		return;
	}
	int var = order[curInd];
	set<Noeud*> vals = membresDroits[curInd]->getAffectations(this->p,affectPart,N); //R�cup�rer les valeurs possibles pour le membre droit en cours de traitement.

	for(set<Noeud*>::iterator ite = vals.begin();ite!=vals.end();ite++)
	{
		//cout<<(w++)<<endl;
		//cout<<"Valeur "<<(*ite)->nom_parser<<"pour la variable "<<var<<endl;
		//Affecter � la variable var la valeur ite
		affectPart[var] = *ite;
		solveCSP(affectPart,curInd+1);
	}
}
