#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <vector>

void timer(int);

using namespace std;
static double s_line_length = 0.5;

typedef struct MyPoint2D
{
    double dX;
    double dY;

} MyPoint2D;

//Holds Coordinates of Point Shapefile
vector<MyPoint2D> vPoints;

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

    ///
}
float counter = -1;

GLfloat gfBasePosX = 0.0;
GLfloat gfBasePosY = -1.0;

GLfloat topToBottomX = 0.0;
GLfloat topToBottomY = 1.0;

GLfloat gfPosX2 = 0.0;
GLfloat gfPosY2 = 1.0;

GLfloat gfPosX = 0.0;
GLfloat gfPosY = -1.0;
void render(void)
{
    // glClear(GL_COLOR_BUFFER_BIT );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // reset the coordiates of screen
    glLineWidth(4.0);
    ///////////////////////////

    

    // bottom to top lines
    glBegin(GL_LINES);

    glVertex2f(gfBasePosX - 0.1, gfBasePosY);
    glVertex2f(gfPosX - 0.1, gfPosY);
    // counter+= 0.2;

    glEnd();

    glBegin(GL_LINES);

    glVertex2f(gfBasePosX + 0.1, gfBasePosY);
    glVertex2f(-gfPosX + 0.1, gfPosY);
    // counter+= 0.2;

    glEnd();

    // top to bottom

    glBegin(GL_LINES);

    glVertex2f(topToBottomX, topToBottomY);
    glVertex2f(gfPosX2, gfPosY2);
    // counter+= 0.2;

    glEnd();

    glBegin(GL_LINES);

    glVertex2f(topToBottomX, topToBottomY);
    glVertex2f(-gfPosX2, gfPosY2);
    // counter+= 0.2;

    glEnd();

    // left to right

    glBegin(GL_LINES);

    glVertex2f(topToBottomX, topToBottomY);
    glVertex2f(gfPosX2, gfPosY2);
    // counter+= 0.2;

    glEnd();

    glBegin(GL_LINES);

    glVertex2f(topToBottomX, topToBottomY);
    glVertex2f(-gfPosX2, gfPosY2);
    // counter+= 0.2;

    glEnd();


    glutSwapBuffers();
    glFlush();
}
int state = 1;
void timer(int)
{

    switch (state)
    {
    case 1:
        if (gfPosX <= 1.0 && gfPosY <= 1.0)
        {
            gfPosX += 0.01;
            gfPosY += 0.02;
        }
        else
        {
            state = 2;
            // gfPosX = 0.0;
            // gfPosY = -1.0;

            // gfBasePosX = -0.2;
            // // gfBasePosY =
        }
        break;

    case 2:
        if (gfPosX >= 0.0 && gfPosY >= -1.0)
        {
            gfPosX2 -= 0.01;
            gfPosY2 -= 0.02;
        }
        else
        {
            state = 1;
        }
        break;
    }

    glutPostRedisplay();
    glutTimerFunc(1, timer, 0);
    // glutPostRedisplay(); // it will called display fucntion itself
    // glutTimerFunc(1000 / 60, timer, 0);

    // cout << "-";
    // counter += 0.05;
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