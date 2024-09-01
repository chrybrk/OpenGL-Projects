#version 330 core

in vec3 Vcolor;
out vec4 OUTcolor;

uniform vec3 Ucolor;

void main()
{
	OUTcolor = vec4(Ucolor.xyz, 1.0f);
}
