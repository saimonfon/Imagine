#include <QGLViewer/qglviewer.h>
#include "../geometrie/Polygone.h"
#include <vector>
class Viewer : public QGLViewer
{
public :
Viewer(vector<Polygone*> p);
Viewer(vector<Polygone*> p, float ms);
void setColoredIndices(bool* colored_ind);
void setViewPrimitives();
  float modele_scale;
protected :
	int* primColors;
  virtual void draw();
  virtual void init();
  virtual QString helpString() const;
  vector<Polygone*> p;
  bool* colored_ind;
  GLuint base_ind ;
  int mode; //0 pour les indices, 1 pour les primitives


};
