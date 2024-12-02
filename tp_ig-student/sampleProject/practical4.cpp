//#include <ShaderProgram.hpp>
//#include <Viewer.hpp>
//
//#include <CylinderMeshRenderable.hpp>
//#include <FrameRenderable.hpp>
//#include <GeometricTransformation.hpp>
//#include <iostream>
//#include <iomanip>
//
//void movingTree(Viewer& viewer);
//void movingCylinder(Viewer& viewer);
//
//void initialize_scene( Viewer& viewer )
//{
//    movingCylinder(viewer);
//    //movingTree(viewer);
//}
//
//int main()
//{
//    glm::vec4 background_color(0.7,0.7,0.7,1);
//	Viewer viewer(1280,720, background_color);
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
//
//void movingCylinder( Viewer& viewer )
//{
//    //Add shader
//    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
//                                                                    "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
//    viewer.addShaderProgram( flatShader );
//
//    //Frame
//    FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
//    viewer.addRenderable(frame);
//
//
//	CylinderMeshRenderablePtr root = std::make_shared<CylinderMeshRenderable>(flatShader, false);
//    glm::mat4 rootOrientation = getRotationMatrix(glm::radians(-90.0f), 1, 0, 0);
//    root -> setGlobalTransform(rootOrientation);
//    glm::mat4 rootScale = getScaleMatrix(0.1,0.1,1.0);
//    root -> setLocalTransform(rootScale);
//
//    CylinderMeshRenderablePtr child1 = std::make_shared<CylinderMeshRenderable>(flatShader, false);
//    CylinderMeshRenderablePtr child2 = std::make_shared<CylinderMeshRenderable>(flatShader, false);
//    CylinderMeshRenderablePtr child3 = std::make_shared<CylinderMeshRenderable>(flatShader, false);
//    CylinderMeshRenderablePtr child4 = std::make_shared<CylinderMeshRenderable>(flatShader, false);
//
//    glm::mat4 chil1Transform = getTranslationMatrix(0,0,1);
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
//    HierarchicalRenderable::addChild(root, child1);
//    HierarchicalRenderable::addChild(root, child2);
//    HierarchicalRenderable::addChild(root, child3);
//    HierarchicalRenderable::addChild(root, child4);
//
//  // add global keyframe without changing root orientation
//
//	// Initial orientation: Rotate -90 degrees around the x-axis
//	glm::quat initialOrientation = glm::angleAxis(glm::radians(-90.0f), glm::vec3(1,0,0));
//	root->setGlobalTransform( GeometricTransformation( glm::vec3{}, initialOrientation, glm::vec3{0.1,0.1,2.0}).toMatrix() );
//
//	// Adding keyframes
//	// Start with the initial orientation (-90 degrees around x-axis)
//	root->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3{}, initialOrientation, glm::vec3{1,1,1}), 0.0);
//
//	// Rotation around the y-axis (over time)
//	glm::quat rotateY1 = glm::angleAxis(glm::radians(45.0f), glm::vec3(0,0,1));
//	glm::quat rotateY2 = glm::angleAxis(glm::radians(90.0f), glm::vec3(0,0,1));
//
//	root->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3{}, initialOrientation * rotateY1, glm::vec3{1,1,1}), 2.0);
//	root->addGlobalTransformKeyframe(GeometricTransformation(glm::vec3{}, initialOrientation * rotateY2, glm::vec3{1,1,1}), 4.0);
//
//    viewer.addRenderable(root);
//    viewer.startAnimation();
//}
//
//void movingTree( Viewer& viewer )
//{
//    //Add shader
//    ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(  "../../sfmlGraphicsPipeline/shaders/flatVertex.glsl",
//                                                                    "../../sfmlGraphicsPipeline/shaders/flatFragment.glsl");
//    viewer.addShaderProgram( flatShader );
//
//    //Frame
//    FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
//    viewer.addRenderable(frame);
//
//    //Tree modeling:
//    //The modeling is hierarchical (setLocalTransform, setGlobalTransform)
//    //The animation is hierarchical too (addGlobalTransformKeyframe, addLocalTransformKeyframe)
//
//    // TODO: Create and animate the main branch
//    CylinderMeshRenderablePtr root = std::make_shared<CylinderMeshRenderable>(flatShader, false);
//    root->setLocalTransform( GeometricTransformation( glm::vec3{}, glm::quat(), glm::vec3{0.1,0.1,2.0}).toMatrix() );
//    // TODO: root->addGlobalTransformKeyframe(...)
//    // ...
//
//    //TODO: Add and animate a child branch
//    CylinderMeshRenderablePtr r1 = std::make_shared<CylinderMeshRenderable>(flatShader, false);
//    //r1->addGlobalTransformKeyframe(...);
//    //r1->addLocalTransformKeyframe(...);
//    // ...
//    //HierarchicalRenderable::addChild( root, r1 );
//    // ...
//
//    // TODO: Add and animate any other child branchs you want
//
//    viewer.addRenderable( root );
//
//    viewer.startAnimation();
//}