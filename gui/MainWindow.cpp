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
#include "../user/parsermurs.cpp"
#include "../user/ParserHLMSimple.cpp"
#include "../user/ParserReel.cpp"

class Parserescalier;
MainWindow::MainWindow() : QMainWindow()
{
	
	QMenu* fileMenu = menuBar()->addMenu(tr("&Fichier"));
	QAction* chargerTxt = new QAction("Charger mod�le texte",fileMenu);
	QAction* chargerObj = new QAction("Charger mod�le Obj",fileMenu);
	fileMenu->addAction(chargerTxt);
	fileMenu->addAction(chargerObj);
	connect(chargerTxt,SIGNAL(triggered()),this,SLOT(chargerFichierTexte()));
	connect(chargerObj,SIGNAL(triggered()),this,SLOT(chargerFichierObj()));
	QAction*  gHLMAct = new QAction(tr("&HLM"), fileMenu);
	QAction*  gescAct = new QAction(tr("&Escalier"), fileMenu);
	QAction*  gmursAct = new QAction(tr("&Murs"), fileMenu);
	QAction*  gHLMsimpleAct = new QAction(tr("&HLM Simple"), fileMenu);
	QAction*  gReelAct = new QAction(tr("&Donn�es r�elles"), fileMenu);
     gHLMAct->setCheckable(true);
	 gescAct->setCheckable(true);
	 gmursAct->setCheckable(true);
	 gReelAct->setCheckable(true);
	 gHLMsimpleAct->setCheckable(true);
	 QActionGroup* choixGram = new QActionGroup(fileMenu);
	 choixGram->addAction(gHLMAct);
	 choixGram->addAction(gescAct);
	 choixGram->addAction(gmursAct);
	 choixGram->addAction(gHLMsimpleAct);
	 choixGram->addAction(gReelAct);
	 QMenu* gMenu = fileMenu->addMenu("&Grammaire");
	 gMenu->addAction(gHLMAct);
	 gMenu->addAction(gescAct);
	 gMenu->addAction(gmursAct);
	 gMenu->addAction(gHLMsimpleAct);
	 gMenu->addAction(gReelAct);
	QSignalMapper *signalMapper = new QSignalMapper(this);
	 signalMapper->setMapping(gHLMAct, 0);
	  signalMapper->setMapping(gescAct, 1);
	  signalMapper->setMapping(gmursAct, 2);
	  signalMapper->setMapping(gHLMsimpleAct, 3);
	  signalMapper->setMapping(gReelAct, 4);
	  connect(gHLMAct,SIGNAL(triggered()),signalMapper,SLOT(map()));
	  connect(gescAct,SIGNAL(triggered()),signalMapper,SLOT(map()));
	  connect(gmursAct,SIGNAL(triggered()),signalMapper,SLOT(map()));
	  connect(gHLMsimpleAct,SIGNAL(triggered()),signalMapper,SLOT(map()));
	  connect(gReelAct,SIGNAL(triggered()),signalMapper,SLOT(map()));
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(changerGrammaire(int)));
	 gHLMAct->setChecked(true);
	 changerGrammaire(0);
	
	QMenu* execMenu = menuBar()->addMenu(tr("&Ex�cuter"));
	QAction* a_executer = new QAction("Totalement",execMenu);
	execMenu->addAction(a_executer);
	connect(a_executer,SIGNAL(triggered()),this,SLOT(executer()));
	QAction* a_executerPartiel = new QAction("Partiellement",execMenu);
	execMenu->addAction(a_executerPartiel);
	connect(a_executerPartiel,SIGNAL(triggered()),this,SLOT(executerPartiel()));
	
	QMenu* modelMenu = menuBar()->addMenu(tr("&Mod�le"));
	QAction* inverser = new QAction("Inverser axes Y et Z",modelMenu);
	modelMenu->addAction(inverser);
	connect(inverser,SIGNAL(triggered()),this,SLOT(inverserAxesModele()));
	
	QMenu* graphMenu = menuBar()->addMenu(tr("&Graphes"));
	QAction* exclu = new QAction("Graphe d'exclusivit�",graphMenu);
	QAction* adj = new QAction("Graphe d'adjacence",graphMenu);
	graphMenu->addAction(exclu);
	graphMenu->addAction(adj);
	connect(exclu,SIGNAL(triggered()),this,SLOT(afficherExclu()));
	connect(adj,SIGNAL(triggered()),this,SLOT(afficherAdj()));
	tabs = new QTabWidget;
	resultWidget = new QWidget;
	modelWidget = new QWidget;
	tabs->addTab(modelWidget,"Mod�le");
	tabs->addTab(resultWidget,"R�sultat");
	this->setCentralWidget(tabs);
	
}

