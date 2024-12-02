#ifndef NEIGHBORSEARCH_HPP
#define NEIGHBORSEARCH_HPP

#include "SPHParticle.hpp"
#include <vector>

class NeighborSearch {
public:
    /**
     * Constructor
     * @param smoothingLength The maximum distance within which particles are considered neighbors.
     */
    NeighborSearch(float smoothingLength);

    /**
     * Find neighbors of a given particle within the smoothing length.
     * @param particles The list of all particles in the system.
     * @param particle The particle for which neighbors are being searched.
     * @return A vector of pointers to neighboring particles.
     */
    std::vector<SPHParticlePtr> findNeighbors(const std::vector<SPHParticlePtr>& particles, const SPHParticlePtr& particle);

private:
    float smoothingLength; // Maximum interaction range for neighbors
};

#endif // NEIGHBORSEARCH_HPP
