#include <GL/glut.h>
#include <math.h>

#define PI 3.14159265

struct Point {
    float x;
    float y;
    float z;
};

float scale = 1.0f;
float translateX = 0.0f;
float translateY = 0.0f;
float translateZ = -5.0f;

Point A = {-0.5f, -0.5f, 0.5f};
Point B = {0.5f, -0.5f, 0.5f};
Point C = {0.5f, 0.5f, 0.5f};
Point D = {-0.5f, 0.5f, 0.5f};
Point E = {-0.5f, -0.5f, -0.5f};
Point F = {-0.5f, 0.5f, -0.5f};
Point G = {0.5f, 0.5f, -0.5f};
Point H = {0.5f, -0.5f, -0.5f};


void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(translateX, translateY, translateZ);
    glScalef(scale, scale, scale);

    glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(A.x, A.y, A.z);
    glVertex3f(B.x, B.y, B.z);
    glVertex3f(C.x, C.y, C.z);
    glVertex3f(D.x, D.y, D.z);
    // Back face
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(E.x, E.y, E.z);
    glVertex3f(F.x, F.y, F.z);
    glVertex3f(G.x, G.y, G.z);
    glVertex3f(H.x, H.y, H.z);
    // Top face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(F.x, F.y, F.z);
    glVertex3f(D.x, D.y, D.z);
    glVertex3f(C.x, C.y, C.z);
    glVertex3f(G.x, G.y, G.z);
    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(E.x, E.y, E.z);
    glVertex3f(H.x, H.y, H.z);
    glVertex3f(B.x, B.y, B.z);
    glVertex3f(A.x, A.y, A.z);
    // Right face
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(H.x, H.y, H.z);
    glVertex3f(G.x, G.y, G.z);
    glVertex3f(C.x, C.y, C.z);
    glVertex3f(B.x, B.y, B.z);
    // Left face
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(E.x, E.y, E.z);
    glVertex3f(A.x, A.y, A.z);
    glVertex3f(D.x, D.y, D.z);
    glVertex3f(F.x, F.y, F.z);
    glEnd();

    glutSwapBuffers();
}
void display2()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(translateX, translateY, translateZ);
    glScalef(scale, scale, scale);

    glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    // Back face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    // Top face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    // Right face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    // Left face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    glutSwapBuffers();
}


void display3()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    translateX+=0.3f;
    translateY+=0.5f;
    glTranslatef(translateX, translateY, translateZ);
    glScalef(scale, scale, scale);

    glBegin(GL_QUADS);
    // Front face
     glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    // Back face
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    // Top face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    // Right face
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    // Left face
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    glutSwapBuffers();


}


void display4()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(translateX, translateY, translateZ);
    glScalef(scale, scale, scale);

     glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(A.x, A.y, A.z);
    glVertex3f(B.x, B.y, B.z);
    glVertex3f(C.x, C.y, C.z);
    glVertex3f(D.x, D.y, D.z);
    // Back face
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(E.x, E.y, E.z);
    glVertex3f(F.x, F.y, F.z);
    glVertex3f(G.x, G.y, G.z);
    glVertex3f(H.x, H.y, H.z);
    // Top face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(F.x, F.y, F.z);
    glVertex3f(D.x, D.y, D.z);
    glVertex3f(C.x, C.y, C.z);
    glVertex3f(G.x, G.y, G.z);
    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(E.x, E.y, E.z);
    glVertex3f(H.x, H.y, H.z);
    glVertex3f(B.x, B.y, B.z);
    glVertex3f(A.x, A.y, A.z);
    // Right face
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(H.x, H.y, H.z);
    glVertex3f(G.x, G.y, G.z);
    glVertex3f(C.x, C.y, C.z);
    glVertex3f(B.x, B.y, B.z);
    // Left face
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(E.x, E.y, E.z);
    glVertex3f(A.x, A.y, A.z);
    glVertex3f(D.x, D.y, D.z);
    glVertex3f(F.x, F.y, F.z);
    glEnd();

    glutSwapBuffers();
}
void reshape(int width, int height)
{
    if (height == 0)
        height = 1;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'a')
        translateX -= 0.1f;
    if (key == 'd')
        translateX += 0.1f;
    if (key == 'w')
        translateY += 0.1f;
    if (key == 's')
        translateY -= 0.1f;
    if (key == 'q')
        translateZ += 0.1f;
    if (key == 'e')
        translateZ -= 0.1f;
    if (key == 'r')
        scale += 0.1f;
    if (key == 'f')
        scale -= 0.1f;

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Transformation");

    init();
    glutInitWindowPosition(100, 100);
    glutDisplayFunc(display);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(600, 100);
    glutCreateWindow("Yellow");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glutDisplayFunc(display2);

    glutReshapeFunc(reshape);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(1100, 100);
    glutCreateWindow("Translated");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
    glutDisplayFunc(display3);

    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();




    return 0;
}

