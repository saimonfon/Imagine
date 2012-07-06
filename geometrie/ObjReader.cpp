#include "ObjReader.h"
#include "Vec3.h"
#include <stack>
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
		//cout<<normales[i].x<<" "<<normales[i].y<<" "<<normales[i].z<<endl;
	}
		
	/* Calculer les faces incidentes � chaque sommet */
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
	bool* marque = new bool[M];
	for(int i=0;i<M;i++)
		marque[i]=false;
	for(int i=0;i<M;i++)
	{
		if(marque[i])
			continue;
		marque[i]=true;
		res.push_back(composante(i,marque));
	}
	
	/*Simplification des contours */
	
	return res;
}

Polygone* ObjReader::composante(int i,bool* marque)
{
	vector<int> faces;
	stack<int> aVoir;
	aVoir.push(i);
	while(!aVoir.empty())
	{
		int j = aVoir.top();
		aVoir.pop();
		faces.push_back(j);
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
			if((!marque[voisin]) && abs(normales[j]*normales[voisin])>0.95) //METTRE LE SEUIL EN PARAMETRE (5 deg de d�viation autoris�s)
			{
				marque[voisin] =true;
				aVoir.push(voisin);
			}
			}
		}
	}
	for(vector<int>::iterator it = faces.begin();it!=faces.end();it++)
		cout<<(*it)<<" ";
	cout<<endl;
	return new Polygone();
}

Vec3 ObjReader::normale(obj_face* f,obj_vector** vertices)
{
	Vec3 v1(vertices[f->vertex_index[1]],vertices[f->vertex_index[0]]);
	Vec3 v2(vertices[f->vertex_index[2]],vertices[f->vertex_index[0]]);
	Vec3 normale = v1^v2;
	normale.normalize();
	return normale;
}