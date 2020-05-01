#include <GL/glut.h>

#include <cmath>
#include <cstdio>

GLuint LoadTexture(const char * filename);

void Texture() {
  GLuint texture = LoadTexture("Pict.bmp");
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  // glTexImage2D(
  //   GL_TEXTURE_2D, 0, 3, T->sizeX, T->sizeY, 0,
  //   GL_RGB, GL_UNSIGNED_BYTE, T->date);
}

void Draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(0.0, 1.0, 0.0, 1.0);
  glEnable(GL_TEXTURE_2D);
  glBegin(GL_POLYGON);
    glTexCoord2d(0.0, 0.0);
    glVertex2d(0.0, 0.0);
    glTexCoord2d(0.0, 1.0);
    glVertex2d(0.0, 1.0);
    glTexCoord2d(1.0, 1.0);
    glVertex2d(1.0, 1.0);
    glTexCoord2d(1.0, 0.0);
    glVertex2d(1.0, 0.0);
  glEnd();
  glFlush();
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Texture");
  glClearColor(0.0, 0.5, 1.0, 1.0);
  Texture();
  glutDisplayFunc(Draw);
  glutMainLoop();
}

GLuint LoadTexture(const char * filename) {
  GLuint texture;
  int width, height;
  unsigned char * data;
  FILE * file;
  file = fopen(filename, "rb");
  if ( file == NULL ) return 0;
  width = 1024;
  height = 512;
  data = (unsigned char *)malloc(width * height * 3);
  fread(data, width * height * 3, 1, file);
  fclose(file);
  for (int i = 0; i < width * height ; ++i) {
    int index = i * 3;
    unsigned char B, R;
    B = data[index];
    R = data[index + 2];
    data[index] = R;
    data[index+2] = B;
  }
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
    GL_LINEAR_MIPMAP_NEAREST);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, GL_RGB,
    GL_UNSIGNED_BYTE, data);
  free(data);
  return texture;
}
