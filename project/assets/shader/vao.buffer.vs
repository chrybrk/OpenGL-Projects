#version 330 core

layout (location = 0) in vec3 INposition;
layout (location = 1) in vec3 INcolor;

out vec3 Vcolor;

void main() {
	Vcolor = INcolor;
	gl_Position = vec4(INposition.xyz, 1.0f);
}
