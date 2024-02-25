#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

int xone, yone, xtwo, ytwo;

void drawLineBresenham() {
    glBegin(GL_POINTS);

    int dx = abs(xtwo - xone);
    int dy = abs(ytwo - yone);
    float m = abs(dy/dx);

    if(m<1.0)
    {
        int twody = 2 * dy;
        int p = twody - dx;

        int x = xone;
        int y = yone;

        for (int i = 0; i <= dx; ++i) {
            glVertex2i(x, y);
            cout<<"("<<x<<","<<y<<")"<<endl;
            cout<<"p"<<i<<" = "<<p<<endl;
            if(p<0)
            {
                x+=1;
                p = p + twody;
            }
            else
            {
                x += 1;
                y += 1;
                p = p + twody - (2*dx);
            }
        }
    }
    else
    {
        int twodx = 2 * dx;
        int p = twodx - dy;

        int x = xone;
        int y = yone;

        for (int i = 0; i <= dy; ++i) {
            glVertex2i(x, y);
            cout<<"("<<x<<","<<y<<")"<<endl;
            cout<<"p"<<i<<" = "<<p<<endl;
            if(p<0)
            {
                y+=1;
                p = p + twodx;
            }
            else
            {
                x += 1;
                y += 1;
                p = p + twodx - (2*dy);
            }
        }
    }
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    drawLineBresenham();

    glFlush();
}

void myinit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    cout << "Enter the coordinates of the first endpoint (x1, y1): ";
    cin >> xone >> yone;

    cout << "Enter the coordinates of the second endpoint (x2 y2): ";
    cin >> xtwo >> ytwo;

    cout<<endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham Line Drawing Algorithm");
    glutDisplayFunc(display);

    myinit();
    glutMainLoop();

    return 0;
}
