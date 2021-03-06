#include <GL/glut.h>

#include <cmath>

constexpr double a { 0.7 }, b { 0.4 };
constexpr int n { 100 };

void Axis() {
  glColor3d(1.0, 0.0, 0.0);
  glLineWidth(1);
  glBegin(GL_LINES);
    glVertex2d(0.0, 1.0);
    glVertex2d(0.0, -1.0);
    glVertex2d(1.0, 0.0);
    glVertex2d(-1.0, 0.0);
  glEnd();
}

void Ellipse() {
  glColor3d(1.0, 1.0, 1.0);
  glLineWidth(3);
  glBegin(GL_LINE_LOOP);
  for (auto i { 0 }; i < n; ++i) {
    glVertex2d(
      a * std::sin(2 * 3.1416 * i / n),
      b * std::cos(2 * 3.1416 * i / n));
  }
  glEnd();
}

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  Axis();
  Ellipse();
  glFinish();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(200, 200);
  glutInitWindowSize(400, 400);
  glutCreateWindow("Ellipse-Example1");
  glClearColor(0.0, 0.0, 0.5, 1.0);
  glutDisplayFunc(Draw);
  glutMainLoop();
  return 0;
}
