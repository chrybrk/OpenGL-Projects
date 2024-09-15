#include "Window.h"

GLFWwindow *InitWindow(int width, int height, const char *title)
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to init window.\n");
		glfwTerminate();
		return NULL;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		fprintf(stderr, "Failed to init glad.\n");
		glfwTerminate();
		return NULL;
	}

	glViewport(0, 0, 800, 600);

	return window;
}

void ClearBackground(Color color)
{
	glClearColor(
			(float)(color.r / 255.0f), 
			(float)(color.g / 255.0f), 
			(float)(color.b / 255.0f), 
			(float)(color.a / 255.0f)
	);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void UpdateWindow(GLFWwindow *window)
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}
