#pragma once
#include <SDL/SDL.h>
#include <GLEW/glew.h>
#include <vector>
#include "Sprite.h"
#include "GLProgram.h"
#include "Window.h"
enum class GameState
{
	PLAY, EXIT
};

class MainGame
{
private:
	int witdh;
	int height;
	GLProgram glProgram;
	Window window;
	//Crear Vector de Sprites
	vector<Sprite> vecSprite;
	void processInput();
	void init();
	void initShaders();
	float time;
public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void draw();
	void update();
};
