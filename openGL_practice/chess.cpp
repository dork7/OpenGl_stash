#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
void timer(int);
void timer2(int);

#define drawOneLine(x1, y1, x2, y2) \
    glBegin(GL_LINES);              \
    glVertex2f((x1), (y1));         \
    glVertex2f((x2), (y2));         \
    glEnd();

/* Initialize OpenGL Graphics */
void initGL()
{
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer with current clearing color
    glColor3f(0.973, 0.773, 0.243);
}

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
float i = -2.82;
float j = -2.82;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color

    glPointSize(10);

    // for ( )
    glBegin(GL_POINTS); // Each set of 4 vertices form a quad
    for (float i = -5.0; i < 5.0; i += 0.2)
    {
        glVertex2f(0 + i, -0.8 );
    }
    glEnd();

    glFlush(); // Render now
}
// void display2()
// {
// glLineWidth(3);

//    // Define shapes enclosed within a pair of glBegin and glEnd
//    glBegin(GL_LINES); // Each set of 4 vertices form a quad
//                       //    for (float i = -5.0; i < 5.0; i += 0.2)
//    {
// // lower
//       glVertex2f(1, 0 + j);
//       glVertex2f(0, -1 + j);

//       glVertex2f(0, -1 + j);
//       glVertex2f(-1, 0 + j);
//    }
//    glEnd();

//    glFlush(); // Render now
// }

void timer(int)
{
    i += 0.1538;

    display();
    glutTimerFunc(10, timer, 0);
    // glutPostRedisplay(); // it will called display fucntion itself
    // glutTimerFunc(1000 / 60, timer, 0);

    // cout << "-";
    // counter += 0.05;
}
// void timer2(int)
// {
//    j += 0.1538;

//    // glutPostRedisplay();
//    display2();
//    glutTimerFunc(10, timer2, 0);
//    // glutPostRedisplay(); // it will called display fucntion itself
//    // glutTimerFunc(1000 / 60, timer, 0);   glutPostRedisplay();

//    // cout << "-";
//    // counter += 0.05;
// }

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char **argv)
{
    glutInit(&argc, argv); // Initialize GLUT
                           //  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("window tittle"); // Set the window's initial width & height
                                       //  glutInitWindowPosition(100, 100);               // Position the window's initial top-left corner
    // glutDisplayFunc(display);
    glutTimerFunc(220, timer, 0); // 0 is the interger to pass it to the function // this will call the timer function periodically
                                  //    glutTimerFunc(1, timer2, 0);  // 0 is the interger to pass it to the function // this will call the timer function periodically
                                  // Register callback handler for window re-paint event
    initGL();                     // Our own OpenGL initialization
    glutMainLoop();               // Enter the event-processing loop
    return 0;
}