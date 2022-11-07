#include "galaxy.h"

class Galaxy: public app {
protected:

	VertexArray va;
	Buffer ssbo;
	Renderer renderer;
	Shader shader;
	Shader Cshader;
	std::vector<glm::vec4> vertices;
	float speedHack = 1.f;
	int number = 100000;
	float accuracy = 0.01f;
	float iniVel = 0.5f;
	float gravity = 1e-5;
	float csmooth = 1e-1;
	float scale = 1;
public:
	void init() override {
		vertices.clear();
		for (float i = 0; i < number; i++) {
			float angle = (float)(rand() % 62831852)/1000;
			float len = scale*(float)(rand() % 1000)/1000;
			vertices.push_back(glm::vec4(cos(angle)*len, 1*(float)(rand() % 100) / 1000, sin(angle) * len,0));
			vertices.push_back(glm::vec4(-sin(angle), 0, cos(angle), 0) * iniVel);
			vertices.push_back(glm::vec4(0, 0, 0, 0)- glm::vec4(cos(angle) * len*100,0, sin(angle) * len*100, 0));
			//vertices.push_back(glm::vec4(0, 0, 0, 0));
		}

		va.createVertexArray();
		ssbo.CreateBuffer(sizeof(glm::vec4)*vertices.size(), vertices, GL_SHADER_STORAGE_BUFFER, GL_DYNAMIC_COPY);

		shader.createVFShader("core/shaders/Basic.vert", "core/shaders/Basic.frag");
		Cshader.createCShader("core/shaders/compute.glsl");

		va.Unbind();
		ssbo.Unbind(GL_SHADER_STORAGE_BUFFER);
		shader.Unind();	
	}

	void mainLoop(float& dt) override {

		ImGui::Begin("parametres");
		ImGui::Text("simulation");
		if (ImGui::Button("Restart")) { init(); }
		ImGui::SliderInt("nombre de particle", &number, 128, 5000000);
		ImGui::InputInt("manuelle", &number);
		ImGui::InputFloat("precision", &accuracy, 0.00001, NULL, "%.5f");
		ImGui::Text("physique");
		ImGui::InputFloat("gravite", &gravity, 0.00000001f, NULL, "%.8f");
		ImGui::InputFloat("csmooth", &csmooth, 0.0000001f, NULL, "%.8f");
		ImGui::InputFloat("velocite", &iniVel, 0.001f, NULL, "%.4f");
		ImGui::SliderFloat("speedHack", &speedHack, 0, 1000);
		ImGui::SliderFloat("scale", &scale, 0, 100);
		ImGui::End();

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			cameraPos += glm::normalize(glm::vec3(1.0, 0.0, 1.0) * cameraFront) * dt * speedHack;
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			cameraPos -= glm::normalize(glm::vec3(1.0, 0.0, 1.0) * cameraFront) * dt * speedHack;
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * dt * speedHack;
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * dt * speedHack;
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
			cameraPos += cameraUp * dt * speedHack;
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
			cameraPos -= cameraUp * dt * speedHack;
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
			glfwSetCursorPosCallback(window, NULL);
		}
			
		if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
		{
			glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
			glfwSetCursorPosCallback(window, mouse_callback);

		}
		glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
		glm::mat4 projection = glm::perspective(glm::radians(110.0f), (float)width / (float)height, 0.0001f, 20000.0f);

		Cshader.useCompute(ssbo, floor(vertices.size() / 128.f));
		Cshader.setFloat("dt", dt);
		Cshader.setFloat("accuracy", accuracy);
		Cshader.setFloat("gravity", gravity);
		Cshader.setFloat("csmooth", csmooth);
		va.AddBuffer(ssbo,0, GL_ARRAY_BUFFER, 3, 12, 0);
		va.AddBuffer(ssbo, 1, GL_ARRAY_BUFFER, 3, 12, 4);
		shader.Bind();
		shader.setMat4("projection", projection);
		shader.setMat4("view", view);
		renderer.DrawArray(va, shader, number);

		
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
};

int main(void){
	std::unique_ptr<Galaxy> galaxy = std::make_unique<Galaxy>();
	galaxy->start();
}