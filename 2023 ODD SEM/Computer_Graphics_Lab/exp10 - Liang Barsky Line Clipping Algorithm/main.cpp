#include <iostream>
#include <GL/glut.h>
#include <cstdlib> // For usleep
#ifdef _WIN32
#include <windows.h> // For Sleep
#else
#include <unistd.h> // For usleep
#endif

float x_min = 100, y_min = 100, x_max = 400, y_max = 300;
bool clippingDone = false;

void draw_clipping_window() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x_min, y_min);
    glVertex2f(x_max, y_min);
    glVertex2f(x_max, y_max);
    glVertex2f(x_min, y_max);
    glEnd();
}

void liang_barsky(float x1, float y1, float x2, float y2) {
    float p1 = -(x2 - x1);
    float p2 = x2 - x1;
    float p3 = -(y2 - y1);
    float p4 = y2 - y1;
    float q1 = x1 - x_min;
    float q2 = x_max - x1;
    float q3 = y1 - y_min;
    float q4 = y_max - y1;
    float t1 = 0, t2 = 1;
    if (p1 == 0 && p2 == 0 && (q1 < 0 || q2 < 0)) {
        return;
    }
    if (p3 == 0 && p4 == 0 && (q3 < 0 || q4 < 0)) {
        return;
    }
    if (p1 != 0) {
        t1 = std::max(t1, q1 / p1);
        t2 = std::min(t2, q2 / p2);
    }
    if (p3 != 0) {
        t1 = std::max(t1, q3 / p3);
        t2 = std::min(t2, q4 / p4);
    }
    if (t1 <= t2) {
        float new_x1 = x1 + t1 * (x2 - x1);
        float new_y1 = y1 + t1 * (y2 - y1);
        float new_x2 = x1 + t2 * (x2 - x1);
        float new_y2 = y1 + t2 * (y2 - y1);

        glBegin(GL_LINES);
        glVertex2f(new_x1, new_y1);
        glVertex2f(new_x2, new_y2);
        glEnd();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    draw_clipping_window();
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(250, 350);
    glVertex2f(450, 200);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(50, 200);
    glVertex2f(470, 200);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(250, 150);
    glVertex2f(250, 50);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(215, 150);
    glVertex2f(215, 50);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(180, 150);
    glVertex2f(180, 50);
    glEnd();

    if (clippingDone) {
        liang_barsky(190, 100, 190, 175);
        liang_barsky(220, 100, 220, 175);
        liang_barsky(250, 100, 250, 175);
    }

    glutSwapBuffers();
    glFlush();
}

void timer(int value) {
    clippingDone = true;
    glutPostRedisplay(); // Request a display callback
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Liang-Barsky Line Clipping");
    glOrtho(0, 500, 0, 400, -1, 1);
    glutDisplayFunc(display);

    // Set a timer for 5 seconds
#ifdef _WIN32
    Sleep(5000); // Sleep for 5 seconds on Windows
#else
    usleep(5000000); // Sleep for 5 seconds on Unix-like systems (microseconds)
#endif
    timer(0); // Trigger the timer manually after sleeping

    glutMainLoop();
    return 0;
}
