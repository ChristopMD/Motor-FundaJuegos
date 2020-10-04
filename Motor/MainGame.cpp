#include "MainGame.h"
#include <iostream>
#include "Error.h"

using namespace std;

MainGame::MainGame()
//: window(nullptr),witdh(800),height(600), gameState(GameState::PLAY)
{
	witdh = 800;
	height = 600;
	gameState = GameState::PLAY;
	time = 0;
}

MainGame::~MainGame()
{
}

void MainGame::initShaders() {
	glProgram.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	glProgram.AddAtribute("vertexPosition");
	glProgram.AddAtribute("vertexColor");
	glProgram.AddAtribute("vertexUV");
	glProgram.linkShader();
}

void MainGame::run()
{
	init();
	//Agregar cuatos sprites al vector
	for (int i = 0; i < 4; i++)
	{
		Sprite sprite;
		vecSprite.push_back(sprite);
	}

	//Poner las posiciones en los sprites del vector
	int pos = 0;
	for (int x = -1; x < 1; x++)
	{
		for (int y = -1; y < 1; y++)
		{
			vecSprite[pos].init(x, y, 1, 1, "Images/Emil.png");
			pos++;
		}
	}

	update();
}

void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			//cout << event.motion.x <<  " , " << event.motion.y << endl;
			break;
		}
	}
}

void MainGame::init()
{
	window.create("Glory to Mankind!", witdh, height);
	initShaders();

}

void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glProgram.use();
	GLuint timeLocation = glProgram.getUniformLocation("time");
	glUniform1f(timeLocation, time);
	GLuint imageLocation = glProgram.getUniformLocation("image");
	glUniform1i(imageLocation, 0);

	time += 0.002;

	//Un for para dibujar todos los elementes del vector Sprite
	for (int i = 0; i < vecSprite.size(); i++)
	{
		vecSprite[i].draw();
	}
	glProgram.unuse();
	window.swapBuffer();
}

void MainGame::update()
{
	while (gameState != GameState::EXIT) {
		processInput();
		draw();
	}
}
