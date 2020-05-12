#include <GL/glut.h>

#include <cmath>

void CoordinateSystem() {
  glLineWidth(4.0);
  glColor3d(1.0, 1.0, 1.0);
  glBegin(GL_LINES);
    glVertex2d(0, 0);
    glVertex2d(1.4, 0);
  glEnd();
  glBegin(GL_LINES);
    glVertex2d(0, 0);
    glVertex2d(0, 1.4);
  glEnd();
}

void Limits() {
  glColor3f(1.0, 0.0, 0.0);
  glLineWidth(1.0);
  for (float i { 0 }; i <= 1.3; i += 0.25) {
    glBegin(GL_LINES);
      glVertex2f(1.0, i);
      glVertex2f(1.0, i + 0.1);
    glEnd();
  }
  for (float i { 0 }; i <= 1.3; i += 0.25) {
    glBegin(GL_LINES);
      glVertex2f(i, 1.0);
      glVertex2f(i + 0.1, 1.0);
    glEnd();
  }
}

void TheDependenceOfSpeedOnTime() {
  constexpr double
    b { 0.00129 },
    c { 0.45 },
    dt { 0.1 },
    g { 9.8 },
    ro { 1.29 },
    s { 20 };

  double
    F { 150'000'000 },
    m0 { 20'000'000 },
    mk { 500'000 },
    alpha { 100'000 },
    k { 3 };

  for (std::size_t i { 0 }; i <= k; ++i) {
    F += F * 0.6666667;  // Коэффициент роста F
    double v { 0 };
    double h { 0 };
    double t { dt };
    double tk { (m0 - mk) / alpha };
    glColor3d(i / 10.0, 1.0 - i / 10.0, 1.0);
    glBegin(GL_POINTS);
      while ((t <= tk) && (v <= 1.0)) {
        double m { m0 - alpha * t };
        double a { (F - m * g - (1 / 2) * c * ro * std::exp(-b * h)
          * s * v * v) / m };
        v += a * dt / 7800;
        h += v * dt;
        glVertex2d(t / tk, v);
        t += dt;
      }
    glEnd();
  }
}

void RenderScene() {
  glClear(GL_COLOR_BUFFER_BIT);
  CoordinateSystem();
  Limits();
  TheDependenceOfSpeedOnTime();
  glFlush();
  glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h) {
  if (h == 0) { h = 1; }
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(5, 5, w, h);
  gluOrtho2D(0, 1.5, 0, 1.5);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Initialize() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(20, 20);
  glutCreateWindow("The dependence of speed on time.");
  glutDisplayFunc(RenderScene);
  glutReshapeFunc(ChangeSize);
  Initialize();
  glutMainLoop();
  return 0;
}
