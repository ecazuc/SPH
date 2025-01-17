#include "./../../include/dynamics/ParticlePlaneCollision.hpp"

ParticlePlaneCollision::~ParticlePlaneCollision()
{}


ParticlePlaneCollision::ParticlePlaneCollision(ParticlePtr particle, PlanePtr plane, float restitution) :
    Collision(restitution)
{
    m_particle = particle;
    m_plane = plane;
}

void ParticlePlaneCollision::do_solveCollision()
{
    //Don't process fixed particles (Let's assume that the ground plane is fixed)
    if (m_particle->isFixed()) return;

    float d = m_plane->distanceToOrigin();
    glm::vec3 n = m_plane->normal();
    float r = m_particle->getRadius();
    glm::vec3 x = m_particle->getPosition();
    glm::vec3 v = m_particle->getVelocity();

    //Compute particle-plane distance
    float d2Plane = abs(glm::dot(x, n) - d);

    //Project the particle on the plane
    glm::vec3 xProj = x - (d2Plane-r) * n;
    m_particle->setPosition(xProj);

    //Compute post-collision velocity
    glm::vec3 vProj = v - (1.0f + m_restitution) * glm::dot(v, n) * n;
    m_particle->setVelocity(vProj);

}



bool testParticlePlane(const ParticlePtr &particle, const PlanePtr &plane)
{
    /* Equation of a plane passing through A and normal to n:
   * dot( p - A, n ) = dot( p, n ) - dot( A, n ) = 0
   * dot( A, n ) is stored in the "distanceToOrigin" of the plane.
   *
   * Equation of a particle of radius r centered in c:
   * dot( p - c, p - c ) = r²
   *
   * distance( plane, particle )
   *   = min( distance( plane, c ) - r, 0 )              //definition
   *   = min( abs( dot( c - A, n ) ) - r, 0 )
   *   = min( abs( dot( c, n ) - dot( A, n ) ) - r, 0 )
   *
   * So, there is intersection if distance( plane, particle ) = 0
   * <=> abs( dot( c, n ) - dot( A, n ) ) - r <= 0
   * <=> abs( dot( c, n ) - dot( A, n ) ) <= r
   */

    //TODO: Test collision between particle and plane
    //Functions to use:
    //glm::dot(v1, v2): Return the dot product of two vector.
    //Plane::distanceToOrigin(): Return the distance to origin from the plane
    //Plane::normal(): Return the normal of the plane
    //Particle::getRadius(), Particle::getPosition()

    float d = plane->distanceToOrigin();
    glm::vec3 n = plane->normal();
    float r = particle->getRadius();
    glm::vec3 x = particle->getPosition();

    return ((glm::dot(x, n) - d) <= r);

}
