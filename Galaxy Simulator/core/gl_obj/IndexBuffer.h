#pragma once
#include <GL/glew.h>

class IndexBuffer {
private:
	unsigned int ID;
	unsigned int count;
public:
	void createIndexBuffer(const int size, const unsigned int data[]);
	~IndexBuffer();

	void Bind() const;
	void Unbind() const;
	inline unsigned int GetCount() const { return count; }

};