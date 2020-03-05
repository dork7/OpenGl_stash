#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

#include <stdlib.h>

#include "shapefil.h"
#include <GL/glut.h>
#include "camera.h"

#include <vector>

#define WIDTH 800
#define HEIGHT 600
using namespace std;

/////////////////////////////////////////
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    Display display(WIDTH, HEIGHT , "openGL"); // call this first xD no matter what

////    Vertex vertices[] = {
////        Vertex(glm::vec3(-0.5 , -0.5 , 0) ),
////        Vertex(glm::vec3(0 ,0.5 , 0) ),
////        Vertex(glm::vec3(0.5 ,-0.5 , 0) )
////    };

//    Vertex vertices[] = {
//        Vertex(glm::vec3(-0.5 , -0.5 , 0) , glm::vec2(0.0,0.0)),
//        Vertex(glm::vec3(0.0 , 0.5 , 0) , glm::vec2(0.5,1.0)),
//        Vertex(glm::vec3(0.5 ,-0.5 , 0) , glm::vec2(1.0,0.0))
//    };


//    mesh mesh(vertices , sizeof(vertices)/ sizeof(vertices[0]));
////    Shader shader("/home/hamza/Pictures/qtOpenGL/res/shader");
//    Shader shader("/home/hamza/Pictures/qtOpenGL/res/basicShader");
//    Texture texture("/home/hamza/Pictures/qtOpenGL/res/bricks.jpg");
//    Camera camera(glm::vec3(0 , 0 , -1) ,  70.0f , (float)WIDTH/(float)HEIGHT , 0.01f , 1000.0f);
//    Transform transform;

//    float counter = 0.0f;

//    while (!display.isClosed()){
        

//        display.Clear(0.0f , 0.15f,  0.3f, 1.0f);

//        float sinCounter = sinf(counter);
//        float cosCounter = cosf(counter);

//        transform.GetPos().x = sinCounter;//sinf(counter);
//////        transform.GetPos().z = (counter*50);
////        transform.SetScale( glm::vec3(cosCounter , cosCounter , cosCounter));


//        shader.Bind();
//        shader.Update(transform , camera);
//        texture.Bind(0);
//        mesh.Draw();
//        display.update();
//        SDL_Delay(1);
//        counter+= 0.01f;
//    }
        MainWindow w;
        w.show();
    return a.exec();
}


