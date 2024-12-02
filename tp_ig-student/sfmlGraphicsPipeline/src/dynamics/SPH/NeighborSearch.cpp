#include "./../../include/dynamics/SPH/NeighborSearch.hpp"
#include <cmath>

NeighborSearch::NeighborSearch(float smoothingLength) : smoothingLength(smoothingLength) {}

std::vector<SPHParticlePtr> NeighborSearch::findNeighbors(const std::vector<SPHParticlePtr>& particles, const SPHParticlePtr& particle) {
    std::vector<SPHParticlePtr> neighbors;
    for (const auto& p : particles) {
        if (glm::distance(p->getPosition(), particle->getPosition()) < smoothingLength) {
            neighbors.push_back(p);
        }
    }
    return neighbors;
}
