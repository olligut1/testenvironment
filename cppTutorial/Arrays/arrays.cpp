#include <iostream>

using namespace std;

int main()
{
	int firstArray[10]; // Größe 10 (40 byte)
	firstArray[0] = 5; //zugriff auf nullte Element
	/*
	firstArray[9] = 3;
	firstArray[8] = firstArray[0] * firstArray[9];
	cout << firstArray[8] << endl;
	*/
	int secondArray[] = { 27, 4, 52 }; //3 elemente

	for (int i = 0; i < 3; i++); //3 mal ausführen
	{
		cout << "Element Index " << i <<" Value: " << secondArray[i] << endl;
	}

	float thirdArray[5][5][5]; //3 dimensionen
	for (i);
	{
		for (j);
		{
			thirdArray[i][j]
		}
	}
	thirdArray[2][4][3]; //Zugriff

	float maxRAM[100][100][100]; // 1 mio doubles

	return 0;
}