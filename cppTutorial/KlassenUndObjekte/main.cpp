#include <iostream>
#include "Car.h"

class Pen //daten und funktion in Klasse zusammenpacken, eine Art Schablone
{
private : //nur innerhalb der Klasse zugreifen
	std::string color; //membervariablen
	int size;
public: //auch von außerhalb Zugriff

	Pen(std::string color = "red", int size = 27) //constructor wird immer aufgerufen wenn wir einen neuen pen haben
	{
		this->color = color;
		this->size = size;
	}

	//Pen(float) //Überladung von Constructoren

	void draw(std::string shape)
	{
		std::cout << "Drawing a " << color.c_str() << " " << shape.c_str() << " with size " << this->size << std::endl;
	}
};

int main()
{
	/*Pen pen("yellow", 42); //Klammern nur wenn Parameter übergeben werden sollen
	pen.draw("triangle");
	pen.draw("sqaure");	//mehrmals eine Methode aufrufen
	Pen pen2("green", 27); //weiterer Pen hinzufügen
	pen2.draw("line");*/

	Car car;
	car.accelerate(2.7f);
	car.move(3.0f);
	std::cout << "isMoving:" << car.isMoving() << std::endl;
	car.brake();
	std::cout << "isMoving:" << car.isMoving() << std::endl;
	std::cout << "Position:" << car.getPosition() << std::endl;

	system("PAUSE");

	return 0;
}

// generell für jede Klasse eine Header und eine cpp datei