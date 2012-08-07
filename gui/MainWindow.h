#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../grammaire/Parser.h"
#include <QtGui>
class Viewer;
class Modele;
class MainWindow: public QMainWindow
{
	Q_OBJECT
	public :
	MainWindow();
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
	void executerPartiel();
	void inverserAxesModele();
	void colorier();
	void changerGrammaire(int grammaire);
	private :
	void afficherModele();
	void scaleModel();
	Parser* p;
	Modele* modele;
	QTreeView* view;
	QWidget* modelWidget;
	QWidget* resultWidget;
};
#endif