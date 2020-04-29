#include "texture.h"
#include <cassert>
#include "stb_image.h"


Texture::Texture(const string &fileName)
{
    int width , height , numComponents;

   unsigned char* imgData = stbi_load(fileName.c_str() , &width , &height , &numComponents , 4);

    if (imgData == NULL){
        qDebug() <<" error in image loading ";
    }

    glGenTextures(1, &m_texture ) ; // generate space for 1 texture
    glBindTexture( GL_TEXTURE_2D , m_texture );

    //settign some properties of texture
    glTexParameteri(GL_TEXTURE_2D ,  GL_TEXTURE_WRAP_S , GL_REPEAT );
    glTexParameteri(GL_TEXTURE_2D ,  GL_TEXTURE_WRAP_T , GL_REPEAT );

    glTexParameterf(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_LINEAR);

    // sending texture to GPU
    glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGBA /* STORING PIXELS ON GPU*/ , width, height , 0, GL_RGBA, GL_UNSIGNED_BYTE , imgData);

    stbi_image_free(imgData);
}

Texture::~Texture()
{
    glDeleteTextures(1,&m_texture);
}
void Texture::Bind(unsigned int unit){

    assert(unit >= 0 && unit <= 31);
    glActiveTexture(GL_TEXTURE + unit); // for multiple textures
    glBindTexture(GL_TEXTURE_2D , m_texture);
}
