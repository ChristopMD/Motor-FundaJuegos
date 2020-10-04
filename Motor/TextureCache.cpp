#include "TextureCache.h"
#include "ImageLoader.h"
#include <iostream>
using namespace std;
TextureCache::TextureCache()
{
}

TextureCache::~TextureCache()
{
}

GLTexture TextureCache::getTexture(std::string texturePath)
{
	//primera forma
	//std::map<std::string, GLTexture>::iterator textureCacheIterator = textureMap.find(texturePath);
	
	//segunda forma
	auto textureCacheIterator = textureMap.find(texturePath);
	cout << "buscando " << texturePath << endl;
	if (textureCacheIterator == textureMap.end())
	{
		GLTexture texture = ImageLoader::loadPNG(texturePath);

		//primera forma
		//std::pair<std::string, GLTexture> newPair(texturePath, texture);
		//textureMap.insert(newPair);

		//segunda forma
		textureMap[texturePath] = texture;
		return texture;
	}
	return textureCacheIterator->second;
}
