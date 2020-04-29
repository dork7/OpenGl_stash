#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <vector>
#include <QDebug>

using namespace std;

class Vertex{
public:
    Vertex(const glm::vec3& pos , const glm::vec2& texCoord)
    {
        this->pos = pos;
        this->texCoord = texCoord;
    }


    inline glm::vec3* GetPos(){return &pos;}
    inline glm::vec2* GetCoord(){return &texCoord;}

protected:

private:
    glm::vec3 pos;
    glm::vec2 texCoord;
};


class mesh
{
public:
    mesh(Vertex* vertices, unsigned int numVertices);

    void Draw();

    virtual ~mesh();

protected:

private:

    enum{
        POSITION_VB,
        TEXCOORD_VB,

        NUM_BUFFERS
    };

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffer[NUM_BUFFERS];
    unsigned int m_drawCount; // keeping count of how much we are going to draw


};

#endif // MESH_H
