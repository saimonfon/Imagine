#include "objLoader/objLoader.h"
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
#include <irrlicht.h>
#include <time.h>
#include <fstream>
using namespace std;
using namespace irr;

void irrlichtShowPolygons (vector<Polygone*> v);
void test(int n);
/*void test2();
void test3();
void testAuto();
void testEscalier();*/

/*void testAuto()
{
	FileReader f;
	vector<Polygone*> maison = f.readFile("hlm.txt");
	ParserHLM* parser = new ParserHLM();
	parser->adj = f.adj;
	parser->parse(maison);
	//irrlichtShowPolygons(maison);
}*/
int main()
{
		//test2();
		/*for(int i=10;i<=1500;i*=2)
			test(i);*/
		test(20);
        return 0; 
		//test3();
		//testAuto();
		//testEscalier();
}

/*void testEscalier()
{
	FileReader f;
	vector<Polygone*> maison = f.readFile("christian01.txt");
	Parserescalier* parser = new Parserescalier();
	parser->adj = f.adj;
	parser->parse(maison);
}*/

/*void test3()
{
std::vector<Polygone*> plusieurs_cycles;
map<Polygone*, set<Polygone*> > adj;
for(int i=0;i<10;i++)
{
	Polygone* p1 = new Polygone();
	Polygone* p2 = new Polygone();
	Polygone* p3 = new Polygone();
	adj[p1].insert(p2);
	adj[p2].insert(p1);
	adj[p1].insert(p3);
	adj[p3].insert(p1);
	adj[p2].insert(p3);
	adj[p3].insert(p2);
	plusieurs_cycles.push_back(p1);
	plusieurs_cycles.push_back(p2);
	plusieurs_cycles.push_back(p3);
}
Parser* p = new Parser();
p->adj=adj;
RegleCycle* r2 = new RegleCycle("maison","polygone");
r2->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
p->ajouterRegle(r2); 
clock_t start = clock();
p->parse(plusieurs_cycles);
cout<<(((double)clock() - start) / CLOCKS_PER_SEC)<<endl;
}*/

void test(int n)
{

class SyntheseRegle1 : public CalculAttributs
{
	void calculAttrib(Noeud* nouveau)
	{
		
		nouveau->setAttribut("primitive1",nouveau->getEnfants()[0]->getAttribut("primitive"));
		nouveau->setAttribut("primitive2",nouveau->getEnfants()[1]->getAttribut("primitive"));
		//cout<<"primitive1 du noeud"<<nouveau->nom_parser<<" mis à "<<nouveau->getAttribut("primitive1")<<endl;
		//cout<<"primitive2 du noeud"<<nouveau->nom_parser<<" mis à "<<nouveau->getAttribut("primitive2")<<endl;
	}
};

std::vector<Polygone*> escalier;
map<Polygone*, set<Polygone*> > adj;
Polygone* prev=NULL; //Pour l'adjacence
for(int i=0;i<n;i++)
{
	if(i%10==5)
	{
		prev=NULL;
		continue;
	}
	Polygone* p = new Polygone();
	vector<point2d> contour;
	contour.push_back(point2d(0,i));
	contour.push_back(point2d(0,i+1));
	contour.push_back(point2d(5,i+1));
	contour.push_back(point2d(5,i));
	p->x = i;
	p->backRot = new Matrice2(1,0,0,1);
	p->setContour(contour);
	if(prev!=NULL)
	{
		adj[p].insert(prev);
		adj[prev].insert(p);
	}
	Polygone* p2 = new Polygone();
	vector<point2d> contour2;
	contour2.push_back(point2d(0,i));
	contour2.push_back(point2d(0,i+1));
	contour2.push_back(point2d(5,i+1));
	contour2.push_back(point2d(5,i));
	p2->x = -(i+1);
	p2->backRot = new Matrice2(0,1,-1,0);
	p2->setContour(contour2);
	adj[p2].insert(p);
	adj[p].insert(p2);
	escalier.push_back(p);
	escalier.push_back(p2);
	prev=p2;
}
Parser* p = new Parser();
p->adj=adj;
vector<MembreDroit*> membresDroits;
membresDroits.push_back(new MembreStandard("polygone"));
membresDroits.push_back(new MembreStandard("polygone"));
Regle* r = new Regle("marche",membresDroits);
r->condAdj.push_back(new ConditionAdj(0,"primitive",1,"primitive"));
r->calculAtt = new SyntheseRegle1();
membresDroits.clear();
OperateurSequence* op = new OperateurSequence("marche");
op->condAdj.push_back(new ConditionAdj(0,"primitive2",1,"primitive1"));
membresDroits.push_back(op);
Regle* r2 = new Regle("escalier",membresDroits);
p->ajouterRegle(r);
p->ajouterRegle(r2); 
clock_t start = clock();
p->parse(escalier);
ofstream f;
	f.open("temps",ios_base::app);
f<<(2*n)<<"|"<<(((double)clock() - start) / CLOCKS_PER_SEC)<<endl;
f.close();
//irrlichtShowPolygons(escalier);
}

