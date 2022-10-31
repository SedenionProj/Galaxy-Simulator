#pragma once
#include <GL/glew.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

struct Renderer {
	void DrawElements(const VertexArray& va, const IndexBuffer& ib, const Shader& shader);
	void DrawArray(const VertexArray& va, const Shader& shader, const GLsizei& size);
	void Clear();
};