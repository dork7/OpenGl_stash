#include <stdio.h>
#include <iostream>
#include <GL/glut.h>

void timer(int);

using namespace std;

void init()
{
    // For displaying the window color
    glClearColor(0.2, 0.2, 0.2, 0);
    // Choosing the type of projection
    glMatrixMode(GL_PROJECTION);
    // for setting the transformation which here is 2D
    // gluOrtho2D(0, 800, 0, 600);
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}
GLint counter = 0;
void render(void)
{
    // glClear(GL_COLOR_BUFFER_BIT );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // reset the coordiates of screen

    glPointSize(10.0);
    glColor3f(1, 1, 1); // white color value is 1 1 1

    glBegin(GL_POINTS);
    // vertices
    glVertex2f(0.5, 0.5 + counter);
    glVertex2f(0.5, -0.5 + counter);
    glVertex2f(-0.5, 0.5 + counter);
    glVertex2f(-0.5, -0.5 + counter);

    glEnd();

    // glBegin(GL_TRIANGLES);
    // glVertex2f(-0.5, -0.5 + counter);
    // glVertex2f(-0.5, 0.5);
    // glVertex2f(0.5, 0.5 - counter);
    // glEnd();

    glBegin(GL_POLYGON);
    // vertices

    glVertex2f(-0.5, 0.5 + counter);
    glVertex2f(-0.5, -0.5 + counter);
    glVertex2f(0.5, -0.5 + counter);
    glVertex2f(0.5, 0.5 + counter);

    //    glVertex2f(5,5);
    //    glVertex2f(5,-5);
    //    glVertex2f(-5,5);
    //    glVertex2f(0,0);

    glEnd();

    glutSwapBuffers();
    // glFlush();
}
void timer(int)
{
    glutPostRedisplay(); // it will called display fucntion itself
    glutTimerFunc(1000 / 60, timer, 0);

    cout << "-";
    counter += 0.15;
}
void glReshape(int w, int h) // resized or change in shape
{
    // viewport
    // rectangular are where shapes are beign drawn
    //  x,y is the bottom left
    // widht / height
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // 0, 0 will be according to the size of window

    // projection
    // based on matrix
    // default is model view matrix but to change the projection attribute we need to switch into projection matrix
    //
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();         // reset the current matrix
    gluOrtho2D(-1, 1, -1, 1); // for 2D projection
    // gluPerspective( 60 , 1, 2.0 , 50.0 );
    glMatrixMode(GL_MODELVIEW);
}
int main(int agrc, char **argv)
{
    // Initialize GLUT
    glutInit(&agrc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("window tittle");
    glutDisplayFunc(render);
    glutReshapeFunc(glReshape);
    glutTimerFunc(1000, timer, 0); // 0 is the interger to pass it to the function // this will call the timer function periodically

    init();

    glutMainLoop();
    return 0;
}