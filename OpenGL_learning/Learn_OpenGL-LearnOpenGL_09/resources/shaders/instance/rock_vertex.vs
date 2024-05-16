#version 420 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

layout (location = 5) in mat4 aModel;

out VS_OUT {
    vec2 texCoord;
} vs_out;

uniform mat4 matView;
uniform mat4 matProjection;

void main()
{
	gl_Position = matProjection * matView * aModel * vec4(aPos, 1.0);
	vs_out.texCoord = aTexCoord;
}