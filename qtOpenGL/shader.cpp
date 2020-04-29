#include "shader.h"

//static GLuint CreateShader(const string& text, GLenum shaderType);

Shader::Shader(const string& fileName)
{

   m_program = glCreateProgram();

//   qDebug()<< QString(fileName.c_str);
   qDebug()<< "File name" << QString(fileName.c_str());


    m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER );
    m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER ); // vs and fs is just for vertex shader and fileshader.

    for (unsigned int i = 0; i < NUM_SHADERS ; i++) {
        glAttachShader(m_program , m_shaders[i]);
    }

    glBindAttribLocation(m_program , 0 , "position");
    glBindAttribLocation(m_program , 1 , "texCoord");



    glLinkProgram(m_program);
    CheckShaderError(m_program , GL_LINK_STATUS , true , "error : m_program failed to link ");

    glValidateProgram(m_program);
    CheckShaderError(m_program , GL_VALIDATE_STATUS , true , "error : m_program is invalid");

}

Shader::~Shader()
{
    for (unsigned int i = 0; i < NUM_SHADERS ; i++) {
        glDetachShader(m_program , m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }
    glDeleteProgram(m_program);
}
void Shader::Bind(){
    glUseProgram(m_program);
}

GLuint Shader::CreateShader(const string& text, GLenum shaderType){
    GLuint  shader = glCreateShader(shaderType);
    if (shader == 0){
        qDebug() <<"  shader creation failed";
    }
    const GLchar* shaderSrcString[1];
    GLint shaderSrcStringLen[1];
    shaderSrcString[0] = text.c_str();
    shaderSrcStringLen[0] = text.length();

    glShaderSource(shader , 1  , shaderSrcString , shaderSrcStringLen );
    glCompileShader(shader);


    CheckShaderError( shader , GL_COMPILE_STATUS , false , "error : shader compilation ");


    return shader;
}

string Shader::LoadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;
    qDebug() <<" loading shader ";

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
            output.append(line + "\n");
//            output.append(line).append("\n");
        }
        file.close();

    }
    else
    {
        qDebug()<< "Unable to load shader: " << QString(fileName.c_str());
    }

    return output;
}

void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        qDebug()<< QString(errorMessage.c_str())   ;//<< ": '" << QString(error);
    }
}
