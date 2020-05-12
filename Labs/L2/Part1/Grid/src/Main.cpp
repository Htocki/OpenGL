#include <GL/glut.h>

#include <exception>
#include <iostream>

void Act() {
  glTranslated(0.3, -0.3, 0.0);
  glScaled(0.5, 0.5, 1.0);
  glRotated(45.0, 0.0, 0.0, 1.0);
}

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3d(1.0, 1.0, 1.0);
  glLineWidth(3);
  glBegin(GL_LINES);
  for (auto i { 0 }; i <= 10; ++i) {
    glVertex2d(-1.0 + 0.2*i, 1.0);
    glVertex2d(-1.0 + 0.2*i, -1.0);
    glVertex2d(-1.0, -1.0 + 0.2*i);
    glVertex2d(1.0, -1.0 + 0.2*i);
  }
  glEnd();
  glFinish();
}

int main(int argc, char** argv) {
  try {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Grid");
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glutDisplayFunc(Draw);
    Act();
    glutMainLoop();
    return 0;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
}
