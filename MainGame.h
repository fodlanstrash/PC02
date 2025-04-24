#pragma once
#include <SDL3/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include "Sprite.h"

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
	SDL_Window* window;
	void init();
	void processInput();
public:
	MainGame();
	~MainGame();
	GameState gameState;
	void run();
	void update();
	void draw();
};

