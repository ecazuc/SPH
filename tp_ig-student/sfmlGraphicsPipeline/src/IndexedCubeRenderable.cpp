#include "./../include/IndexedCubeRenderable.hpp"
#include "./../include/gl_helper.hpp"
#include "./../include/log.hpp"
#include "./../include/Utils.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>

IndexedCubeRenderable::IndexedCubeRenderable(ShaderProgramPtr shaderProgram)
        : Renderable(shaderProgram), m_vBuffer(0)
{

    //Cube
    m_positions.push_back( glm::vec3 (1,-1,1));
    m_positions.push_back( glm::vec3 (1,1,1));
    m_positions.push_back( glm::vec3 (-1,1,1));
    m_positions.push_back( glm::vec3 (-1,-1,1));
    m_positions.push_back( glm::vec3 (1,-1,-1));
    m_positions.push_back( glm::vec3 (1,1,-1));
    m_positions.push_back( glm::vec3 (-1,1,-1));
    m_positions.push_back( glm::vec3 (-1,-1,-1));

    m_indices = {
        0,5,4,
        0,5,1,
        0,2,1,
        0,2,3,
        0,7,4,
        0,7,3,
        6,3,7,
        6,3,2,
        6,4,5,
        6,4,7,
        6,1,2,
        6,1,5
    };

    //Couleurs cube
    for (size_t i = 0; i < m_positions.size(); ++i) {
        if (i % 3 == 0) m_colors.push_back(glm::vec4(0.7,0.9,0.4,1)); // Red color for all vertices
        if (i % 3 == 1) m_colors.push_back(glm::vec4(0.4,0.9,0.7,1)); // Green color for all vertices
        if (i % 3 == 2) m_colors.push_back(glm::vec4(0.9,0.4,0.7,1)); // Blue color for all vertices

    }

    // Set the model matrix to identity
    m_model = glm::mat4(1.0);

    //Create buffers
    glGenBuffers(1, &m_vBuffer); //vertices
    glGenBuffers(1, &m_cBuffer);
    glGenBuffers(1, &m_iBuffer);

    //Activate buffer and send data to the graphics card
    glBindBuffer(GL_ARRAY_BUFFER, m_vBuffer);
    glBufferData(GL_ARRAY_BUFFER, m_positions.size()*sizeof(glm::vec3), m_positions.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, m_cBuffer);
    glBufferData(GL_ARRAY_BUFFER, m_colors.size()*sizeof(glm::vec4), m_colors.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_iBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size()*sizeof(glm::vec3), m_indices.data(), GL_STATIC_DRAW);
}

void IndexedCubeRenderable::do_draw()
{
    // Get the identifier ( location ) of the uniform modelMat in the shader program
    int modelLocation = m_shaderProgram->getUniformLocation("modelMat");
    // Send the data corresponding to this identifier on the GPU
    glUniformMatrix4fv( modelLocation , 1, GL_FALSE , glm::value_ptr( m_model ));

    // Get the identifier of the attribute vPosition in the shader program
    int positionLocation = m_shaderProgram->getAttributeLocation("vPosition");
    // Activate the attribute array at this location
    glEnableVertexAttribArray( positionLocation );
    // Bind the position buffer on the GL_ARRAY_BUFFER target
    glBindBuffer( GL_ARRAY_BUFFER , m_vBuffer );
    // Specify the location and the format of the vertex position attribute
    glVertexAttribPointer( positionLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    int colorLocation = m_shaderProgram->getAttributeLocation("vColor");
    glEnableVertexAttribArray( colorLocation );
    glBindBuffer( GL_ARRAY_BUFFER , m_cBuffer );
    glVertexAttribPointer( colorLocation, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER , m_iBuffer );

    // Draw the triangles
    //glDrawArrays( GL_TRIANGLES, 0, m_positions.size());

    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    // Release the vertex attribute array
    glDisableVertexAttribArray( positionLocation );
    glDisableVertexAttribArray( colorLocation );
}

IndexedCubeRenderable::~IndexedCubeRenderable()
{
    glcheck(glDeleteBuffers(1, &m_vBuffer));
    glcheck(glDeleteBuffers(1, &m_cBuffer));
    glcheck(glDeleteBuffers(1, &m_iBuffer));
}