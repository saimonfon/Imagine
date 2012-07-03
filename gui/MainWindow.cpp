#include "MainWindow.h"
#include <QApplication>
#include <QtGui>
#include <QPushButton>
#include "SimpleViewer.h"
#include <QGLViewer/qglviewer.h>
#include "treemodel.h"
#include "treeitem.h"
#include <queue>
MainWindow::MainWindow(Parser* p) : QMainWindow()
{
	this->p = p;
	//setCentralWidget(new QPushButton("hello"));
	v= new Viewer(p->terminaux);
	bool * indices = new bool[p->terminaux.size()];
	v->setColoredIndices(indices); 
     TreeModel* model = new TreeModel(p);
	 QTreeView* view = new QTreeView();
	 connect(view,SIGNAL(activated(const QModelIndex&)), this, SLOT(afficherElems(const QModelIndex&)));
     view->setModel(model);
	 QSplitter* s = new QSplitter();
	s->addWidget(view);
	s->addWidget(v);
	QList<int> sizes;
	sizes<<200<<200;
	s->setSizes(sizes);
	this->setCentralWidget(s);
	//this->setCentralWidget(v);
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
