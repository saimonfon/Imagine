#include "ObjReader.h"
#include "Vec3.h"
#include <stack>
#include <map>
#include <set>
#include <iostream>

ObjReader::ObjReader(){}

ObjReader::ObjReader(string fileName)
{
	objData = new objLoader();
	objData->load(fileName.c_str());
}


int modulo (int m, int n) {
	return m >= 0 ? m % n : ( n - (int)fabs( m%n ) ) % n;
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

	/* Calculer les faces incidentes � chaque sommet */
	incidence = new set<int>[N];
	for (int i=0;i<M;i++)
	{
		int* ind = objData->faceList[i]->vertex_index;
		for(int j = 0;j<objData->faceList[i]->vertex_count;j++)
			incidence[ind[j]].insert(i);
	}
	//cout<<"OK ICI"<<endl;

	incidence_faces = new set<int>[M];
	for(int i=0; i<N; i++){
		for(set<int>::iterator it=incidence[i].begin(); it != incidence[i].end(); it++){
			incidence_faces[*it].insert(i);
		}
	}

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

		for(set<int>::iterator it2= incidence_faces[j].begin(); it2 != incidence_faces[j].end(); it2++)
		{
			int k = *it2;
			int s = k;
			for(set<int>::iterator it = incidence[s].begin();it!=incidence[s].end();it++)
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
	//recherche des adjacences labelisees
		for(int j=0; j<M; j++){

			//cout<<j<<":"<<composantes[j]<<endl;
			for(set<int>::iterator it2= incidence_faces[j].begin(); it2 != incidence_faces[j].end(); it2++)
			{
				int k = *it2;
				int s = k;
				for(set<int>::iterator it = incidence[s].begin();it!=incidence[s].end();it++)
				{
					int voisin = *it;
					if(composantes[voisin]!=composantes[j]) //Si deux faces adjacentes ne sont pas coplanaires, on marque les polygones correspondants comme adjacents.
					{

						//cout<<"Adjacence entre "<<composantes[voisin]<<" et "<<composantes[j]<<endl;
						for(int v1 = 0; v1<res[composantes[j]]->points3D.size(); v1++){
							for(int v2 = 0; v2<res[composantes[voisin]]->points3D.size(); v2++){
								if(res[composantes[j]]->points3D[v1] == res[composantes[voisin]]->points3D[v2]){
									if( res[composantes[j]]->points3D[modulo(v1-1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2+1,res[composantes[voisin]]->points3D.size())] ||
											res[composantes[j]]->points3D[modulo(v1+1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2-1,res[composantes[voisin]]->points3D.size())] ||
											res[composantes[j]]->points3D[modulo(v1-1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2-1,res[composantes[voisin]]->points3D.size())] ||
											res[composantes[j]]->points3D[modulo(v1+1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2+1,res[composantes[voisin]]->points3D.size())] ){
										adj_edge_ext[res[composantes[voisin]]].insert(res[composantes[j]]);
										adj_edge_ext[res[composantes[j]]].insert(res[composantes[voisin]]);
									}
								}
							}
						}

						for(int v1 = 0; v1<res[composantes[j]]->points3D.size(); v1++){
							for(int v2 = 0; v2<res[composantes[voisin]]->trous.size(); v2++){
								for(int v3=0; v3<res[composantes[voisin]]->trous[v2]->points3D.size(); v3++){
									if(res[composantes[j]]->points3D[v1] == res[composantes[voisin]]->trous[v2]->points3D[v3]){
										if( res[composantes[j]]->points3D[modulo(v1-1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v3+1,res[composantes[voisin]]->trous[v2]->points3D.size())] ||
												res[composantes[j]]->points3D[modulo(v1+1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v3-1,res[composantes[voisin]]->trous[v2]->points3D.size())] ||
												res[composantes[j]]->points3D[modulo(v1-1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v3-1,res[composantes[voisin]]->trous[v2]->points3D.size())] ||
												res[composantes[j]]->points3D[modulo(v1+1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v3+1,res[composantes[voisin]]->trous[v2]->points3D.size())]){
											adj_edge_int[res[composantes[voisin]]].insert(res[composantes[j]]);
											adj_edge_ext[res[composantes[j]]].insert(res[composantes[voisin]]);
										}
									}
								}
							}
						}

						for(int v1 = 0; v1<res[composantes[j]]->trous.size(); v1++){
							for(int v3 = 0 ; v3<res[composantes[j]]->trous[v1]->points3D.size(); v3++){
								for(int v2 = 0; v2<res[composantes[voisin]]->points3D.size(); v2++){
									if(res[composantes[j]]->trous[v1]->points3D[v3] == res[composantes[voisin]]->points3D[v2]){
										if( res[composantes[j]]->trous[v1]->points3D[modulo(v3-1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2+1,res[composantes[voisin]]->points3D.size())] ||
												res[composantes[j]]->trous[v1]->points3D[modulo(v3+1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2-1,res[composantes[voisin]]->points3D.size())] ||
												res[composantes[j]]->trous[v1]->points3D[modulo(v3-1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2-1,res[composantes[voisin]]->points3D.size())] ||
												res[composantes[j]]->trous[v1]->points3D[modulo(v3+1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2+1,res[composantes[voisin]]->points3D.size())]
												){
											adj_edge_ext[res[composantes[voisin]]].insert(res[composantes[j]]);
											adj_edge_int[res[composantes[j]]].insert(res[composantes[voisin]]);
										}
									}
								}
							}
						}

						for(int v1 = 0; v1<res[composantes[j]]->trous.size(); v1++){
							for(int v3 = 0 ; v3<res[composantes[j]]->trous[v1]->points3D.size(); v3++){
								for(int v2 = 0; v2<res[composantes[voisin]]->trous.size(); v2++){
									for(int v4=0; v4<res[composantes[voisin]]->trous[v2]->points3D.size(); v4++){
										if(res[composantes[j]]->trous[v1]->points3D[v3] == res[composantes[voisin]]->trous[v2]->points3D[v3]){
											if( res[composantes[j]]->trous[v1]->points3D[modulo(v3-1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v4+1,res[composantes[voisin]]->trous[v2]->points3D.size())] ||
													res[composantes[j]]->trous[v1]->points3D[modulo(v3+1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v4-1,res[composantes[voisin]]->trous[v2]->points3D.size())] ||
													res[composantes[j]]->trous[v1]->points3D[modulo(v3-1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v4-11,res[composantes[voisin]]->trous[v2]->points3D.size())] ||
													res[composantes[j]]->trous[v1]->points3D[modulo(v3+1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v4+1,res[composantes[voisin]]->trous[v2]->points3D.size())]){
												adj_edge_int[res[composantes[voisin]]].insert(res[composantes[j]]);
												adj_edge_int[res[composantes[j]]].insert(res[composantes[voisin]]);
											}
										}
									}
								}
							}
						}

					}
				}
			}

		}

		/*
		for(int i=0; i<N; i++){
			cout << "v" << i << " -> " ;
			for(set<int>::iterator it=incidence[i].begin(); it != incidence[i].end(); it++){
				cout << *it << " ";
			}
			cout << endl;
		}*/

		Modele* m = new Modele(res,adj,true);
		m->adj_edge_ext = adj_edge_ext;
		m->adj_edge_int = adj_edge_int;
		return m;
}

bool is_incident(obj_vector** vertexList, int vertex_idx, obj_face** faceList, int face_idx, float epsilon){

	//on teste si le point appartient aux sommet de la face
	int* vertices_of_face = faceList[face_idx]->vertex_index;
	for(int i=0; i<faceList[face_idx]->vertex_count; i++){
		if(vertices_of_face[i] == vertex_idx){
			return true;
		}
	}



	//on teste si le sommet est a distance moins de epsilon du plan de la face
	Vec3 normal = ObjReader::normale(faceList[face_idx], vertexList);
	Vec3 point_plane (vertexList[faceList[face_idx]->vertex_index[0]]);
	Vec3 point(vertexList[vertex_idx]);
	if(fabs(point*normal - point_plane*normal)<epsilon){
		//cout << " " << fabs(point*normal - point_plane*normal) << " " << vertex_idx << " " << face_idx << endl;
		Vec3 vA(vertexList[faceList[face_idx]->vertex_index[0]]);
		Vec3 vAB(vertexList[faceList[face_idx]->vertex_index[1]],vertexList[faceList[face_idx]->vertex_index[0]]);
		Vec3 normalAB = vAB^normal;
		normalAB.normalize();
		//cout << " " << point*normalAB - vA*normalAB << endl;
		if(point*normalAB - vA*normalAB < -epsilon){
			return false;
		}

		Vec3 vB(vertexList[faceList[face_idx]->vertex_index[1]]);
		Vec3 vBC(vertexList[faceList[face_idx]->vertex_index[2]],vertexList[faceList[face_idx]->vertex_index[1]]);
		Vec3 normalBC = vBC^normal;
		normalBC.normalize();
		//cout << " " << point*normalBC - vB*normalBC << endl;
		if(point*normalBC - vB*normalBC < -epsilon){
			return false;
		}

		Vec3 vC(vertexList[faceList[face_idx]->vertex_index[2]]);
		Vec3 vCA(vertexList[faceList[face_idx]->vertex_index[0]],vertexList[faceList[face_idx]->vertex_index[2]]);
		Vec3 normalCA = vCA^normal;
		normalCA.normalize();
		//cout << " " << point*normalCA - vC*normalCA << endl;
		if(point*normalCA - vC*normalCA < -epsilon){
			return false;
		}

		//cout << vertex_idx << " " << face_idx << endl;

		return true;
	}

	return false;
}


Modele* ObjReader::polygones2(float epsilon)
{


	int M = objData->faceCount;
	//cout << "Nombre de faces : " << M << endl;
	int N = objData->vertexCount;
	//cout << "Nombre de sommets : " << N << endl;

	/* Calculer les normales pour chaque face */
	normales = new Vec3[M];
	for (int i=0;i<M;i++)
	{
		normales[i] = this->normale(objData->faceList[i],objData->vertexList);
		//Inverser y et z pour avoir l'axe z vertical
		//normales[i].inverserYetZ();
		//cout<<normales[i].x<<" "<<normales[i].y<<" "<<normales[i].z<<endl;
	}

	/* Calculer les faces incidentes � chaque sommet */
	incidence = new set<int>[N];
	//recherche sur les faces
	for (int i=0;i<M;i++)
	{
		for(int j=0; j<N; j++){
			if(is_incident(objData->vertexList,j, objData->faceList, i, epsilon)){
				incidence[j].insert(i);
			}
		}
	}
	//
	//cout<<"OK ICI"<<endl;
	/*incidence sur les faces*/
	incidence_faces = new set<int>[M];
	for(int i=0; i<N; i++){
		for(set<int>::iterator it=incidence[i].begin(); it != incidence[i].end(); it++){
			incidence_faces[*it].insert(i);
		}
	}

	/*Recherche des composantes connexes*/
	vector<Polygone*> res;

	composantes = new int[M];
	bool* marque = new bool[M];
	for(int i=0;i<M;i++)
		marque[i]=false;
	int cur_comp = 0;
	for(int i=0;i<M;i++)
	{
		//cout << i << endl;
		if(marque[i])
			continue;
		marque[i]=true;
		Polygone* p  = composante(i,cur_comp,marque);
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
		for(set<int>::iterator it2= incidence_faces[j].begin(); it2 != incidence_faces[j].end(); it2++)
		{
			int k = *it2;
			int s = k;
			for(set<int>::iterator it = incidence[s].begin();it!=incidence[s].end();it++)
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

	//recherche des adjacences labelisees
	for(int j=0; j<M; j++){

		//cout<<j<<":"<<composantes[j]<<endl;
		for(set<int>::iterator it2= incidence_faces[j].begin(); it2 != incidence_faces[j].end(); it2++)
		{
			int k = *it2;
			int s = k;
			for(set<int>::iterator it = incidence[s].begin();it!=incidence[s].end();it++)
			{
				int voisin = *it;
				if(composantes[voisin]!=composantes[j]) //Si deux faces adjacentes ne sont pas coplanaires, on marque les polygones correspondants comme adjacents.
				{

					//cout<<"Adjacence entre "<<composantes[voisin]<<" et "<<composantes[j]<<endl;
					for(int v1 = 0; v1<res[composantes[j]]->points3D.size(); v1++){
						for(int v2 = 0; v2<res[composantes[voisin]]->points3D.size(); v2++){
							if(res[composantes[j]]->points3D[v1] == res[composantes[voisin]]->points3D[v2]){
								if( res[composantes[j]]->points3D[modulo(v1-1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2+1,res[composantes[voisin]]->points3D.size())] ||
										res[composantes[j]]->points3D[modulo(v1+1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2-1,res[composantes[voisin]]->points3D.size())] ||
										res[composantes[j]]->points3D[modulo(v1-1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2-1,res[composantes[voisin]]->points3D.size())] ||
										res[composantes[j]]->points3D[modulo(v1+1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2+1,res[composantes[voisin]]->points3D.size())] ){
									adj_edge_ext[res[composantes[voisin]]].insert(res[composantes[j]]);
									adj_edge_ext[res[composantes[j]]].insert(res[composantes[voisin]]);
								}
							}
						}
					}

					for(int v1 = 0; v1<res[composantes[j]]->points3D.size(); v1++){
						for(int v2 = 0; v2<res[composantes[voisin]]->trous.size(); v2++){
							for(int v3=0; v3<res[composantes[voisin]]->trous[v2]->points3D.size(); v3++){
								if(res[composantes[j]]->points3D[v1] == res[composantes[voisin]]->trous[v2]->points3D[v3]){
									if( res[composantes[j]]->points3D[modulo(v1-1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v3+1,res[composantes[voisin]]->trous[v2]->points3D.size())] ||
											res[composantes[j]]->points3D[modulo(v1+1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v3-1,res[composantes[voisin]]->trous[v2]->points3D.size())] ||
											res[composantes[j]]->points3D[modulo(v1-1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v3-1,res[composantes[voisin]]->trous[v2]->points3D.size())] ||
											res[composantes[j]]->points3D[modulo(v1+1,res[composantes[j]]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v3+1,res[composantes[voisin]]->trous[v2]->points3D.size())]){
										adj_edge_int[res[composantes[voisin]]].insert(res[composantes[j]]);
										adj_edge_ext[res[composantes[j]]].insert(res[composantes[voisin]]);
									}
								}
							}
						}
					}

					for(int v1 = 0; v1<res[composantes[j]]->trous.size(); v1++){
						for(int v3 = 0 ; v3<res[composantes[j]]->trous[v1]->points3D.size(); v3++){
							for(int v2 = 0; v2<res[composantes[voisin]]->points3D.size(); v2++){
								if(res[composantes[j]]->trous[v1]->points3D[v3] == res[composantes[voisin]]->points3D[v2]){
									if( res[composantes[j]]->trous[v1]->points3D[modulo(v3-1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2+1,res[composantes[voisin]]->points3D.size())] ||
											res[composantes[j]]->trous[v1]->points3D[modulo(v3+1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2-1,res[composantes[voisin]]->points3D.size())] ||
											res[composantes[j]]->trous[v1]->points3D[modulo(v3-1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2-1,res[composantes[voisin]]->points3D.size())] ||
											res[composantes[j]]->trous[v1]->points3D[modulo(v3+1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->points3D[modulo(v2+1,res[composantes[voisin]]->points3D.size())]
											){
										adj_edge_ext[res[composantes[voisin]]].insert(res[composantes[j]]);
										adj_edge_int[res[composantes[j]]].insert(res[composantes[voisin]]);
									}
								}
							}
						}
					}

					for(int v1 = 0; v1<res[composantes[j]]->trous.size(); v1++){
						for(int v3 = 0 ; v3<res[composantes[j]]->trous[v1]->points3D.size(); v3++){
							for(int v2 = 0; v2<res[composantes[voisin]]->trous.size(); v2++){
								for(int v4=0; v4<res[composantes[voisin]]->trous[v2]->points3D.size(); v4++){
									if(res[composantes[j]]->trous[v1]->points3D[v3] == res[composantes[voisin]]->trous[v2]->points3D[v3]){
										if( res[composantes[j]]->trous[v1]->points3D[modulo(v3-1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v4+1,res[composantes[voisin]]->trous[v2]->points3D.size())] ||
												res[composantes[j]]->trous[v1]->points3D[modulo(v3+1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v4-1,res[composantes[voisin]]->trous[v2]->points3D.size())] ||
												res[composantes[j]]->trous[v1]->points3D[modulo(v3-1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v4-11,res[composantes[voisin]]->trous[v2]->points3D.size())] ||
												res[composantes[j]]->trous[v1]->points3D[modulo(v3+1,res[composantes[j]]->trous[v1]->points3D.size())] == res[composantes[voisin]]->trous[v2]->points3D[modulo(v4+1,res[composantes[voisin]]->trous[v2]->points3D.size())]){
											adj_edge_int[res[composantes[voisin]]].insert(res[composantes[j]]);
											adj_edge_int[res[composantes[j]]].insert(res[composantes[voisin]]);
										}
									}
								}
							}
						}
					}

				}
			}
		}

	}

	/*
	for(int i=0; i<N; i++){
		cout << "v" << i << " -> " ;
		for(set<int>::iterator it=incidence[i].begin(); it != incidence[i].end(); it++){
			cout << *it << " ";
		}
		cout << endl;
	}*/

	Modele* m = new Modele(res,adj,true);
	m->adj_edge_ext = adj_edge_ext;
	m->adj_edge_int = adj_edge_int;
	return m;
}

Polygone* ObjReader::composante(int i,int cur_comp,bool* marque)
{
	//cout<<"TRAITEMENT D'UN NOUVEAU POLYGONE"<<endl;
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
		for(set<int>::iterator it2= incidence_faces[j].begin(); it2 != incidence_faces[j].end(); it2++)
		{
			int k = *it2;
			//cout<<"ok iter "<<k<<endl;
			int s = k;
			//cout<<"ok s= "<<s<<endl;
			//cout<<incidence[s].size()<<endl;
			for(set<int>::iterator it = incidence[s].begin();it!=incidence[s].end();it++)
			{
				int voisin = *it;
				//cout<<"Voisin de la face "<<j<<" : "<<voisin<<endl;
				if((!marque[voisin]) && fabs(normales[j]*normales[voisin])>0.95) //METTRE LE SEUIL EN PARAMETRE (5 deg de d�viation autoris�s)
				{
					marque[voisin] =true;
					aVoir.push(voisin);
				}
			}
		}
	}
	/*for(vector<int>::iterator it = faces.begin();it!=faces.end();it++)
	{
		cout<<"(";
		int nAretes = objData->faceList[*it]->vertex_count;
		for(int k = 0;k<nAretes;k++)
			cout<<objData->faceList[*it]->vertex_index[k]<<", ";
		cout<<") ";
	}*/
	//cout<<"Ok avant copntour"<<endl;
	/* Extraire le contour.
	Cela se fait en trouvant les cycles d'aretes adjacente a une seule face, puis en cherchant les cycles de ces aretes.
	On r�cup�re le bord et les trous, le polygone de plus grande aire correspond au bord.*/
	map<pair<int,int>,int> nbFacesAdjacentes; //Nombre de faces adjacentes a chaque arete.
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
	//Trouver les ar�tes qui ont une seule face adjacente
	vector< pair<int,int> > bords;
	for(map<pair<int,int>,int>::iterator it = nbFacesAdjacentes.begin();it!=nbFacesAdjacentes.end();it++)
	{
		//cout<<it->first.first<<" -> "<<it->first.second<<" : "<<it->second<<endl;
		if(it->second == 1)
		{
			bords.push_back(it->first);
			//cout<<"( "<<it->first.first<<" -> "<<it->first.second<<" ) ";
		}
	}
	//cout<<endl;
	//cout<<"Ok apres les bords"<<endl;
	/*Pour l'instant, on prend seulement le premier bord, comme des sagouins*/
	//cout<<"Niombre d'ar�tes de bord :"<<bords.size()<<endl;
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
			//Trouver la suite (i.e. une ar�te de bord pas marqu�e adjacente � celle-l� par la 2e extr�mit�)
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
		/*cout<<cur_bord.size()<<endl;
	for(int i=0;i<cur_bord.size();i++)
		cout<<"("<<cur_bord[i].x<<" , "<<cur_bord[i].y<<" , "<<cur_bord[i].z<<" ) ->";
	cout<<endl;*/
		while(j<cur_bord.size())
		{
			int N = cur_bord.size();
			//V�rifier si les points j,j+1 et j+2 sont colin�aires (i.e. que leur produit vectoriel vaut 0 � une erreur pr�s).
			if(((cur_bord[(j+1)%N]-cur_bord[j]).normalize()^(cur_bord[(j+2)%N]-cur_bord[j]).normalize()).norm()<1e-3)
				cur_bord.erase(cur_bord.begin()+(j+1)%N);
			else
				j=j+1;
		}
		if(cur_bord.size()==0) //Devrait normalement pas arriver, mais certains mod�les sont d�g�n�r�s (triangles plats)
			continue;
		//On a trouv� un bord, on construit un polygone avec
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
	for(vector<int>::iterator it = faces.begin();it!=faces.end();it++)
	{
		Vec3* vertices = new Vec3[3];
		for(int i=0;i<3;i++)
			vertices[i] = Vec3(objData->vertexList[objData->faceList[*it]->vertex_index[i]]);
		p->triangles.push_back(vertices);
	}
	return p;
	//return NULL;
}


Polygone* ObjReader::composante2(int i,int cur_comp,bool* marque,
		set<pair<Vec3,Vec3> > seg_ext,
		set<pair<Vec3,Vec3> > seg_int)
{
	//cout<<"TRAITEMENT D'UN NOUVEAU POLYGONE"<<endl;
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
		for(set<int>::iterator it2= incidence_faces[j].begin(); it2 != incidence_faces[j].end(); it2++)
		{
			int k = *it2;
			//cout<<"ok iter "<<k<<endl;
			int s = k;
			//cout<<"ok s= "<<s<<endl;
			//cout<<incidence[s].size()<<endl;
			for(set<int>::iterator it = incidence[s].begin();it!=incidence[s].end();it++)
			{
				int voisin = *it;
				//cout<<"Voisin de la face "<<j<<" : "<<voisin<<endl;
				if((!marque[voisin]) && fabs(normales[j]*normales[voisin])>0.95) //METTRE LE SEUIL EN PARAMETRE (5 deg de d�viation autoris�s)
				{
					marque[voisin] =true;
					aVoir.push(voisin);
				}
			}
		}
	}
	/*for(vector<int>::iterator it = faces.begin();it!=faces.end();it++)
	{
		cout<<"(";
		int nAretes = objData->faceList[*it]->vertex_count;
		for(int k = 0;k<nAretes;k++)
			cout<<objData->faceList[*it]->vertex_index[k]<<", ";
		cout<<") ";
	}*/
	//cout<<"Ok avant copntour"<<endl;
	/* Extraire le contour.
	Cela se fait en trouvant les cycles d'aretes adjacente a une seule face, puis en cherchant les cycles de ces aretes.
	On r�cup�re le bord et les trous, le polygone de plus grande aire correspond au bord.*/
	map<pair<int,int>,int> nbFacesAdjacentes; //Nombre de faces adjacentes a chaque arete.
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
	//Trouver les ar�tes qui ont une seule face adjacente
	vector< pair<int,int> > bords;
	for(map<pair<int,int>,int>::iterator it = nbFacesAdjacentes.begin();it!=nbFacesAdjacentes.end();it++)
	{
		//cout<<it->first.first<<" -> "<<it->first.second<<" : "<<it->second<<endl;
		if(it->second == 1)
		{
			bords.push_back(it->first);
			//cout<<"( "<<it->first.first<<" -> "<<it->first.second<<" ) ";
		}
	}
	//cout<<endl;
	//cout<<"Ok apres les bords"<<endl;
	/*Pour l'instant, on prend seulement le premier bord, comme des sagouins*/
	//cout<<"Niombre d'ar�tes de bord :"<<bords.size()<<endl;
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
			//Trouver la suite (i.e. une ar�te de bord pas marqu�e adjacente � celle-l� par la 2e extr�mit�)
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
		/*cout<<cur_bord.size()<<endl;
	for(int i=0;i<cur_bord.size();i++)
		cout<<"("<<cur_bord[i].x<<" , "<<cur_bord[i].y<<" , "<<cur_bord[i].z<<" ) ->";
	cout<<endl;*/
		while(j<cur_bord.size())
		{
			int N = cur_bord.size();
			//V�rifier si les points j,j+1 et j+2 sont colin�aires (i.e. que leur produit vectoriel vaut 0 � une erreur pr�s).
			if(((cur_bord[(j+1)%N]-cur_bord[j]).normalize()^(cur_bord[(j+2)%N]-cur_bord[j]).normalize()).norm()<1e-3)
				cur_bord.erase(cur_bord.begin()+(j+1)%N);
			else
				j=j+1;
		}
		if(cur_bord.size()==0) //Devrait normalement pas arriver, mais certains mod�les sont d�g�n�r�s (triangles plats)
			continue;
		//On a trouv� un bord, on construit un polygone avec
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
	for(vector<int>::iterator it = faces.begin();it!=faces.end();it++)
	{
		Vec3* vertices = new Vec3[3];
		for(int i=0;i<3;i++)
			vertices[i] = Vec3(objData->vertexList[objData->faceList[*it]->vertex_index[i]]);
		p->triangles.push_back(vertices);
	}
	return p;
	//return NULL;
}




static Vec3 ObjReader::normale(obj_face* f,obj_vector** vertices)
{
	Vec3 v1(vertices[f->vertex_index[1]],vertices[f->vertex_index[0]]);
	Vec3 v2(vertices[f->vertex_index[2]],vertices[f->vertex_index[0]]);
	Vec3 normale = v1^v2;
	normale.normalize();
	return normale;
}
