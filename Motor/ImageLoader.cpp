#include "ImageLoader.h"
#include "IOManager.h"
#include "Error.h"
#include "picoPNG.h"

GLTexture ImageLoader::loadPNG(string filePath)
{
	vector<unsigned char>in;
	vector<unsigned char>out;
	unsigned long height, width;
	GLTexture texture = {};
	if (!IOManager::readFileBuffer(filePath, in))
	{
		fatalError("Can't read " + filePath);
	}
	int errorCode = decodePNG(out, width, height, &(in[0]), in.size());
	if (errorCode != 0)
	{
		fatalError("Can't decode image with error " + std::to_string(errorCode));
	}
	//generar textura con id
	glGenTextures(1, &(texture.id));
	//comenzar a crear la textura
	glBindTexture(GL_TEXTURE_2D, texture.id);
	//Que propiedades tendra la textura
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));

	//Permite que la imagen se pueda estirar en x
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//Permite que la imagen se pueda estirar en Y
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	//Permite que la imagen no se distorciones a lo lejos buscar ejemplo de
	//ajedrez
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	texture.widht = width;
	texture.height = height;

	return texture;
}
