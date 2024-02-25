#include <GL/glut.h>
#include <iostream>
#include <cmath>

int xone, yone, xtwo, ytwo;

void drawLineDDA() {
    glBegin(GL_POINTS);

    int dx = xtwo - xone;
    int dy = ytwo - yone;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = float(dx) / steps;
    float yIncrement = float(dy) / steps;

    float x = xone;
    float y = yone;

    for (int i = 0; i <= steps; ++i) {
        glVertex2i(round(x), round(y));
        x += xIncrement;
        y += yIncrement;
    }

    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    drawLineDDA();

    glFlush();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    std::cout << "Enter the coordinates of the first endpoint (x1, y1): ";
    std::cin >> xone >> yone;

    std::cout << "Enter the coordinates of the second endpoint (x2 y2): ";
    std::cin >> xtwo >> ytwo;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("DDA Line Drawing Algorithm");
    glutDisplayFunc(display);

    myinit();
    glutMainLoop();

    return 0;
}
