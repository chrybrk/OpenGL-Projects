#version 330 core

in vec3 OUTposition;
out vec4 OUTcolor;

void main()
{
	OUTcolor = vec4(OUTposition.xyz * .5f + .5f, 1.0f);
}
