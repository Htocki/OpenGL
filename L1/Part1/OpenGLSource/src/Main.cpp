#include <GL/glut.h>

void Initialize() {
  glClearColor(1.0, 0.0, 0.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_POLYGON);
    glVertex3f(0.10, 0.10, 0.0);
    glVertex3f(0.90, 0.10, 0.0);
    glVertex3f(0.90, 0.90, 0.0);
    glVertex3f(0.10, 0.90, 0.0);
  glEnd();
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("OpenGLSource: Polygon");
  Initialize();
  glutDisplayFunc(Draw);
  glutMainLoop();
  return 0;
}
