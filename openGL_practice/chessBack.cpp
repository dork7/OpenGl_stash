
#include <GL/glut.h>
#include <iostream>
int c = 1;
void init()
{
    // For displaying the window color
     // Choosing the type of projection
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
      glEnable(GL_ALPHA_TEST);        
    glMatrixMode(GL_PROJECTION);
    // for setting the transformation which here is 2D
    gluOrtho2D(0, 423, 0, 423);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}
int state = 0;
void drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4)
{
    // if color is 0 then draw white box and change value of color = 1
    switch (state)
    {
    case 0:
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
        break;

    case 1:
        if (c == 0)
        {
            // glColor3f(1, 1, 1); // white color value is 1 1 1
            glColor3f(0, 0, 0); // black color value is 0 0 0
            c = 1;
        }
        // if color is 1 then draw black box and change value of color = 0
        else
        {
            glColor3f(0.973, 0.773, 0.243);

            c = 0;
        }
        break;
    }

    // Draw Square
    glBegin(GL_POLYGON);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x4, y4);
    glEnd();
}
double x = 0;
double y = 0;
void chessboard()
{
    // glClear(GL_COLOR_BUFFER_BIT); // Clear display window

    // for (x = 0; x <= 400; x += 25)
    // {
    for (x = 0; x < 423; x += 16.92)
    {
        drawSquare(x, y + 16.92, x + 16.92, y + 16.92, x + 16.92, y, x, y);
    }
    // }
    // Process all OpenGL routine s as quickly as possible
    // glFlush();
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

    


    // if (y < 423)// && !subCheck) 
    // {
    //    y += 16.92;
    //    state = 0;
    //    c = 1;
    // }
    // else   {
    //     subCheck = true;
    //     y = 32;
    //     state = 1 ;
    // }
 

// y += 25;
//   state = 0;
    if (y <= 423  && !invert) 
    {
       y += 16.92;
       state = 0;
    }
    else if (invert) {
        subCheck = true;
        y += 16.92;
        state = 1 ;
    }
    if ( y > 423){
        invert = true;
        y = -16.92;
    }
    halt++;
    if ( halt < 50 )
    {
        glutTimerFunc(25, timer2, 0);
    }

}

int main(int agrc, char **argv)
{
    // Initialize GLUT
    glutInit(&agrc, argv);
    // Set display mode
    // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Set top - left display window position.
    //glutInitWindowPosition(100, 100);

   // glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2, (glutGet(GLUT_SCREEN_HEIGHT)-480)/2);
    // Set display window width and height
                      
    glutInitWindowSize(423, 423);
    // Create display window with the given title
    glutCreateWindow("Chess Board using OpenGL in C++");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(chessboard);

    // glutTimerFunc(1, timer, 0);    // 0 is the interger to pass it to the function // this will call the timer function periodically
    glutTimerFunc(2, timer2, 0); // 0 is the interger to pass it to the function // this will call the timer function periodically

    // Display everything and wait.
    glutMainLoop();
}
