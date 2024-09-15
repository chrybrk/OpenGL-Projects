#version 330 core

in vec3 Vcolor;
in vec2 VtexCoord;

out vec4 OUTcolor;

uniform sampler2D INtexture;

void main()
{
    OUTcolor = texture(INtexture, VtexCoord) * vec3(0.4f, 0.5f, 0.3f);
}
