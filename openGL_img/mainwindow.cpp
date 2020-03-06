#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <GL/glut.h>
#include "stb_image.h"

#include <math.h>
#include <QDebug>
#include <IL/il.h>
unsigned char* imgData2;
const double PI = 3.141593654;

void uvSphere(double radius, int slices, int stacks, int makeTexCoords) {
    int i,j;
    for (j = 0; j < stacks; j++) {
        double latitude1 = (PI/stacks) * j - PI/2;
        double latitude2 = (PI/stacks) * (j+1) - PI/2;
        double sinLat1 = sin(latitude1);
        double cosLat1 = cos(latitude1);
        double sinLat2 = sin(latitude2);
        double cosLat2 = cos(latitude2);
        glBegin(GL_QUAD_STRIP);
        for (i = 0; i <= slices; i++) {
            double longitude = (2*PI/slices) * i;
            double sinLong = sin(longitude);
            double cosLong = cos(longitude);
            double x1 = cosLong * cosLat1;
            double y1 = sinLong * cosLat1;
            double z1 = sinLat1;
            double x2 = cosLong * cosLat2;
            double y2 = sinLong * cosLat2;
            double z2 = sinLat2;
            glNormal3d(x2,y2,z2);
            if (makeTexCoords)
                glTexCoord2d(1.0/slices * i, 1.0/stacks * (j+1));
            glVertex3d(radius*x2,radius*y2,radius*z2);
            glNormal3d(x1,y1,z1);
            if (makeTexCoords)
                glTexCoord2d(1.0/slices * i, 1.0/stacks * j);
            glVertex3d(radius*x1,radius*y1,radius*z1);
        }
        glEnd();
    }
} // end uvSphere

void myinit()
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClearColor(1,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_QUADS);

    glTexCoord2d(0.0, 0.0);	glVertex2d(-1.0, -1.0);
    glTexCoord2d(0.0, 1.0);	glVertex2d(1.0, -1.0);
    glTexCoord2d(1.0, 1.0);	glVertex2d(1.0, 1.0);
    glTexCoord2d(1.0, 0.0);	glVertex2d(-1.0, 1.0);

    glEnd();


//    glutSolidSphere(1,500,500);
    uvSphere(1.0,64,64,0);

    glFlush();
}
void bindTexture2(int height, GLuint texid, int width)
{
    glGenTextures(1, &texid); /* Texture name generation */
    glBindTexture(GL_TEXTURE_2D, texid); /* Binding of texture name */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); /* We will use linear interpolation for magnification filter */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); /* We will use linear interpolation for minifying filter */
    //       glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT),
    //        0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE, ilGetData()); /* Texture specification */
    glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGBA /* STORING PIXELS ON GPU*/ , width, height , 0, GL_RGBA, GL_UNSIGNED_BYTE , imgData2);
}


void myReshape(GLsizei w, GLsizei h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

        glOrtho (-1.5, 1.5, -1.5*(GLfloat)480/(GLfloat)640,
            1.5*(GLfloat)480/(GLfloat)640, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    //glViewport(0,0,w,h);  //Use the whole window for rendering
    glLoadIdentity();
}




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    glutInit(&argc,argv);
    glutInitWindowSize (640,480);
    glutInitWindowPosition (200,200);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA |GLUT_DEPTH);
    glutCreateWindow("Sphere_LIGHT");
    glutDisplayFunc(display);
    glutReshapeFunc (myReshape);
    myinit();
    glutMainLoop();

    ///////////////////////////////////
     GLuint texid;

    /* Initialization of DevIL */
    if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
    {
        qDebug() << "wrong DevIL version ";
        //return -1;
    }
    ilInit();

    int width , height , numComponents;

    imgData2 = stbi_load( "/home/hamza/Pictures/EARTH.BMP", &width , &height , &numComponents , 4);

    if (imgData2 == NULL){
        qDebug() <<" error in image loading ";
    }



    /* OpenGL texture binding of the image loaded by DevIL  */
    bindTexture2(height, texid, width);

}

MainWindow::~MainWindow()
{
    delete ui;
}




