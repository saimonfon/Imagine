#include "MainWindow.h"
#include <QApplication>
#include <QtGui>
#include <QPushButton>
#include "SimpleViewer.h"
#include <QGLViewer/qglviewer.h>
#include "treemodel.h"
#include "treeitem.h"
#include <queue>
#include <map>
#include "../geometrie/FileReader.h"
 #include <QSvgWidget>
 #include "../geometrie/ObjReader.h"
 #include "../geometrie/Modele.h"
#include "../user/ParserHLM.cpp"
#include "../user/parserescalier.cpp"

class Parserescalier;
MainWindow::MainWindow() : QMainWindow()
{
	
	QMenu* fileMenu = menuBar()->addMenu(tr("&Fichier"));
	QAction* chargerTxt = new QAction("Charger modèle texte",fileMenu);
	QAction* chargerObj = new QAction("Charger modèle Obj",fileMenu);
	fileMenu->addAction(chargerTxt);
	fileMenu->addAction(chargerObj);
	connect(chargerTxt,SIGNAL(triggered()),this,SLOT(chargerFichierTexte()));
	connect(chargerObj,SIGNAL(triggered()),this,SLOT(chargerFichierObj()));
	QAction*  gHLMAct = new QAction(tr("&HLM"), fileMenu);
	QAction*  gescAct = new QAction(tr("&Escalier"), fileMenu);
     gHLMAct->setCheckable(true);
	 gescAct->setCheckable(true);
	 QActionGroup* choixGram = new QActionGroup(fileMenu);
	 choixGram->addAction(gHLMAct);
	 choixGram->addAction(gescAct);
	 QMenu* gMenu = fileMenu->addMenu("&Grammaire");
	 gMenu->addAction(gHLMAct);
	 gMenu->addAction(gescAct);
	connect(chargerTxt,SIGNAL(triggered()),this,SLOT(chargerFichierTexte()));
	QSignalMapper *signalMapper = new QSignalMapper(this);
	 signalMapper->setMapping(gHLMAct, 0);
	  signalMapper->setMapping(gescAct, 1);
	  connect(gHLMAct,SIGNAL(triggered()),signalMapper,SLOT(map()));
	  connect(gescAct,SIGNAL(triggered()),signalMapper,SLOT(map()));
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(changerGrammaire(int)));
	 gHLMAct->setChecked(true);
	 changerGrammaire(0);
	
	QMenu* execMenu = menuBar()->addMenu(tr("&Exécuter"));
	QAction* a_executer = new QAction("Totalement",execMenu);
	execMenu->addAction(a_executer);
	connect(a_executer,SIGNAL(triggered()),this,SLOT(executer()));
	QAction* a_executerPartiel = new QAction("Partiellement",execMenu);
	execMenu->addAction(a_executerPartiel);
	connect(a_executerPartiel,SIGNAL(triggered()),this,SLOT(executerPartiel()));
	
	QMenu* modelMenu = menuBar()->addMenu(tr("&Modèle"));
	QAction* inverser = new QAction("Inverser axes Y et Z",modelMenu);
	modelMenu->addAction(inverser);
	connect(inverser,SIGNAL(triggered()),this,SLOT(inverserAxesModele()));
	
	QMenu* graphMenu = menuBar()->addMenu(tr("&Graphes"));
	QAction* exclu = new QAction("Graphe d'exclusivité",graphMenu);
	QAction* adj = new QAction("Graphe d'adjacence",graphMenu);
	graphMenu->addAction(exclu);
	graphMenu->addAction(adj);
	connect(exclu,SIGNAL(triggered()),this,SLOT(afficherExclu()));
	connect(adj,SIGNAL(triggered()),this,SLOT(afficherAdj()));
	tabs = new QTabWidget;
	resultWidget = new QWidget;
	modelWidget = new QWidget;
	tabs->addTab(modelWidget,"Modèle");
	tabs->addTab(resultWidget,"Résultat");
	this->setCentralWidget(tabs);
	
}

