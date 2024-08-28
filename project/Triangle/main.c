#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../common/IO.h"

#include <stdio.h>
#include <stdbool.h>

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *window = glfwCreateWindow(800, 600, "Triangle", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to init window.\n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		fprintf(stderr, "Failed to init glad.\n");
		glfwTerminate();
		return -1;
	}

	glViewport(0, 0, 800, 600);

	float vertices[] = {
		-.5f, -.5f, .0f,
		.5f,  -.5f, .0f,
		.0f,  .5f,  .0f,
	};

	unsigned int VBO;
	glGenBuffers(1, &VBO);

	const char *vertex_shader_source = read_file("assets/shader/triangle.vs");
	const char *fragment_shader_source = read_file("assets/shader/triangle.fs");

	int success;
	char infoLog[512];

	unsigned int vertex_shader;
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
	glCompileShader(vertex_shader);

	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
		fprintf(stderr, "Failed to compile vertex_shader :: %s\n", infoLog);
	}

	unsigned int fragment_shader;
	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
	glCompileShader(fragment_shader);

	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment_shader, 512, NULL, infoLog);
		fprintf(stderr, "Failed to compile fragment_shader :: %s\n", infoLog);
	}

	unsigned int shader_program = glCreateProgram();

	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);

	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader_program, 512, NULL, infoLog);
		fprintf(stderr, "Failed to link shader_program :: %s\n", infoLog);
	}

	glUseProgram(shader_program);

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.13f, 0.13f, 0.13f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		glUseProgram(shader_program);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	
	return 0;
}
