#include "./../../include/dynamics/EulerExplicitSolver.hpp"

EulerExplicitSolver::EulerExplicitSolver()
{

}

EulerExplicitSolver::~EulerExplicitSolver()
{

}

void EulerExplicitSolver::do_solve(const float& dt, std::vector<ParticlePtr>& particles)
{
    for(ParticlePtr p : particles)
    {
        if(!p->isFixed())
        {


            //Compute the new position of the particle
            glm::vec3 newPosition = p->getPosition() + dt*p->getVelocity();
            //Compute the new velocity of the particle
            glm::vec3 newVelocity = p->getVelocity() + dt*(p->getForce()/p->getMass());
            //Update the particle position
            p->setPosition(newPosition);
            //Update the particle velocity
            p->setVelocity(newVelocity);
        }
    }
}
