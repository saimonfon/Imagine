#include <QGLViewer/qglviewer.h>
#include "../geometrie/Polygone.h"
#include <vector>
class Viewer : public QGLViewer
{
public :
Viewer(vector<Polygone*> p);
void setColoredIndices(int* colored_ind,int max);
void setViewPrimitives();
protected :
	int* primColors;
	int* nodeColors;
  virtual void draw();
  virtual void init();
  virtual QString helpString() const;
  vector<Polygone*> p;
  int* colored_ind;
  GLuint base_ind ;
  int mode; //0 pour les indices, 1 pour les primitives
};