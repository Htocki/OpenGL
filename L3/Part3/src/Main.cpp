#include <GL/glut.h>

#include <cmath>
#include <iostream>

double
  ro { 1.29 },
  g { 9.8 },
  dt { 0.1 },
  c { 0.45 },
  b { 0.00129 },
  F { 0 },
  s { 20 },
  alpha { 0 },
  m0 { 0 },
  mk { 0 },
  m { 0 },
  a { 0 },
  v { 0 },
  h { 0 },
  t { 0 },
  k { 0 };

void RenderScene() {
  glClear(GL_COLOR_BUFFER_BIT);

  // Система координат
  glLineWidth(4.0);
  glColor3d(1.0, 1.0, 1.0);
  glBegin(GL_LINE);
    glVertex2d(0.0, 0.0);
    glVertex2d(1.4, 0.0);
  glEnd();
  glBegin(GL_LINES);
    glVertex2d(0.0, 0.0);
    glVertex2d(0.0, 1.4);
  glEnd();
  glLineWidth(1.0);

  glColor3f(1.0, 0.0, 0.0);

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

  /*
  std::cout << "F = ";
  std::cin >> F;
  std::cout << "m0: ";
  std::cin >> m0;
  std::cout << "mk: ";
  std::cin >> mk;
  std::cout << "alpha: ";
  std::cin >> alpha;
  std::cout << "k = ";
  std::cin >> k;
  */

  F = 150'000'000;
  m0 = 20'000'000;
  mk = 500'000;
  alpha = 100'000;
  k = 3;

  for (std::size_t i { 0 }; i <= k; ++i) {
    F += F * 0.5;
    v = 0;
    h = 0;
    t = dt;
    double tk { (m0 - mk) / alpha };
    glColor3d(i / 10.0, 1.0 - i / 10.0, 1.0);
    glBegin(GL_POINTS);
      while ((t <= tk) && (v <= 1.0)) {
        m = m0 - alpha * t;
        a = (F - m * g - (1 / 2) * c * ro * std::exp(-b * h)
          * s * v * v) / m;
        v += a * dt / 7800;
        h += v * dt;
        glVertex2d(t / tk, v);
        t += dt;
      }
    glEnd();
    glutSwapBuffers();
  }
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
  glutCreateWindow("Dependence of speed and altitude on time.");
  glutDisplayFunc(RenderScene);
  glutReshapeFunc(ChangeSize);
  Initialize();
  glutMainLoop();
  return 0;
}
