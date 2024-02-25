#include <GL/glut.h>
#include <cmath>
// Circle parameters
int radius = 50;
int translateX = 50;
int translateY = 20;
float scaleX = 2.0;
float scaleY = 1.5;
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400, 0.0, 400);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);

    for (int i = 0; i < 360; i++)
        {
        float angle = i * 3.1415926 / 180.0;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x + 100, y + 100);
        }
    glEnd();
    glutSwapBuffers();
}
void drawCircle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
        {
        float angle = i * 3.1415926 / 180.0;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f((x + 100 + translateX)* scaleX, (y+100+translateY) *scaleY);
        }
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Original");
    init();
    glutDisplayFunc(display);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Translate and scale");
    init();
    glutDisplayFunc(drawCircle);
    glutMainLoop();
    glutMainLoop();

    return 0;
}
