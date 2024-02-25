#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

int xc, yc, r;

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
    drawCircleBresenham();
    glutSwapBuffers();
}



void myinit() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char** argv) {
    cout << "Enter the center coordinates (xc, yc): ";
    cin >> xc >> yc;
    cout << "Enter the radius (r): ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Circle Drawing Algorithm");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();

    return 0;
}
