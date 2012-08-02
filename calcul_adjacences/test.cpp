#include <iostream>
#include "prog_grammaires\geometrie\Vec3.h"
#include <vector>
#include <map>
#include <set>
#include <fstream>
using namespace std;
int main()
{
	std::ifstream infile("samples.txt");
float x,y,z;
int n;int i=0;
float minX=0, minY=0 ,minZ=0;
float maxX=0, maxY=0 ,maxZ=0;
vector<vector<Vec3> > points; 
while(!infile.eof())
	{
	infile>>n;
	vector<Vec3> samples;
	for(int j=0;j<n;j++)
	{
		infile>>x>>y>>z;
		if(x<minX) minX=x;
		if(y<minY) minY=y;
		if(z<minZ) minZ=z;
		if(x>maxX) maxX=x;
		if(y>maxY) maxY=y;
		if(z>maxZ) maxZ=z;
		samples.push_back(Vec3(x,y,z));
	}
	points.push_back(samples);
	}

bool** adj = new bool*[points.size()];
for(int i=0;i<points.size();i++)
{
	adj[i] = new bool[points.size()];
	for(int j=0;j<points.size();j++)
		adj[i][j]=false;
}

int nb_cell = 100;
float pas = max(maxX-minX,max(maxY-minY,maxZ-minZ))/nb_cell;
for(int iter=0;iter<8;iter++)
{
map<int,set<int> > grille;
for(int i=0;i<points.size();i++)
{
	for(int j=0;j<points[i].size();j++)
	{
		int indX = floor((points[i][j].x-minX + ((iter%8==0)?(pas/2):0))/pas);
		int indY = floor((points[i][j].y-minY + ((iter/8<4)?(pas/2):0))/pas);
		int indZ = floor((points[i][j].z-minZ + ((iter%4<2)?(pas/2):0))/pas);
		grille[indX*nb_cell*nb_cell + indY*nb_cell + indZ].insert(i);
	}
}
for(map<int,set<int> >::iterator it = grille.begin();it!=grille.end();it++)
{
	for(set<int>::iterator it2 = it->second.begin();it2!=it->second.end();it2++)
		for(set<int>::iterator it3 = it->second.begin();it3!=it->second.end();it3++)
			if((*it2)!=(*it3))
				adj[*it2][*it3]=true;
}
}
for(int i=0;i<points.size();i++)
{
for(int j=0;j<points.size();j++)
	cout<<(adj[i][j]? "1":"0")<<" ";
cout<<endl;
}

}