#include <GLFW/glfw3.h>
import Exception;
import Window_creator;

int main()
{
	auto window = Window_creator::create_window();
	if (!window) { return -1; }

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}