#include <qt/QtWidgets/qwidget.h>

Widget::Widget(QWidget *parent)
    : QGLWidget(parent) {
  resize(300, 300);
}

void Widget::initializeGL() {
  qglClearColor(Qt::white);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_FLAT);
  glEnable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Widget::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
}

void Widget::paintGL() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  QColor halfGreen(0, 128, 0, 255);
  qglColor(halfGreen)
  glBegin(GL_QUADS);
    glVertex3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.5);
    glVertex3f(0.5, -0.5, 0.5);
  glEnd();
}
