#ifndef CONTRAINTE_ORTHO2_HEADER
#define CONTRAINTE_ORTHO2_HEADER

#include "../grammaire/condition/ConditionGenerale.h"
#include "../grammaire/parsing/Noeud.h"
#include "../grammaire/Parser.h"
#include <vector>
#include <iostream>
//La contrainte pour deux marches cons�cutives
class ContrainteOrtho2 : public ConditionGenerale
{
public: 
bool estVerifiee(vector<Noeud*> enfants, Parser* p)
{
	Polygone* p1 = (*enfants[0])["top"]->polygoneValue();
	Polygone* p2 = (*enfants[1])["front"]->polygoneValue();
	Polygone* p3 = (*enfants[0])["front"]->polygoneValue();
	Polygone* p4 = (*enfants[1])["top"]->polygoneValue();
	Vec3 n1(p1->equation[0],p1->equation[1],p1->equation[2]);
	Vec3 n2(p2->equation[0],p2->equation[1],p2->equation[2]);
	Vec3 n3(p3->equation[0],p3->equation[1],p3->equation[2]);
	return (n1*n2<0.1);
	
	//Pour chaque marche, trouver l'ar�te d'adjacence
	int arete1,arete2;
	for(int k=0;k<p1->points3D.size();k++)
			for(int l=0;l<p3->points3D.size();l++)
			{
				Vec3 a = p1->points3D[k];
				Vec3 b = p1->points3D[(k+1)%p1->size()];
				Vec3 c = p3->points3D[l];
				Vec3 d = p3->points3D[(l+1)%p3->size()];
				if(((a-c).norm()<0.1 && (b-d).norm()<0.1)||((a-d).norm()<0.1&&(b-c).norm()<0.1))
				{
					arete1 = k;
				}
			}
			
	for(int k=0;k<p2->points3D.size();k++)
			for(int l=0;l<p4->points3D.size();l++)
			{
				Vec3 a = p2->points3D[k];
				Vec3 b = p2->points3D[(k+1)%p2->points3D.size()];
				Vec3 c = p4->points3D[l];
				Vec3 d = p4->points3D[(l+1)%p4->points3D.size()];
				if(((a-c).norm()<0.1 && (b-d).norm()<0.1)||((a-d).norm()<0.1&&(b-c).norm()<0.1))
				{
					arete2 = k;
				}
			}
			
	//V�rifier que les deux top se situent bien de part et d'autre de l'ar�te commune
	/*float x1,y1,x2,y2;
	x1 = p1->points3D[arete1].x;
	y1 = p1->points3D[arete1].y;
	x2 = p1->points3D[(arete1+1)%4].x;
	y2 = p1->points3D[(arete1+1)%4].y;	
	float rotated_x = (y2-y1);
	float rotated_y = -(x2-x1);
	float sign1,sign2;
	for(int i=0;i<4;i++)
	{
		sign1 += rotated_x*(p1->points3D[i].x-x1) + rotated_y*(p1->points3D[i].y-y1);
		sign2 += rotated_x*(p4->points3D[i].x-x1) + rotated_y*(p4->points3D[i].y-y1);
	}
	if(sign1*sign2<0)
		return false;*/
		
		//V�rifier qu'il y ait bien adjacence au niveau de l'ar�te parall�le au lieu d'adjacence
	Vec3 a = p1->points3D[(arete1+2)%4];
				Vec3 b = p1->points3D[(arete1+3)%4];
				Vec3 c = p2->points3D[(arete2+2)%4];
				Vec3 d = p2->points3D[(arete2+3)%4];
	
	if(((a-c).norm()<0.1 && (b-d).norm()<0.1)||((a-d).norm()<0.1&&(b-c).norm()<0.1))
					return (n1*n2<0.1) && (abs((n2*n3)-1)<0.1);
	return false;
}
};

#endif
