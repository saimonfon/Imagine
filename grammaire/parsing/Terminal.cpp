#include "Terminal.h"
#include "../../geometrie/Vec3.h"
#include "../attributs/Attribut.h"
vector<Noeud*> Terminal::getEnfants() const
{
	return vector<Noeud*>();
}
string Terminal::getType() const
{
	return string("polygone");
}

Terminal::Terminal(Polygone* polygone, int number)
{
	attributs = map<string,Attribut*>();
	attributs["primitive"] = new AttributPoly(polygone);
	attributs["number"] = new AttributInt(number);
	attributs["plan"] =  new AttributPtr(polygone->equation);
	if(polygone->points3D.size()>0) //Utilise t on les coordonnées 3D ?
	{
	cout<<number<<" "<<abs(Vec3(polygone->equation[0],polygone->equation[1],polygone->equation[2])*Vec3(0,0,1))<<" "<<polygone->getArea()<<endl;
	Vec3 normale(polygone->equation[0],polygone->equation[1],polygone->equation[2]);
	attributs["vert_or_hor"] = new AttributBool(false);
	//Verticalité
	if(abs(normale*Vec3(0,0,1))<0.1)
	{
		attributs["vertical"] = new AttributBool(true);
		attributs["vert_or_hor"] = new AttributBool(true);
		}
		else
		attributs["vertical"] = new AttributBool(false);
		
	//Horizontalité	
	if(abs(abs(normale*Vec3(0,0,1))-normale.norm())<0.01)
	{
		attributs["horizontal"] = new AttributBool(true);
		attributs["vert_or_hor"] = new AttributBool(true);
		}
		else
		attributs["horizontal"] = new AttributBool(false);
		}
	if(polygone->points3D.size()==4) //On considère que c'est un rectangle si 4 sommets
	attributs["rectangle"] = new AttributBool(true);
	else
	attributs["rectangle"] = new AttributBool(false);
	score=1;
	attributs["area"] = new AttributFloat(polygone->getArea());
}

bool Terminal::equals(const Noeud* n) const
{
	return n==this; //Un seul terminal créé donc on peut comparer les pointeurs
} 