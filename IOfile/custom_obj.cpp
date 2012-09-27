#include "custom_obj.h"

#include "../geometrie/Polygone.h"

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void Custom_obj::write_obj_file_terminaux(const std::string &filename, vector<Noeud*> &forest) const
{
	//on ne veut ecrire que ceux qui sont terminaux

	cout << "Writing Custom Obj file" << endl;

	ofstream os(filename.c_str());
	if(!os.is_open()){
		cout << "Error while opening file" << endl;
		return;
	}

	map<Polygone*, bool> used;

	for(int i=0; i<forest.size(); i++){
		if(forest[i]->getEnfants().size()==0){
			used[forest[i]->attributs["primitive"]->polygoneValue()] = false;
		}
	}

	os.close();

	cout << "Endl" << endl;

}
