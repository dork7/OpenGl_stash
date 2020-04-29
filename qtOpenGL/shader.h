#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <GL/glew.h>

#include <iostream>
#include <fstream>
#include <QDebug>


using namespace std;
class Shader
{
public:
    Shader(const string& fileName);

    void Bind();


    ~Shader();
protected:

private:
    static const unsigned int NUM_SHADERS = 2; // types of shaders // 2 is for -> vertex and fragment shades
    string LoadShader(const std::string& fileName);
    void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

    GLuint CreateShader(const string &text, GLenum shaderType);

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];

};

#endif // SHADER_H
