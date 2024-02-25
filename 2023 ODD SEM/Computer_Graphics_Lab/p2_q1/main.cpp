#include <GL/glut.h>
#include <math.h>

GLfloat kiteVertices[][2] = {
    {0.0, 0.0},    // Top
    {-60.0, -120.0}, // Left
    {60.0, -120.0},  // Right
    {0.0, -240.0}   // Tail
};

//GLfloat lineVertices[][2] = {
//    {0.0, 12.0},    // Top
//};

GLfloat translateX = 0.0;
GLfloat translateY = 0.0;
GLfloat rotationAngle = 0.0;


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.7, 0.85, 0.2);

    glPushMatrix();
    glTranslatef(translateX, translateY, 0.0);
    glRotatef(rotationAngle, 0.0, 0.0, 1.0);

    glBegin(GL_TRIANGLES);
    glVertex2fv(kiteVertices[0]);
    glVertex2fv(kiteVertices[1]);
    glVertex2fv(kiteVertices[2]);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2fv(kiteVertices[1]);
    glVertex2fv(kiteVertices[2]);
    glVertex2fv(kiteVertices[3]);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2fv(kiteVertices[0]);
    glVertex2fv(kiteVertices[2]);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    translateX -= 1.0;
    translateY += 0.5;
    rotationAngle += 0.25;

    if (translateX > 400.0) {
        translateX = -400.0;
    }

    if (translateY > 400.0) {
        translateY = -400.0;
    }

    glutPostRedisplay();
    glutTimerFunc(15, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Flying Kite");

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -400, 400);

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();

    return 0;
}
