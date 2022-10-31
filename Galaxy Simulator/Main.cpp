#include "galaxy.h"

class Galaxy: public app {
protected:
	VertexArray va;
	Buffer ssbo;
	Renderer renderer;
	Shader shader;
	Shader Cshader;
	std::vector<float> vertices;
	int number = 20000;
public:
	void init() override {
		for (float i = 0; i < 20000; i++) {
			vertices.push_back((2*i / number) - 1);
			vertices.push_back((float)((rand() % 200) - 100) / 100);
			vertices.push_back(1);
		}

		va.createVertexArray();
		ssbo.CreateBuffer(sizeof(float)*vertices.size(), vertices, GL_SHADER_STORAGE_BUFFER, GL_DYNAMIC_COPY);

		shader.createVFShader("core/shaders/Basic.vert", "core/shaders/Basic.frag");
		Cshader.createCShader("core/shaders/compute.glsl");

		va.Unbind();
		ssbo.Unbind(GL_SHADER_STORAGE_BUFFER);
		shader.Unind();	
	}

	void mainLoop() override {
		Cshader.useCompute(ssbo, vertices.size() / 128);
		va.AddBuffer(ssbo,0, GL_ARRAY_BUFFER, 4, 4, 0);
		renderer.DrawArray(va, shader, vertices.size());
	}
};

int main(void){
	std::unique_ptr<Galaxy> galaxy = std::make_unique<Galaxy>();
	galaxy->start();
}