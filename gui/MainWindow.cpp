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
MainWindow::MainWindow(Parser* p) : QMainWindow()
{
	this->p = p;
	
	QMenu* fileMenu = menuBar()->addMenu(tr("&Fichier"));
	QAction* chargerTxt = new QAction("Charger mod�le texte",fileMenu);
	QAction* chargerObj = new QAction("Charger mod�le Obj",fileMenu);
	QAction* a_executer = new QAction("Ex�cuter",fileMenu);
	fileMenu->addAction(chargerTxt);
	fileMenu->addAction(chargerObj);
	fileMenu->addAction(a_executer);
	connect(chargerTxt,SIGNAL(triggered()),this,SLOT(chargerFichierTexte()));
	connect(chargerObj,SIGNAL(triggered()),this,SLOT(chargerFichierObj()));
	connect(a_executer,SIGNAL(triggered()),this,SLOT(executer()));
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

static int MainWindow::afficher(Parser* p,int& argc,char** argv)
{
QApplication app(argc, argv);
    MainWindow fenetre(p);
    fenetre.show();
	return app.exec();
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
			indices[(int)((*n)["number"])-1] = true;
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
	FileReader f;
	model = f.readFile(fileName.toStdString());
	p->adj = f.adj;
	tabs->removeTab(0);
	delete modelWidget;
	modelWidget = new Viewer(model);
	tabs->insertTab(0,modelWidget,"Mod�le");
}

void MainWindow::chargerFichierObj()
{
	QString fileName = QFileDialog::getOpenFileName(this,"Charger un mod�le au format obj",QString(),"Fichiers Wavefront (*.obj)");
	ObjReader f(fileName.toStdString());
	model = f.polygones();
	//p->adj = f.adj; A REMETTRE
	tabs->removeTab(0);
	delete modelWidget;
	modelWidget = new Viewer(model);
	tabs->insertTab(0,modelWidget,"Mod�le");
}

void MainWindow::executer()
{
p->parse(model);
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