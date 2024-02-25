#include<GL/glut.h>

void display() {
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 0.0, 0.0);

glBegin(GL_LINE_LOOP);
    glVertex2i(180,10);
    glVertex2i(10,145);
    glVertex2i(210,210);
    glVertex2i(300,415);
    glVertex2i(325,450);
glEnd();

glutSwapBuffers();
}

void myinit() {
glClearColor(1.0, 1.0, 1.0, 1.0);
glColor3f(1.0, 0.0, 0.0);
glPointSize(10.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(0, 0);
glutCreateWindow("Line Loop");
glutDisplayFunc(display);

myinit();
glutMainLoop();
}
