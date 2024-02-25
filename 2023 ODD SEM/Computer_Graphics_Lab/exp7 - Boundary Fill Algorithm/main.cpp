#include <GL/glut.h>
#include <iostream>
#include <vector>

int width = 400;
int height = 400;

void drawPixel(int x, int y, float* color) {
    glColor3fv(color);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

bool colorsEqual(float* color1, float* color2) {
    return (color1[0] == color2[0] && color1[1] == color2[1] && color1[2] == color2[2]);
}

void boundaryFill(int x, int y, float* fillColor, float* boundaryColor) {
    float currentColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, currentColor);

    if (!colorsEqual(currentColor, boundaryColor) && !colorsEqual(currentColor, fillColor)) {
        drawPixel(x, y, fillColor);

        boundaryFill(x + 1, y, fillColor, boundaryColor);
        boundaryFill(x - 1, y, fillColor, boundaryColor);
        boundaryFill(x, y + 1, fillColor, boundaryColor);
        boundaryFill(x, y - 1, fillColor, boundaryColor);
    }
}

void drawShape() {
    glClear(GL_COLOR_BUFFER_BIT);
    float fillColor[] = {1.0f, 1.0f, 0.0f};
    float boundaryColor[] = {1.0f, 0.0f, 0.0f};

    glColor3fv(boundaryColor);
    glBegin(GL_LINE_LOOP);
    glVertex2i(100, 100);
    glVertex2i(300, 100);
    glVertex2i(250, 300);
    glVertex2i(150, 300);
    glEnd();

    boundaryFill(200, 200, fillColor, boundaryColor);

}

void display() {
    drawShape();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Boundary Fill Algorithm");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
