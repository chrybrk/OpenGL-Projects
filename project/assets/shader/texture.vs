#version 330 core

layout (location = 0) in vec3 INposition;
layout (location = 1) in vec2 INtexCoord;

out vec2 VtexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main() {
    VtexCoord = INtexCoord;
	gl_Position = proj * view * model * vec4(INposition.xyz, 1.0f);
}
