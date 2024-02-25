#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void setup(){
   glClearColor(0.75f, 0.5f, 0.0f, 0.0f);
}

void display(){

   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(255.0f, 255.0f, 0.0f);
   glRectf(-0.75f, 0.75f, 0.75f, -0.75f);
   glColor3f(0.1f, 0.2f, 0.4f);
   glRectf(-0.50f, 0.50f, 0.50f, -0.50f);
   glFlush();
   glutSwapBuffers();
}

int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500, 255);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Hello World");
    setup();
    glutDisplayFunc(display);
    glutMainLoop();


    return 0;
}
