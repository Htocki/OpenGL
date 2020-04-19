#include <GL/glut.h>

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3d(1.0, 1.0, 1.0);
  glLineWidth(3);
  glBegin(GL_LINES);
    glVertex2d(-0.8, 0.8);
    glVertex2d(0.8, 0.8);
    glVertex2d(0, 0.3);
    glVertex2d(0, -0.3);
    glVertex2d(-0.8, -0.8);
    glVertex2d(0.8, -0.8);
  glEnd();
  glFinish();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(200, 200);
  glutInitWindowSize(240, 300);
  glutCreateWindow("Lines");
  glClearColor(0.0, 0.0, 0.5, 1.0);
  glutDisplayFunc(Draw);
  glutMainLoop();
  return 0;
}
