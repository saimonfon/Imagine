#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../grammaire/Parser.h"
#include "geometrie/ObjReader.h"
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
	QModelIndex modIndex;

	double echelle;
	double epsilon;

	public slots : 
	void afficherElems(const QModelIndex& index);
	void afficherExclu();
	void afficherAdj();
	void afficherArbre();
	void chargerFichierTexte();
	void chargerFichierObj();

	void setEpsilon();
	void setScale();

	void executer();
	void executerPartiel();
	void inverserAxesModele();
	void changerGrammaire(int grammaire);
	void saveCustomObj();
	private :
	void afficherModele();
	void scaleModel();
	Parser* p;
	Modele* modele;
	QTreeView* view;
	QWidget* modelWidget;
	QWidget* resultWidget;

	ObjReader f;
};
#endif
