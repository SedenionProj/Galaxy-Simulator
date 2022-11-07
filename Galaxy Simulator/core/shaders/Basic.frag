#version 430 core
out vec4 FragColor;

in float color;

void main()
{
	FragColor = vec4(1.f, color*0.1f, 1.f, 1.0f);
}