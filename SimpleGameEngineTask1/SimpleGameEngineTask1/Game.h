#pragma once
#include "GameComponent.h"

typedef void(*FP)();

class Game
{
private:
	int componentCount;
	GameComponent** components;

	FP initialise;
	FP terminate;

	const int TICKS_1000MS = 1000;

public:
	Game(int maxComponents);

public:
	void Add(GameComponent* gameComponent);

	void SetInitialise(FP init);
	void SetTerminate(FP term);

	void Run();
};