void MainWindow::afficherElems(const QModelIndex& index)
{
TreeItem* item = static_cast<TreeItem*>(index.internalPointer());
	qDebug()<<QString::fromStdString(item->n->nom_parser)<<" "<<endl;
Noeud* n = item->n;	
bool * indices = new bool[p->terminaux.size()];
for(int i=0;i<p->terminaux.size();i++)
	indices[i]=false;
	
	queue<Noeud*> aVoir;
		aVoir.push(n);
	while(!aVoir.empty())
	{
		Noeud* n = aVoir.front();
		aVoir.pop();
		if(n->getType().compare("polygone")==0)
		{
			qDebug()<<QString::number(n->getAttribut("number")->intValue()-1)<<endl;
			indices[n->getAttribut("number")->intValue()] = true;
		}
		vector<Noeud*> enfants = n->getEnfants();
		for(vector<Noeud*>::iterator it = enfants.begin();it!=enfants.end();it++)
		{
			aVoir.push(*it);
		}
	}
	
	v->setColoredIndices(indices);
	v->update();
	}

void MainWindow::afficherExclu()
{
//Générer un SVG avec GraphViz
QFile f("exclu.dot");
if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
         return;
QTextStream out(&f);
out<<"graph G{\n";
for(map<Noeud*,set<Noeud*> >::iterator it = p->exclusivite.begin();it!=p->exclusivite.end();it++)
{
	for(set<Noeud*>::iterator it2 = it->second.begin();it2!=it->second.end();it2++)
		out<<QString::fromStdString(it->first->nom_parser)<<" -- "<<QString::fromStdString((*it2)->nom_parser)	<<"\n";
}
out<<"}";
f.close();
system("dot -Tsvg exclu.dot > exclu.svg");
//Afficher le SVG avec Qt
QSvgWidget svgWidget("exclu.svg");
svgWidget.show();
}

void MainWindow::afficherAdj()
{
//Générer un SVG avec GraphViz
QFile f("adj.dot");
if (!f.open(QIODevice::WriteOnly | QIODevice::Text))
         return;
QTextStream out(&f);
out<<"graph G{\n";
for(map<Polygone*,set<Polygone*> >::iterator it = p->adj.begin();it!=p->adj.end();it++)
{
	for(set<Polygone*>::iterator it2 = it->second.begin();it2!=it->second.end();it2++)
		out<<it->first->number<<" -- "<<(*it2)->number<<"\n";
}
out<<"}";
f.close();
system("dot -Tsvg adj.dot > adj.svg");
//Afficher le SVG avec Qt
QSvgWidget* svgWidget = new QSvgWidget("adj.svg");
svgWidget->show();
}

void MainWindow::afficherArbre()
{
if(!view->currentIndex().isValid())
	return;
TreeItem* item = static_cast<TreeItem*>(view->currentIndex().internalPointer());
p->generateDot("arbre.dot",item->n);
system("dot -Tsvg arbre.dot > arbre.svg");
//Afficher le SVG avec Qt
QSvgWidget* svgWidget = new QSvgWidget("arbre.svg");
svgWidget->show();
}

void MainWindow::chargerFichierTexte()
{
	QString fileName = QFileDialog::getOpenFileName(this,"Charger un modèle au format texte",QString(),"Fichiers texte (*.txt)");
	if(fileName.isNull())
		return;
	FileReader f;
	modele = f.readFile(fileName.toStdString());
	scaleModel();
	afficherModele();
}

void MainWindow::inverserAxesModele()
{
qDebug()<<"Inversion des axes !"<<endl;
for(vector<Polygone*>::iterator it = modele->polygones.begin();it!=modele->polygones.end();it++)
{
	for(vector<Vec3>::iterator it2 = (*it)->points3D.begin();it2!=(*it)->points3D.end();it2++)
	{
	cout<<it2->y<<" "<<it2->z;
		it2->inverserYetZ();
	cout<<"--->"<<it2->y<<" "<<it2->z<<endl;
	}
}
afficherModele();
}

