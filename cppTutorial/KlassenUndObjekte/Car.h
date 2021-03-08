#pragma once
#include <iostream>

class Car
{
private: //möglichst viel (variablen) private machen, von außen nur die Methoden sehen
	float position = 0;
	float velocity = 0;
public:
	void move(float time); //kleine Methoden in Header, große in cpp - man kann auch den namen "time" weglassen
	void accelerate(float newVelocity);
	void brake();
	bool isMoving();

	float getPosition() //setter und getter
	{
		return position;
	}

	void setPosition(float position)
	{
		if (position > 0)
			this->position = position;
	}
};