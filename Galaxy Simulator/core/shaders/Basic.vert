#version 430 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 vel;

uniform mat4 view;
uniform mat4 projection;

out float color;

void main()
{
	color = length(vel);
	gl_Position = projection*view*vec4(pos, 1.0);
}