#ifndef CALCULATTFC_H
#define CALCULATTFC_H
#include "regles/CalculAttributs.h"
#include "../geometrie/Polygone.h"
class CalculAttFenetreComplete : public CalculAttributs
{
//Trouver le plan d'accroche au mur
void calculAttrib(Noeud* nouveau){
cout<<"Début du calcul des attributs"<<endl;
cout<<"Taille de eefenfants"<<nouveau->getEnfants().size()<<endl;
cout<<nouveau->getEnfants()[0]->nom_parser<<endl;
cout<<(*(nouveau->getEnfants()[0]))["primitive"]<<endl;
Polygone* f = (Polygone*) (*(nouveau->getEnfants()[0]))["primitive"];
cout<<"Ok fenetre"<<endl;
Noeud* rebord = nouveau->getEnfants()[1];
//Prendre deux rebords opposés.
cout<<"Taille de rebord :"<<rebord->getEnfants().size()<<endl;
Polygone* r1 = (Polygone*) ((*(rebord->getEnfants()[0]))["primitive"]);
Polygone* r2 = (Polygone*) ((*(rebord->getEnfants()[2]))["primitive"]);
cout<<"ok rebords opposés"<<endl;

//Trouver les arêtes adjacentes pour ces 2 rebords
int arete1,arete2;
	for(int k=0;k<r1->size();k++)
			for(int l=0;l<f->size();l++)
			{
				Vec3 a = (*r1)[k];
				Vec3 b = (*r1)[(k+1)%r1->size()];
				Vec3 c = (*f)[l];
				Vec3 d = (*f)[(l+1)%f->size()];
				if(((a-c).norm()<0.1 && (b-d).norm()<0.1)||((a-d).norm()<0.1&&(b-c).norm()<0.1))
				{
					arete1 = k;
				}
			}
			
	for(int k=0;k<r2->size();k++)
			for(int l=0;l<f->size();l++)
			{
				Vec3 a = (*r2)[k];
				Vec3 b = (*r2)[(k+1)%r2->size()];
				Vec3 c = (*f)[l];
				Vec3 d = (*f)[(l+1)%f->size()];
				if(((a-c).norm()<0.1 && (b-d).norm()<0.1)||((a-d).norm()<0.1&&(b-c).norm()<0.1))
				{
					arete1 = k;
				}
			}
			
cout<<"Ok arreêtes"<<endl;

//Trouver les 4 points opposés à la fenetre
Vec3 p1 = (*r1)[(arete1 + 2)%4];
Vec3 p2 = (*r1)[(arete1 + 3)%4];
Vec3 p3 = (*r2)[(arete2 + 2)%4];
Vec3 p4 = (*r2)[(arete2 + 3)%4];
//Trouver le plan qui passe par les 4 points (on en prend que 3)
Vec3 normale = (p2-p1)^(p3-p1);
if(normale.y<0)
		normale = Vec3(0,0,0)-normale;
	normale.normalize();
	float d = - (normale*p1);
	float* equation = new float[4];
	equation[0]  = normale.x;
	equation[1]  = normale.y;
	equation[2]  = normale.z;
	equation[3]  = d;
nouveau->setAttribut("plan",equation);
cout<<"Fin du calcul des attributs"<<endl;
cout<<"Fenetre complete :"<<equation[0]<<" "<<equation[1]<<" "<<equation[2]<<" "<<equation[3]<<endl;
}
};
#endif