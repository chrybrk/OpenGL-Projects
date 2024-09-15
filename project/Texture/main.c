#include "../common/common.h"
#include "../common/Graphic.h"
#include "../common/IO.h"
#include "../common/Shader.h"
#include "../common/Window.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../vendor/stb/stb_image.h"

int main()
{
	GLFWwindow *window = InitWindow(800, 600, "Texture");

	int width, height, nrChannels;
	unsigned char *data = stbi_load("assets/image/metalbox_diffuse.png", &width, &height, &nrChannels, 0);
	if (data == NULL) printf("Failed to load image.\n");

	unsigned int texture;
	glGenTextures(1, &texture);

	glBindTexture(GL_TEXTURE_2D, texture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);

	float vertices[] = {
		// positions 					   // colors 						// texture coords
		 0.5f,   0.5f,   0.0f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f, // top right
		 0.5f,   -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
		-0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // top left
	};

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	ShaderElementKind shaderElementKinds[] = { f3, f3, f2 };
	ShaderElement SE = InitShaderElement(shaderElementKinds, sizeof(shaderElementKinds) / sizeof(shaderElementKinds[0]), GL_FLOAT, GL_FALSE);

	VertexBuffer vbo;
	ElementBuffer ebo;
	VertexArray vao;

	vao = CreateVertexArray();
	VertexArrayBind(&vao);

	vbo = CreateVertexBuffer(vertices, sizeof(vertices), STATIC);
	ebo = CreateElementBuffer(indices, sizeof(indices), STATIC);

	VertexBufferSetLayout(&vbo, &SE);
	VertexArrayPointers(&vao, &vbo);

	Shader shaderProgram = CreateShader("assets/shader/texture.vs", "assets/shader/texture.fs");

	while (!glfwWindowShouldClose(window))
	{
		ClearBackground((Color) { 23, 23, 23, 255 });
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		float dt = glfwGetTime();

		// remove comment to enable wireframe mode.
		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		ShaderBind(&shaderProgram);

		glBindTexture(GL_TEXTURE_2D, texture);

		VertexArrayBind(&vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		UpdateWindow(window);
	}

	glfwTerminate();
	
	return 0;
}