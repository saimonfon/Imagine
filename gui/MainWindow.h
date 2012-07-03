#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../grammaire/Parser.h"
#include <QtGui>
class Viewer;
class MainWindow: public QMainWindow
{
	Q_OBJECT
	public :
	MainWindow(Parser* p);
	static int afficher(Parser* p,int& argc,char** argv);
	Viewer* v;
	public slots : 
	void afficherElems(const QModelIndex& index);
	private :
	Parser* p;
};
#endif