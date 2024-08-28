#version 330 core

layout (location = 0) in vec3 INposition;
out vec3 OUTposition;

void main() {
	OUTposition = INposition;
	gl_Position = vec4(INposition.x, INposition.y, INposition.z, 1.0f);
}
