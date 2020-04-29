#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define DEGREES_TO_RADIANS 3.14159 / 180.0

static GLfloat spin = 0.0;
GLfloat x, y;

void square()
{
    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(-y, x);
    glVertex2f(-x, -y);
    glVertex2f(y, -x);
    glEnd();

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(x + 4, y + 4);
    glVertex2f(-y - 4, x + 4);
    glVertex2f(-x - 4, -y - 4);
    glVertex2f(y + 4, -x - 4);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    square();
    glutSwapBuffers();
}

void spinDisplay() // ORIGINAL FUNCTION
{
    spin = spin + 2.5;
    if (spin > 360.0)
        spin = spin - 360.0;
    x = 25.0 * cos(DEGREES_TO_RADIANS * spin);
    y = 25.0 * sin(DEGREES_TO_RADIANS * spin);
    glutPostRedisplay();
}

void timer_func(int n) // NEW FUNCTION
{
    // Update the object positions, etc.
    // glutPostRedisplay();
    //glutTimerFunc(n, timer_func, n);
    // glutTimerFunc(5, timer_func, 5);
}

void myinit()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glShadeModel(GL_FLAT);
    glPointSize(12);
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-50.0, 50.0, -50.0 * (GLfloat)h / (GLfloat)w,
                50.0 * (GLfloat)h / (GLfloat)w, -1.0, 1.0);
    else
        glOrtho(-50.0 * (GLfloat)w / (GLfloat)h,
                50.0 * (GLfloat)w / (GLfloat)h, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

/*  main loop
 *  open window with initial window size, title bar,
 *  RGBA display mode, and handle input events
 */
int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("double buffered");
    myinit();
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutIdleFunc(spinDisplay);

    glutMainLoop();
}