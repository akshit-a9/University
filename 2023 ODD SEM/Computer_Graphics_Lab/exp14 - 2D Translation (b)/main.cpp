  #define _GLIBCXX_USE_CXX11_ABI 0

#include <GL/glut.h>
#include <string>
#include <sstream>
#include <cmath>

// Define the vertices of an equilateral triangle
float vertices[][2] = {{0, 100 * sqrt(3)}, {-50, 0}, {50, 0}};

float tx = 50;
float ty = 50;

void displayOriginalPosition() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.75, 0.75);
    glBegin(GL_LINES);
    glVertex2f(-250, 0);
    glVertex2f(250, 0);
    glVertex2f(0, -250);
    glVertex2f(0, 250);
    glEnd();

    glColor3f(1.0, 0.75, 0.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
        glRasterPos2f(vertices[i][0], vertices[i][1]);
        std::stringstream ss;
        ss << "(" << vertices[i][0] << "," << vertices[i][1] << ")";
        std::string text = ss.str();

        for (size_t j = 0; j < text.size(); j++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[j]);
        }
    }
    glEnd();
    glutSwapBuffers();
    glFlush();
}

void displayTranslatedPosition() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.75, 0.0);
    glBegin(GL_LINES);
    glVertex2f(-250, 0);
    glVertex2f(250, 0);
    glVertex2f(0, -250);
    glVertex2f(0, 250);
    glEnd();

    for (int i = 0; i < 3; i++) {
        vertices[i][0] += tx;
        vertices[i][1] += ty;
    }

    glColor3f(1.0, 0.45, 1.0);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 3; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
        glRasterPos2f(vertices[i][0], vertices[i][1]);
        std::stringstream ss;
        ss << "(" << vertices[i][0] << "," << vertices[i][1] << ")";
        std::string text = ss.str();
        for (size_t j = 0; j < text.size(); j++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, text[j]);
        }
    }
    glEnd();
    glutSwapBuffers();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(500, 500);
    glutCreateWindow("Original Position");
    gluOrtho2D(-250, 250, -250, 250);
    glutDisplayFunc(displayOriginalPosition);

    glutInitWindowSize(500, 500);
    glutCreateWindow("Translated Position");
    gluOrtho2D(-250 + tx, 250 + tx, -250 + ty, 250 + ty);
    glutDisplayFunc(displayTranslatedPosition);

    glutMainLoop();
    return 0;
}
