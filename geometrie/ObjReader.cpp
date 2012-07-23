#include "ObjReader.h"
#include "Vec3.h"
#include <stack>
#include <map>
ObjReader::ObjReader(string fileName)
{
objData = new objLoader();
objData->load(fileName.c_str());
}

Modele* ObjReader::polygones()
{
	int M = objData->faceCount;
	int N = objData->vertexCount;
	/* Calculer les normales pour chaque face */
	normales = new Vec3[M];
	for (int i=0;i<M;i++)
	{
		normales[i] = this->normale(objData->faceList[i],objData->vertexList);
		//Inverser y et z pour avoir l'axe z vertical
		normales[i].inverserYetZ();
		
		//cout<<normales[i].x<<" "<<normales[i].y<<" "<<normales[i].z<<endl;
	}
		
	/* Calculer les faces incidentes à chaque sommet */
	incidence = new vector<int>[N];
	for (int i=0;i<M;i++)
	{
		int* ind = objData->faceList[i]->vertex_index;
		for(int j = 0;j<objData->faceList[i]->vertex_count;j++)
			incidence[ind[j]].push_back(i);
	}
	//cout<<"OK ICI"<<endl;
	
	/*Recherche des composantes connexes*/
	vector<Polygone*> res;
	composantes = new int[M];
	bool* marque = new bool[M];
	for(int i=0;i<M;i++)
		marque[i]=false;
	int cur_comp = 0;
	for(int i=0;i<M;i++)
	{
		if(marque[i])
			continue;
		marque[i]=true;
		Polygone* p =composante(i,cur_comp,marque);
		if(p!=NULL)
		{
		res.push_back(p);
		cur_comp++;
		}
	}
	
	/*Construction du graphe d'adjacence */
	for (int j=0;j<M;j++)
	{
		//cout<<j<<":"<<composantes[j]<<endl;
		for(int k=0;k<objData->faceList[j]->vertex_count;k++)
		{
			int s = objData->faceList[j]->vertex_index[k];
			for(vector<int>::iterator it = incidence[s].begin();it!=incidence[s].end();it++)
			{
			int voisin = *it;
			if(composantes[voisin]!=composantes[j]) //Si deux faces adjacentes ne sont pas coplanaires, on marque les polygones correspondants comme adjacents.
			{
				//cout<<"Adjacence entre "<<composantes[voisin]<<" et "<<composantes[j]<<endl;
				adj[res[composantes[voisin]]].insert(res[composantes[j]]);
				adj[res[composantes[j]]].insert(res[composantes[voisin]]);
			}
			}
		}
	}
	return new Modele(res,adj);
}

