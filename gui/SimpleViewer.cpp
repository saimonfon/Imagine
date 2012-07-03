#include "simpleViewer.h"

using namespace std;

Viewer::Viewer(vector<Polygone*> p)
{
this->p = p;

}

void Viewer::setColoredIndices(bool* colored_ind)
{
	this->colored_ind = colored_ind;
}

// Draws a spiral
void Viewer::draw()
{
int i=0;
for(vector<Polygone*>::iterator it = p.begin();it!=p.end();it++)
{
if(colored_ind[i])
glColor4ub(255, 0,0,100); // on demande du bleu
else
glColor4ub(255, 255, 255,100); // on demande du bleu

glBegin(GL_POLYGON); // debut du dessin
for(vector<Vec3>::iterator it2 = (*it)->points3D.begin();it2!=(*it)->points3D.end();it2++)
{
	//cout<<"("<<(*it2).x<<" "<<(*it2).y<<" "<<(*it2).z<<") -> ";
	glVertex3f((*it2).x/1000,(*it2).y/1000,(*it2).z/1000);
	}
	//cout<<endl;
glEnd(); // fin du dessin
i++;
}
/*glColor3ub(255, 255, 255); // on demande du bleu
glBegin(GL_POLYGON); // debut du dessin
	glVertex2f(-.5,  -1); // envoi du premier sommet
	glVertex2f( -1,   0); // puis le second
	glVertex2f(-.5,   1); // ect
	glVertex2f( .5,   1);
	glVertex2f(  1,   0);
	glVertex2f( .5,  -1); // jusqu'au dernier
glEnd(); // fin du dessin*/
}

void Viewer::init()
{
  // Restore previous viewer state.
  restoreStateFromFile();
  glDisable(GL_LIGHTING);
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