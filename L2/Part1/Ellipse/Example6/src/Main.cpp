#include <GL/glut.h>

#include <cmath>

constexpr double a { 0.7 }, b { 0.7 };
constexpr int n { 11 };

void Figure() {
  glColor3d(0.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
  for (auto i { 0 }; i < n; ++i) {
    glVertex2d(
      b * std::sin(2 * 3.1416 * i / n),
      a * std::cos(2 * 3.1416 * i / n));
  }
  glEnd();
}

void Ellipse() {
  glColor3d(0.0, 0.0, 1.0);
  glLineWidth(3);
  glBegin(GL_LINE_LOOP);
  for (auto i { 0 }; i < n; ++i) {
    glVertex2d(
      b * std::sin(2 * 3.1416 * i / n),
      a * std::cos(2 * 3.1416 * i / n));
  }
  glEnd();
}

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  Figure();
  Ellipse();
  glFinish();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(200, 200);
  glutInitWindowSize(400, 400);
  glutCreateWindow("Ellipse");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glutDisplayFunc(Draw);
  glutMainLoop();
  return 0;
}
