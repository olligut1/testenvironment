#include <iostream>

using namespace std;

int main()
{
	char input = 'q';
	//while (true) // Endlosschleife
	for (int i = 1; i < 27; i*=2) //Zielschleife, Anfang; Bedingung; Ausführung
	{
		cout << i << endl;
	}
	/*
do
{
	cin >> input;
	if (input == 'q')
		//		break; // Aus Schleife ausbrechen
		continue; // Startet nächsten Schleifenduchlauf
	cout << "Kein Q\n";
} while (input != 'b');
*/
//while (input != 'q')
/*
do
{
	cout << "Input: ";
	cin >> input;
	system("cls");
} while (input != 'q');
*/
	return 0;
}