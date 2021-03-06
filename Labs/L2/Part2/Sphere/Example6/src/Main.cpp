#include <GL/glut.h>

void Light() {
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glEnable(GL_DEPTH_TEST);
  GLfloat color[] = { 1.0, 0.5, 0.1, 1.0 };
  glLightfv(GL_LIGHT0, GL_DIFFUSE, color);
  GLfloat position[] = { 1.0, 0.0, 0.0, 0.0 };
  glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glutSolidSphere(0.7, 50, 40);
  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(400, 400);
  glutCreateWindow("Sphere-Example6");
  glClearColor(0.0, 0.0, 0.0, 0.0);
  Light();
  glutDisplayFunc(Draw);
  glutMainLoop();
}
