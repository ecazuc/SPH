#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/norm.hpp>

#include "./../../../include/gl_helper.hpp"
#include "./../../../include/dynamics/SPH/SPHDynamicSystem.hpp"
#include "./../../../include/dynamics/SPH/SPHParticlePlaneCollision.hpp"



SPHDynamicSystem::SPHDynamicSystem() :
    m_dt(0.1),
    m_restitution(0.1),
    m_handleCollisions(true)
{}

glm::vec3 SPHDynamicSystem::gravity = glm::vec3(0.0, -9.81, 0.0);


const std::vector<ParticlePtr>& SPHDynamicSystem::getParticles() const
{
    return m_particles;
}

void SPHDynamicSystem::setParticles(const std::vector<ParticlePtr> &particles)
{
    m_particles = particles;
}

const std::vector<ForceFieldPtr>& SPHDynamicSystem::getForceFields() const
{
    return m_forceFields;
}

void SPHDynamicSystem::setForceFields(const std::vector<ForceFieldPtr> &forceFields)
{
    m_forceFields = forceFields;
}


float SPHDynamicSystem::getDt() const
{
    return m_dt;
}

void SPHDynamicSystem::setDt(float dt)
{
    m_dt = dt;
}

SPHDynamicSystem::~SPHDynamicSystem() {}

void SPHDynamicSystem::clear()
{
    m_particles.clear();
    m_forceFields.clear();
    m_planeObstacles.clear();
}

bool SPHDynamicSystem::getCollisionDetection()
{
    return m_handleCollisions;
}

void SPHDynamicSystem::setCollisionsDetection(bool onOff)
{
    m_handleCollisions = onOff;
}

void SPHDynamicSystem::addParticle(ParticlePtr p)
{
    m_particles.push_back(std::dynamic_pointer_cast<SPHParticle>(p));
}

void SPHDynamicSystem::addForceField(ForceFieldPtr forceField)
{
    m_forceFields.push_back(forceField);
}

void SPHDynamicSystem::addPlaneObstacle(PlanePtr planeObstacle)
{
    m_planeObstacles.push_back(planeObstacle);
}

SolverPtr SPHDynamicSystem::getSolver()
{
    return m_solver;
}

void SPHDynamicSystem::setSolver(SolverPtr solver)
{
    m_solver = solver;
}

void SPHDynamicSystem::detectCollisions()
{
    //Detect particle plane collisions
    for(ParticlePtr p : m_particles)
    {
        for(PlanePtr o : m_planeObstacles)
        {
            if(testSPHParticlePlane(std::dynamic_pointer_cast<SPHParticle>(p), o))
            {
                SPHParticlePlaneCollisionPtr c = std::make_shared<SPHParticlePlaneCollision>(p,o,m_restitution);
                m_collisions.push_back(c);
            }
        }
    }
}

void SPHDynamicSystem::solveCollisions()
{
    while(!m_collisions.empty())
    {
        CollisionPtr collision = m_collisions.back();
        collision->solveCollision();
        m_collisions.pop_back();
    }
}

void SPHDynamicSystem::computeSimulationStep()
{
    //Compute particle's force
    for(ParticlePtr p : m_particles)
    {
        p->setForce(glm::vec3(0.0,0.0,0.0));
    }
    for(ForceFieldPtr f : m_forceFields)
    {
        f->addForce();
    }

    //Integrate position and velocity of particles
    m_solver->solve(m_dt, m_particles);

    //Detect and resolve collisions
    if(m_handleCollisions)
    {
        detectCollisions();
        solveCollisions();
    }
}

const float SPHDynamicSystem::getRestitution()
{
    return m_restitution;
}

void SPHDynamicSystem::setRestitution(const float& restitution)
{
    m_restitution = std::max(0.0f,std::min(restitution,1.0f));
}

std::ostream& operator<<(std::ostream& os, const SPHDynamicSystemPtr& system)
{
    std::vector<ParticlePtr> particles = system->getParticles();
    os << "Particle number: " << particles.size() << std::endl;
    for(ParticlePtr p : particles)
        os << p << std::endl;
    return os;
}
