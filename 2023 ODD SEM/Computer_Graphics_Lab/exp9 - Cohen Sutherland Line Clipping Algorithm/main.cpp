#include <GL/glut.h>
#include <iostream>

const int LEFT = 50, RIGHT = 250, BOTTOM = 50, TOP = 150;

struct Point {
    int x, y;
};

Point lines[8][2] = {
    {{300, 100}, {400, 150}},
    {{120, 120}, {180, 180}},
    {{125, 50}, {125, 150}},
    {{75, 75}, {175, 175}},
    {{30, 10}, {30, 190}},
    {{150, 100}, {300, 50}}
};


int computeCode(Point p) {
    int code = 0;
    if (p.x < LEFT) code |= 1;
    if (p.x > RIGHT) code |= 2;
    if (p.y < BOTTOM) code |= 4;
    if (p.y > TOP) code |= 8;
    return code;
}


void cohenSutherland(Point p1, Point p2) {
    int code1 = computeCode(p1);
    int code2 = computeCode(p2);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int code_out = code1 ? code1 : code2;
            Point intersect;

            if (code_out & 1) {
                intersect.x = LEFT;
                intersect.y = p1.y + (p2.y - p1.y) * (LEFT - p1.x) / (p2.x - p1.x);
            } else if (code_out & 2) {
                intersect.x = RIGHT;
                intersect.y = p1.y + (p2.y - p1.y) * (RIGHT - p1.x) / (p2.x - p1.x);
            } else if (code_out & 4) {
                intersect.x = p1.x + (p2.x - p1.x) * (BOTTOM - p1.y) / (p2.y - p1.y);
                intersect.y = BOTTOM;
            } else {
                intersect.x = p1.x + (p2.x - p1.x) * (TOP - p1.y) / (p2.y - p1.y);
                intersect.y = TOP;
            }

            if (code_out == code1) {
                p1 = intersect;
                code1 = computeCode(p1);
            } else {
                p2 = intersect;
                code2 = computeCode(p2);
            }
        }
    }

    if (accept) {
        glBegin(GL_LINES);
        glVertex2i(p1.x, p1.y);
        glVertex2i(p2.x, p2.y);
        glEnd();
    }
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
    for (int i = 0; i < 8; i++) {
        glBegin(GL_LINES);
        glVertex2i(lines[i][0].x, lines[i][0].y);
        glVertex2i(lines[i][1].x, lines[i][1].y);
        glEnd();
    }
    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i < 8; i++) {
        cohenSutherland(lines[i][0], lines[i][1]);
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
    glutCreateWindow("Cohen-Sutherland Line Clipping");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glOrtho(0, 400, 0, 400, -1, 1);
    glutMainLoop();
    return 0;
}
