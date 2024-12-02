//#include <Viewer.hpp>
//#include <glm/glm.hpp>
//#include "./../include/ShaderProgram.hpp"
//#include "./../include/FrameRenderable.hpp"
//// Do not forget the include
//# include "./../include/CubeRenderable.hpp"
//#include "./../include/IndexedCubeRenderable.hpp"
//
//#define SCR_WIDTH 1024
//#define SCR_HEIGHT 768
//
//
//
//int main( int argc, char* argv[] )
//{
//	// Stage 1: Create the window and its OpenGL context
//    glm::vec4 background_color = glm::vec4(0.8,0.8,0.8,1.0);
//	Viewer viewer(SCR_WIDTH, SCR_HEIGHT, background_color);
//
//	// Compile and link the flat shaders into a shader program
//	std::string vShader = "./../../sfmlGraphicsPipeline/shaders/flatVertex.glsl";
//	std::string fShader = "./../../sfmlGraphicsPipeline/shaders/flatFragment.glsl";
//	ShaderProgramPtr flatShader = std::make_shared<ShaderProgram>(vShader, fShader);
//	// Add the shader to the Viewer
//	viewer.addShaderProgram(flatShader);
//
//
//	FrameRenderablePtr frame = std::make_shared<FrameRenderable>(flatShader);
//	viewer.addRenderable(frame);
//
//	CubeRenderablePtr cube = std::make_shared<CubeRenderable>(flatShader);
//    IndexedCubeRenderablePtr cube2 = std::make_shared<IndexedCubeRenderable>(flatShader);
//
//   	// Add the renderable to the Viewer
//	viewer.addRenderable(cube);
//    viewer.addRenderable(cube2);
//
//    cube->setModelMatrix( getTranslationMatrix(3, 0,0) );
//
//	// Stage 3: Our program loop
//	while( viewer.isRunning() )
//	{
//	    viewer.handleEvent(); 	// user interactivity (keyboard/mouse)
//	    viewer.draw();		// rasterization (write in framebuffer)
//	    viewer.display();		// refresh window
//	}
//
//	return EXIT_SUCCESS;
//}
//
