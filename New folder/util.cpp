#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
const bool DEBUG = false;
class ColorRGB

{
public:
float R, G, B;
void set(float r, float g, float b);
string print();
void mult(float c);
void mult(ColorRGB c);
void add(ColorRGB c);
void sub(ColorRGB c);
void clamp();
};
class Point3D
{
public:
float px, py, pz;
void set(float x, float y, float z);
string print();
float distance(Point3D p);
};
class Vector3D
{
public:
float vx, vy, vz;
void set(float x, float y, float z);
string print();
void normalize();
float dot(Vector3D v);
void mult(float c);
void add(Vector3D v);
void sub(Vector3D v);
};
class Ray3D
{
public:
Point3D point;

Vector3D dir;
void set(Point3D p, Vector3D d);
void set(Point3D p1, Point3D p2);
string print();
Point3D get_sample(float t);
};
class Sphere3D
{
public:
Point3D center;
float radius;
void set(Point3D p, float r);
string print();
bool get_intersection(Ray3D ray, Point3D &point, Vector3D &normal);
};
class Phong
{
public:
Phong();
~Phong();
void SetCamera(Point3D pos);
void SetLight(ColorRGB color, Vector3D dir);
void SetObject(ColorRGB color, float ka, float kd, float ks, float kp);
void GetShade(Point3D point, Vector3D normal, ColorRGB & color);
private:
Point3D CameraPos;
ColorRGB LightColor;
Vector3D LightDir;
ColorRGB ObjectColor;
float Ka, Kd, Ks, Kp;
};
Phong::Phong()
{
CameraPos.set(0, 0, 0);
LightColor.set(0, 0, 0);

LightDir.set(0, 0, 0);
ObjectColor.set(0, 0, 0);
Ka = 0; Kd = 0; Ks = 0; Kp = 0;
}
Phong::~Phong()
{
}
void Phong::SetCamera(Point3D pos)
{
CameraPos = pos;
if (DEBUG) cout << CameraPos.print() << endl;
}
void Phong::SetLight(ColorRGB color, Vector3D dir)
{
LightColor = color;
if (DEBUG) cout << LightColor.print() << endl;
LightDir = dir;
LightDir.normalize();
if (DEBUG) cout << LightDir.print() << endl;
}
void Phong::SetObject(ColorRGB color, float ka, float kd, float ks, float kp)
{
ObjectColor = color;
if (DEBUG) cout << ObjectColor.print() << endl;
Ka = ka; Kd = kd; Ks = ks; Kp = kp;
}
void Phong::GetShade(Point3D point, Vector3D normal, ColorRGB & color)
{
normal.normalize();
ColorRGB ambient;
ambient = LightColor;
ambient.mult(ObjectColor);
ambient.mult(Ka);
if (DEBUG) cout << "ambient " << ambient.print() << endl;
color = ambient;

float NdotL = normal.dot(LightDir);
if (DEBUG) cout << "NdotL " << NdotL << endl;
if (NdotL > 0)
{
ColorRGB diffuse;
diffuse = LightColor;
diffuse.mult(ObjectColor);
diffuse.mult(Kd * NdotL);
if (DEBUG) cout << "diffuse " << diffuse.print() << endl;
color.add(diffuse);
Vector3D R = normal;
R.mult(2 * NdotL);
R.sub(LightDir);
R.normalize();
Vector3D V;
float Vx = CameraPos.px - point.px;
float Vy = CameraPos.py - point.py;
float Vz = CameraPos.pz - point.pz;
V.set(Vx, Vy, Vz);
V.normalize();
float RdotV = R.dot(V);
if (DEBUG) cout << "RdotV " << RdotV << endl;
if (RdotV > 0)
{
RdotV = pow(RdotV, Kp);
ColorRGB specular;
specular = LightColor;
specular.mult(Ks * RdotV);
if (DEBUG) cout << "specular " << specular.print() << endl;
color.add(specular);
}
}
}