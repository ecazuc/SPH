#include "./../../include/dynamics/SPH/PressureForceField.hpp"

PressureForceField::PressureForceField(const std::vector<ParticlePtr>& particles, float smoothingLength)
    : smoothingLength(smoothingLength), kernel(smoothingLength), neighborSearch(smoothingLength){
    for (const auto& particle : particles) {
        m_particles.push_back(std::dynamic_pointer_cast<SPHParticle>(particle));
    }
}

void PressureForceField::do_addForce(){
    for (auto& particle : m_particles) {
        glm::vec3 pressureForce = glm::vec3(0.0f);
        auto neighbors = neighborSearch.findNeighbors(m_particles, particle);
        for (const auto& neighbor : neighbors) {
            if (&particle == &neighbor) continue;
            float pressureTerm = (particle->getPressure() + neighbor->getPressure()) / (2 * neighbor->getDensity());
            pressureForce += pressureTerm * kernel.spikyKernelGradient(glm::distance(particle->getPosition(),neighbor->getPosition())) * neighbor->getMass();
        }
        particle->incrForce(-pressureForce);
    }
}
