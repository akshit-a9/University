#include <GL/glut.h>
#include <iostream>

const int LEFT = 50, RIGHT = 270, BOTTOM = 50, TOP = 270;

struct Point {
    int x, y;
};

Point lines[4][2] = {
    {{10, 180}, {240, 320}}
};

enum { INSIDE, LEFT_EDGE, RIGHT_EDGE, BOTTOM_EDGE, TOP_EDGE };

int computeRegionCode(Point p) {
    int code = INSIDE;

    if (p.x < LEFT)
        code |= LEFT_EDGE;
    else if (p.x > RIGHT)
        code |= RIGHT_EDGE;

    if (p.y < BOTTOM)
        code |= BOTTOM_EDGE;
    else if (p.y > TOP)
        code |= TOP_EDGE;

    return code;
}

bool clipLine(Point &p1, Point &p2) {
    int code1 = computeRegionCode(p1);
    int code2 = computeRegionCode(p2);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int code_out = code1 ? code1 : code2;
            Point newPoint;

            if (code_out & LEFT_EDGE) {
                newPoint.x = LEFT;
                newPoint.y = p1.y + (p2.y - p1.y) * (LEFT - p1.x) / (p2.x - p1.x);
            } else if (code_out & RIGHT_EDGE) {
                newPoint.x = RIGHT;
                newPoint.y = p1.y + (p2.y - p1.y) * (RIGHT - p1.x) / (p2.x - p1.x);
            } else if (code_out & BOTTOM_EDGE) {
                newPoint.x = p1.x + (p2.x - p1.x) * (BOTTOM - p1.y) / (p2.y - p1.y);
                newPoint.y = BOTTOM;
            } else if (code_out & TOP_EDGE) {
                newPoint.x = p1.x + (p2.x - p1.x) * (TOP - p1.y) / (p2.y - p1.y);
                newPoint.y = TOP;
            }

            if (code_out == code1) {
                p1 = newPoint;
                code1 = computeRegionCode(p1);
            } else {
                p2 = newPoint;
                code2 = computeRegionCode(p2);
            }
        }
    }

    return accept;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(LEFT, BOTTOM);
    glVertex2i(RIGHT, BOTTOM);
    glVertex2i(RIGHT, TOP);
    glVertex2i(LEFT, TOP);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 8; i++) {
        glBegin(GL_LINES);
        glVertex2i(lines[i][0].x, lines[i][0].y);
        glVertex2i(lines[i][1].x, lines[i][1].y);
        glEnd();
    }

    glColor3f(1.0, 1.0, 0.0);
    for (int i = 0; i < 8; i++) {
        Point p1 = lines[i][0];
        Point p2 = lines[i][1];
        if (clipLine(p1, p2)) {
            glBegin(GL_LINES);
            glVertex2i(p1.x, p1.y);
            glVertex2i(p2.x, p2.y);
            glEnd();
        }
    }

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glClear(GL_COLOR_BUFFER_BIT);
        display();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Nicoll-Lee-Nicoll Line Clipping");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glOrtho(0, 400, 0, 400, -1, 1);
    glutMainLoop();
    return 0;
}