void MainWindow::afficherElems(const QModelIndex& index)
{
TreeItem* item = static_cast<TreeItem*>(index.internalPointer());
	qDebug()<<QString::fromStdString(item->n->nom_parser)<<" "<<endl;
Noeud* n = item->n;	
if(n==NULL)
	return;
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
//G�n�rer un SVG avec GraphViz
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
//G�n�rer un SVG avec GraphViz
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
	QString fileName = QFileDialog::getOpenFileName(this,"Charger un mod�le au format texte",QString(),"Fichiers texte (*.txt)");
	if(fileName.isNull())
		return;
	QString fileName2 = QFileDialog::getOpenFileName(this,"Choisir le fichier contenant les adjacences (si annulation, calcul automatique)",QString(),"Fichiers texte (*.txt)");
	FileReader f;
	if(fileName2.isNull())
		modele = f.readFile(fileName.toStdString());
	else
		modele = f.readFile(fileName.toStdString(),fileName2.toStdString());
	scaleModel();
	afficherModele();
}

void MainWindow::inverserAxesModele()
{
modele->inverserAxes();
afficherModele();
}

void MainWindow::scaleModel()
{
modele->normaliser();
}

void MainWindow::chargerFichierObj()
{
	QString fileName = QFileDialog::getOpenFileName(this,"Charger un mod�le au format obj",QString(),"Fichiers Wavefront (*.obj)");
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
	tabs->insertTab(0,modelWidget,"Mod�le");
	setWindowTitle(QString::number(modele->polygones.size())+" primitives");
}

void MainWindow::executer()
{
bool ok;
double echelle = QInputDialog::getDouble  (this,"Echelle du mod�le","Indiquer la taille (en m�tres) de l'axe.", 1, 0,1000, 3, &ok);
if(!ok)
	return;
modele->setEchelle(1/(float)echelle);
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
	QAction* showTree = new QAction("Arbre de d�rivation",view);
	connect(showTree,SIGNAL(triggered()),this,SLOT(afficherArbre()));
	view->addAction(showTree);
	tabs->removeTab(1);
	delete resultWidget;
	resultWidget = s;
	tabs->insertTab(1,resultWidget,"R�sultat");
}

void MainWindow::executerPartiel()
{
bool ok;
double echelle = QInputDialog::getDouble  (this,"Echelle du mod�le","Indiquer la taille (en m�tres) de l'axe.", 1, 0,1000, 3, &ok);
if(!ok)
	return;
modele->setEchelle(1/(float)echelle);
int nb_iter = QInputDialog::getInt (this,"Execution partielle","Nombre maximal d'it�rations :", 3, 1,1000, 1, &ok);
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
	QAction* showTree = new QAction("Arbre de d�rivation",view);
	connect(showTree,SIGNAL(triggered()),this,SLOT(afficherArbre()));
	view->addAction(showTree);
	tabs->removeTab(1);
	delete resultWidget;
	resultWidget = s;
	tabs->insertTab(1,resultWidget,"R�sultat");
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
		case 2 :
		p = new Parsermurs();
		break;
		case 3 :
		p = new ParserHLMSimple();
		break;
		case 4 :
		p = new ParserReel();
		break;
		default :
		p=new ParserHLM();
		break;
	}
}