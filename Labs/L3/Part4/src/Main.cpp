#include <GL/glut.h>

#include <cmath>

double velo(double v, double z, double l, double ta) {
  double m { z * z + l * l };
  double k { std::sqrt(m) };
  return v - z / std::pow(k, 3.0) * ta;
}

void ChangeSize(GLsizei w, GLsizei h) {
  // Предотвращает деление на 0
  if (h == 0) { h = 1; }
  // Уставливает область просмотра равной размеру окна
  glViewport(0, 0, w, h);
  // Обновляет систему координат
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // С помощью плоскостей отсечения
  // (левая, правая, нижняя, верхняя, ближняя, дальняя)
  // устанавливает объем отсечения
  GLdouble aspect_ratio { GLdouble(w) / GLdouble(h) };
  if (w <= h) {
    glOrtho(
      -40.0, 6.0,
      -23.0 / aspect_ratio, 23.0 / aspect_ratio,
      -1.0, 1.0);
  } else {
    glOrtho(
      -40.0 * aspect_ratio, 6.0 * aspect_ratio,
      -23.0, 23.0,
      -1.0, 1.0);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Initialize() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

struct Color {
  float red { 0 };
  float green { 0 };
  float blue { 0 };
};

void CoordinateSystem(Color c) {
  glColor3f(c.red, c.green, c.blue);
  // Ось х
  glBegin(GL_LINES);
    glVertex2f(-39.0, 0.0);
    glVertex2f(5.0, 0.0);
  glEnd();
  // Ось y
  glBegin(GL_LINES);
    glVertex2f(0.0, -22.0);
    glVertex2f(0.0, 22.0);
  glEnd();
}

void CenterOfGravity(Color c) {
  constexpr double pi { 3.1415 };
  glColor3f(c.red, c.green, c.blue);
  glBegin(GL_POINTS);
    for (double radian { 0 }; radian <= 2 * pi; radian += 0.05) {
      glVertex2d(std::cos(radian), std::sin(radian));
    }
  glEnd();
}

void Orbit(
  Color c,  // Цвет
  double limit,  // Временной предел
  double x,  // Расстояние между спутником и центром притяжения
  double y = 0,  // Координата спутника
  double vx = 0,  // Составляющая скорости по оси x
  double vy = 1.2  // Составляющая скорости по оси y
) {
  constexpr double dt { 0.00005 };
  glColor3f(c.red, c.green, c.blue);
  glBegin(GL_POINTS);
    for (double t { 0 }; t <= limit; t += dt) {
      glVertex2d(x, y);
      vx = velo(vx, x, y, dt);
      vy = velo(vy, y, x, dt);
      x += vx * dt;
      y += vy * dt;
    }
  glEnd();
}

void RenderScene() {
  glClear(GL_COLOR_BUFFER_BIT);
  CoordinateSystem(Color{ 1.0, 0.0, 0.0 });
  CenterOfGravity(Color{ 0.0, 1.0, 0.0 });
  Orbit(Color{0.0, 0.0, 1.0}, 70, 1.20);
  Orbit(Color{0.0, 1.0, 1.0}, 200, 1.25);
  Orbit(Color{0.5, 0.6, 1.0}, 220, 1.30);
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640, 640);
  glutInitWindowPosition(20, 20);
  glutCreateWindow("The movement of celestial bodies");
  glutDisplayFunc(RenderScene);
  glutReshapeFunc(ChangeSize);
  Initialize();
  glutMainLoop();
  return 0;
}
