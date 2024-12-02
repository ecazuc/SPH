#ifndef SPHSOLVER_HPP
#define SPHSOLVER_HPP

#include "../Solver.hpp"
#include "SPHParticle.hpp"
#include "SmoothingKernel.hpp"
#include "NeighborSearch.hpp"


class SPHSolver : public Solver {
public:

    SPHSolver(float smoothingLength, float restDensity);
    ~SPHSolver();

private:
    float gasStiffness;
    float restDensity;
    float smoothingLength;
    SmoothingKernel kernel;
    NeighborSearch neighborSearch;
    void do_solve(const float& dt, std::vector<ParticlePtr>& particles);
};

typedef std::shared_ptr<SPHSolver> SPHSolverPtr;

#endif // SPHSOLVER_HPP
