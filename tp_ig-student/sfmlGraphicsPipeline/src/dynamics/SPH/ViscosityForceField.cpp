#include "./../../include/dynamics/SPH/ViscosityForceField.hpp"

ViscosityForceField::ViscosityForceField(const std::vector<ParticlePtr>& particles, float smoothingLength, float viscosityCoefficient)
    : smoothingLength(smoothingLength), viscosityCoefficient(viscosityCoefficient), kernel(smoothingLength), neighborSearch(smoothingLength) {
    for (const auto& particle : particles) {
        m_particles.push_back(std::dynamic_pointer_cast<SPHParticle>(particle));
    }
}

void ViscosityForceField::do_addForce(){
    for (auto& particle : m_particles) {
        glm::vec3 viscosityForce = glm::vec3(0.0f);
        auto neighbors = neighborSearch.findNeighbors(m_particles, particle);
        for (const auto& neighbor : neighbors) {
            if (&particle == &neighbor) continue;
            glm::vec3 velocityDiff = (neighbor->getVelocity() - particle->getVelocity())/neighbor->getDensity();
            viscosityForce += viscosityCoefficient * velocityDiff * kernel.viscosityKernelLaplacian(glm::distance(particle->getPosition(),neighbor->getPosition())) * neighbor->getMass();
        }
        particle->incrForce(viscosityForce);
    }
}
