module;
#include <GLFW/glfw3.h>

module Window_creator;

auto Window_creator::create_window() -> GLFWwindow*
{
	if (!glfwInit()) { return nullptr;  }

	// Provide target OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	// Specify wanting only the modern functionality
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/* Create a windowed mode window and its OpenGL context */
	auto window = glfwCreateWindow(1280, 720, "GraphicsProject", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return nullptr;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	return window;
}