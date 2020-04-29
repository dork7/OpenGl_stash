#ifndef DISPLAY_H
#define DISPLAY_H

#include "QDebug"
#include <SDL2/SDL.h>
#include <GL/glew.h>


class Display
{
public:
    Display(int width , int height, const std::string& title);

    ~Display();
    void update();
    bool isClosed();
    void Clear(float r, float g, float b, float a);
protected:

private:
    SDL_Window * m_window;
    SDL_GLContext m_glContext;
    bool m_isClosed;

};

#endif // DISPLAY_H
