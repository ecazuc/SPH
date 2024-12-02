#ifndef PRESSUREFORCEFIELD_HPP
#define PRESSUREFORCEFIELD_HPP

#include "SPHParticle.hpp"
#include "SmoothingKernel.hpp"
#include <vector>
#include "../ForceField.hpp"
#include "NeighborSearch.hpp"

/** @brief Class to compute pressure forces between particles.
 *
 * This class computes the pressure forces between particles in an SPH simulation.
 * The pressure force is calculated using the gradient of the pressure field.
 */
class PressureForceField : public ForceField {
public:

    /** @brief Constructor for the pressure force.
     *
     * @param smoothingLength The smoothing length for the SPH kernel.
     */
    PressureForceField(const std::vector<ParticlePtr>& particles, float smoothingLength);

    /**@brief Access to the particles influenced by this force field.
          *
          * Get the particles influenced by this pressure force field.
          * @return The set of particles influenced by this.
          */
    const std::vector<ParticlePtr> getParticles();

    /**@brief Define the set of particles influenced by this force field.
     *
     * Define the set of particles that will be influenced by this pressure
     * force force.
     * @param particles The new set of influenced particles.
     */
    void setParticles(const std::vector<ParticlePtr>& particles);

    /**@brief Access to the pressure factor.
     *
     * Get the pressure factor of this force field.
     * @return The pressure factor of this.
     */
    const float& getSmoothingLength();
    /**@brief Set the pressure factor of this force field.
     *
     * Define the pressure factor of this pressure force field.
     * @param pressure The new pressure factor.
     */
    void setSmoothingLength(const float& sl);

private:

    void do_addForce();
    std::vector<SPHParticlePtr> m_particles;

    NeighborSearch neighborSearch;

    /** @brief The smoothing length for the SPH kernel. */
    float smoothingLength;

    /** @brief The SPH kernel used to compute the pressure force. */
    SmoothingKernel kernel;
};

typedef std::shared_ptr<PressureForceField> PressureForceFieldPtr;

#endif // PRESSUREFORCEFIELD_HPP
