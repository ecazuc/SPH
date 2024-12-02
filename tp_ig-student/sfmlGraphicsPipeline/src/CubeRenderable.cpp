#include "./../include/CubeRenderable.hpp"
#include "./../include/gl_helper.hpp"
#include "./../include/log.hpp"
#include "./../include/Utils.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>


//CubeRenderable::CubeRenderable(ShaderProgramPtr shaderProgram)
//  : Renderable(shaderProgram), m_vBuffer(0), m_cBuffer(0)
//{
//    //Face 1
//    m_positions.push_back(glm::vec3(-0.5, -0.5, -0.5));
//    m_positions.push_back(glm::vec3(0.5, 0.5, -0.5));
//    m_positions.push_back(glm::vec3(0.5, -0.5, -0.5));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//
//    //Face 2
//    m_positions.push_back(glm::vec3(-0.5, -0.5, -0.5));
//    m_positions.push_back(glm::vec3(-0.5, 0.5, -0.5));
//    m_positions.push_back(glm::vec3(0.5, 0.5, -0.5));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//
//    //Face 3
//    m_positions.push_back(glm::vec3(0.5, -0.5, -0.5));
//    m_positions.push_back(glm::vec3(0.5, 0.5, 0.5));
//    m_positions.push_back(glm::vec3(0.5, -0.5, 0.5));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//
//    //Face 4
//    m_positions.push_back(glm::vec3(0.5, -0.5, -0.5));
//    m_positions.push_back(glm::vec3(0.5, 0.5, -0.5));
//    m_positions.push_back(glm::vec3(0.5, 0.5, 0.5));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//
//    //Face 5
//    m_positions.push_back(glm::vec3(-0.5, 0.5, 0.5));
//    m_positions.push_back(glm::vec3(-0.5, -0.5, 0.5));
//    m_positions.push_back(glm::vec3(0.5, -0.5, 0.5));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//
//    //Face 6
//    m_positions.push_back(glm::vec3(-0.5, 0.5, 0.5));
//    m_positions.push_back(glm::vec3(0.5, -0.5, 0.5));
//    m_positions.push_back(glm::vec3(0.5, 0.5, 0.5));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//
//
//    //Face 7
//    m_positions.push_back(glm::vec3(-0.5, -0.5, 0.5));
//    m_positions.push_back(glm::vec3(-0.5, 0.5, -0.5));
//    m_positions.push_back(glm::vec3(-0.5, -0.5, -0.5));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//
//    //Face 8
//    m_positions.push_back(glm::vec3(-0.5, -0.5, 0.5));
//    m_positions.push_back(glm::vec3(-0.5, 0.5, 0.5));
//    m_positions.push_back(glm::vec3(-0.5, 0.5, -0.5));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//
//    //Face 9
//    m_positions.push_back(glm::vec3(-0.5, 0.5, -0.5));
//    m_positions.push_back(glm::vec3(0.5, 0.5, 0.5));
//    m_positions.push_back(glm::vec3(0.5, 0.5, -0.5));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//
//    //Face 10
//    m_positions.push_back(glm::vec3(-0.5, 0.5, -0.5));
//    m_positions.push_back(glm::vec3(-0.5, 0.5, 0.5));
//    m_positions.push_back(glm::vec3(0.5, 0.5, 0.5));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//
//    //Face 11
//    m_positions.push_back(glm::vec3(-0.5, -0.5, 0.5));
//    m_positions.push_back(glm::vec3(-0.5, -0.5, -0.5));
//    m_positions.push_back(glm::vec3(0.5, -0.5, -0.5));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//
//    //Face 12
//    m_positions.push_back(glm::vec3(-0.5, -0.5, 0.5));
//    m_positions.push_back(glm::vec3(0.5, -0.5, -0.5));
//    m_positions.push_back(glm::vec3(0.5, -0.5, 0.5));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//    m_colors.push_back(glm::vec4(1, 1, 0, 1));
//
//
//
//	// Set the model matrix to identity
//	m_model = glm::mat4(1.0);
//
//	//Create buffers
//	glGenBuffers(1, &m_vBuffer); //vertices
//	glGenBuffers(1, &m_cBuffer); //colors
//
//	//Activate buffer and send data to the graphics card
//	glBindBuffer(GL_ARRAY_BUFFER, m_vBuffer);
//	glBufferData(GL_ARRAY_BUFFER, m_positions.size()*sizeof(glm::vec3), m_positions.data(), GL_STATIC_DRAW);
//	glBindBuffer(GL_ARRAY_BUFFER, m_cBuffer);
//	glBufferData(GL_ARRAY_BUFFER, m_colors.size() * sizeof(glm::vec4), m_colors.data(), GL_STATIC_DRAW);
//}
//
//void CubeRenderable::do_draw()
//{
//	// Get the identifier ( location ) of the uniform modelMat in the shader program
//	int modelLocation = m_shaderProgram->getUniformLocation("modelMat");
//	// Send the data corresponding to this identifier on the GPU
//	glUniformMatrix4fv( modelLocation , 1, GL_FALSE , glm::value_ptr( m_model ));
//
//	// Get the identifier of the attribute vPosition in the shader program
//	int positionLocation = m_shaderProgram->getAttributeLocation("vPosition");
//	int colorLocation = m_shaderProgram->getAttributeLocation("vColor");
//	// Activate the attribute array at this location
//	glEnableVertexAttribArray( positionLocation );
//	// Bind the position buffer on the GL_ARRAY_BUFFER target
//	glBindBuffer( GL_ARRAY_BUFFER , m_vBuffer );
//	// Specify the location and the format of the vertex position attribute
//	glVertexAttribPointer( positionLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//	// Activate the attribute array at this location
//	glEnableVertexAttribArray(colorLocation);
//	// Bind the position buffer on the GL_ARRAY_BUFFER target
//	glBindBuffer(GL_ARRAY_BUFFER, m_cBuffer);
//	// Specify the location and the format of the vertex position attribute
//	glVertexAttribPointer(colorLocation, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
//
//
//
//
//	// Draw the triangles
//	glDrawArrays( GL_TRIANGLES, 0, m_positions.size());
//
//	// Release the vertex attribute array
//	glDisableVertexAttribArray( positionLocation );
//    glDisableVertexAttribArray( colorLocation );
//}
//
//CubeRenderable::~CubeRenderable()
//{
//    glcheck(glDeleteBuffers(1, &m_vBuffer));
//	glcheck(glDeleteBuffers(1, &m_cBuffer));
//}

