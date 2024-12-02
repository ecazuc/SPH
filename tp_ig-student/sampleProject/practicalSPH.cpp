#include <ShaderProgram.hpp>
#include <Viewer.hpp>

#include <ShaderProgram.hpp>

#include <QuadMeshRenderable.hpp>
#include <FrameRenderable.hpp>

#include <dynamics/DynamicSystemRenderable.hpp>
#include <dynamics/ConstantForceField.hpp>

#include <dynamics/ParticleRenderable.hpp>
#include <dynamics/ParticleListRenderable.hpp>
#include <dynamics/ConstantForceFieldRenderable.hpp>
#include <dynamics/ControlledForceFieldRenderable.hpp>

#include <dynamics/SPH/SPHSolver.hpp>
#include <dynamics/SPH/SPHParticle.hpp>
#include <dynamics/SPH/SPHDynamicSystem.hpp>
#include <dynamics/SPH/SPHParticlePlaneCollision.hpp>
#include <dynamics/SPH/SPHDynamicSystemRenderable.hpp>
#include <dynamics/SPH/PressureForceField.hpp>
#include <dynamics/SPH/ViscosityForceField.hpp>


void sph_simulation(Viewer& viewer, SPHDynamicSystemPtr& system, SPHDynamicSystemRenderablePtr& systemRenderable);

void initialize_scene(Viewer& viewer) {
    // Set up a shader and add a 3D frame.
    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(
        "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
        "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
    viewer.addShaderProgram(flatShader);

    FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
    viewer.addRenderable(frame);

    // Initialize a dynamic system and solver.
    SPHDynamicSystemPtr system = std::make_shared<SPHDynamicSystem>();
    SPHSolverPtr solver = std::make_shared<SPHSolver>(0.15f, 1000.0f);
    system->setSolver(solver);
    system->setDt(0.01f);

    // Create a renderable associated with the dynamic system.
    SPHDynamicSystemRenderablePtr systemRenderable = std::make_shared<SPHDynamicSystemRenderable>(system);
    viewer.addRenderable(systemRenderable);

    // Populate the dynamic system with SPH particles and obstacles.
    sph_simulation(viewer, system, systemRenderable);

    // Activate animation.
    viewer.startAnimation();
}

int main() {
    //glm::vec4 background_color(0.1f, 0.1f, 0.2f, 1.0f);
    glm::vec4 background_color(0.7,0.7,0.7,1);
    Viewer viewer(1280, 720, background_color);
    initialize_scene(viewer);

    while (viewer.isRunning()) {
        viewer.handleEvent();
        viewer.animate();
        viewer.draw();
        viewer.display();
    }

    return EXIT_SUCCESS;
}

void sph_simulation(Viewer& viewer, SPHDynamicSystemPtr& system, SPHDynamicSystemRenderablePtr& systemRenderable) {
    // Initialize shaders.
    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(
        "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
        "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
//    ShaderProgramPtr instancedShader = std::make_shared<ShaderProgram>(
//        "../../sfmlGraphicsPipeline/shaders/instancedVertex.glsl",
//        "../../sfmlGraphicsPipeline/shaders/instancedFragment.glsl");
    viewer.addShaderProgram(flatShader);
//    viewer.addShaderProgram(instancedShader);

    system->setCollisionsDetection(true);

    // Create SPH particle grid.
    glm::vec3 px, pv;
    float pm = 4.0f, pr = 0.1f;
    std::vector<SPHParticlePtr> particles;

    for (float x = -1.50f; x <= 1.50f; x += 0.3f) {
        for (float y = 0.1f; y <= 1.5f; y += 0.2f) {
             for (float z = -1.5f; z <= 1.5f; z += 0.2f) {
                px = glm::vec3(x, y, z);
                pv = glm::vec3(0.0f, 0.0f, 0.0f);
                SPHParticlePtr particle = std::make_shared<SPHParticle>(px, pv, pm, pr);
                //particle->setVelocity(glm::vec3(0.1,0,0.1));
                particles.push_back(particle);
                system->addParticle(particle);
                ParticleRenderablePtr particleRenderable = std::make_shared<ParticleRenderable>(flatShader, particle);
                HierarchicalRenderable::addChild( systemRenderable, particleRenderable );
             }
        }
    }

    // Add gravity to the system.
    ConstantForceFieldPtr gravityForceField = std::make_shared<ConstantForceField>(system->getParticles(), SPHDynamicSystem::gravity );
    system->addForceField( gravityForceField );

    // Add a pressure force field to the system.
    PressureForceFieldPtr pressureForceField = std::make_shared<PressureForceField>(system->getParticles(), 0.15f);
    system->addForceField(pressureForceField);

    // Add a viscosity force field to the system.
    ViscosityForceFieldPtr viscosityForceField = std::make_shared<ViscosityForceField>(system->getParticles(), 0.15f, 0.001f);
    system->addForceField(viscosityForceField);


    float pool_size(2.0), pool_height(2.5);
    //Initialize four planes to create walls arround the particles
    glm::vec3 planeNormal, planePoint;
    planeNormal = glm::vec3(-1,0,0);
    planePoint = glm::vec3(pool_size,0,0);
    PlanePtr p0 = std::make_shared<Plane>( planeNormal, planePoint);
    system->addPlaneObstacle( p0 );

    planeNormal = glm::vec3(1,0,0);
    planePoint = glm::vec3(-pool_size,0,0);
    PlanePtr p1 = std::make_shared<Plane>( planeNormal, planePoint);
    system->addPlaneObstacle( p1 );

    planeNormal = glm::vec3(0,0,-1);
    planePoint = glm::vec3(0,0,pool_size);
    PlanePtr p2 = std::make_shared<Plane>( planeNormal, planePoint);
    system->addPlaneObstacle( p2 );

    planeNormal = glm::vec3(0,0,1);
    planePoint = glm::vec3(0,0,-pool_size);
    PlanePtr p3 = std::make_shared<Plane>( planeNormal, planePoint);
    system->addPlaneObstacle( p3 );

    planeNormal = glm::vec3(0,1,0);
    planePoint = glm::vec3(0,0,0);
    PlanePtr floor = std::make_shared<Plane>( planeNormal, planePoint);
    system->addPlaneObstacle( floor );


}

