#include <GL/glut.h>

#include <cmath>

constexpr double pi { 3.1415 };
constexpr std::size_t size { 4 };

double x { 0 }, A { 0 }, B { 0 }, a { 30 };
double Y[size], y[size];
double h { 0.00001 }, hpr { 0.0001 };

double Ff(int i, double *x, double *y) {
  switch (i) {
    case 0:
      return (-A * std::sin(a) * y[0] - B * std::sin(a)
        * std::sqrt(y[0] * y[0] + y[1] * y[1]) * y[0]);

    case 1:
      return (-std::sin(a) - A * std::sin(a) * y[0]
        - B * std::sin(a) * std::sqrt(y[0] * y[0] + y[1]
        * y[1]) * y[1]);

    case 2:
      return (y[0] / (2 * std::cos(a)));

    case 3:
      return (2 * y[1] / std::sin(a));
  }
  return -1;
}

// Вычисление правой части дифференциального уравнения
void Right(double *x, double *y, double *g) {
  for (std::size_t i { 0 }; i < size; ++i) {
    g[i] = Ff(i, x, y);
  }
}

// Реализация алгоритма Рунге-Кутта
void MethodRungeKutta(double *x, double *y0, double *y, double h) {
  double z[size], k1[size], k2[size], k3[size], k4[size];

  Right(x, y0, k1);
  *x = *x + h / 2;

  for (std::size_t i { 0 }; i < size; ++i) {
    z[i] = y0[i] + h * k1[i] / 2;
  }
  Right(x, z, k2);

  for (std::size_t i { 0 }; i < size; ++i) {
    z[i] = y0[i] + h * k2[i] / 2;
  }
  Right(x, z, k3);
  *x = *x + h / 2;

  for (std::size_t i { 0 }; i < size; ++i) {
    z[i] = y0[i] + h * k3[i] / 2;
  }
  Right(x, z, k4);

  for (std::size_t i { 0 }; i < size; ++i) {
    y[i] = y0[i] + h * (k1[i] + 2 * k2[i] + 2 * k3[i]
      + k4[i]) / 6;
  }
  Right(x, z, k2);
}

void RenderScene() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3d(1.0, 0.0, 0.0);
  glBegin(GL_LINES);
    glVertex2d(0.0, 0.0);
    glVertex2d(2.0, 0.0);
  glEnd();
  glBegin(GL_LINES);
    glVertex2d(0.0, 0.0);
    glVertex2d(0.0, 2.0);
  glEnd();

  A = 0.5;
  B = 0.04;
  double x0 { 0 };
  x = x0;
  y[3] = Y[3];

  for (std::size_t i { 1 }; i < size; ++i) {
    A *= i;
    B *= i;
    a *= pi / 180;
    Y[0] = std::cos(a);
    Y[1] = std::sin(a);
    Y[2] = 0;
    Y[3] = 0;
    glColor3d(1 - 0.4 / i, 0.4 / i, 0.4 + 0.4 / i);
    x = x0 = 0;
    y[3] = Y[3];

    glBegin(GL_POINTS);
      while (y[3] >= 0.0) {
        MethodRungeKutta(&x, Y, y, h);
        for (std::size_t j { 0 }; j < size; ++j) {
          Y[j] = y[j];
        }
        glVertex2d(Y[2], Y[3]);
      }
    glEnd();
  }
  glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h) {
  if (h == 0) { h = 1; }
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(5, 5, w, h);
  gluOrtho2D(0, 2.0, 0, 2.0);
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
  glutInitWindowPosition(100, 100);
  auto window_name {
    "Throw to the horizon taking into "
    "account air resistance."
  };
  glutCreateWindow(window_name);
  glutDisplayFunc(RenderScene);
  glutReshapeFunc(ChangeSize);
  Initialize();
  glutMainLoop();
  return 0;
}
