#include "../common/common.h"
#include "../common/Graphic.h"
#include "../common/IO.h"
#include "../common/Shader.h"
#include "../common/Window.h"


int main()
{
	GLFWwindow *window = InitWindow(800, 600, "Texture");
	glEnable(GL_DEPTH_TEST);

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
	Mat4x4 proj = Mat4x4Prespective(DEG2RAD * 45.0f, 800.0f / 600.0f, 0.1f, 100.0f);

	// camera
	Vec3 cameraPosition = (Vec3) { 0.0f, 0.0f, 3.0f };
	Vec3 cameraFront = (Vec3) { 0.0f, 0.0f, -1.0f };
	Vec3 cameraUp = (Vec3) { 0.0f, 1.0f, 0.0f };

	float dt = 0.0f;
	float lf = 0.0f;

	while (!glfwWindowShouldClose(window))
	{
		float cf = glfwGetTime();
		dt = cf - lf;
		lf = cf;

		const float cameraSpeed = 2.5f * dt;

		ClearBackground((Color) { 23, 23, 23, 255 });
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			cameraPosition = Vec3Add(cameraPosition, Vec3Scale(cameraFront, cameraSpeed));

		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			cameraPosition = Vec3Sub(cameraPosition, Vec3Scale(cameraFront, cameraSpeed));

		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			cameraPosition = Vec3Sub(cameraPosition, Vec3Scale(Vec3Normalize(Vec3CrossProduct(cameraFront, cameraUp)), cameraSpeed));

		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			cameraPosition = Vec3Add(cameraPosition, Vec3Scale(Vec3Normalize(Vec3CrossProduct(cameraFront, cameraUp)), cameraSpeed));

		model = Mat4x4Rotate((Vec3){ 0.5f, 1.0f, 0.0f}, DEG2RAD * 50.0f * cf);
		view = Mat4x4LookAt(cameraPosition, Vec3Add(cameraPosition, cameraFront), cameraUp);

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