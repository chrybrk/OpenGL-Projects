#ifndef __SHADER_H__
#define __SHADER_H__

#include "cmath.h"

typedef struct Shader {
	unsigned int shaderID;
} Shader;

void ShaderBind(Shader *shader);
void ShaderSetInt(Shader *shader, const char *name, int value);
void ShaderSetFloat(Shader *shader, const char *name, float value);
void ShaderSetFloat3(Shader *shader, const char *name, const Vec3 value);

Shader CreateShader(const char *vertexShaderPath, const char *fragmentShaderPath);

#endif // __SHADER_H__
