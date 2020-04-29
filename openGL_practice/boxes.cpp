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

GLfloat gfPosX = 0.0;
GLfloat gfPosY = -1.0;
void render(void)
{
    // glClear(GL_COLOR_BUFFER_BIT );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); // reset the coordiates of screen
    glLineWidth(4.0);
    ///////////////////////////
    glPointSize(12.0);
    ///////////////////////////
    glColor3f(1, 0, 0);

    glBegin(GL_POINTS);
    // vertices
    for (float t = -1.0; t <= 1.1; t += 0.05)
    {
        for (float i = -1.0; i <= 1.1; i += 0.05)
            glVertex2f(i, t);
    }
    glEnd();
    // for (float i = -4.0; i < 4.0; i += 0.02)
    // for (float i = -4.0; i < 4.0; i += 0.2)
    // {
    //     glEnd();
    //     ///////////////////////////
    //     glBegin(GL_LINE_STRIP);

    //     // glVertex2f(0, -1);
    //     glVertex2f(gfBasePosX - i, gfBasePosY);
    //     glVertex2f(-gfPosX - i, gfPosY);
    //     // counter+= 0.2;

    //     glEnd();

    //     glBegin(GL_LINE_STRIP);

    //     // glVertex2f(0, -1);
    //     glVertex2f(gfBasePosX - i, gfBasePosY);
    //     glVertex2f(gfPosX - i, gfPosY);
    //     // counter+= 0.2;

    //     glEnd();
    // }
    // grid

    // const float sizeL = 1.f;
    // const float grid = 0.1f;

    // glPointSize(sizeL);
    // glBegin(GL_LINES);
    // for (float i = -10; i < 10; i += grid)
    // {
    //     glVertex3f(-1.f, i, 0.f);
    //     glVertex3f(1.f, i, 0.f);

    //     glVertex3f(i, -1.f, 0.f);
    //     glVertex3f(i, 1.f, 0.f);
    // }
    // glEnd();

    /////////////////////

    //////////////////////

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
            state = -1;
            // gfPosX = 0.0;
            // gfPosY = -1.0;

            // gfBasePosX = -0.2;
            // // gfBasePosY =
        }
        break;

    case -1:
        if (gfPosX >= 0.0 && gfPosY >= -1.0)
        {
            gfPosX -= 0.01;
            gfPosY -= 0.02;
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