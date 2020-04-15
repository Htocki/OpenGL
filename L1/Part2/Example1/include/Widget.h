#pragma once

#include <QtGui>
#include <QGLWidget>

class Widget : public QGLWidget {
 public:
  explicit Widget(QWidget *parent = 0);

 protected:
  void initializeGL();
  void resizeGL(int Width, int Height);
  void paintGL();
};
