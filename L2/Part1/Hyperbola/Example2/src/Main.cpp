#include <GL/glut.h>

#include <cmath>

constexpr double a { 0.3 }, b { 0.2 };
constexpr int n { 200 };

void Axis() {
  glColor3d(0.0, 0.0, 0.0);
  glLineWidth(1);
  glBegin(GL_LINES);
    glVertex2d(0.0, 1.0);
    glVertex2d(0.0, -1.0);
    glVertex2d(1.0, 0.0);
    glVertex2d(-1.0, 0.0);
  glEnd();
}

void Hyperbola() {
  glColor3d(1.0, 1.0, 1.0);
  glLineWidth(3);
  glBegin(GL_LINE_LOOP);
  for (auto i { -n }; i < n; ++i) {
    glColor3d(i / 80, i / 50, i / 15);
    glVertex2d(
      a * (std::exp(0.01 * i) + std::exp(-0.01 * i)) / 2,
      b * (std::exp(0.01 * i) - std::exp(-0.01 * i)) / 2);
  }
  glEnd();
  glBegin(GL_LINE_LOOP);
  for (auto i { -n }; i < n; ++i) {
    glColor3d(i / 80, i / 50, i / 15);
    glVertex2d(
      -a * (std::exp(0.01 * i) + std::exp(-0.01 * i)) / 2,
      b * (std::exp(0.01 * i) - std::exp(-0.01 * i)) / 2);
  }
  glEnd();
  glColor3d(0.0, 1.0, 0.0);
  glLineWidth(1);
  glBegin(GL_LINES);
    glVertex2d(-1.0, -b / a);
    glVertex2d(1.0, b / a);
    glVertex2d(-1.0, b / a);
    glVertex2d(1.0, -b / a);
  glEnd();
}

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  Axis();
  Hyperbola();
  glFinish();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(200, 200);
  glutInitWindowSize(400, 400);
  glutCreateWindow("Hyberbola");
  glClearColor(1.0, 0.5, 0.0, 1.0);
  glutDisplayFunc(Draw);
  glutMainLoop();
  return 0;
}
