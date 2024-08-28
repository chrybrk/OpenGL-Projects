#version 330 core

in vec3 Vcolor;
out vec4 OUTcolor;

void main()
{
	OUTcolor = vec4(Vcolor.xyz * 0.1f + 0.1f, 1.0f);
}
