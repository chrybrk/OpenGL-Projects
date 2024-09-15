#version 330 core

layout (location = 0) in vec3 INposition;
layout (location = 1) in vec3 INcolor;
layout (location = 2) in vec2 INtexCoord;

out vec3 Vcolor;
out vec2 VtexCoord;

void main() {
	Vcolor = INcolor;
    VtexCoord = INtexCoord;
	gl_Position = vec4(INposition.xyz, 1.0f);
}
