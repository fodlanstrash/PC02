#include "MainGame.h"



MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

void MainGame::run()
{
	witdh = 800;
	height = 600;
	gameState = GameState::PLAY;
	init();
	sprite.init(-1, -1, 1, 1);
	update();
}

void MainGame::init()
{
	SDL_Init(SDL_INIT_HAPTIC | SDL_INIT_CAMERA | SDL_INIT_EVENTS);
	window = SDL_CreateWindow("Hola", witdh, height, SDL_WINDOW_OPENGL);

	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
	
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.4f, 1.0f, 1.0f);
}

void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_EVENT_QUIT:
			gameState = GameState::EXIT;
			break;
		case SDL_EVENT_MOUSE_MOTION:
			//cout << "posicion x " << event.motion.x << " posicion y " 
				//			<< event.motion.y << endl;
			break;
		}
	}
}

void MainGame::update()
{
	while (gameState != GameState::EXIT) {
		processInput();
		draw();
	}
}

void MainGame::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	sprite.draw();
	SDL_GL_SwapWindow(window);
}
