#ifndef INDEXEDCUBE_RENDERABLE_HPP
#define INDEXEDCUBE_RENDERABLE_HPP

#include "Renderable.hpp"
#include <vector>
#include <glm/glm.hpp>

class IndexedCubeRenderable : public Renderable
{
public:
    ~IndexedCubeRenderable();
    IndexedCubeRenderable( ShaderProgramPtr program );

private:
    void do_draw();

    std::vector< glm::vec3 > m_positions;
    unsigned int m_vBuffer;

    std::vector< glm::vec3 > m_normals;
    unsigned int m_nBuffer;

    std::vector< glm::vec4 > m_colors;
    unsigned int m_cBuffer;

    std::vector< glm::vec3 > m_tangents;
    unsigned int m_tBuffer;

    std::vector<int> m_indices;
    unsigned int m_iBuffer;

};

typedef std::shared_ptr<IndexedCubeRenderable> IndexedCubeRenderablePtr;

#endif
