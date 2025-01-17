#include <cmath>
#include <iostream>
#include <map>
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/random.hpp>

#include "./../../../include/gl_helper.hpp"
#include "./../../../include/dynamics/SPH/SPHDynamicSystemRenderable.hpp"
#include "./../../../include/Viewer.hpp"

SPHDynamicSystemRenderable::~SPHDynamicSystemRenderable()
{}

SPHDynamicSystemRenderable::SPHDynamicSystemRenderable(SPHDynamicSystemPtr system) :
    HierarchicalRenderable(nullptr), m_lastUpdateTime( 0 )
{
    m_system = system;
}

void SPHDynamicSystemRenderable::do_draw()
{}

void SPHDynamicSystemRenderable::do_animate(float time )
{
    if( time - m_lastUpdateTime >= m_system->getDt() )
    {
        //Dynamic system step
        m_system->computeSimulationStep();
        m_lastUpdateTime = time;
    }

}

void SPHDynamicSystemRenderable::setDynamicSystem(const SPHDynamicSystemPtr &system)
{
    m_system = system;
}

void SPHDynamicSystemRenderable::do_keyPressedEvent(sf::Event &e)
{
    if(e.key.code == sf::Keyboard::A ) //Toggle collision detection
    {
        m_system->setCollisionsDetection( !m_system->getCollisionDetection() );
    }
    else if(e.key.code == sf::Keyboard::T ) //Tilt particles
    {
        srand(time(0));
        // "tilt" all particles randomly around their position
        for(const ParticlePtr& p : m_system->getParticles()) {
            glm::vec3 pos = p->getPosition();
            // tilt all positions
            pos += glm::ballRand(1.0f);
            p->setPosition(pos);
        }
    }
    else if( e.key.code == sf::Keyboard::F5 ) //Reset the simulation
    {
        for( const ParticlePtr& p : m_system->getParticles() )
        {
            p->restart();
        }
        m_lastUpdateTime = 0;
    }
    else //Propagate events to the children
    {
        for(HierarchicalRenderablePtr c : getChildren())
        {
            c->keyPressedEvent(e);
        }
    }
}

void SPHDynamicSystemRenderable::do_keyReleasedEvent(sf::Event& e)
{
    //Propagate events to the children
    for(HierarchicalRenderablePtr c : getChildren())
    {
        c->keyReleasedEvent(e);
    }
}
