#include "stdafx.h"
#include "GameComponent.h"
#include "Game.h"
#include "DrawableGameComponent.h"
#include <iostream>

using namespace std;

void Initialise()
{
	cout << "Initialising Game" << endl;
}

void Terminate()
{
	cout << "Terminating Game" << endl;
}

int GameComponent::instances = 0;

int main()
{
	Game* game = new Game(10);

	game->SetInitialise(Initialise);
	game->SetTerminate(Terminate);

	game->Add(new GameComponent());
	game->Add(new DrawableGameComponent(0, 0));

	game->Run();

	return 0;
}