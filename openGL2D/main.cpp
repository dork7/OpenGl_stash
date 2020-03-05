#include "mainwindow.h"
#include <QApplication>
#include <GL/glut.h>
#include "stb_image.h"
#include <QDebug>

void display();
void init(); // for initializing purpose
void glReshape(int w, int h);
void timer(int);
unsigned char* imgData;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // using glut for windows
    // glut is used for makign a window

    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowPosition(200,200);
    glutInitWindowSize(500,500);
    glutCreateWindow("title");

    glutDisplayFunc(display); // display call point
    glutReshapeFunc(glReshape);
    /////// to test the translation i have commented the line below this line
    glutTimerFunc(1000,timer,0); // 0 is the interger to pass it to the function // this will call the timer function periodically
    init();
    glutMainLoop(); // ta
    int width , height , numComponents;

    imgData = stbi_load( "/home/hamza/QT_projects/openGL_2D/bricks.jpg", &width , &height , &numComponents , 4);

    if (imgData == NULL){
        qDebug() <<" error in image loading ";
    }



    //    MainWindow w;
    //    w.show();

    return a.exec();
}

float x_position = 0;//-10.0; // to test the translation i have used 0 as x_position
int state = 1; // 1 for right

float angle =  0.0;
void display2(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glMatrixMode((GL_PROJECTION));
    glLoadIdentity(); // reset the coordiates of screen

    glOrtho(-20,20,-20,20,-1,1);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_EQUAL,1.0);

    glPixelZoom(1,1);
    glRasterPos2i(-20,20);

    glutSwapBuffers();
    glFlush();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity(); // reset the coordiates of screen

    glPointSize(10.0);

    //    glTranslatef(0,0,0);

    //    // drawing here xD
    //    //    points
    //    glBegin(GL_POINTS);
    //    // vertices
    //    glVertex3f(5,5,-5);
    //    glVertex3f(5,-5,-5);
    //    glVertex3f(-5,5,-5);
    //    glVertex3f(-5,-5,-5);


    //    glEnd();
    // triangles



    //    // quad
    //    glColor3f(1.0,1.0, 0.0);
    //    glBegin(GL_POLYGON);
    //    // vertices

    //    glVertex2f(-5,5);
    //    glVertex2f(-5,-5);
    //    glVertex2f(5,-5);
    //    glVertex2f(5,5);


    //    //    glVertex2f(5,5);
    //    //    glVertex2f(5,-5);
    //    //    glVertex2f(-5,5);
    //    //    glVertex2f(0,0);

    //    glEnd();

    //    glColor3f(1.0,0.0, 0.0);
    //    glBegin(GL_TRIANGLES);
    //    // vertices
    //    glVertex2f(0.0,1.0);
    //    glVertex2f(0.0 ,3.5);
    //    glVertex2f(1.0,4.0);


    //    glEnd();
    ////////////
    //    glFlush(); // flush shows // used for single buffer

    // animation stuff


    //    glTranslatef(x_position,x_position,0.0);

    //    glShadeModel((GL_FLAT)); // to remove the gradient thingy

    //    glBegin(GL_POLYGON);
    //    // vertices
    //    glColor3f(1.0,1.0,1.0);
    //    glVertex2f(-1.0,1.0);
    //    glVertex2f(-1.0,-1.0);
    //    glVertex2f(1.0,-1.0);
    //    glVertex2f(1.0,1.0);

    //    glEnd();


    //    glBegin(GL_POINTS);
    //    // vertices
    //    glColor3f(1.0,0.0, 0.0);
    //    glVertex2f(-1.0,1.0);
    //    glVertex2f(-1.0,-1.0);
    //    glVertex2f(1.0,-1.0);
    //    glVertex2f(1.0,1.0);

    //    glEnd();

    // 3D work here
    // working with 2D objects inside 3D space

    //    glTranslatef(0,0,x_position);

    // drawing here xD
    //    points
    //    glBegin(GL_POINTS);
    //    // vertices
    //    glVertex3f(5,5,0);
    //    glVertex3f(5,-5,0);
    //    glVertex3f(-5,5,0);
    //    glVertex3f(-5,-5,0);

    //    glVertex3f(5,5,-5);
    //    glVertex3f(5,-5,-5);
    //    glVertex3f(-5,5,-5);
    //    glVertex3f(-5,-5,-5);


    //    glEnd();


    //    glBegin(GL_POLYGON);
    //    // vertices
    //    glColor3f(1.0,1.0,1.0);
    //    glVertex3f(-1.0,1.0,5.0 );
    //    glVertex3f(-1.0,-1.0,5.0 );
    //    glVertex3f(1.0,-1.0,5.0 );
    //    glVertex3f(1.0,1.0,5.0 );

    //    glEnd();

    // NOW WORKING WITH 3D OBJECTS INSIDE 3D SPACE
    //    Cube vertex data:
    glEnd();

    glTranslatef(0,0,-8.0);

    glRotatef(angle , 1.0 , 0.0 ,0.0);
    glRotatef(angle , 0.0 , 1.0 ,0.0);
    //    glRotatef(angle , 0.0 , 0.0 ,1.0);


    glBegin(GL_QUADS);
    //front // anti clock wise
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    //back // clock wise
    glColor3f(0.0,1.0,0.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);
    //right
    glColor3f(0.0,0.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    //left
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);
    //top
    glColor3f(0.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,1.0,-1.0);
    //bottom
    glColor3f(1.0,0.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glEnd();

    glutSwapBuffers();
    //    glFlush();



}



void init(){
    glClearColor(0.2,0.2,0.2,1.0); // to specify the bg color of the window
    glEnable(GL_DEPTH_TEST);

    //    glDepthFunc(GL_LEQUAL);

    //    glEnable(GL_LIGHTING);
    //    float pos[] = {10,10,50};
    //    glLightfv(GL_LIGHT0 , GL_POSITION , pos);

    //    glEnable(GL_LIGHT0);

}

void glReshape(int w,int h) // resized or change in shape
{
    // viewport
    // rectangular are where shapes are beign drawn
    //  x,y is the bottom left
    // widht / height
    glViewport( 0 , 0 , (GLsizei)w , (GLsizei)h ); // 0, 0 will be according to the size of window

    // projection
    // based on matrix
    // default is model view matrix but to change the projection attribute we need to switch into projection matrix
    //
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); // reset the current matrix
    //    gluOrtho2D(-10,10,-10,10); // for 2D projection
    gluPerspective( 60 , 1, 2.0 , 50.0 );
    glMatrixMode(GL_MODELVIEW);

}
void timer(int){
    glutPostRedisplay(); // it will called display fucntion itself
    glutTimerFunc(1000/60, timer , 0);

    //    switch (state) {
    //    case 1:
    //        if (x_position < -5){
    //            x_position+=0.15;
    //        }
    //        else {
    //            state = -1;
    //        }
    //        break;

    //    case -1:
    //        if (x_position > -25){
    //            x_position-=0.15;
    //        }
    //        else {
    //            state = 1;
    //        }
    //        break;

    //    }
    angle += 0.8*4;
    if ( angle > 360.0)
        angle = angle - 360.0;

}
