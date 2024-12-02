//#include <Viewer.hpp>
//#include <ShaderProgram.hpp>
//#include <FrameRenderable.hpp>
//#include <HierarchicalRenderable.hpp>
//#include <CylinderMeshRenderable.hpp>
//#include <MeshRenderable.hpp>
//#include <SphereMeshRenderable.hpp>
//
//void initialize_scene( Viewer& viewer )
//{
//	ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(
//        "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
//        "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
//
//	viewer.addShaderProgram( flatShader );
//
//	//Frame
//	FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
//	viewer.addRenderable(frame);
//
//	CylinderMeshRenderablePtr root = std::make_shared<CylinderMeshRenderable>(flatShader, false);
//    glm::mat4 rootOrientation = getRotationMatrix(glm::radians(-90.0f), 1, 0, 0);
//    root -> setGlobalTransform(rootOrientation);
//    glm::mat4 rootScale = getScaleMatrix(0.1,0.1,1.0);
//    root -> setLocalTransform(rootScale);
//
//
//    std::shared_ptr<SphereMeshRenderable> s3 = std::make_shared<SphereMeshRenderable>(flatShader,false);
//    std::shared_ptr<SphereMeshRenderable> s1 = std::make_shared<SphereMeshRenderable>(flatShader,false);
//    std::shared_ptr<SphereMeshRenderable> s2 = std::make_shared<SphereMeshRenderable>(flatShader,false);
//
//    CylinderMeshRenderablePtr child1 = std::make_shared<CylinderMeshRenderable>(flatShader, false);
//    CylinderMeshRenderablePtr child2 = std::make_shared<CylinderMeshRenderable>(flatShader, false);
//    CylinderMeshRenderablePtr child3 = std::make_shared<CylinderMeshRenderable>(flatShader, false);
//    CylinderMeshRenderablePtr child4 = std::make_shared<CylinderMeshRenderable>(flatShader, false);
//
//    glm::mat4 child1GlobalTransform = getTranslationMatrix(0,0,1);
//    glm::mat4 s1Scale = getScaleMatrix(0.1,0.1,0.1);
//    s1 -> setGlobalTransform(child1GlobalTransform * s1Scale);
//
//    glm::mat4 chil1Transform = getTranslationMatrix(0,0,1.1);
//    glm::mat4 child1Rotation = getRotationMatrix(glm::radians(-45.0f), 0, 1, 0);
//    child1 -> setGlobalTransform(chil1Transform * child1Rotation);
//    child1 -> setLocalTransform(rootScale);
//
//    glm::mat4 child2Rotation = getRotationMatrix(glm::radians(45.0f), 0, 1, 0);
//    child2 -> setGlobalTransform(chil1Transform * child2Rotation);
//    child2 -> setLocalTransform(rootScale);
//
//    glm::mat4 child3Rotation = getRotationMatrix(glm::radians(45.0f), 1, 0, 0);
//    child3 -> setGlobalTransform(chil1Transform * child3Rotation);
//    child3 -> setLocalTransform(rootScale);
//
//    glm::mat4 child4Rotation = getRotationMatrix(glm::radians(-45.0f), 1, 0, 0);
//    child4 -> setGlobalTransform(chil1Transform * child4Rotation);
//    child4 -> setLocalTransform(rootScale);
//
//    glm::mat4 child2GlobalTransform = getTranslationMatrix(1,2,0) ;
//    s2 -> setGlobalTransform(child2GlobalTransform);
//
//
//    HierarchicalRenderable::addChild(root, s1);
//    HierarchicalRenderable::addChild(root, child1);
//    HierarchicalRenderable::addChild(root, child2);
//    HierarchicalRenderable::addChild(root, child3);
//    HierarchicalRenderable::addChild(root, child4);
//
//    viewer.addRenderable(root);
//
//}
//
//int main()
//{
//	Viewer viewer(1280,720);
//	initialize_scene(viewer);
//
//	while( viewer.isRunning() )
//	{
//		viewer.handleEvent();
//		viewer.animate();
//		viewer.draw();
//		viewer.display();
//	}
//
//	return EXIT_SUCCESS;
//}
