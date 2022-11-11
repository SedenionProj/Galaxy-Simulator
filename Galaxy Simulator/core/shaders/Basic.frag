#version 430 core
out vec4 FragColor;

in float color;
uniform vec3 hue;

void main()
{
	FragColor = vec4(hue.x, color+hue.y, hue.z, 1.0f);
}