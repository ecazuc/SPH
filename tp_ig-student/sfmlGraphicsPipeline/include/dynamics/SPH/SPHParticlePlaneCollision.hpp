#ifndef SPH_PARTICLE_PLANE_COLLISION_HPP
#define SPH_PARTICLE_PLANE_COLLISION_HPP

#include "SPHParticle.hpp"
#include "../../../include/Plane.hpp"
#include "../Collision.hpp"

class SPHParticlePlaneCollision : public Collision {
public:
    SPHParticlePlaneCollision(ParticlePtr particle, PlanePtr plane, float restitution);
    ~SPHParticlePlaneCollision();

private:
    void do_solveCollision();

    ParticlePtr m_particle;
    PlanePtr m_plane;
};

typedef std::shared_ptr<SPHParticlePlaneCollision> SPHParticlePlaneCollisionPtr;

bool testSPHParticlePlane(const SPHParticlePtr& particle, const PlanePtr& plane);

#endif // SPH_PARTICLE_PLANE_COLLISION_HPP
