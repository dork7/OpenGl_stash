#include "mainwindow.h"
#include <QApplication>
#define GLEW_STATIC
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include <SOIL/SOIL.h>


//#include "display.h"
//#include <GL/glut.h>

//#include <SDL2/SDL.h>
//#include <SDL2/SDL_opengl.h>
#include <string>
#include <fstream>
#include <QDebug>
using namespace std;


void frambufferResize(GLFWwindow * window , int w, int h){
    glViewport(0 ,0 , w , h);

}

void display(){

}

void init(){

}
bool loadShader(GLint &program){

    bool loadSuccess = true;

    char infoLog[512];
    GLint success;

    string temp = "";
    string src = "";

    ifstream in_file;

    //
    in_file.open("/home/hamza/QT_projects/openGL_3DTexture/vertex_core.glsl");

    if( in_file.is_open()){
        while(getline(in_file,temp)){
            src += temp + "\n";
        }
    }else{
        qDebug()  << " error loading shader";
        loadSuccess =  false;

    }
    in_file.close();


    //making shader
    GLuint vertexShader = glCreateShader(GL_ARB_vertex_shader);

    const GLchar* vertSrc = src.c_str();
    glShaderSource(vertexShader , 1 , &vertSrc , NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader ,  GL_COMPILE_STATUS , &success);
    if (!success){
        glGetShaderInfoLog(vertexShader , 512 , NULL , infoLog);
        qDebug() << " error in compilation vertex sharder";
        qDebug() << infoLog;
        loadSuccess =  false;
    }


    temp = "";
    src = "";

    // for fragment shader

    //
    in_file.open("/home/hamza/QT_projects/openGL_3DTexture/fragment_core.glsl");

    if( in_file.is_open()){
        while(getline(in_file,temp)){
            src += temp + "\n";
        }
    }else{
        qDebug()  << " error loading fragment";
        loadSuccess =  false;
    }
    in_file.close();


    //making shader
    GLuint fragmentShader = glCreateShader(GL_ARB_vertex_shader);

    const GLchar* fragmentSrc = src.c_str();
    glShaderSource(fragmentShader , 1 , &fragmentSrc , NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader ,  GL_COMPILE_STATUS , &success);
    if (!success){
        glGetShaderInfoLog(fragmentShader , 512 , NULL , infoLog);
        qDebug() << " error in compilation fragment shader";
        qDebug() << infoLog;
        loadSuccess =  false;
    }


    temp = "";
    src = "";
    // create program
    program = glCreateProgram();

    // attaching shader
    glAttachShader( program , vertexShader );
    glAttachShader( program , fragmentShader );

    glLinkProgram(program);

    // error checking
    glGetProgramiv(program , GL_LINK_STATUS, &success);
    if (!success){
        glGetShaderInfoLog(program , 512 , NULL , infoLog);
        qDebug() << "err in linking";
        qDebug() << infoLog;
        loadSuccess =  false;

    }

    //end
    glUseProgram(0);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return loadSuccess;

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // init GLFW
    glfwInit();
    // CREATE WINDOW
    const int width = 640;
    const int height = 480;
    int frameBufferWidth = 0;
    int frameBufferHeight = 0;

    glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);


    GLFWwindow * window = glfwCreateWindow(width , height , "window" , NULL , NULL);

    glfwSetFramebufferSizeCallback( window , frambufferResize); // this is for resizing
//    glfwGetFramebufferSize(window , &frameBufferWidth , &frameBufferHeight);
//    glViewport( 0 ,0 , frameBufferWidth , frameBufferHeight );

    glfwMakeContextCurrent(window);
    // ini GLEW
    glewExperimental = GL_TRUE;
    if(glewInit()!= GLEW_OK){
        qDebug() <<" eroro glew init ";
        glfwTerminate();
    }

    // shader init
    GLint core_program;
    if(!loadShader(core_program)){
        qDebug() << "MAIN : loading shaders err";
        glfwTerminate();
    }

    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        //        clear

        glClearColor(0.0f ,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
        // draw


        //

        glfwSwapBuffers(window);
        glFlush();
    }

    //

    glfwDestroyWindow(window);
    glfwTerminate();


    glDeleteProgram(core_program);

    return a.exec();
}


