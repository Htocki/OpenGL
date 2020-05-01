#include <GL/glut.h>

#include <cmath>

constexpr double PI { 3.1415 }, g { 9.8 };
double V { 20 }, alpha { 30 };
double cx { 0 }, cy { 0 };
int m { 0 };

void RenderScene() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(cx,  0.0);
  glEnd();

  glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0,  cy);
  glEnd();

  glColor3f(0.5, 0.8, 0.4);
  double x { 0.0 }, y { 0.0 };
  alpha *= PI / 180;
  double t { 0.0 };

  glBegin(GL_POINTS);
    while (t <= (V * std::sin(alpha) / g)) {
      x = V * std::cos(alpha) * t;
      y = V * std::sin(alpha) * t - g * t * t / 2;
      glVertex2d(x, y);
      t += 0.01;
    }
    double h { y };
    double l { x };
    t = 0.0;
    while (t <= (V * std::sin(alpha) / g)) {
      x = l + V * std::cos(alpha) * t;
      y = h - g * t * t / 2;
      glVertex2d(x, y);
      t += 0.01;
    }
  glEnd();
  glutSwapBuffers();
}

void ChangeSize(GLsizei w, GLsizei h) {
  if (h == 0) { h = 1; }
  cx = V * V * std::sin(2 * (alpha * PI / 180)) / g + 15;
  cy = V * V * std::sin(alpha * PI / 180)
    * std::sin(alpha * PI / 180) / (2 * g) + 15;
  glViewport(5, 5, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, cx, 0.0, cy);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void Initialise() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
}

void CheckMenu(int v) {
  if (v == 0) {
    glutSetWindowTitle("Hi");
  }
}

void CheckMenu2(int v) {
  switch (v) {
    case 6:
      alpha = 30;
      glutPostRedisplay();
      break;
    case 7:
      alpha = 45;
      glutPostRedisplay();
      break;
    case 8:
      alpha = 60;
      glutPostRedisplay();
      break;
  }
}

void InitialMenu() {
  int cm2 = glutCreateMenu(CheckMenu2);
  glutSetMenu(cm2);
  glutAddMenuEntry("30 degrees", 6);
  glutAddMenuEntry("45 degrees", 7);
  glutAddMenuEntry("60 degrees", 8);

  int cm = glutCreateMenu(CheckMenu);
  glutSetMenu(cm);
  glutAddSubMenu("The angle is", cm2);

  glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(480, 360);
  glutInitWindowPosition(40, 60);
  glutCreateWindow("Throwing the body at an angle to the horizon.");
  glutDisplayFunc(RenderScene);
  glutReshapeFunc(ChangeSize);
  Initialise();
  InitialMenu();
  glutMainLoop();
}
