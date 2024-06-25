#pragma once
#include "Core/Core.h"

class Galaxy : public WindowApp {

public:
	Galaxy() : WindowApp(1920, 1080) {}
	void init() override;

private:
	void reInit();
	void mainLoop(float dt) override;
	void inputHandler(float dt);
	void DrawGUI(float dt);

private:
	void savePresets(const std::string& name);
	void loadPresets(const std::string& name);
	void deletePreset(const std::string& name);
	void updatePresetList();

private:
	VertexArray va;
	Buffer ssbo;
	Shader shader;
	Shader Cshader;
	
	glm::mat4 view;
	glm::mat4 projection;
	std::vector<glm::vec4> vertices;
	
	bool fullscrean = true;
	bool hold = false;

private:
	char preset[15] = "default";
	char presetList[100];

	int number = 100000;
	float accuracy = 0.01f;
	float scale = 1;

	float gravity = 1e-5;
	float csmooth = 1e-1;
	float iniVel = 0.5f;
	float blackHole = 1;

	glm::vec3 hue = glm::vec3(1, 1, 1);

	float speedHack = 1.f;
};