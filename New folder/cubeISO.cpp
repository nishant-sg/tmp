#include < GL/freeglut.h > // we use glut here as window manager
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int ocounter;
class Renderer
{
public:
int mode;
double alpha;
public:
Renderer() : mode(1), alpha(-45.0) {}
public:
void display()
{
glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
float m[16]; // identity
glGetFloatv(GL_MODELVIEW_MATRIX, m);
float angle = (M_PI / 180.0f) * float(alpha);
if (mode == 1)
{ // cavalier
m[2 * 4 + 0] = -cos(angle);
m[2 * 4 + 1] = sin(angle);
}
if (mode == 2)

{ // cabinet
m[2 * 4 + 0] = -cos(angle) / 2.0f;
m[2 * 4 + 1] = sin(angle) / 2.0f;
}
// double aspect = double(w) / double(h);
// glViewport(0, 0, w, h);
// glMatrixMode(GL_PROJECTION);
// glLoadIdentity();
// glOrtho(-2.0 * aspect, 2.0 * aspect, -2.0, 2.0, -5.0, 5.0);
double dist = sqrt(1 / 3.0);
if (mode == 4)
{ // dimetic
gluLookAt(dist, dist, dist, /* position of camera */
0.0, 0.3, 0.0, /* where camera is pointing at */
0.0, 1.0, 0.0);
}
if (mode == 3)
{ // iso
gluLookAt(dist, dist, dist, /* position of camera */
0.0, 0.0, 0.0, /* where camera is pointing at */
0.0, 1.0, 0.0);
}
if (mode == 5)
{ // trimetric
gluLookAt(dist, dist, dist, /* position of camera */
0.3, 0.2, 0.0, /* where camera is pointing at */
0.0, 0.8, 0.0);
}
glMultMatrixf(m);
glColor3f(0.0f, 0.0f, 1.0f);
drawCoordinateAxisZ();
glColor3f(0.0f, 1.0f, 0.0f);
drawCoordinateAxisY();
glColor3f(1.0f, 0.0f, 0.0f);
drawCoordinateAxisX();
drawUnitCube();
}
void init()
{
glEnable(GL_DEPTH_TEST);
}
void resize(int w, int h)
{
double aspect = double(w) / double(h);
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-2.0 * aspect, 2.0 * aspect, -2.0, 2.0, -5.0, 5.0);
}
private:

