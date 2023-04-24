void init(){
glClearColor(0.0, 0.0, 0.0, 1.0);
glEnable(GL_DEPTH_TEST);
}
int main(int argc, char **argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowPosition(200, 100);
glutInitWindowSize(500, 500);

glutCreateWindow("Back Face Removal");
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutTimerFunc(0,timer,0);
init();
glutMainLoop();
}
float x_position = 0.0;
int state = 1;
float angle = 0.0;
void reshape(int w , int h){
glViewport(0, 0, (GLsizei)w, (GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60, 1, 2.0, 50.0);
glMatrixMode(GL_MODELVIEW);
}
void timer(int t){
glutPostRedisplay();
glutTimerFunc(1000 / 60, timer, 0);
angle += 0.8;
if (angle>360 )
angle = angle -360;
}
void init(){
glClearColor(0.0, 0.0, 0.0, 1.0);
glEnable(GL_DEPTH_TEST);
}
int main(int argc, char **argv){
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowPosition(200, 100);
glutInitWindowSize(500, 500);
glutCreateWindow("Back Face Removal");
glutDisplayFunc(display);

glutReshapeFunc(reshape);
glutTimerFunc(0,timer,0);
init();
glutMainLoop();
}
float x_position = 0.0;
int state = 1;
float angle = 0.0;
void reshape(int w , int h){
glViewport(0, 0, (GLsizei)w, (GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(60, 1, 2.0, 50.0);
glMatrixMode(GL_MODELVIEW);
}
void timer(int t){
glutPostRedisplay();
glutTimerFunc(1000 / 60, timer, 0);
angle += 0.8;
if (angle>360 )
angle = angle -360;
}
{
case 27:
exit(0);
break;
}
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(width, height);
glutCreateWindow("Z-buffer algorithm");
glutDisplayFunc(display);

glutReshapeFunc(reshape);
glutKeyboardFunc(keyboard);
for (int x = 0; x < width; x++)
{
for (int y = 0; y < height; y++)
{
zBuffer[x][y] = 1.0;
}
}
glShadeModel(GL_SMOOTH);
glutMainLoop();
return