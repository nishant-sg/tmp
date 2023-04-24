#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

// Define initial polygon coordinates
float vertices[][2] = {{-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5}};
int num_vertices = 4;

// Define translation values
float tx = 0.0;
float ty = 0.0;

// Define rotation values
float angle = 0.0;
float rx = 0.0;
float ry = 0.0;

// Define scaling values
float sx = 1.0;
float sy = 1.0;

// Draw the polygon
void draw_polygon() {
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_POLYGON);

for (int i = 0; i < num_vertices; i++) {
glVertex2f(vertices[i][0], vertices[i][1]);
}
glEnd();

glFlush();
}

// Translate the polygon
void translate() {
for (int i = 0; i < num_vertices; i++) {
vertices[i][0] += tx;
vertices[i][1] += ty;
}
}

// Rotate the polygon around the center
void rotate() {
float cx = 0.0;
float cy = 0.0;
for (int i = 0; i < num_vertices; i++) {
cx += vertices[i][0];
cy += vertices[i][1];
}
cx /= num_vertices;
cy /= num_vertices;

for (int i = 0; i < num_vertices; i++) {
float x = vertices[i][0] - cx;
float y = vertices[i][1] - cy;

vertices[i][0] = x * cos(angle) - y * sin(angle) + cx;
vertices[i][1] = x * sin(angle) + y * cos(angle) + cy;
}
}

// Scale the polygon
void scale() {
for (int i = 0; i < num_vertices; i++) {
vertices[i][0] *= sx;
vertices[i][1] *= sy;
}
}

// Display the polygon after applying transformations
void display() {
translate();
rotate();
scale();

draw_polygon();
}

// Initialize the OpenGL environment
void init() {
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

// Handle keyboard events

void keyboard(unsigned char key, int x, int y) {
switch (key) {
case 't':
tx += 0.1;
glutPostRedisplay();
break;
case 'T':
tx -= 0.1;
glutPostRedisplay();
break;
case 'r':
angle += 0.1;
glutPostRedisplay();
break;
case 'R':
angle -= 0.1;
glutPostRedisplay();
break;
case 's':
sx += 0.1;
sy += 0.1;
glutPostRedisplay();
break;
case 'S':
sx -= 0.1;
sy -= 0.1;
glutPostRedisplay();
break;
default:
break;
}

}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("Polygon Transformations");
init();
glutDisplayFunc(display);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}