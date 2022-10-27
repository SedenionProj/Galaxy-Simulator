#include "galaxy.h"

float vertices[] = {
	 0.5f,  0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	-0.5f,  0.5f, 0.0f
};
unsigned int indices[] = {
	0, 1, 3,
	1, 2, 3
};

class Galaxy: public app {
	VertexArray va;
	IndexBuffer ib;
	Renderer renderer;
	Shader shader;
public:
	void init() override {
		shader.createShader("core/shaders/Basic.vert", "core/shaders/Basic.frag");

		va.createVertexArray();
		VertexBuffer vb(sizeof(vertices), vertices);
		va.AddBuffer(vb, 3, 3, 0);
		ib.createIndexBuffer(sizeof(indices), indices);

		va.Unbind();
		vb.Unbind();
		shader.Unind();
		ib.Unbind();
	
	}

	void mainLoop() override {
		renderer.Draw(va, ib, shader);
	}
};

int main(void){
	std::unique_ptr<Galaxy> galaxy = std::make_unique<Galaxy>();
	galaxy->init();
	galaxy->start();
}