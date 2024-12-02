#ifndef SPHPARTICLE_HPP
#define SPHPARTICLE_HPP

#include "../Particle.hpp"

/** @brief SPH particle class.
 *
 * This class represents a particle in an SPH simulation.
 * It extends the Particle class by adding density and pressure
 * attributes.
 */
class SPHParticle : public Particle {
public:

    /** @brief Constructor for an SPH particle.
     *
     * @param mass The mass of the particle.
     * @param radius The radius of the particle.
     */
 SPHParticle(const glm::vec3& position,
   const glm::vec3& velocity,
   const float& mass,
   const float& radius);


    /** @brief Set the density of the particle.
     *
     * @param density The density of the particle.
     */
    void setDensity(float density);

    /** @brief Get the density of the particle.
     *
     * @return The density of the particle.
     */
    float getDensity() const;

    /** @brief Set the pressure of the particle.
     *
     * @param pressure The pressure of the particle.
     */
    void setPressure(float pressure);

    /** @brief Get the pressure of the particle.
     *
     * @return The pressure of the particle.
     */
    float getPressure() const;

private:

    /** @brief The density of the particle. */
    float density;

    /** @brief The pressure of the particle. */
    float pressure;
};

typedef std::shared_ptr<SPHParticle> SPHParticlePtr;

#endif // SPHPARTICLE_HPP
