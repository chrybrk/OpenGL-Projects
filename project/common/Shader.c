#include "Shader.h"
#include "common.h"
#include "IO.h"

void CheckShader(unsigned int shader, const char *message)
{
	int status;
	char info[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if( !status )
	{
		glGetShaderInfoLog(shader, 512, NULL, info);
		fprintf(stderr, "%s :: %s\n", message, info);
	}
}

unsigned int CreateVetexShader(const char *vertexShaderSource)
{
	unsigned int shader;
	shader = glCreateShader(GL_VERTEX_SHADER);

	glShaderSource(shader, 1, &vertexShaderSource, NULL);
	glCompileShader(shader);

	CheckShader(shader, "Failed to compile vertex shader");

	return shader;
}

unsigned int CreateFragmentShader(const char *fragmentShaderSource)
{
	unsigned int shader;
	shader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(shader, 1, &fragmentShaderSource, NULL);
	glCompileShader(shader);

	CheckShader(shader, "Failed to compile fragment shader");

	return shader;
}

unsigned int CreateShader(const char *vertexShaderPath, const char *fragmentShaderPath)
{
	const char *vertexShaderSource = read_file(vertexShaderPath);
	const char *fragmentShaderSource = read_file(fragmentShaderPath);

	// check if files exist.
	if (!vertexShaderSource || !fragmentShaderSource)
		return -1;

	// compile vertex and fragment shader 
	unsigned int vertexShaderStatus = CreateVetexShader(vertexShaderSource);
	unsigned int fragmentShaderStatus = CreateFragmentShader(fragmentShaderSource);

	unsigned int program = glCreateProgram();

	glAttachShader(program, vertexShaderStatus);
	glAttachShader(program, fragmentShaderStatus);
	glLinkProgram(program);

	int status;
	char info[512];

	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if ( !status )
	{
		glGetShaderInfoLog(program, 512, NULL, info);
		fprintf(stderr, "Failed to linke shader program :: %s\n", info);
	}

	glUseProgram(program);

	glDeleteShader(vertexShaderStatus);
	glDeleteShader(fragmentShaderStatus);

	return program;
}
