#include "ObjReader.h"
#include "Vec3.h"
#include <stack>
#include <map>
ObjReader::ObjReader(string fileName)
{
objData = new objLoader();
objData->load(fileName.c_str());
}

vector<Polygone*> ObjReader::polygones()
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
	return res;
}

Polygone* ObjReader::composante(int i,int cur_comp,bool* marque)
{
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
		//cout<<it->first.first<<" -> "<<it->first.second<<" : "<<it->second<<endl;
		if(it->second == 1)
		{
			bords.push_back(it->first);
			cout<<"( "<<it->first.first<<" -> "<<it->first.second<<" ) ";
		}
	}
	cout<<endl;
	//cout<<"Ok apres les bords"<<endl;
	/*Pour l'instant, on prend seulement le premier bord, comme des sagouins*/
	//cout<<"Niombre d'arêtes de bord :"<<bords.size()<<endl;
	bool* marque2 = new bool[bords.size()];
	for(int k=0;k<bords.size();k++)
		marque2[k] = false;
	pair<int,int> cur = bords[0];
	marque2[0]=true;
	vector<Vec3> res;//vector<vector<Vec3> > res;
	cout<<"Bord trouvé :";
	while(true)
	{
		bool found=false;
		Vec3 v(objData->vertexList[cur.first]);
		v.inverserYetZ();
		res.push_back(v);
		cout<<"( "<<cur.first<<" -> "<<cur.second<<" ) ";
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
	cout<<endl;
	cout<<"Taille du contour :"<<res.size()<<endl;
	//cout<<"Ok poiur la construction du polygone"<<endl;
	
	/*Simplification du contour*/
	int j = 0;
	while(j<res.size())
	{
		int N = res.size();
		//Vérifier si les points j,j+1 et j+2 sont colinéaires (i.e. que leur produit vectoriel vaut 0 à une erreur près).
		if(((res[(j+1)%N]-res[j])^(res[(j+2)%N]-res[j])).norm()<0.00001)
			res.erase(res.begin()+(j+1)%N);
		else
			j=j+1;
	}
	if(res.size()==0)
	{
		cout<<"Bugggggg, polygone vide"<<endl;
		return NULL;
	}
	
	Polygone* p = new Polygone();
	p->equation = new float[4];
	p->equation[0] = normales[i].x;
	p->equation[1] = normales[i].y;
	p->equation[2] = normales[i].z;
	p->points3D = res;
	p->number = cur_comp;
	return p;
}

Vec3 ObjReader::normale(obj_face* f,obj_vector** vertices)
{
	Vec3 v1(vertices[f->vertex_index[1]],vertices[f->vertex_index[0]]);
	Vec3 v2(vertices[f->vertex_index[2]],vertices[f->vertex_index[0]]);
	Vec3 normale = v1^v2;
	normale.normalize();
	return normale;
}