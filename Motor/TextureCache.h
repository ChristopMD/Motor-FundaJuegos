#pragma once
#include "GLTexture.h"
#include <map>

class TextureCache
{
	std::map<std::string, GLTexture> textureMap;
public:
	TextureCache();
	~TextureCache();
	GLTexture getTexture(std::string texturePath);
};

