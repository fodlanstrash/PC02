#pragma once
#include <SDL3/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include "Sprite.h"
#include "GLSProgram.h"

using namespace std;

enum class GameState {
	PLAY,EXIT
};

class MainGame
{
private:
	int witdh;
	int height;
	Sprite sprite;
	GLSProgram program;
	SDL_Window* window;
	void init();
	void processInput();
	void initShaders();
public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void update();
	void draw();
};

