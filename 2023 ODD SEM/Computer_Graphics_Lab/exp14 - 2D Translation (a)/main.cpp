#include <GL/glut.h>

GLfloat A[2] = {50.0, 50.0};
GLfloat B[2] = {150.0, 50.0};
GLfloat C[2] = {150.0, 150.0};
GLfloat D[2] = {50.0, 150.0};

GLfloat translateX = 100.0;
GLfloat translateY = 50.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_POLYGON);
    glVertex2fv(A);
    glVertex2fv(B);
    glVertex2fv(C);
    glVertex2fv(D);
    glEnd();

    A[0] += translateX;
    B[0] += translateX;
    C[0] += translateX;
    D[0] += translateX;

    A[1] += translateY;
    B[1] += translateY;
    C[1] += translateY;
    D[1] += translateY;

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2fv(A);
    glVertex2fv(B);
    glVertex2fv(C);
    glVertex2fv(D);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Square Translation");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 400, 0, 400);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
