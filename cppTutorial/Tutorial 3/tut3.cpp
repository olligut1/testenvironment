#include <iostream>

using namespace std;

//Hauptfunktion
int main()
{
	const int WOCHENTAGE = 7;
	char buchstabe;
	/*int Zahl1 = 0;
	int Zahl2 = 0;

	cout << "Bitte gebe die erste Zahl ein: ";
	cin >> Zahl1;
	cout << "Bitte gebe die zweite Zahl ein: ";
	cin >> Zahl2;
	cout << "Das Ergebnis von " << Zahl1 << " * " << Zahl2 << " = " << Zahl1 * Zahl2 << endl;
	*/
	cout << "Gib einen Namen ein: ";
	cin >> buchstabe;
	cout << "Dein Anfangsbuchstabe ist " << buchstabe << endl;

	system("PAUSE");

	return 0;
}