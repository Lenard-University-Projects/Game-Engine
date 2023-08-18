#pragma once
#include "GameComponent.h"

class DrawableGameComponent : public GameComponent
{
	enum Direction { Left, Right, Up, Down };

public:
	DrawableGameComponent(int x, int y);

public:
	Direction direction;

	const int SCREEN_HEIGHT = 20;
	const int SCREEN_WIDTH = 80;

	void Update(const tm* eventTime) override;

private:
	void ChangeDirection();
	void Draw();

	int x;
	int y;
};