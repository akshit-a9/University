#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265

struct Point {
    float x;
    float y;
};

Point A = {0.0, 0.0};
Point B = {1.0, 0.0};
Point C = {1.0, 1.0};

void drawTriangle(Point A, Point B, Point C) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(A.x, A.y);
    glVertex2f(B.x, B.y);
    glVertex2f(C.x, C.y);
    glEnd();
    glFlush();
}

void rotatePoint(Point &p, float angle) {
    float rad = angle * PI / 180.0;
    float new_x = p.x * cos(rad) - p.y * sin(rad);
    float new_y = p.x * sin(rad) + p.y * cos(rad);
    p.x = new_x;
    p.y = new_y;
}

void displayFirstWindow() {
    glutSetWindow(1);
    drawTriangle(A, B, C);
}

void displaySecondWindow() {
    glutSetWindow(2);
    rotatePoint(A, -45.0);
    rotatePoint(B, -45.0);
    rotatePoint(C, -45.0);
    drawTriangle(A, B, C);
}

void displayThirdWindow() {
    glutSetWindow(3);
    rotatePoint(A, 90.0);
    rotatePoint(B, 90.0);
    rotatePoint(C, 90.0);
    drawTriangle(A, B, C);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Original Triangle");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glutDisplayFunc(displayFirstWindow);

    glutInitWindowSize(250, 250);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("Rotated 45 Degrees");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glutDisplayFunc(displaySecondWindow);

    glutInitWindowSize(250, 250);
    glutInitWindowPosition(700, 100);
    glutCreateWindow("Rotated 90 Degrees");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glutDisplayFunc(displayThirdWindow);

    glutMainLoop();
    return 0;
}
