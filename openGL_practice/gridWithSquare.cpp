#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

/* Initialize OpenGL Graphics */
void initGL()
{
   // Set "clearing" or background color
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display()
{
   glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer with current clearing color

   // Define shapes enclosed within a pair of glBegin and glEnd
   glBegin(GL_LINES); // Each set of 4 vertices form a quad
   for (float i = -5.0; i < 5.0; i += 0.2)
   {
      glVertex2f(-1 + i, 0);
      glVertex2f(0 + i, 1);

      glVertex2f(0 + i, 1);
      glVertex2f(1 + i, 0);

      glVertex2f(1 + i, 0);
      glVertex2f(0 + i, -1);

      glVertex2f(0 + i, -1);
      glVertex2f(-1 + i, 0);
   }
   glEnd();

   glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char **argv)
{
   glutInit(&argc, argv);                         // Initialize GLUT
   glutCreateWindow("Vertex, Primitive & Color"); // Create window with the given title
   glutInitWindowSize(320, 320);                  // Set the window's initial width & height
   glutInitWindowPosition(50, 50);                // Position the window's initial top-left corner
   glutDisplayFunc(display);                      // Register callback handler for window re-paint event
   initGL();                                      // Our own OpenGL initialization
   glutMainLoop();                                // Enter the event-processing loop
   return 0;
}