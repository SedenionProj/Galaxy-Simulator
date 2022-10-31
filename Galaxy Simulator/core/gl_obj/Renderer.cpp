#include "Renderer.h"

void Renderer::DrawElements(const VertexArray& va, const IndexBuffer& ib, const Shader& shader)
{
	va.Bind();
	shader.Bind();
	ib.Bind();
	glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, 0);

}

void Renderer::DrawArray(const VertexArray& va, const Shader& shader, const GLsizei& size) {
	shader.Bind();
	va.Bind();
	glDrawArrays(GL_POINTS, 0, size);
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