// Include the function prototype for getUnitCube
extern void getUnitCube(std::vector<glm::vec3>& positions, std::vector<glm::vec3>& normals, std::vector<glm::vec2>& tcoords);

CubeRenderable::CubeRenderable(ShaderProgramPtr shaderProgram)
  : Renderable(shaderProgram), m_vBuffer(0), m_cBuffer(0), m_nBuffer(0), m_tBuffer(0)
{
    // Get the unit cube data (positions, normals, and texture coordinates)
    getUnitCube(m_positions, m_normals, m_tcoords);

    // Set colors (you can adjust or change this part)
   for (size_t i = 0; i < m_positions.size(); ++i) {
      if (i % 3 == 0) m_colors.push_back(glm::vec4(0.7,0.9,0.4,1)); // Red color for all vertices
      if (i % 3 == 1) m_colors.push_back(glm::vec4(0.4,0.9,0.7,1)); // Green color for all vertices
      if (i % 3 == 2) m_colors.push_back(glm::vec4(0.9,0.4,0.7,1)); // Blue color for all vertices

    }

    // Create and populate vertex buffer objects (VBOs) for positions, normals, colors, and texture coordinates
    glGenBuffers(1, &m_vBuffer); // Positions
    glGenBuffers(1, &m_cBuffer); // Colors
    glGenBuffers(1, &m_nBuffer); // Normals
    glGenBuffers(1, &m_tBuffer); // Texture coordinates

    // Upload positions to the GPU
    glBindBuffer(GL_ARRAY_BUFFER, m_vBuffer);
    glBufferData(GL_ARRAY_BUFFER, m_positions.size() * sizeof(glm::vec3), m_positions.data(), GL_STATIC_DRAW);

    // Upload colors to the GPU
    glBindBuffer(GL_ARRAY_BUFFER, m_cBuffer);
    glBufferData(GL_ARRAY_BUFFER, m_colors.size() * sizeof(glm::vec4), m_colors.data(), GL_STATIC_DRAW);

    // Upload normals to the GPU
    glBindBuffer(GL_ARRAY_BUFFER, m_nBuffer);
    glBufferData(GL_ARRAY_BUFFER, m_normals.size() * sizeof(glm::vec3), m_normals.data(), GL_STATIC_DRAW);

    // Upload texture coordinates to the GPU
    glBindBuffer(GL_ARRAY_BUFFER, m_tBuffer);
    glBufferData(GL_ARRAY_BUFFER, m_tcoords.size() * sizeof(glm::vec2), m_tcoords.data(), GL_STATIC_DRAW);
}

void CubeRenderable::do_draw()
{
    // Send the model matrix to the shader
    int modelLocation = m_shaderProgram->getUniformLocation("modelMat");
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(m_model));

    // Activate and bind the position attribute
    int positionLocation = m_shaderProgram->getAttributeLocation("vPosition");
    glEnableVertexAttribArray(positionLocation);
    glBindBuffer(GL_ARRAY_BUFFER, m_vBuffer);
    glVertexAttribPointer(positionLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    // Activate and bind the color attribute
    int colorLocation = m_shaderProgram->getAttributeLocation("vColor");
    glEnableVertexAttribArray(colorLocation);
    glBindBuffer(GL_ARRAY_BUFFER, m_cBuffer);
    glVertexAttribPointer(colorLocation, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

    // Activate and bind the normal attribute (if using in shaders)
    int normalLocation = m_shaderProgram->getAttributeLocation("vNormal");
    if (normalLocation != -1) {
        glEnableVertexAttribArray(normalLocation);
        glBindBuffer(GL_ARRAY_BUFFER, m_nBuffer);
        glVertexAttribPointer(normalLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    }

    // Activate and bind the texture coordinate attribute (if using in shaders)
    int tcoordLocation = m_shaderProgram->getAttributeLocation("vTexCoord");
    if (tcoordLocation != -1) {
        glEnableVertexAttribArray(tcoordLocation);
        glBindBuffer(GL_ARRAY_BUFFER, m_tBuffer);
        glVertexAttribPointer(tcoordLocation, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    }

    // Draw the triangles
    glDrawArrays(GL_TRIANGLES, 0, m_colors.size());

    // Disable the vertex attribute arrays
    glDisableVertexAttribArray(positionLocation);
    glDisableVertexAttribArray(colorLocation);
    if (normalLocation != -1) glDisableVertexAttribArray(normalLocation);
    if (tcoordLocation != -1) glDisableVertexAttribArray(tcoordLocation);
}

CubeRenderable::~CubeRenderable()
{
    glDeleteBuffers(1, &m_vBuffer);
    glDeleteBuffers(1, &m_cBuffer);
    glDeleteBuffers(1, &m_nBuffer);
    glDeleteBuffers(1, &m_tBuffer);
}