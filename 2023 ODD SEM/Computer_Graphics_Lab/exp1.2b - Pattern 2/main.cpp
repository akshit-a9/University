#include<GL/glut.h>

void display() {
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 1.0, 0.0); //yellow
    glVertex2i(150,300);
    glVertex2i(200,400);
    glVertex2i(250,300);
glEnd();

glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 1.0, 1.0); //cyan
    glVertex2i(100,270);
    glVertex2i(200,450);
    glVertex2i(300,270);
glEnd();

glEnable(GL_LINE_STIPPLE);
glLineStipple(1,0x00FF);
glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 0.0f, 0.0f); //color gradient
    glVertex2i(125,290);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2i(200,425);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2i(275,290);
glEnd();
glDisable(GL_LINE_STIPPLE);
glutSwapBuffers();
}

void myinit() {
glClearColor(0.0, 0.0, 0.0, 1.0);
glPointSize(10.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0, 0);
glutCreateWindow("Line_LOOP");
glutDisplayFunc(display);

myinit();
glutMainLoop();
}
