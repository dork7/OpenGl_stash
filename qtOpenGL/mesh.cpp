#include "mesh.h"

mesh::mesh(Vertex *vertices, unsigned int numVertices)
{
    m_drawCount = numVertices;

    glGenVertexArrays(1 , &m_vertexArrayObject);
    glBindVertexArray( m_vertexArrayObject );

    vector<glm::vec3> position;
    vector<glm::vec2> texCoords;

    position.reserve(numVertices);
    texCoords.reserve(numVertices);

    for (unsigned int i =0;i < numVertices; i++ ){
          position.push_back(*vertices[i].GetPos());
          texCoords.push_back(*vertices[i].GetCoord());

      }

    glGenBuffers(NUM_BUFFERS , m_vertexArrayBuffer );
    glBindBuffer(GL_ARRAY_BUFFER , m_vertexArrayBuffer[POSITION_VB]);
    glBufferData(GL_ARRAY_BUFFER , numVertices * sizeof(&position[0]) , &position[0] , GL_STATIC_DRAW );

    // data interpretation
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 0 , 0);

    glBindBuffer(GL_ARRAY_BUFFER , m_vertexArrayBuffer[TEXCOORD_VB]);
    glBufferData(GL_ARRAY_BUFFER , numVertices * sizeof(&texCoords[0]) , &texCoords[0] , GL_STATIC_DRAW );

    // data interpretation
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1 , 2 , GL_FLOAT , GL_FALSE , 0 , 0);

    glBindVertexArray(0);

}

mesh::~mesh(){
    glDeleteVertexArrays(1 , &m_vertexArrayObject);
}


void mesh::Draw()
{
    glBindVertexArray( m_vertexArrayObject );

    glDrawArrays(GL_TRIANGLES , 0 , m_drawCount ); // drawing a triangle

    glBindVertexArray(0);
}
