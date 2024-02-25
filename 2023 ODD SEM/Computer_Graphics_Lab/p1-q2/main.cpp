#include <GL/glut.h>
#include <iostream>
#include <math.h>

int start_x = -1;
int start_y = -1;
int xc = 250;
int yc = 250;
int r = 50;

void floodFill4(int x, int y, float fillColor[3], float oldColor[3]) {
    float currentColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, currentColor);

    if (currentColor[0] == oldColor[0] && currentColor[1] == oldColor[1] && currentColor[2] == oldColor[2]) {
        glColor3fv(fillColor);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
        glFlush();

        floodFill4(x + 1, y, fillColor, oldColor);
        floodFill4(x - 1, y, fillColor, oldColor);
        floodFill4(x, y + 1, fillColor, oldColor);
        floodFill4(x, y - 1, fillColor, oldColor);
    }
}
void plotCirclePoints(int x, int y) {
    glColor3f(0.0, 0.0, 0.0);
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

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(150, 100);
    glVertex2i(350, 100);
    glVertex2i(350, 200);
    glVertex2i(150, 200);
    glEnd();

    float fillColor[3] = {0.0, 1.0, 0.0};
    float oldColor[3] = {1.0, 1.0, 1.0};

    if (start_x != -1 && start_y != -1) {
        floodFill4(start_x, start_y, fillColor, oldColor);
        start_x = -1;
        start_y = -1;
    }
    drawCircleBresenham();
    float fillColor2[3] = {0.0, 0.0, 1.0};
    float oldColor2[3] = {1.0, 1.0, 1.0};

    if (start_x != -1 && start_y != -1) {
        floodFill4(start_x, start_y, fillColor2, oldColor2);
        start_x = -1;
        start_y = -1;
    }
    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        start_x = x;
        start_y = glutGet(GLUT_WINDOW_HEIGHT) - y;
        glutPostRedisplay();
    }
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("2");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    myinit();
    glutMainLoop();
    return 0;
}
