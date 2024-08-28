#include "../common/common.h"
#include "../common/IO.h"
#include "../common/Shader.h"
#include "../common/Window.h"

int main()
{
	GLFWwindow *window = InitWindow(800, 600, "TriangleWithEBO");

	float vertices[] = {
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
	};

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};
	
	unsigned int VBO;
	glGenBuffers(1, &VBO);

	unsigned int EBO;
	glGenBuffers(1, &EBO);

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	unsigned int shaderProgram = CreateShader("assets/shader/color.interpolate.vs", "assets/shader/color.interpolate.fs");

	while (!glfwWindowShouldClose(window))
	{
		ClearBackground((Color) { 23, 23, 23, 255 });
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		// remove comment to enable wireframe mode.
		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		UpdateWindow(window);
	}

	glfwTerminate();
	
	return 0;
}
