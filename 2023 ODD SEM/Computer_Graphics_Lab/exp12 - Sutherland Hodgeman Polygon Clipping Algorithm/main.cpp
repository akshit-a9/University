#include <iostream>
#include <vector>
#include <GL/glut.h>

struct Point
{
    GLfloat x, y;
};


std::vector<Point> clipPolygon(const std::vector<Point>& inputPolygon, GLfloat left, GLfloat right, GLfloat top, GLfloat bottom) {
std::vector<Point> outputPolygon;

for (size_t i = 0; i < inputPolygon.size(); i++) {
    size_t next = (i + 1) % inputPolygon.size();
        Point current = inputPolygon[i];
        Point nextPoint = inputPolygon[next];

        bool insideCurrent = (current.x >= left && current.x <= right && current.y >= bottom && current.y <= top);

        bool insideNext = (nextPoint.x >= left && nextPoint.x <= right && nextPoint.y >= bottom && nextPoint.y <= top);

        if (insideCurrent && insideNext) {
            outputPolygon.push_back(nextPoint);
        } else if (insideCurrent && !insideNext) {
            GLfloat x, y;

            if (current.x >= left) {
                x = left;
                y = current.y + (nextPoint.y - current.y) * (left - current.x) / (nextPoint.x - current.x);
            }

            else if (current.x <= right) {
                x = right;
                y = current.y + (nextPoint.y - current.y) * (right - current.x) / (nextPoint.x - current.x);
            }
            else if (current.y >= bottom) {
                x = current.x + (nextPoint.x - current.x) * (bottom - current.y) / (nextPoint.y - current.y);
                y = bottom;
            }
            else {
                x = current.x + (nextPoint.x - current.x) * (top - current.y) / (nextPoint.y - current.y);
                y = top;
            }

            Point intersection = {x, y};
            outputPolygon.push_back(intersection);
        } else if (!insideCurrent && insideNext) {

            GLfloat x, y;

            if (nextPoint.x >= left) {
                x = left;
                y = current.y + (nextPoint.y - current.y) * (left - current.x) / (nextPoint.x - current.x);
            }
            else if (nextPoint.x <= right) {
                x = right;
                y = current.y + (nextPoint.y - current.y) * (right - current.x) / (nextPoint.x - current.x);
            }
            else if (nextPoint.y >= bottom) {
                x = current.x + (nextPoint.x - current.x) * (bottom - current.y) / (nextPoint.y - current.y);
                y = bottom;
            }
            else {
                x = current.x + (nextPoint.x - current.x) * (top - current.y) / (nextPoint.y - current.y);
                y = top;
            }
            Point intersection = {x, y};
            outputPolygon.push_back(intersection);
            outputPolygon.push_back(nextPoint);
        }
    }
    return outputPolygon;
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    std::vector<Point> starVertices;
    starVertices.push_back({-0.2f, 0.3f});
    starVertices.push_back({-0.25f, 0.1f});
    starVertices.push_back({-0.4f, 0.1f});
    starVertices.push_back({-0.3f, -0.1f});
    starVertices.push_back({-0.35f, -0.3f});
    starVertices.push_back({-0.2f, -0.15f});
    starVertices.push_back({-0.05f, -0.3f});
    starVertices.push_back({-0.1f, -0.1f});
    starVertices.push_back({0.0f, 0.1f});
    starVertices.push_back({-0.15f, 0.1f});

    GLfloat left = -0.3f;
    GLfloat right = 0.3f;
    GLfloat top = 0.3f;
    GLfloat bottom = -0.3f;

    starVertices = clipPolygon(starVertices, left, right, top, bottom);
    glBegin(GL_LINE_LOOP);

    for (size_t i = 0; i < starVertices.size(); i++) {
        glVertex2f(starVertices[i].x, starVertices[i].y);
    }
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(left, bottom);
    glVertex2f(right, bottom);
    glVertex2f(right, top);
    glVertex2f(left, top);
    glEnd();
    glutSwapBuffers();
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);

}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Sutherland-Hodgman Clipping");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;

}
