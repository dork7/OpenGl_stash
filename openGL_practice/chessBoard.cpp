#include <string>
#include <stdlib.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
using namespace std;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display()
{
    int x, y, color = 0;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    for (x = 1; x <= 8; x++)
    {
        if (color == 0)
        {
            glColor3f(1.0, 0.0, 0.0);
            color++;
        }
        else
        {
            glColor3f(1.0, 1.0, 1.0);
            color = 0;
        }
        for (y = 1; y <= 8; y++)
        {
            if (color == 0)
            {
                glColor3f(1.0, 0.0, 0.0);
                color++;
            }
            else
            {
                glColor3f(1.0, 1.0, 1.0);
                color = 0;
            }
            glBegin(GL_QUADS);
            glVertex2f(37.5 + 37.5 * x, 37.5 + 37.5 * y);
            glVertex2f(37.5 * x, 37.5 + 37.5 * y);
            glVertex2f(37.5 * x, 37.5 * y);
            glVertex2f(37.5 + 37.5 * x, 37.5 * y);

            glEnd();
        }
    }
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(375, 375);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
