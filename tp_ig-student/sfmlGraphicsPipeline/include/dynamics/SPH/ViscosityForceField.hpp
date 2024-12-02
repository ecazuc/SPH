#ifndef VISCOSITYFORCEFIELD_HPP
#define VISCOSITYFORCEFIELD_HPP

#include "SPHParticle.hpp"
#include "../ForceField.hpp"
#include "SmoothingKernel.hpp"
#include <vector>
#include "NeighborSearch.hpp"


/** @brief Class to compute viscosity forces between particles.
 *
 * This class computes the viscosity forces between particles in an SPH simulation.
 * The viscosity force is calculated using the gradient of the velocity field.
 */
class ViscosityForceField : public ForceField
{
public:

    /** @brief Constructor for the viscosity force.
     *
     * @param smoothingLength The smoothing length for the SPH kernel.
     * @param viscosityCoefficient The viscosity coefficient for the fluid.
     */
    ViscosityForceField(const std::vector<ParticlePtr>& particles, float smoothingLength, float viscosityCoefficient);

    /**@brief Access to the particles influenced by this force field.
             *
             * Get the particles influenced by this viscosity force field.
             * @return The set of particles influenced by this.
             */
    const std::vector<ParticlePtr> getParticles();

    /**@brief Define the set of particles influenced by this force field.
     *
     * Define the set of particles that will be influenced by this viscosity
     * force force.
     * @param particles The new set of influenced particles.
     */
    void setParticles(const std::vector<ParticlePtr>& particles);

    /**@brief Access to the viscosity coeficient.
     *
     * Get the viscosity coeficient of this force field.
     * @return The viscosity factor of this.
     */
    const float& getViscosity();
    /**@brief Set the viscosity coeficient of this force field.
     *
     * Define the viscosity coeficient of this viscosity force field.
     * @param viscosity The new viscosity coeficient.
     */
    void setViscosity(const float& viscosity);

private:

    /** @brief The smoothing length for the SPH kernel. */
    float smoothingLength;

    /** @brief The viscosity coefficient for the fluid. */
    float viscosityCoefficient;

    /** @brief The SPH kernel used to compute the viscosity force. */
    SmoothingKernel kernel;

    NeighborSearch neighborSearch;

    std::vector<SPHParticlePtr> m_particles;

    void do_addForce();
};

typedef std::shared_ptr<ViscosityForceField> ViscosityForceFieldPtr;

#endif // VISCOSITYFORCEFIELD_HPP
