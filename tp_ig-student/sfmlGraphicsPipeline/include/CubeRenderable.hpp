#ifndef CUBE_RENDERABLE_HPP
#define CUBE_RENDERABLE_HPP

#include "Renderable.hpp"
#include <vector>
#include <glm/glm.hpp>

class CubeRenderable : public Renderable
{
    public:
        ~CubeRenderable();
        CubeRenderable( ShaderProgramPtr program );

    private:
        void do_draw();

        std::vector< glm::vec3 > m_positions;
        unsigned int m_vBuffer;

        std::vector< glm::vec3 > m_normals;
        unsigned int m_nBuffer;

        std::vector< glm::vec4 > m_colors;
        unsigned int m_cBuffer;

        std::vector< glm::vec2 > m_tcoords;
        unsigned int m_tBuffer;

};

typedef std::shared_ptr<CubeRenderable> CubeRenderablePtr;

#endif
