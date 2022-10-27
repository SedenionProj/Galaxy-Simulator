#pragma once
#include <GL/glew.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

struct Renderer {
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	void Clear();
};