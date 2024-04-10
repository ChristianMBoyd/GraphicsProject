module;
#include <GLFW/glfw3.h>

export module Window_creator;
import std;

export class Window_creator
{
public:
	static auto create_window() -> GLFWwindow*;
};