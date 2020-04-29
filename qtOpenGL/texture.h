#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <QDebug>
#include  "string"

using namespace std;

class Texture
{
public:
    Texture(const string& fileName);

    void Bind(unsigned int unit);



    ~Texture();
protected:

private:
    GLuint m_texture;
};

#endif // TEXTURE_H
