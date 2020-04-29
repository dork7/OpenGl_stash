#include "display.h"


Display::Display(int width , int height, const std::string& title)
{
    qDebug() << "window ";
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        qDebug() << "SDL could not initialize! SDL Error: %s\n", SDL_GetError();
        //		success = false;
    }
    m_isClosed = false;
    SDL_Init(SDL_INIT_EVERYTHING);
    // setting bits for color

    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
//    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
//    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
//    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE , 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE , 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE , 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE , 8);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER , 1);



    m_window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED , width , height , SDL_WINDOW_OPENGL );
    if ( m_window == NULL )
    {
         qDebug() << "Window could not be created! SDL Error:", SDL_GetError() ;

    }
    m_glContext = SDL_GL_CreateContext(m_window);
    glewExperimental = GL_TRUE;

    GLenum status = glewInit();

    if ( status != GLEW_OK)
    {
        qDebug() << "Glew Error";
    }
}
Display::~Display(){
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

bool Display::isClosed(){
    return m_isClosed;
}
void Display::Clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::update(){
    SDL_GL_SwapWindow(m_window);

    SDL_Event e;

    while (SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            m_isClosed = true;
        }
    }
}
