
#include <GL/glut.h>
#include <iostream>
int c = 1;
void init()
{
    // For displaying the window color
    // Choosing the type of projection
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_ALPHA_TEST);
    glMatrixMode(GL_PROJECTION);
    // for setting the transformation which here is 2D
    gluOrtho2D(0, 423, 0, 423);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}
int state = 0;
void drawLine(GLint x1, GLint y1, GLint x2, GLint y2)
{

    if (c == 0)
    {
        // glColor3f(1, 1, 1); // white color value is 1 1 1
        glColor3f(0.973, 0.773, 0.243);

        c = 1;
    }
    // if color is 1 then draw black box and change value of color = 0
    else
    {
        glColor3f(0, 0, 0); // black color value is 0 0 0
        c = 0;
    }

    // Draw Square
    glBegin(GL_LINES);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);

    glEnd();
}
GLfloat x1 = 0;
GLfloat y1 = 0;
GLfloat x2 = 423;
GLfloat y2 = 0;

void lines()
{
    glLineWidth(2);
    for (int i = 0; i < 40; i += 2)
    {
        drawLine(x1, y1 + i, x2, y2 + i);

        // y1 += 2;
        // y2 += 2;
    }
    glutSwapBuffers();
}

// void timer(int)
// {
//     x += 25;
//     glutPostRedisplay();
//     glutTimerFunc(25, timer, 0);
// }
bool subCheck = false;
bool invert = false;
int halt = 0;
void timer2(int)
{

    glutPostRedisplay();

    if (y1 <= 450)
    {
        glutTimerFunc(1, timer2, 0);
        y1 += 40;
        y2 += 40;
    }
}

int main(int agrc, char **argv)
{
    // Initialize GLUT
    glutInit(&agrc, argv);
    // Set display mode
    // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );

    // Set top - left display window position.
   // glutInitWindowPosition(960, 540);

    // Set display window width and height
     glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-423)/2, (glutGet(GLUT_SCREEN_HEIGHT)-423)/2);

    glutInitWindowSize(423, 423);
    // Create display window with the given title
    glutCreateWindow("");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(lines);

    // glutTimerFunc(1, timer, 0);    // 0 is the interger to pass it to the function // this will call the timer function periodically
    glutTimerFunc(1, timer2, 0); // 0 is the interger to pass it to the function // this will call the timer function periodically

    // Display everything and wait.
    glutMainLoop();
}
