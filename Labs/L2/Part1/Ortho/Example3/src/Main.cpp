#include <GL/glut.h>

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3d(1.0, 1.0, 1.0);
  glLineWidth(3);
  glBegin(GL_LINES);
    glVertex2d(25.0, 90.0);
    glVertex2d(75.0, 10.0);
  glEnd();
  glFinish();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(200, 200);
  glutInitWindowSize(240, 300);
  glutCreateWindow("Ortho-Example3");
  gluOrtho2D(0.0, 100.0, 0.0, 100.0);
  glClearColor(0.0, 0.0, 0.5, 1.0);
  glutDisplayFunc(Draw);
  glutMainLoop();
  return 0;
}
