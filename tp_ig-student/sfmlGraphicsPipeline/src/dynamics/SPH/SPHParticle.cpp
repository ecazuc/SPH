#include "./../../include/dynamics/SPH/SPHParticle.hpp"

SPHParticle::SPHParticle(const glm::vec3 &position, const glm::vec3 &velocity, const float &mass, const float &radius)
    : Particle(position,velocity, mass, radius), density(1000.0f), pressure(0.0f) {}

void SPHParticle::setDensity(float density) { this->density = density; }
float SPHParticle::getDensity() const { return density; }

void SPHParticle::setPressure(float pressure) { this->pressure = pressure; }
float SPHParticle::getPressure() const { return pressure; }
