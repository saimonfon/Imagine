#include <iostream>
#include <vector>
#include <queue>
#include "geometrie/Polygone_Detector.h"
#include "geometrie/FileReader.h"
#include "grammaire/Parser.h"
#include "grammaire/condition/ConditionAdj.h"
#include "grammaire/regles/CalculAttributs.h"
#include "grammaire/Regle.h"
#include "grammaire/MembreDroit.h"
#include "grammaire/MembreStandard.h"
#include "grammaire/OperateurSequence.h"
#include "grammaire/parsing/Noeud.h"
#include "user/parserescalier.h"
#include "user/parserTest.h"
#include "user/parserHLM.h"
#include <time.h>
#include <fstream>
#include "gui/MainWindow.h"
#include "geometrie/ObjReader.h"
#include "geometrie/Modele.h"
#include <QtGui>
using namespace std;



int gui(int argc, char** argv)
{
	QApplication app(argc, argv);
	MainWindow fenetre;
	fenetre.show();
	return app.exec();
}

void test(){
	ObjReader f("models/test2.obj");

	Modele* m2 = f.polygones2(0.01);
	cout << "M2" << endl;
	cout << m2->polygones.size() << endl;
	/*for(map<Polygone*,set<Polygone*> >::iterator it=m2->adj.begin(); it != m2->adj.end(); it++){
		cout << " " << it->first->number << endl;
	}*/

	for(int i=0; i<m2->polygones.size(); i++){
		cout << m2->polygones[i]->number << endl;

		cout << "Nombre de trous : " << m2->polygones[i]->trous.size() << endl;
		for(int j=0; j<m2->polygones[i]->trous.size(); j++){
			for(int k=0; k<m2->polygones[i]->trous[j]->points3D.size(); k++){
				cout << m2->polygones[i]->trous[j]->points3D[k].x << " ";
				cout << m2->polygones[i]->trous[j]->points3D[k].y << " ";
				cout << m2->polygones[i]->trous[j]->points3D[k].z << " ";
				cout << endl;
			}
			cout << "-------------" << endl;
		}
		cout<<endl;

	}

	cout << "Adjacence exterieure" << endl;
	for(map<Polygone*, set<Polygone*> >::iterator it=m2->adj_edge_ext.begin(); it != m2->adj_edge_ext.end(); it++){
		cout << it->first->number << " --> ";
		for(set<Polygone*>::iterator itset= it->second.begin(); itset != it->second.end(); itset++){
			cout << (*itset)->number << " ";
		}
		cout << endl;
	}

	cout << "Adjacence interieure" << endl;
	for(map<Polygone*, set<Polygone*> >::iterator it=m2->adj_edge_int.begin(); it != m2->adj_edge_int.end(); it++){
		cout << it->first->number << " --> ";
		for(set<Polygone*>::iterator itset= it->second.begin(); itset != it->second.end(); itset++){
			cout << (*itset)->number << " ";
		}
		cout << endl;

	}

	cout << "Parser" << endl;
	m2->normaliser();
	m2->setEchelle(1);
	Parsertest p;
	p.parse(m2,2);
	cout << "End" << endl;

}

void remise_en_forme();

int main(int argc, char** argv)
{
	//test();
	gui(argc,argv);
	//remise_en_forme();
}

/***
 * fonction de remise en forme du nuage (on veut supprimer les vertex redondants)
 *
 */

void remise_en_forme(){

	ObjReader f("models/immeuble.obj");

	int M = f.objData->faceCount;
	int N = f.objData->vertexCount;

	map<Vec3,int> vertices;
	vector<Vec3> vert;
	vector<int> faces;

	int compteur = 0;
	for(int i=0; i<M; i++){
		for(int j=0; j<3; j++){
			Vec3 cur(f.objData->vertexList[f.objData->faceList[i]->vertex_index[j]]);
			map<Vec3,int>::iterator itmap = vertices.find(cur);
			int indexv;
			if(itmap == vertices.end()){
				vertices[cur] = compteur;
				vert.push_back(cur);
				indexv = compteur;
				compteur++;
			}else{
				indexv = itmap->second;
			}
			faces.push_back(indexv);
		}
	}

	//ecriture du .obj

	string out = "outObj.obj";
	ofstream os(out.c_str());
	if(! os.is_open()){
		cout << "Error, opening file"<< endl;
		return;
	}

	os << "# test" << endl;
	os << "# " << endl;
	os << endl;

	for(int i=0; i<vert.size(); i++){
		os << "v " << vert[i].x << " " << vert[i].y << " " << vert[i].z << endl;
	}
	os << endl;
	for(int i=0; i<faces.size(); i+=3){
		os << "f ";
		os << faces[i]+1 << " ";
		os << faces[i+1]+1 << " ";
		os << faces[i+2]+1 << endl;
	}

	os.close();

}

