#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#define pi 3.142857
int width, height;
int windowWidth;
int windowHeight;
// Ellipse Variables
int xCenter = -200;
int yCenter = -100;
// Major and Minor Axis
int rx = 200;
int ry = 100;
// Variables for Circle
// Radius
int r = 200;
// Offset of the centre
int offx = 0;
int offy = 0;
// Coordinates of a Line
// point 1
int g = 100;
int h = 200;
// point 2
int i = -300;
int j = -100;
// Polygon Variables
int polygon[];
int size = 8;
// function to initialize
void myInit(void)
{
glClearColor(0.0, 0.0, 0.0, 1.0);
glColor3f(0.0, 1.0, 0.0);
glPointSize(1.0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-800, 800, -450, 450);
}
void drawAxis()
{
glBegin(GL_POINTS);
glColor3ub(0, 0, 255);
for (int i = -800; i < 800; i++)
{
glVertex2i(0, i);
glVertex2i(i, 0);
}
glEnd();
}
void drawCircle(void)
{
glClear(GL_COLOR_BUFFER_BIT);
drawAxis();
glBegin(GL_POINTS);
int x = 0;
int y = r;
glColor3ub(0, 255, 0);
int d = 5 / 4 - r;
while (x < y)
{
if (d <= 0)
{
d = d + 2 * x + 3;
}
else
{
d = d + 2 * (x - y) + 5;
y--;
}
x++;

glVertex2i(x + offx, y + offy);
glVertex2i(y + offx, x + offy);
glVertex2i(x + offx, -y + offy);
glVertex2i(y + offx, -x + offy);
glVertex2i(-y + offx, -x + offy);
glVertex2i(-x + offx, -y + offy);
glVertex2i(-x + offx, y + offy);
glVertex2i(-y + offx, x + offy);
}
glEnd();
glFlush();
}
void draw(int a, int b, int c, int d)
{
int x1;
int x2;
int y1;
int y2;
int dx, dy, i, e;
int incx, incy, inc1, inc2;
int x, y;
x1 = a;
x2 = c;
y1 = b;
y2 = d;
dx = x2 - x1;
dy = y2 - y1;
if (dx < 0)
dx = -dx;
if (dy < 0)
dy = -dy;
incx = 1;
if (x2 < x1)
incx = -1;
incy = 1;
if (y2 < y1)
incy = -1;
x = x1;
y = y1;

if (dx > dy)
{
glVertex2i(x, y);
e = 2 * dy - dx;
inc1 = 2 * (dy - dx);
inc2 = 2 * dy;
for (i = 0; i < dx; i++)
{
if (e >= 0)
{
y += incy;
e += inc1;
}
else
e += inc2;
x += incx;
glVertex2i(x, y);
}
}
else
{
glVertex2i(x, y);
e = 2 * dx - dy;
inc1 = 2 * (dx - dy);
inc2 = 2 * dx;
for (i = 0; i < dy; i++)
{
if (e >= 0)
{
x += incx;
e += inc1;
}
else
e += inc2;
y += incy;
glVertex2i(x, y);
}
}
}
void drawLine(void)

{
glClear(GL_COLOR_BUFFER_BIT);
drawAxis();
glBegin(GL_POINTS);
glColor3ub(0, 255, 0);
draw(g, h, i, j);
glEnd();
glFlush();
}
void drawEllipse(void)
{
glClear(GL_COLOR_BUFFER_BIT);
drawAxis();
glBegin(GL_POINTS);
glColor3ub(0, 255, 0);
float x = 0;
float y = ry;
float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);
float dx = 2 * (ry * ry) * x;
float dy = 2 * (rx * rx) * y;
while (dx < dy)
{
glVertex2i(xCenter + x, yCenter + y);
glVertex2i(xCenter - x, yCenter + y);
glVertex2i(xCenter + x, yCenter - y);
glVertex2i(xCenter - x, yCenter - y);
if (p1 < 0)
{
x = x + 1;
dx = 2 * (ry * ry) * x;
p1 = p1 + dx + (ry * ry);
}
else
{
x = x + 1;
y = y - 1;
dx = 2 * (ry * ry) * x;

dy = 2 * (rx * rx) * y;
p1 = p1 + dx - dy + (ry * ry);
}
}
float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) *
(y - 1) - (rx * rx) * (ry * ry);
while (y > 0)
{
glVertex2i(xCenter + x, yCenter + y);
glVertex2i(xCenter - x, yCenter + y);
glVertex2i(xCenter + x, yCenter - y);
glVertex2i(xCenter - x, yCenter - y);
if (p2 > 0)
{
x = x;
y = y - 1;
dy = 2 * (rx * rx) * y;
p2 = p2 - dy + (rx * rx);
}
else
{
x = x + 1;
y = y - 1;
dy = dy - 2 * (rx * rx);
dx = dx + 2 * (ry * ry);
p2 = p2 + dx -
dy + (rx * rx);

}
}
glEnd();
glFlush();
}
void drawPolygon(void)
{
glClear(GL_COLOR_BUFFER_BIT);
drawAxis();
glBegin(GL_POINTS);
glColor3ub(0, 255, 0);

for (int i = 2; i < 8; i = i + 2)
{
int x1 = polygon[i - 2];
int x2 = polygon[i];
int y1 = polygon[i - 1];
int y2 = polygon[i + 1];
draw(x1, y1, x2, y2);
}
draw(polygon[0], polygon[1], polygon[size - 2], polygon[size - 1]);
glEnd();
glFlush();
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
width = glutGet(GLUT_SCREEN_WIDTH);
height = glutGet(GLUT_SCREEN_HEIGHT);
windowWidth = width / 2;
windowHeight = height / 2;
polygon[0] = 300;
polygon[1] = 0;
polygon[2] = 200;
polygon[3] = 200;
polygon[4] = -200;
polygon[5] = 300;
polygon[6] = -100;
polygon[7] = -200;
glutInitWindowSize(windowWidth, windowHeight);
glutInitWindowPosition(0, 0);
glutCreateWindow("Line Draw");
myInit();
glutDisplayFunc(drawLine);

glutInitWindowSize(windowWidth, windowHeight);
glutInitWindowPosition(windowWidth, 0);
glutCreateWindow("Circle Drawing");
myInit();
glutDisplayFunc(drawCircle);
glutInitWindowSize(windowWidth, windowHeight);
glutInitWindowPosition(0, windowHeight);
glutCreateWindow("Ellipse Drawing");
myInit();
glutDisplayFunc(drawEllipse);
glutInitWindowSize(windowWidth, windowHeight);
glutInitWindowPosition(windowWidth, windowHeight);
glutCreateWindow("Polygon Drawing");
myInit();
glutDisplayFunc(drawPolygon);
glutMainLoop();
}