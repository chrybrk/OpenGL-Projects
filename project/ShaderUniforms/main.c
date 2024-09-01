#include "../common/common.h"
#include "../common/IO.h"
#include "../common/Shader.h"
#include "../common/Window.h"

extern float sinf(float);

int main()
{
	GLFWwindow *window = InitWindow(800, 600, "ShaderUniforms");

	float vertices[] = {
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // top
	};

	unsigned int indices[] = {
		0, 1, 2
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	Shader shaderProgram = CreateShader("assets/shader/vao.buffer.vs", "assets/shader/vao.buffer.fs");

	Vec3 color = { 0.2f, 0.5f, 0.4f };

	while (!glfwWindowShouldClose(window))
	{
		ClearBackground((Color) { 23, 23, 23, 255 });
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		float dt = glfwGetTime();

		// remove comment to enable wireframe mode.
		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		ShaderBind(&shaderProgram);
		ShaderSetFloat3(&shaderProgram, "Ucolor", color);

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		UpdateWindow(window);
	}

	glfwTerminate();
	
	return 0;
}
