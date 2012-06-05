#include "Terminal.h"
#include "../../geometrie/Vec3.h"
vector<Noeud*> Terminal::getEnfants()
{
	return vector<Noeud*>();
}
string Terminal::getType()
{
	return string("polygone");
}

Terminal::Terminal(Polygone* polygone, int number)
{
	attributs = map<string,void*>();
	attributs["primitive"] = polygone;
	attributs["number"] = (void*) number;
	if(polygone->points3D.size()>0) //Utilise t on les coordonnées 3D ?
	{
	cout<<number<<" "<<abs(Vec3(polygone->equation[0],polygone->equation[1],polygone->equation[2])*Vec3(0,0,1))<<" "<<polygone->getArea()<<endl;
	Vec3 normale(polygone->equation[0],polygone->equation[1],polygone->equation[2]);
	attributs["vert_or_hor"] = (void*)false;
	//Verticalité
	if(abs(normale*Vec3(0,0,1))<0.1)
	{
		attributs["vertical"] = (void*)true;
		attributs["vert_or_hor"] = (void*)true;
		}
		else
		attributs["vertical"] = (void*)false;
		
	//Horizontalité	
	if(abs(abs(normale*Vec3(0,0,1))-normale.norm())<0.1)
	{
		attributs["horizontal"] = (void*)true;
		attributs["vert_or_hor"] = (void*)true;
		}
		else
		attributs["horizontal"] = (void*)false;
		}
	score=1;
}

bool Terminal::equals(Noeud* n)
{
	return n==this; //Un seul terminal créé donc on peut comparer les pointeurs
} 