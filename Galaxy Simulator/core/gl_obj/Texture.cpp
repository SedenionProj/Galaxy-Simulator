#include "Texture.h"
#include "../../libs/stb_image.h"

Texture::Texture(const std::string& path)
    : ID(0) 
{
    stbi_set_flip_vertically_on_load(true);
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int width, height, nrChannels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if(!data)
        std::cout << "Failed" << std::endl;
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
};
Texture::~Texture() {

};

void Texture::Bind() const {
    glBindTexture(GL_TEXTURE_2D, ID);
}
void Texture::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}