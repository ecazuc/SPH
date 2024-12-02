#include "./../../include/dynamics/SPH/SPHParticlePlaneCollision.hpp"
#include <glm/gtc/constants.hpp>

SPHParticlePlaneCollision::SPHParticlePlaneCollision(ParticlePtr particle, PlanePtr plane, float restitution)
    : Collision(restitution), m_particle(particle), m_plane(plane) {}

SPHParticlePlaneCollision::~SPHParticlePlaneCollision() {}

void SPHParticlePlaneCollision::do_solveCollision() {
    if (m_particle->isFixed()) return;

    SPHParticlePtr m_sphParticle = std::dynamic_pointer_cast<SPHParticle>(m_particle);
    glm::vec3 position = m_sphParticle->getPosition();
    glm::vec3 velocity = m_sphParticle->getVelocity();
    glm::vec3 normal = m_plane->normal();
    float distance = glm::dot(position, normal) - m_plane->distanceToOrigin();
    float radius = m_sphParticle->getRadius();

    if (distance <= radius) {
        // Adjust position based on interpenetration
        glm::vec3 correctedPosition = position - (distance - radius) * normal;
        m_sphParticle->setPosition(correctedPosition);

        // Adjust velocity with SPH-based restitution
        glm::vec3 correctedVelocity = velocity - (1 + m_restitution) * glm::dot(velocity, normal) * normal;
        m_sphParticle->setVelocity(correctedVelocity);
        //m_sphParticle->setVelocity(glm::vec3(0));

        // Optional: Influence density or pressure
        float density = m_sphParticle->getDensity();
        m_sphParticle->setDensity(density * 0.9f); // Example: Reduce density slightly on collision
    }
}

bool testSPHParticlePlane(const SPHParticlePtr& particle, const PlanePtr& plane) {
    glm::vec3 position = particle->getPosition();
    glm::vec3 normal = plane->normal();
    float distance = glm::dot(position, normal) - plane->distanceToOrigin();
    float radius = particle->getRadius();

    return distance <= radius;
}
