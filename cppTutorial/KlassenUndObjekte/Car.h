#pragma once
#include <iostream>

class Car
{
private: //m�glichst viel (variablen) private machen, von au�en nur die Methoden sehen
	float position = 0;
	float velocity = 0;
public:
	void move(float time); //kleine Methoden in Header, gro�e in cpp - man kann auch den namen "time" weglassen
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