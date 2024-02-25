#include <GL/glut.h>
#include <math.h>

GLfloat A[2] = {300.0, 300.0};
GLfloat B[2] = {400.0, 300.0};
GLfloat C[2] = {400.0, 400.0};
GLfloat D[2] = {300.0, 400.0};

GLfloat translateX = 0.0;
GLfloat translateY = 0.0;

// Reflection matrix for the origin
GLfloat reflectionMatrix[4] = {-1, 0, 0, -1};

// Function to multiply a 2x2 matrix with a 2x1 vector
void matrixMultiply(GLfloat matrix[4], GLfloat vector[2]) {
    GLfloat x = matrix[0] * vector[0] + matrix[1] * vector[1];
    GLfloat y = matrix[2] * vector[0] + matrix[3] * vector[1];
    vector[0] = x;
    vector[1] = y;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    // Draw the X and Y axes
    glBegin(GL_LINES);
    glVertex2f(0, 250);
    glVertex2f(500, 250);  // X-axis
    glVertex2f(250, 0);
    glVertex2f(250, 500);  // Y-axis
    glEnd();

    // Original square
    glBegin(GL_POLYGON);
    glVertex2fv(A);
    glVertex2fv(B);
    glVertex2fv(C);
    glVertex2fv(D);
    glEnd();

    // Translate the square to the origin (250, 250)
    A[0] -= 250;
    B[0] -= 250;
    C[0] -= 250;
    D[0] -= 250;

    A[1] -= 250;
    B[1] -= 250;
    C[1] -= 250;
    D[1] -= 250;

    // Apply reflection transformation to the square's vertices
    matrixMultiply(reflectionMatrix, A);
    matrixMultiply(reflectionMatrix, B);
    matrixMultiply(reflectionMatrix, C);
    matrixMultiply(reflectionMatrix, D);

    // Translate the square back to its original position
    A[0] += 250;
    B[0] += 250;
    C[0] += 250;
    D[0] += 250;

    A[1] += 250;
    B[1] += 250;
    C[1] += 250;
    D[1] += 250;

    // Draw the reflected square
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
    glutInitWindowSize(500, 500);
    glutCreateWindow("2D Reflection about origin");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