void irrlichtShowPolygons (vector<Polygone*> v)
{
	IrrlichtDevice *device = createDevice(video::EDT_OPENGL,
                core::dimension2d<u32>(1000, 800));

        if (device == 0)
                return; // could not create selected driver.

        device->setWindowCaption(L"Irrlicht Engine - 2D Graphics Demo");

        video::IVideoDriver* driver = device->getVideoDriver();       
		scene::ISceneManager* smgr = device->getSceneManager();
		smgr->addCameraSceneNodeFPS();
		
		video::SColor* colors = new video::SColor[v.size()];
		for(int i=0;i<v.size();i++)
			colors[i] = video::SColor(255,rand()%255,rand()%255,rand()%255);
while(device->run() && driver)
        {
                if (device->isWindowActive())
                {
				driver->beginScene(true, true, video::SColor(255,0,0,0));
				smgr->drawAll();
				video::SMaterial m;
            m.Lighting=false;
            driver->setMaterial(m);
            driver->setTransform(video::ETS_WORLD, core::IdentityMatrix); 
				vector<Polygone*>::iterator it;
				//cout<<polygones.size()<<endl;
				int poly=0;
				for(it = v.begin();it!=v.end();it++)
				{
					Polygone* p = *it;
					//cout<<p->x<<endl;
					//cout<<p->contour.size()<<endl;
					//cout<<p->area()<<endl;
					for(int i=0;i<p->contour.size();i++)
					{
						point2d p1 = p->contour.at(i);
						point2d p2 = p->contour.at((i+1)%(p->contour.size()));
						Matrice2* matrice = p->backRot;
						float** m = matrice->mat;
						core::vector3df start(m[0][0]*p->x + m[0][1]*p1.y,p1.x,m[1][0]*p->x + m[1][1]*p1.y);
						core::vector3df end(m[0][0]*p->x + m[0][1]*p2.y,p2.x,m[1][0]*p->x + m[1][1]*p2.y);
						//core::vector3df start(p1.x,p1.y,poly);
						//core::vector3df end(p2.x,p2.y,poly);
						//cout<<start.X<<" "<<start.Y<<" "<<start.Z<<" "<<endl;
						driver->draw3DLine(start,end,colors[poly]);
					}
					poly++;
					 //cout<<objData->vertexCount<<endl;
					//for(int i=0;i<p->nb_faces;i++)
					//cout<<p->belongingFaces[i]<< " ";
					//cout<<endl; 
					//cout<<p->nb_faces<<endl;
					 //if(shouldDraw[poly-1])
					//driver->drawIndexedTriangleList(vertices,objData->vertexCount,p->belongingFaces,p->nb_faces); 
				}
				driver->endScene();
                }
        }

        device->drop();
}

void test2()
{
objLoader *objData = new objLoader();
objData->load("models/maison.obj");

// read the scene dta into your data structures
cout<<"Vertices :"<<objData->vertexCount<<endl;

//Identification des polygones
Polygone_Detector detector;
vector<Polygone*> polygones = detector.detect(objData->faceList,objData->faceCount,objData->vertexList);

//Dessin des polygones
video::S3DVertex *  	vertices = new video::S3DVertex[objData->vertexCount];
for(int i=0;i<objData->vertexCount;i++)
{
	video::S3DVertex v;
	v.Pos = core::vector3df(objData->vertexList[i]->e[0],objData->vertexList[i]->e[1],objData->vertexList[i]->e[2]);
	v.Color = video::SColor(50,255,255,255);
	v.Normal = core::vector3df(objData->normalList[i]->e[0],objData->normalList[i]->e[1],objData->normalList[i]->e[2]);
	vertices[i] = v;
}

bool* shouldDraw = new bool[objData->vertexCount];
for(int i=0;i<objData->vertexCount;i++)
if(rand()/(double)RAND_MAX>0)
shouldDraw[i]=true;
else
shouldDraw[i]=false;

irrlichtShowPolygons(polygones);

delete(objData);
}