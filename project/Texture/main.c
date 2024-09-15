#include "../common/common.h"
#include "../common/Graphic.h"
#include "../common/IO.h"
#include "../common/Shader.h"
#include "../common/Window.h"


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
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 1.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, -0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, -0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, -0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f, 0.0f, 1.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f,
		0.5f, 0.5f, -0.5f, 1.0f, 1.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		0.5f, 0.5f, 0.5f, 1.0f, 0.0f,
		-0.5f, 0.5f, 0.5f, 0.0f, 0.0f,
		-0.5f, 0.5f, -0.5f, 0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 3,
		1, 2, 3
	};

	ShaderElementKind shaderElementKinds[] = { f3, f2 };
	ShaderElement SE = InitShaderElement(shaderElementKinds, sizeof(shaderElementKinds) / sizeof(shaderElementKinds[0]), GL_FLOAT, GL_FALSE);

	VertexBuffer vbo;
	// ElementBuffer ebo;
	VertexArray vao;

	vao = CreateVertexArray();
	VertexArrayBind(&vao);

	vbo = CreateVertexBuffer(vertices, sizeof(vertices), STATIC);
	// ebo = CreateElementBuffer(indices, sizeof(indices), STATIC);

	VertexBufferSetLayout(&vbo, &SE);
	VertexArrayPointers(&vao, &vbo);

	Shader shaderProgram = CreateShader("assets/shader/texture.vs", "assets/shader/texture.fs");

	Mat4x4 model = Mat4x4Identity();

	Mat4x4 view = Mat4x4Identity();
	view = Mat4x4Translation((Vec3) { 0.0f, 0.0f, -3.0f});

	Mat4x4 proj = Mat4x4Prespective(DEG2RAD * 45.0f, 800.0f / 600.0f, 0.1f, 10.0f);

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window))
	{
		ClearBackground((Color) { 23, 23, 23, 255 });
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		float dt = glfwGetTime();

		model = Mat4x4Rotate((Vec3){ 0.5f, 1.0f, 0.0f}, DEG2RAD * 50.0f * dt);

		// remove comment to enable wireframe mode.
		// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

		ShaderBind(&shaderProgram);

		ShaderSetMat4(&shaderProgram, "model", model);
		ShaderSetMat4(&shaderProgram, "view", view);
		ShaderSetMat4(&shaderProgram, "proj", proj);

		glBindTexture(GL_TEXTURE_2D, texture);

		VertexArrayBind(&vao);
		// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		VertexArrayUnbind(&vao);

		UpdateWindow(window);
	}

	glfwTerminate();
	
	return 0;
}