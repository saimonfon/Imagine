#include "SimpleViewer.h"
#include <stdio.h>
 #ifndef CALLBACK
   #define CALLBACK
   #endif
using namespace std;

Viewer::Viewer(vector<Polygone*> p)
{
this->p = p;
colored_ind= new int[p.size()];
for(int i=0;i<p.size();i++)
	colored_ind[i]=0;
	

setViewPrimitives();
/* Générer les listes OpenGL pour accélérer le rendu */
/*base_ind = glGenLists(p.size());
int i=0;
for(vector<Polygone*>::iterator it = p.begin();it!=p.end();it++)
{
glNewList(base_ind+i,GL_COMPILE);
GLUtriangulatorObj *tess;
tess = gluNewTess();
gluTessCallback(tess, GLU_TESS_VERTEX,
                   (GLvoid (CALLBACK*) ()) &glVertex3dv);
   gluTessCallback(tess, GLU_TESS_BEGIN,
                   (GLvoid (CALLBACK*) ()) &glBegin);
   gluTessCallback(tess, GLU_TESS_END,
                   (GLvoid (CALLBACK*) ()) &glEnd);
gluBeginPolygon(tess);
for(vector<Vec3>::iterator it2 = (*it)->points3D.begin();it2!=(*it)->points3D.end();it2++)
{
  GLdouble* location = new GLdouble[3];
  location[0] = (*it2).x;
  location[1] = (*it2).y;
  location[2] = (*it2).z;
  gluTessVertex(tess, location, location);
  delete location;
}
gluEndPolygon(tess);
gluDeleteTess(tess);
glEndList();
i++;
}*/
}

void Viewer::setColoredIndices(int* colored_ind,int max)
{
	//delete[] this->colored_ind;
	this->colored_ind = colored_ind;
	nodeColors = new int[3*(max+1)];
	nodeColors[0] = nodeColors[1] = nodeColors[2] = 120;
	for(int i=0;i<max;i++)
	{
		QColor c;
		c.setHsv((int)(300./max*i),255,255,255);
		QColor c2 = c.toRgb();
		nodeColors[3*(i+1)] = c2.red();
		nodeColors[3*(i+1)+1] = c2.green();
		nodeColors[3*(i+1)+2] = c2.blue();
	}
	mode=0;
}

void Viewer::setViewPrimitives()
{
	/*Calculer aléatoirement une couleur par primitive*/
	primColors = new int[3*p.size()];
	for(int i=0;i<3*p.size();i++)
		primColors[i] = rand()%256;
	mode=1;
}


void Viewer::draw()
{
int i=0;
for(vector<Polygone*>::iterator it = p.begin();it!=p.end();it++)
{
if(mode==0)
{
glColor4ub(nodeColors[3*colored_ind[i]],nodeColors[3*colored_ind[i]+1],nodeColors[3*colored_ind[i]+2],255);
}
else
{
	glColor4ub(primColors[3*i],primColors[3*i+1],primColors[3*i+2],255);
}
if((*it)->triangles.size()>0)
{
		glBegin( GL_TRIANGLES);
	for(vector<Vec3*>::iterator it2 = (*it)->triangles.begin();it2!=(*it)->triangles.end();it2++)
	{
		for(int k=0;k<3;k++)
			glVertex3f((*it2)[k].x,(*it2)[k].y,(*it2)[k].z);

	}
		glEnd();
}
else
{
GLUtriangulatorObj *tess;
tess = gluNewTess();
//gluTessProperty(tess, GLU_TESS_WINDING_RULE, GLU_TESS_WINDING_EVEN);
gluTessCallback(tess, GLU_TESS_VERTEX,
                   (GLvoid (CALLBACK*) ()) &glVertex3dv);
   gluTessCallback(tess, GLU_TESS_BEGIN,
                   (GLvoid (CALLBACK*) ()) &glBegin);
   gluTessCallback(tess, GLU_TESS_END,
                   (GLvoid (CALLBACK*) ()) &glEnd);
gluBeginPolygon(tess);
 gluTessBeginContour(tess);
for(vector<Vec3>::iterator it2 = (*it)->points3D.begin();it2!=(*it)->points3D.end();it2++)
{
  GLdouble* location = new GLdouble[3];
  location[0] =  it2->x;
  location[1] = it2->y;
  location[2] = it2->z;
 //delete location;
  gluTessVertex(tess, location, location);
}
gluTessEndContour(tess);
/* Dessin des trous */
for(vector<Polygone*>::iterator it3 = (*it)->trous.begin();it3!=(*it)->trous.end();it3++)
{
 gluTessBeginContour(tess);
for(vector<Vec3>::iterator it2 = (*it3)->points3D.begin();it2!=(*it3)->points3D.end();it2++)
{
  GLdouble* location = new GLdouble[3];
  location[0] =  it2->x;
  location[1] = it2->y;
  location[2] = it2->z;
  gluTessVertex(tess, location, location);
 //delete location;
}
gluTessEndContour(tess);
}
gluEndPolygon(tess);
gluDeleteTess(tess);
}
//DESSIN DU CONTOUR (dans les deux cas)
glColor4ub(0, 0, 0,255); 
glBegin(GL_LINE_LOOP);
for(vector<Vec3>::iterator it2 = (*it)->points3D.begin();it2!=(*it)->points3D.end();it2++)
	glVertex3f(it2->x,it2->y,it2->z);
glEnd();
i++;
}
}

void Viewer::init()
{
  // Restore previous viewer state.
  restoreStateFromFile(); 
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  glDisable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
  glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
 
  // Opens help window
  //help();
}

QString Viewer::helpString() const
{
  QString text("<h2>S i m p l e V i e w e r</h2>");
  text += "Use the mouse to move the camera around the object. ";
  text += "You can respectively revolve around, zoom and translate with the three mouse buttons. ";
  text += "Left and middle buttons pressed together rotate around the camera view direction axis<br><br>";
  text += "Pressing <b>Alt</b> and one of the function keys (<b>F1</b>..<b>F12</b>) defines a camera keyFrame. ";
  text += "Simply press the function key again to restore it. Several keyFrames define a ";
  text += "camera path. Paths are saved when you quit the application and restored at next start.<br><br>";
  text += "Press <b>F</b> to display the frame rate, <b>A</b> for the world axis, ";
  text += "<b>Alt+Return</b> for full screen mode and <b>Control+S</b> to save a snapshot. ";
  text += "See the <b>Keyboard</b> tab in this window for a complete shortcut list.<br><br>";
  text += "Double clicks automates single click actions: A left button double click aligns the closer axis with the camera (if close enough). ";
  text += "A middle button double click fits the zoom of the camera and the right button re-centers the scene.<br><br>";
  text += "A left button double click while holding right button pressed defines the camera <i>Revolve Around Point</i>. ";
  text += "See the <b>Mouse</b> tab and the documentation web pages for details.<br><br>";
  text += "Press <b>Escape</b> to exit the viewer.";
  return text;
}
