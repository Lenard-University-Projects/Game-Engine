#pragma once

class GameComponent
{
private:
	int id;
	static int instances;

public:
	GameComponent();

public:
	virtual void Update(const tm* eventTime);
};

