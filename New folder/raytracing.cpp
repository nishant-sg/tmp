#include <math.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glut.h>
#include "raytrace.cpp"
#define XDIM 800
#define YDIM 800
unsigned char image[YDIM][XDIM][3];
Point3D intersect, tmp1, tmp2, cam, point, center[4];
ColorRGB color, shade, obj[4];
Vector3D dir, normal, vec;
Phong ps[4];
Sphere3D spheres[4];
Ray3D ray, shadow;
float r, g, b, x, y, z, a[4], d[4], s[4], p[4];
void init()
{
glClearColor(0.0, 0.0, 0.0, 1.0);
cout << "Program commands:\n"
<< " 'q' - quit program\n";
}
void setSpheres()
{
center[0].set(-100, -100, 200);
center[1].set(50, -50, 100);
center[2].set(-100, 100, 200);
center[3].set(50, 150, 0);
spheres[0].set(center[0], 90);
spheres[1].set(center[1], 100);
spheres[2].set(center[2], 100);
spheres[3].set(center[3], 70);
}
void read()

{
ifstream din;
din.open("input.txt");
string input;
int num = 0;
while (din >> input)
{
if (input == "Camera")
{
din >> x >> y >> z;
cam.set(x, y, -8000);
for (int i = 0; i < 4; i++)
{
ps[i].SetCamera(cam);
}
}
else if (input == "Light")
{
din >> r >> g >> b >> x >> y >> z;
color.set(r, b, g);
dir.set(x, y, z);
for (int i = 0; i < 4; i++)
{
ps[i].SetLight(color, dir);
}
}
else if (input == "Object")
{
din >> r >> g >> b >> a[num] >> d[num] >> s[num] >> p[num];
obj[num].set(r, g, b);
num++;
}
}
}
void display()

{
read();
setSpheres();
for (int i = 0; i < YDIM; i++)
{
for (int z = 0; z < XDIM; z++)
{
bool intersected = false;
for (int f = 0; f < 4; f++)
{
point.set(z - XDIM / 2, i - YDIM / 2, 0);
ray.set(cam, point);
if (spheres[f].get_intersection(ray, intersect, normal))
{
tmp1 = spheres[f].center;
if (cam.distance(tmp1) > cam.distance(intersect) || intersected == false)
{
shadow.set(intersect, dir);
ps[f].SetObject(obj[f], a[f], d[f], s[f], p[f]);
for (int y = 0; y < 4; y++)
{
if (spheres[y].get_intersection(shadow, tmp2, vec) && y != f)
{
ps[f].SetObject(obj[f], a[f], 0, 0, p[f]);
}
}
ps[f].GetShade(intersect, normal, shade);
image[i][z][0] = shade.R;
image[i][z][1] = shade.G;
image[i][z][2] = shade.B;
tmp1.set(intersect.px, intersect.py, intersect.pz);
intersected = true;
}
}
}

}
}
glClear(GL_COLOR_BUFFER_BIT);
glDrawPixels(XDIM, YDIM, GL_RGB, GL_UNSIGNED_BYTE, image);
glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
if (key == 'q')
exit(0);
glutPostRedisplay();
}
int main(int argc, char *argv[])
{
glutInit(&argc, argv);
glutInitWindowSize(XDIM, YDIM);
glutInitWindowPosition(0, 0);
glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
glutCreateWindow("Ray Tracing Opengl - 2020UCP1032");
init();
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}