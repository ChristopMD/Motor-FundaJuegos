#include "ResourceManager.h"

//apunta a la variable estatica textureCache declarada en el .h
//para poder utilizarla
TextureCache ResourceManager::textureCache;
GLTexture ResourceManager::getTexture(std::string texturePath)
{
	return textureCache.getTexture(texturePath);
}