void MainWindow::scaleModel()
{
/* Scaling pour que le modèle soit inclus dans le carré de côté 1*/
float max_size=0;	
for(vector<Polygone*>::iterator it = modele->polygones.begin();it!=modele->polygones.end();it++)
{
for(vector<Vec3>::iterator it2 = (*it)->points3D.begin();it2!=(*it)->points3D.end();it2++)
{
  if((*it2).x > max_size)
	max_size = (*it2).x;
  if((*it2).y > max_size)
	max_size = (*it2).y;
	  if((*it2).z > max_size)
	max_size = (*it2).z;
}
}
float scale = 1 / max_size;

for(vector<Polygone*>::iterator it = modele->polygones.begin();it!=modele->polygones.end();it++)
{
for(vector<Vec3>::iterator it2 = (*it)->points3D.begin();it2!=(*it)->points3D.end();it2++)
{
  it2->x  =it2->x*scale;
  it2->y  =it2->y*scale;
  it2->z  =it2->z*scale;
}
}
}

void MainWindow::chargerFichierObj()
{
	QString fileName = QFileDialog::getOpenFileName(this,"Charger un modèle au format obj",QString(),"Fichiers Wavefront (*.obj)");
	if(fileName.isNull())
		return;
	ObjReader f(fileName.toStdString());
	modele = f.polygones();
	scaleModel();
	afficherModele();
}

void MainWindow::afficherModele()
{
tabs->removeTab(0);
	delete modelWidget;
	modelWidget = new Viewer(modele->polygones);
	tabs->insertTab(0,modelWidget,"Modèle");
	setWindowTitle(QString::number(modele->polygones.size())+" primitives");
}

void MainWindow::executer()
{
p->parse(modele);
v= new Viewer(p->terminaux);
	bool * indices = new bool[p->terminaux.size()];
	v->setColoredIndices(indices); 
     TreeModel* model = new TreeModel(p);
	 view = new QTreeView();
	 connect(view,SIGNAL(activated(const QModelIndex&)), this, SLOT(afficherElems(const QModelIndex&)));
     view->setModel(model);
	 QSplitter* s = new QSplitter();
	s->addWidget(view);
	s->addWidget(v);
	QList<int> sizes;
	sizes<<200<<200;
	s->setSizes(sizes);
	view->setContextMenuPolicy(Qt::ActionsContextMenu);
	QAction* showTree = new QAction("Arbre de dérivation",view);
	connect(showTree,SIGNAL(triggered()),this,SLOT(afficherArbre()));
	view->addAction(showTree);
	tabs->removeTab(1);
	delete resultWidget;
	resultWidget = s;
	tabs->insertTab(1,resultWidget,"Résultat");
}

void MainWindow::executerPartiel()
{
bool ok;
int nb_iter = QInputDialog::getInt (this,"Execution partielle","Nombre maximal d'itérations :", 3, 1,1000, 1, &ok);
if(!ok)
	return;
p->parse(modele,nb_iter);
v= new Viewer(p->terminaux);
	bool * indices = new bool[p->terminaux.size()];
	v->setColoredIndices(indices); 
     TreeModel* model = new TreeModel(p);
	 view = new QTreeView();
	 connect(view,SIGNAL(activated(const QModelIndex&)), this, SLOT(afficherElems(const QModelIndex&)));
     view->setModel(model);
	 QSplitter* s = new QSplitter();
	s->addWidget(view);
	s->addWidget(v);
	QList<int> sizes;
	sizes<<200<<200;
	s->setSizes(sizes);
	view->setContextMenuPolicy(Qt::ActionsContextMenu);
	QAction* showTree = new QAction("Arbre de dérivation",view);
	connect(showTree,SIGNAL(triggered()),this,SLOT(afficherArbre()));
	view->addAction(showTree);
	tabs->removeTab(1);
	delete resultWidget;
	resultWidget = s;
	tabs->insertTab(1,resultWidget,"Résultat");
}

void MainWindow::changerGrammaire(int grammaire)
{
	switch(grammaire)
	{
		case 0:
		p = new ParserHLM();
		break;
		case 1:
		p = new Parserescalier();
		break;
		default :
		p=new ParserHLM();
		break;
	}
}