void drawCoordinateAxisZ()
{
glLineWidth(2);
glBegin(GL_LINES);
glVertex3f(0.0f, 0.0f, 0.0f); // z-axis
glVertex3f(0.0f, 0.0f, 2.0f);
glEnd();
glLineWidth(1);
// z-axis tip
glBegin(GL_TRIANGLES);
glVertex3f(0.0f, 0.0f, 2.0f);
glVertex3f(-0.05f, 0.05f, 1.9f);
glVertex3f(0.05f, 0.05f, 1.9f);
glVertex3f(0.0f, 0.0f, 2.0f);
glVertex3f(0.05f, -0.05f, 1.9f);
glVertex3f(-0.05f, -0.05f, 1.9f);
glVertex3f(0.0f, 0.0f, 2.0f);
glVertex3f(0.05f, 0.05f, 1.9f);
glVertex3f(0.05f, -0.05f, 1.9f);
glVertex3f(0.0f, 0.0f, 2.0f);
glVertex3f(-0.05f, -0.05f, 1.9f);
glVertex3f(-0.05f, 0.05f, 1.9f);
glEnd();
glBegin(GL_POLYGON);
glVertex3f(0.05f, -0.05f, 1.9f);
glVertex3f(0.05f, 0.05f, 1.9f);
glVertex3f(-0.05f, 0.05f, 1.9f);
glVertex3f(-0.05f, -0.05f, 1.9f);
glEnd();
}
void drawCoordinateAxisX()
{
glPushMatrix();
glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
drawCoordinateAxisZ();
glPopMatrix();
}
void drawCoordinateAxisY()
{
glPushMatrix();
glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
drawCoordinateAxisZ();
glPopMatrix();
}
void drawUnitCube()
{
glBegin(GL_QUADS); // Begin drawing the color cube with 6 quads
// Top face (y = 1.0f)
// Define vertices in counter-clockwise (CCW) order with normal pointing out
glColor3f(0.0f, 1.0f, 0.0f); // Green

glVertex3f(0.5f, 0.5f, -0.5f);
glVertex3f(-0.5f, 0.5f, -0.5f);
glVertex3f(-0.5f, 0.5f, 0.5f);
glVertex3f(0.5f, 0.5f, 0.5f);
// Bottom face (y = -1.0f)
glColor3f(1.0f, 0.5f, 0.0f); // Orange
glVertex3f(0.5f, -0.5f, 0.5f);
glVertex3f(-0.5f, -0.5f, 0.5f);
glVertex3f(-0.5f, -0.5f, -0.5f);
glVertex3f(0.5f, -0.5f, -0.5f);
// Front face (z = 1.0f)
glColor3f(1.0f, 0.0f, 0.0f); // Red
glVertex3f(0.5f, 0.5f, 0.5f);
glVertex3f(-0.5f, 0.5f, 0.5f);
glVertex3f(-0.5f, -0.5f, 0.5f);
glVertex3f(0.5f, -0.5f, 0.5f);
// Back face (z = -1.0f)
glColor3f(1.0f, 0.0f, 1.0f); // Yellow
glVertex3f(0.5f, -0.5f, -0.5f);
glVertex3f(-0.5f, -0.5f, -0.5f);
glVertex3f(-0.5f, 0.5f, -0.5f);
glVertex3f(0.5f, 0.5f, -0.5f);
// Left face (x = -1.0f)
glColor3f(0.0f, 0.0f, 1.0f); // Blue
glVertex3f(-0.5f, 0.5f, 0.5f);
glVertex3f(-0.5f, 0.5f, -0.5f);
glVertex3f(-0.5f, -0.5f, -0.5f);
glVertex3f(-0.5f, -0.5f, 0.5f);
// Right face (x = 1.0f)
glColor3f(1.0f, 1.0f, 0.0f); // Magenta
glVertex3f(0.5f, 0.5f, -0.5f);
glVertex3f(0.5f, 0.5f, 0.5f);
glVertex3f(0.5f, -0.5f, 0.5f);
glVertex3f(0.5f, -0.5f, -0.5f);
glEnd(); // End of drawing color-cube
}
};
// this is a static pointer to a Renderer used in the glut callback functions
static Renderer *renderer;
// glut static callbacks start
static void glutResize(int w, int h)
{
renderer->resize(w, h);
}
static void glutDisplay()
{

renderer->display();
glutSwapBuffers();
glutReportErrors();
}
static void glutKeyboard(unsigned char key, int x, int y)
{
bool redraw = false;
std::string modeStr;
std::stringstream ss;
switch (key)
{
case '1':
renderer->mode = 1;
redraw = true;
modeStr = string("Cavalier");
break;
case '2':
renderer->mode = 2;
redraw = true;
modeStr = string("Cabinet");
break;
case 'o':
renderer->mode = 6;
redraw = true;
modeStr = string("Orthographic");
break;
case 'i':
renderer->mode = 3;
redraw = true;
modeStr = string("Isometric");
break;
case 'd':
renderer->mode = 4;
redraw = true;
modeStr = string("Dimetric");
break;
case 't':
renderer->mode = 5;
redraw = true;
modeStr = string("Trimetric");
break;
case '3':
renderer->alpha += 2.0f;
if (renderer->alpha > 360.0f)
renderer->alpha = 0.0f;
redraw = true;
ss << "alpha: " << renderer->alpha;
modeStr = ss.str();
break;
case '0':
renderer->alpha = -45.0f;

redraw = true;
ss << "alpha: " << renderer->alpha;
modeStr = ss.str();
break;
}
if (redraw)
{
glutDisplay();
cout << modeStr << endl;
glutSetWindowTitle(modeStr.c_str());
}
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowPosition(100, 100);
glutInitWindowSize(320, 320);
glutCreateWindow("Use 1, 2, and 3 keys to rotate (ALT+key rotates in other direction)");
glutDisplayFunc(glutDisplay);
// glutIdleFunc(glutDisplay);
glutReshapeFunc(glutResize);
glutKeyboardFunc(glutKeyboard);
renderer = new Renderer;
renderer->init();
glutMainLoop();
}