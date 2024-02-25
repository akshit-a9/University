#include <GL/gl.h>
#include <GL/glut.h>
GLfloat vertices[][2] = {
    {0.0, 0.0},
    {1.0, 0.0},
    {0.5, 1.0}
};
GLfloat scaleX = 2.0;
GLfloat scaleY = 3.0;
void drawAxes() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(-10.0, 0.0);
    glVertex2f(40.0, 0.0);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(0.0, -15.0);
    glVertex2f(0.0, 15.0);
    glEnd();
}
void displayInput() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
    glColor3f(0.35, 0.75, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 3; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();
    glutSwapBuffers();
    glFlush();
}
void displayScaled() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
    glColor3f(0.75, 0.75, 1.0);
    glPushMatrix();
    glScalef(scaleX, scaleY, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 3; i++) {
        glVertex2f(vertices[i][0], vertices[i][1]);
    }
    glEnd();
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Set window size for both windows to ensure full visibility of the scaled triangle
    glutInitWindowSize(800, 800);
    glutCreateWindow("Scaled Triangle");
    glutDisplayFunc(displayInput);
    glutInitWindowPosition(850, 0);
    glutCreateWindow("Input Triangle");
    glutDisplayFunc(displayScaled);
    glOrtho(-10, 40, -15, 15, 0, 1);
    glutMainLoop();
    return 0;
}
