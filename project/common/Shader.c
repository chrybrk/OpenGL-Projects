#include "Shader.h"
#include "common.h"
#include "IO.h"

/*
 * float 	-> 4
 * int 		-> 4
 * unsigned int 	-> 4
*/

unsigned int ShaderGetUniformLocation(unsigned int program, const char *name)
{
	unsigned int result = glGetUniformLocation(program, name);

	if (result)
		fprintf(stderr, "[ERROR]: Failed to retrive `%s` uniform from shader.\n", name);

	return result;
}

void ShaderBind(Shader *shader)
{
	glUseProgram(shader->shaderID);
}

void ShaderSetInt(Shader *shader, const char *name, int value)
{
	glUniform1i(ShaderGetUniformLocation(shader->shaderID, name), value);
}

void ShaderSetFloat(Shader *shader, const char *name, float value)
{
	glUniform1f(ShaderGetUniformLocation(shader->shaderID, name), value);
}

void ShaderSetFloat3(Shader *shader, const char *name, const Vec3 value)
{
	glUniform3f(ShaderGetUniformLocation(shader->shaderID, name), value.x, value.y, value.z);
}

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

Shader CreateShader(const char *vertexShaderPath, const char *fragmentShaderPath)
{
	const char *vertexShaderSource = read_file(vertexShaderPath);
	const char *fragmentShaderSource = read_file(fragmentShaderPath);

	// check if files exist.
	if (!vertexShaderSource || !fragmentShaderSource)
	{
		printf("shader_err: I think, you passed NULL in file parameters.\n");

		return (Shader) { 
			-1
		};
	}

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

	return (Shader) { 
		program
	};
}