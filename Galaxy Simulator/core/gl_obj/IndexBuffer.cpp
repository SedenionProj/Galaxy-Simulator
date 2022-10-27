#include "IndexBuffer.h"

void IndexBuffer::createIndexBuffer(const int size, const unsigned int data[])
{
    count = size;
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &ID);
}

void IndexBuffer::Bind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}
void IndexBuffer::Unbind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}