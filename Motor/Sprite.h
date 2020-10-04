#pragma once
#include <GLEW/glew.h> //GLEW O GL
#include "GLTexture.h"
#include <string>

using namespace std;
class Sprite
{
private:
	float x;
	float y;
	int width;
	int height;
	GLuint vboID;
	GLTexture glTexture;
public:
	Sprite();
	~Sprite();
	void init(float _x, float _y, int _witdh, int _height, string texturePath);
	void draw();
};