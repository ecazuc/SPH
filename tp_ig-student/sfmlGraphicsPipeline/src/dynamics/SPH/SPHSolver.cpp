#include "./../../include/dynamics/SPH/SPHSolver.hpp"

SPHSolver::SPHSolver(float smoothingLength, float restDensity)
    : smoothingLength(smoothingLength), restDensity(restDensity),

      kernel(smoothingLength), neighborSearch(smoothingLength) {
                     gasStiffness = 2000.0f;
      }

SPHSolver::~SPHSolver()
{
}

void SPHSolver::do_solve(const float& dt, std::vector<ParticlePtr>& particles)
{
    std::vector<SPHParticlePtr> sphparticles;
    for (auto& particle : particles) {
        SPHParticlePtr sphParticle = std::dynamic_pointer_cast<SPHParticle>(particle);
        if (sphParticle) {
            sphparticles.push_back(sphParticle);
        }
    }
    for (SPHParticlePtr p : sphparticles)
    {
        if(!p->isFixed())
        {
            float density = 0.0f;
            auto neighbors = neighborSearch.findNeighbors(sphparticles, p);
            for (const auto& neighbor : neighbors) {
                density += neighbor->getMass() * kernel.poly6Kernel(glm::distance(p->getPosition(), neighbor->getPosition()));
            }
            p->setDensity(density);
            p->setPressure(std::max(0.0f, gasStiffness * (density - restDensity)));


           for (auto& particle : sphparticles) {
               particle->setVelocity(particle->getVelocity() + dt * (particle->getForce())/density);
               particle->setPosition(particle->getPosition() + dt * particle->getVelocity());
           }
        }
    }

}
