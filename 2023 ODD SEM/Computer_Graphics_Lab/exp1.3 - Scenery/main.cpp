#include<GL/glut.h>

void drawMountains() {
    glColor3f(0.4, 0.4, 0.4);

    glBegin(GL_TRIANGLES);
    glVertex2i(-100, 200);
    glVertex2i(200, 200);
    glVertex2i(50, 400);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2i(100, 200);
    glVertex2i(400, 200);
    glVertex2i(250, 400);
    glEnd();
}

void drawHouse() {
glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(50,50);
    glVertex2i(50,200);
    glVertex2i(150,200);
    glVertex2i(150,50);
glEnd();

glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(50,200);
    glVertex2i(100,300);
    glVertex2i(150,200);
glEnd();

glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(150,200);
    glVertex2i(300,200);
    glVertex2i(300,50);
    glVertex2i(150,50);
glEnd();

glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(100,300);
    glVertex2i(250,300);
    glVertex2i(300,200);
glEnd();

glBegin(GL_LINE_STRIP);
    glColor3f(0.0, 1.0, 1.0);
    glVertex2f(65.5,50);
    glVertex2f(65.5,155);
    glVertex2f(134.5,155);
    glVertex2f(134.5,50);
glEnd();

glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 1.0);
    glVertex2f(175,86);
    glVertex2f(175,155);
    glVertex2f(275,155);
    glVertex2f(275,86);
glEnd();

glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(200,200);
    glVertex2i(150,300);
    glVertex2i(250,200);
    glVertex2i(200,300);
glEnd();
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawMountains();
    drawHouse();
    glutSwapBuffers();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
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
    glutCreateWindow("Scenery with Mountains");
    glutDisplayFunc(display);

    myinit();
    glutMainLoop();
}
