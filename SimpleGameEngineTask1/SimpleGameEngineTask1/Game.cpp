#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::this_thread; // -> so we can use sleep_for
using namespace std::chrono; // -> so we can use nanoseconds, miliseconds inside sleep_for

Game::Game(int maxComponents)
{
	componentCount = 0;
	components = new GameComponent*[maxComponents];
}

void Game::Add(GameComponent* gameComponent)
{
	components[componentCount] = gameComponent;
	componentCount++;
}

void Game::SetInitialise(FP init)
{
	initialise = init;
}

void Game::SetTerminate(FP term)
{
	terminate = term;
}

void Game::Run()
{
	initialise();

	for (int i = 0; i < 5; i++)
	{
		// Pause the current thread for a second -> 1000ms
		sleep_for(milliseconds(TICKS_1000MS));

		for (int i = 0; i < componentCount; i++)
		{
			// Get the local time
			time_t t = time(0);
			tm* time_t = localtime(&t);

			components[i]->Update(time_t);
		}
	}

	terminate();
}