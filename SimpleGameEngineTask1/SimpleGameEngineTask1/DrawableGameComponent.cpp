#include "stdafx.h"
#include "DrawableGameComponent.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

DrawableGameComponent::DrawableGameComponent(int x, int y)
{
	this->x = x;
	this->y = y;

	direction = Direction::Right;
}

void DrawableGameComponent::Update(const tm * eventTime)
{
	GameComponent::Update(eventTime);

	switch (direction)
	{
	case DrawableGameComponent::Left:
		if (x > 0)
			x -= 1;

		break;
	case DrawableGameComponent::Right:
		if (x < SCREEN_WIDTH)
			x += 1;

		break;
	case DrawableGameComponent::Up:
		if (y < SCREEN_HEIGHT)
			y += 1;

		break;
	case DrawableGameComponent::Down:
		if (y > 0)
			y -= 1;

		break;
	}

	Draw();
	ChangeDirection();
}

void DrawableGameComponent::ChangeDirection()
{
	Direction currentDirection = direction;

	int rdmNum;
	srand(time(NULL)); // Generate a new seed

	while (currentDirection == direction)
	{
		// Generate a random value from 0 to 4
		rdmNum = rand() % 4 + 0;

		switch (rdmNum)
		{
		case 0:
			direction = Direction::Left;
			break;
		case 1:
			direction = Direction::Right;
			break;
		case 2:
			direction = Direction::Up;
			break;
		case 3:
			direction = Direction::Down;
			break;
		}
	}

	/*Direction currentDirection = direction;

	srand(time(NULL));

	int allNums[4] = { 0, 1, 2, 3 };
	int currNumb = direction;
	int rdmNum = rand() % 4;

	while (currNumb == allNums[rdmNum])
	rdmNum = rand() % 4;

	switch (allNums[rdmNum])
	{
	case 0:
	direction = Direction::Left;
	break;
	case 1:
	direction = Direction::Right;
	break;
	case 2:
	direction = Direction::Up;
	break;
	case 3:
	direction = Direction::Down;
	break;
	}*/
}

void DrawableGameComponent::Draw()
{
	string dir = "";

	switch (direction)
	{
	case DrawableGameComponent::Left:
		dir = "Left";
		break;
	case DrawableGameComponent::Right:
		dir = "Right";
		break;
	case DrawableGameComponent::Up:
		dir = "Up";
		break;
	case DrawableGameComponent::Down:
		dir = "Down";
		break;
	}

	cout << dir << " - " << "X: " << x << " " << "Y: " << y << endl;
}
