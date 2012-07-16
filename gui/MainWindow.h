#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../grammaire/Parser.h"
#include <QtGui>
class Viewer;
class Polygone;
class MainWindow: public QMainWindow
{
	Q_OBJECT
	public :
	MainWindow(Parser* p);
	static int afficher(Parser* p,int& argc,char** argv);
	Viewer* v;
	QTabWidget* tabs;
	public slots : 
	void afficherElems(const QModelIndex& index);
	void afficherExclu();
	void afficherAdj();
	void afficherArbre();
	void chargerFichierTexte();
	void chargerFichierObj();
	void executer();
	private :
	Parser* p;
	QTreeView* view;
	vector<Polygone*> model;
	QWidget* modelWidget;
	QWidget* resultWidget;
};
#endif