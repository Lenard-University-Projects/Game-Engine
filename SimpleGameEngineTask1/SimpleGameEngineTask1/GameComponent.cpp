#include "stdafx.h"
#include "GameComponent.h"
#include <iostream>
#include <string>

using namespace std;

GameComponent::GameComponent()
{
	instances++;
	id = instances;
}

void GameComponent::Update(const tm * eventTime)
{
	// Display the ID and hour,min and sec which were provided from in the Run function
	cout << "ID: " << id << " " << "Updated @ " << eventTime->tm_hour << ":" << eventTime->tm_min << ":" << eventTime->tm_sec << endl;
}
