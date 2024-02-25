#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

int xc, yc, rx, ry;

void plotRegion1Points(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);

    glEnd();
    glutSwapBuffers();
}

void plotRegion2Points(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glEnd();
    glutSwapBuffers();
}

void drawEllipseMidPoint() {
    int x = 0;
    int y = ry;
    int p1 = pow(ry, 2) + (0.25 * (pow(rx, 2))) - (ry * (pow(rx, 2)));
    plotRegion1Points(x, y);

    while ((2*(y*(pow(rx,2)))) >= (2*(x*(pow(ry,2))))) {
        x++;
        if (p1 < 0) {
            p1 += (2*(x*(pow(ry,2)))) + (pow(ry,2));
        } else {
            y--;
            p1 += (2*(x*(pow(ry,2)))) + (pow(ry,2)) - (2*(y*(pow(rx,2))));
        }
        cout<<"("<<x<<","<<y<<")"<<endl;
        plotRegion1Points(x, y);
    }

    int p2 = (pow(ry, 2)*(pow((x+0.5), 2))) + ((y-1) * (y-1) * (pow(rx, 2))) - ((pow(ry, 2)) * (pow(rx, 2)));
    plotRegion2Points(x, y);

    while (y>=0) {
        y--;
        if (p2 > 0) {
            p2 -= (2*(y*(rx*rx))) + (rx*rx);
        } else {
            x++;
            p2 += (pow(rx,2)) - (2*(y*(pow(rx,2)))) + (2*(x*(pow(ry,2))));
        }
        cout<<"("<<x<<","<<y<<")"<<endl;
        plotRegion2Points(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    drawEllipseMidPoint();
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
    cout << "Enter the radius along x (rx): ";
    cin >> rx;
    cout << "Enter the radius along y (ry): ";
    cin >> ry;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();

    return 0;
}
