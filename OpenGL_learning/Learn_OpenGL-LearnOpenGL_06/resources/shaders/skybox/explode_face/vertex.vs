#version 420 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) in vec3 aNormal;

out VS_OUT {
	vec3 Normal;
    vec2 TexCoord;
} vs_out;

uniform mat4 matModel;

void main()
{
	vs_out.Normal   =   aNormal;
	vs_out.TexCoord = aTexCoord;

	gl_Position = matModel * vec4(aPos,1.0);
}