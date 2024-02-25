#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

int xc, yc, r;
int temp;

void plotCirclePoints(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
    glEnd();
    glutSwapBuffers();
}

void drawCircleBresenham() {
    int x = 0;
    int y = r;
    int p = 3 - (2*r);

    plotCirclePoints(x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 4 * x + 6;
        } else {
            y--;
            p += 4 * (x - y) + 10;
        }
        plotCirclePoints(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    cout<<xc<<"  "<<yc<<endl;
    drawCircleBresenham();
    glutSwapBuffers();
    xc = 330;
    cout<<xc<<"  "<<yc<<endl;
    drawCircleBresenham();
    glutSwapBuffers();
    glBegin(GL_LINE_LOOP);
    glVertex2i(50,250);
    glVertex2i(90,330);
    glVertex2i(130,250);
    glVertex2i(130,170);
    glVertex2i(210,170);
    glVertex2i(210,250);
    glVertex2i(250,330);
    glVertex2i(290,250);
    glVertex2i(290,170);
    glVertex2i(370,170);
    glVertex2i(370,250);
    glVertex2i(410,330);
    glVertex2i(450,250);
    glEnd();
    glutSwapBuffers();
}



void myinit() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char** argv) {
    xc = 170;
    yc = 210;
    r = 40;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("P1 group B ques1");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();

    return 0;
}
