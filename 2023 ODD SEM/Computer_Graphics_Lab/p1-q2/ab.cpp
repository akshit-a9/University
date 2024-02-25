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
}#include<GL/glut.h>

void display() {
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 0.0, 0.0);

glBegin(GL_LINE_LOOP);
    glVertex2i(180,10);
    glVertex2i(10,145);
    glVertex2i(210,210);
    glVertex2i(300,415);
    glVertex2i(325,450);
glEnd();

glutSwapBuffers();
}

void myinit() {
glClearColor(1.0, 1.0, 1.0, 1.0);
glColor3f(1.0, 0.0, 0.0);
glPointSize(10.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(0, 0);
glutCreateWindow("Line Loop");
glutDisplayFunc(display);

myinit();
glutMainLoop();
}
