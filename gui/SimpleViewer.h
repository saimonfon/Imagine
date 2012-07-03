#include <QGLViewer/qglviewer.h>
#include "../geometrie/Polygone.h"
#include <vector>
class Viewer : public QGLViewer
{
public :
Viewer(vector<Polygone*> p);
void setColoredIndices(bool* colored_ind);
protected :
  virtual void draw();
  virtual void init();
  virtual QString helpString() const;
  vector<Polygone*> p;
  bool* colored_ind;
};