#include <GL/glut.h>
#include <cmath>

const int CIRCLE_POINTS = 100;
const float PI = 3.14159265f;
float scale = 1.0f;
void desenha(void);
void quadrado(void);
void triangulo(void);
void circulo(void);

void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (640, 480);
  glutCreateWindow("Escala");
  glutDisplayFunc(desenha);
  glutIdleFunc(desenha);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;
}

void desenha() {
    glClearColor(0, 0, 0, 0);
    glShadeModel(GL_SMOOTH);
    glClear(GL_COLOR_BUFFER_BIT);
    quadrado();
    circulo();
    triangulo();
    glutSwapBuffers();

}

void circulo(){
    static float scale = 1.0;
    static float direction = 0.01;
    scale += direction;

    if (scale > 1.5) {
        direction = -0.01;
    }
    if (scale < 0.5) {
        direction = 0.01;
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(scale, scale, scale);
    glTranslatef(8, 0.0, 0.0);
    glBegin(GL_TRIANGLE_FAN);
        glColor3f(1.0, 1.0, 0.0); // definir cor verde
        glVertex2f(0.0, 0.0); // centro do círculo
        for (int i = 0; i <= 360; i++) {
            float degInRad = i*M_PI/180;
            glVertex2f(cos(degInRad)*2, sin(degInRad)*2);
        }
    glEnd();
    glPopMatrix();
    glFlush();
}

void triangulo(){
    static float scale = 1.0;
    static float direction = 0.01;
    scale += direction;

    if (scale > 1.5) {
        direction = -0.01;
    }
    if (scale < 0.5) {
        direction = 0.01;
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(scale,scale,1);
    glBegin (GL_TRIANGLES);
      glColor3f(1.0, 0.0, 0.0);
      glVertex2f(-9.0, -2.0);
      glVertex2f(-8.0, 2.0);
      glVertex2f(-7.0, -2.0);
    glEnd();
    glPopMatrix();
    glFlush();

}

void quadrado(){
    static float scale = 1.0;
    static float direction = 0.01;
    scale += direction;

    if (scale > 1.5) {
        direction = -0.01;
    }
    if (scale < 0.5) {
        direction = 0.01;
    }
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10,10,-10,10,-1,1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(scale, scale, 1);
    glBegin(GL_QUADS);
        glColor3f(0.0, 0.0, 1.0); // definir cor azul
        glVertex2f(-2.0, -2.0);
        glVertex2f(-2.0, 2.0);
        glVertex2f(2.0, 2.0);
        glVertex2f(2.0, -2.0);
    glEnd();
    glPopMatrix();
    glFlush();

}
