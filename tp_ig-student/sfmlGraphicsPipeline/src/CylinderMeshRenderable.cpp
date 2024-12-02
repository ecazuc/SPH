#include "./../include/CylinderMeshRenderable.hpp"
#include "./../include/gl_helper.hpp"
#include "./../include/log.hpp"
#include "./../include/Utils.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>

CylinderMeshRenderable::~CylinderMeshRenderable()
{}

CylinderMeshRenderable::CylinderMeshRenderable(ShaderProgramPtr shaderProgram, bool indexed, unsigned int slices, bool vertex_normals) :
    MeshRenderable(shaderProgram, indexed)
{
    if (indexed){
        std::vector<glm::uvec3> indices;
        getUnitIndexedCylinder(m_positions, m_normals, indices, 3);
        // getUniIndexedCube fills a std::vector<glm::uvec3> of length n,
        // but m_indices is a std::vector<unsigned int> of length 3n.
        // We need to unpack the values.
        unpack(indices, m_indices);

        // Set random colors per vertex
        m_colors.resize(m_positions.size(), glm::vec4(0));
        for (size_t i=0; i<m_colors.size(); ++i)
            m_colors[i] = randomColor();
        
    }else{
        // Go to Utils.cpp and fill this function
        getUnitCylinder(m_positions, m_normals, m_tcoords, slices, vertex_normals);
        // Set random colors per triangle
        auto color = glm::vec4(0.9,0,0,1.0);
        m_colors.resize(m_positions.size(), glm::vec4(0));
        for(size_t i=0; i<m_colors.size(); i++){
            if(0<=i%12 && i%12<3){
                m_colors[i] = glm::vec4(0.7,0.9,0.4,1.0);
            }
            if(3<=i%12 && i%12<9){
                m_colors[i] = color;
            }
            if(9<=i%12 && i%12<12){
                m_colors[i] = glm::vec4(0.4,0.9,0.7,1.0);
            }
            if(i%12==0){
                color += glm::vec4(-0.07,0.1,0.05,0.0);
            }
        }

    }

    // See MeshRenderable::update_all_buffers
    update_all_buffers();
}