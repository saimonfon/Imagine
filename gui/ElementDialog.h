#ifndef ELEMENTDIALOG_H
#define ELEMENTDIALOG_H
#include <QtGui>
class ElementDialog : public QDialog
{
Q_OBJECT
public:
QCheckBox** checkboxes;
int n;
QStringList selectionnes;
ElementDialog(QStringList elements,QWidget* parent=0) : QDialog(parent)
{
	n=elements.size();
	checkboxes = new QCheckBox*[elements.size()];
	QVBoxLayout *layout = new QVBoxLayout;
	for(int i=0;i<elements.size();i++)
	{
		checkboxes[i] = new QCheckBox(elements[i],this);
     layout->addWidget(checkboxes[i]);
	}
	QPushButton* b = new QPushButton("OK",this);
	layout->addWidget(b);
	connect(b,SIGNAL(clicked()),this,SLOT(accept()));
     setLayout(layout);
}
public slots:
void accept()
{
	for(int i=0;i<n;i++)
		if(checkboxes[i]->isChecked())
			selectionnes<<checkboxes[i]->text();
	QDialog::accept();
}
};
#endif