Polygone* ObjReader::composante(int i,int cur_comp,bool* marque)
{
	cout<<"TRAITEMENT D'UN NOUVEAU POLYGONE"<<endl;
	vector<int> faces;
	stack<int> aVoir;
	aVoir.push(i);
	while(!aVoir.empty())
	{
		int j = aVoir.top();
		aVoir.pop();
		faces.push_back(j);
		composantes[j] = cur_comp;
		//cout<<"Traitment du noeud "<<j<<endl;
		for(int k=0;k<objData->faceList[j]->vertex_count;k++)
		{
			//cout<<"ok iter "<<k<<endl;
			int s = objData->faceList[j]->vertex_index[k];
			//cout<<"ok s= "<<s<<endl;
			//cout<<incidence[s].size()<<endl;
			for(vector<int>::iterator it = incidence[s].begin();it!=incidence[s].end();it++)
			{
			int voisin = *it;
			//cout<<"Voisin de la face "<<j<<" : "<<voisin<<endl;
			if((!marque[voisin]) && abs(normales[j]*normales[voisin])>0.95) //METTRE LE SEUIL EN PARAMETRE (5 deg de déviation autorisés)
			{
				marque[voisin] =true;
				aVoir.push(voisin);
			}
			}
		}
	}
	for(vector<int>::iterator it = faces.begin();it!=faces.end();it++)
	{
		cout<<"(";
		int nAretes = objData->faceList[*it]->vertex_count;
		for(int k = 0;k<nAretes;k++)
			cout<<objData->faceList[*it]->vertex_index[k]<<", ";
		cout<<") ";
	}
	//cout<<"Ok avant copntour"<<endl;
	/* Extraire le contour.
	Cela se fait en trouvant les cycles d'arêtes adjacente à une seule face, puis en cherchant les cycles de ces arêtes.
	On récupère le bord et les trous, le polygone de plus grande aire correspond au bord.*/
	map<pair<int,int>,int> nbFacesAdjacentes; //Nombre de faces adjacentes à chaque arête. 
	for(vector<int>::iterator it = faces.begin();it!=faces.end();it++)
	{
		int nAretes = objData->faceList[*it]->vertex_count;
		for(int k = 0;k<nAretes;k++)
		{
			int ind1 =  objData->faceList[*it]->vertex_index[k];
			int ind2 =  objData->faceList[*it]->vertex_index[(k+1)%nAretes];
			if(ind1>ind2) //On veut ind1 < ind2
			{
				int tmp = ind2;
				ind2 = ind1;
				ind1 = tmp;
			}
			pair<int,int> arete = pair<int,int>(ind1,ind2);
			if(nbFacesAdjacentes.count(arete)>0)
				nbFacesAdjacentes[arete] = nbFacesAdjacentes[arete]+1;
			else
				nbFacesAdjacentes[arete] = 1;
		}
	}
	
	//cout<<"Ok apres la map"<<endl;
	//Trouver les arêtes qui ont une seule face adjacente
	vector< pair<int,int> > bords;
	for(map<pair<int,int>,int>::iterator it = nbFacesAdjacentes.begin();it!=nbFacesAdjacentes.end();it++)
	{
		cout<<it->first.first<<" -> "<<it->first.second<<" : "<<it->second<<endl;
		if(it->second == 1)
		{
			bords.push_back(it->first);
			cout<<"( "<<it->first.first<<" -> "<<it->first.second<<" ) ";
		}
	}
	//cout<<endl;
	//cout<<"Ok apres les bords"<<endl;
	/*Pour l'instant, on prend seulement le premier bord, comme des sagouins*/
	//cout<<"Niombre d'arêtes de bord :"<<bords.size()<<endl;
	bool* marque2 = new bool[bords.size()];
	for(int k=0;k<bords.size();k++)
		marque2[k] = false;
	vector<Polygone*> res;
	/* On cherche tous les bords */
	for(int i=0;i<bords.size();i++)
	{
	if(marque2[i])
		continue;
	pair<int,int> cur = bords[i];
	marque2[i]=true;
	vector<Vec3> cur_bord;
	while(true)
	{
		bool found=false;
		Vec3 v(objData->vertexList[cur.first]);
		cur_bord.push_back(v);
		//Trouver la suite (i.e. une arête de bord pas marquée adjacente à celle-là par la 2e extrémité)
		for(int k=0;k<bords.size();k++)
		{
			if(marque2[k])
				continue;
			pair<int,int> a = bords[k];
			if(a.first == cur.second)
			{
				marque2[k] = true;
				found = true;
				cur = a;
				break;
			}
			else if(a.second == cur.second)
			{
				marque2[k] = true;
				found = true;
				cur = pair<int,int>(a.second,a.first);
				break;
			}
		}
		if(!found)
			break;
	}
	
	/*Simplification du contour*/
	int j = 0;
	cout<<cur_bord.size()<<endl;
	for(int i=0;i<cur_bord.size();i++)
		cout<<"("<<cur_bord[i].x<<" , "<<cur_bord[i].y<<" , "<<cur_bord[i].z<<" ) ->";
	cout<<endl;
	/*while(j<cur_bord.size())
	{
		int N = cur_bord.size();
		//Vérifier si les points j,j+1 et j+2 sont colinéaires (i.e. que leur produit vectoriel vaut 0 à une erreur près).
		if(((cur_bord[(j+1)%N]-cur_bord[j]).normalize()^(cur_bord[(j+2)%N]-cur_bord[j]).normalize()).norm()<1e-3)
			cur_bord.erase(cur_bord.begin()+(j+1)%N);
		else
			j=j+1;
	}*/
	if(cur_bord.size()==0) //Devrait normalement pas arriver, mais certains modèles sont dégénérés (triangles plats)
		continue;
	//On a trouvé un bord, on construit un polygone avec
	Polygone* p = new Polygone();
	p->points3D = cur_bord;
	p->computeAttributs();
	res.push_back(p);
	}
	/* On a tous les bords, on choisit le polygone de plus grande aire comme contour, les autres sont des trous */
	int best = -1;
	float best_area = 0;
	for(int i=0;i<res.size();i++)
	{
		if(res[i]->getArea()>best_area)
		{
			best = i;
			best_area = res[i]->getArea();
		}
	}
	if(best==-1) //Devrait pas arriver
	{
		cout<<"BUUUUUGGGGG"<<endl;
		return NULL;
	}
	Polygone* p =new Polygone();
	p->points3D = res[best]->points3D;
	p->number = cur_comp;
	res.erase(res.begin()+best);
	p->trous = res;
	/*for(int i=0;i<res.size();i++)
	{
		this->res.push_back(res[i]);
		}*/
	return p;
	//return NULL;
}

Vec3 ObjReader::normale(obj_face* f,obj_vector** vertices)
{
	Vec3 v1(vertices[f->vertex_index[1]],vertices[f->vertex_index[0]]);
	Vec3 v2(vertices[f->vertex_index[2]],vertices[f->vertex_index[0]]);
	Vec3 normale = v1^v2;
	normale.normalize();
	return normale;
}