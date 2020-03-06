#include "mainwindow.h"
#include <QApplication>
#include <GL/glut.h>
#include "stb_image.h"

#include <math.h>
#include <QDebug>
#include <IL/il.h>
void display();
void init(); // for initializing purpose
void glReshape(int w, int h);
void timer(int);
unsigned char* imgData;
int LoadImage(char *filename);


#define DEFAULT_WIDTH  640
#define DEFAULT_HEIGHT 480

int width  = DEFAULT_WIDTH;
int height = DEFAULT_HEIGHT;


/* Initialize OpenGL Graphics */
void initGL(int w, int h)
{
    glViewport(0, 0, w, h); // use a screen size of WIDTH x HEIGHT
    glEnable(GL_TEXTURE_2D);     // Enable 2D texturing

    glMatrixMode(GL_PROJECTION);     // Make a simple 2D projection on the entire window
    glLoadIdentity();
//    glOrtho(0.0, w, h, 0.0, 0.0, 100.0);
   gluPerspective( 60 , 1, 2.0 , 50.0 );
    glMatrixMode(GL_MODELVIEW);    // Set the matrix mode to object modeling

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the window
}

void displayFunc()
{

    //   printf("Frame %d ", ++nFrames);

    // Clear color and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Operate on model-view matrix
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glTranslatef(0,0,0.0);

    /* Draw a fullscreen mapped quad */
    glBegin(GL_QUADS);
    glTexCoord2i(0, 0); glVertex2i(0, 1);
    glTexCoord2i(0, 1); glVertex2i(0, height);
    glTexCoord2i(1, 1); glVertex2i(width, height);
    glTexCoord2i(1, 0); glVertex2i(width, 0);
    glEnd();

    /////////////////////////////////////////////
//    float theta ;//get the current angle
//    float x  ;//calculate the x component
//    float y ;

//    glColor3f(1.0, 0.0, 0.0);

//    glLineWidth(1.5f);

//    glBegin(GL_LINES);
//        int count_lines=0;
//        theta = 2.0f * 3.1415926f * float(43) / float(80);
//        x = 0.85* cosf(theta);//calculate the x component
//        y = 0.85* sinf(theta);//calculate the y component
//        glVertex2f(x*1.0f , y*1.0f);//output vertex
//        glVertex2f(x*1.1f,y*1.1f);

//        theta = 2.0f * 3.1415926f * float(76) / float(80);
//        x = 0.85* cosf(theta);//calculate the x component
//        y = 0.85* sinf(theta);//calculate the y component
//        glVertex2f(x*1.0f , y*1.0f);//output vertex
//        glVertex2f(x*1.1f,y*1.1f);

//        for(int ii = 48; ii <= 72; ii++)
//        {
//            theta = 2.0f * 3.1415926f * float(ii) / float(80);//get the current angle

//            x = 0.85* cosf(theta);//calculate the x component
//            y = 0.85* sinf(theta);//calculate the y component
//            if(count_lines<2){
//            glVertex2f(x*1.0f , y*1.0f);//output vertex
//            glVertex2f(x*1.1f,y*1.1f);
//            ii++;
//            count_lines++;
//            }
//            else{
//                count_lines=0;
//                ii+=2;
//            }

//        }
//    glEnd();

//    glColor3f(0.925, 0.64, 0.01);//    glBegin(GL_QUADS);
    //    glTexCoord2i(0, 0); glVertex2i(0, 0);
    //    glTexCoord2i(0, 1); glVertex2i(0, height);
    //    glTexCoord2i(1, 1); glVertex2i(width, height);
    //    glTexCoord2i(1, 0); glVertex2i(width, 0);
    //    glEnd();
//    glBegin(GL_LINE_STRIP);

//        for(int ii = 43; ii <= 76; ii++)
//        {
//            theta = 2.0f * 3.1415926f * float(ii) / float(80);//get the current angle

//            x = 0.84 * cosf(theta);//calculate the x component
//            y = 0.84* sinf(theta);//calculate the y component

//            glVertex2f(x+0.01 , y+0.01 );//output vertex

//        }
//    glEnd();

    glutSwapBuffers();
}
void reshapeFunc(GLsizei newwidth, GLsizei newheight)
{

    printf("reshape(%d, %d) ", newwidth, newheight );

    // Set the viewport to cover the new window
    glViewport(0, 0, width=newwidth, height=newheight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, 0.0, 100.0);
    glMatrixMode(GL_MODELVIEW);

    glutPostRedisplay();
}

void bindTexture(int height, GLuint texid, int width)
{
    glGenTextures(1, &texid); /* Texture name generation */
    glBindTexture(GL_TEXTURE_2D, texid); /* Binding of texture name */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); /* We will use linear interpolation for magnification filter */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); /* We will use linear interpolation for minifying filter */
    //       glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT),
    //        0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE, ilGetData()); /* Texture specification */
    glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGBA /* STORING PIXELS ON GPU*/ , width, height , 0, GL_RGBA, GL_UNSIGNED_BYTE , imgData);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // using glut for windows
    // glut is used for makign a window


    GLuint texid;
    int    image;

    glutInit(&argc, argv);

    glutInitDisplayMode ( GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH );
    glutInitWindowPosition(200,200);
    glutInitWindowSize(500,500);
    glutCreateWindow("title");

    glutDisplayFunc(displayFunc); // display call point
    glutReshapeFunc(reshapeFunc);
    /////// to test the translation i have commented the line below this line
    //    init();
    initGL(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    ///////////////////////////////////
    /* Initialization of DevIL */
    if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
    {
        qDebug() << "wrong DevIL version ";
        return -1;
    }
    ilInit();

    int width , height , numComponents;

    imgData = stbi_load( "/home/hamza/Pictures/EARTH.BMP", &width , &height , &numComponents , 4);

    if (imgData == NULL){
        qDebug() <<" error in image loading ";
    }

    /* load the file picture with DevIL */
    image = LoadImage("/home/hamza/Pictures/EARTH.BMP");
    if ( image == -1 )
    {
        qDebug() << "Can't load picture file %s by DevIL "<< "/home/hamza/Pictures/EARTH.BMP";
        return -1;
    }

    /* OpenGL texture binding of the image loaded by DevIL  */
    bindTexture(height, texid, width);

    /////////////////////////////////
//    MainWindow w;
//    w.show();

    glutMainLoop(); // ta




    return a.exec();
}
int LoadImage(char *filename)
{
    ILuint    image;
    ILboolean success;

    ilGenImages(1, &image);    /* Generation of one image name */
    ilBindImage(image);        /* Binding of image name */


    /* Loading of the image filename by DevIL */
    if ( success = ilLoadImage(filename) )
    {
        /* Convert every colour component into unsigned byte */
        /* You can replace IL_RGB with IL_RGBA if your image contains alpha channel */

        success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

        if (!success)
        {
            return -1;
        }
    }
    else
        return -1;

    return image;
}



