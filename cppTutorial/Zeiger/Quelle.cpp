#include <iostream>

using namespace std;

void SetTo27(int *number) //variable number != variable1
{
	*number = 27;
}

int EuclideanDivide(unsigned int dividend, unsigned int divisor, unsigned int* quotient, unsigned int* remainder) //r�ckgabewert als zeiger, gut wenn man mehrere r�ckgabewerte hat
{
	if (divisor == 0)
		return -1;
	*quotient = (unsigned int)dividend / divisor; //der wert auf den quotient zeigt ist
	*remainder = dividend % divisor; 
	return 0;
}

int main()
{
	int variable1 = 27;
	int *pointer1 = &variable1; //zeiger muss mit int von dem wert sein auf den er zeigt
	cout << &variable1 << endl; //& f�r adresse,* f�r wert
	cout << pointer1 << endl;
	*pointer1 = 10; //�ber den zeiger der variablen einen anderen wert zuweisen
	SetTo27(&variable1);
	cout << variable1 << endl;

	unsigned int divident = 10;
	unsigned int divisor = 3;
	unsigned int quotient = 0;
	unsigned int remainder = 0;
	EuclideanDivide(divident, divisor, &quotient, &remainder);
	cout << quotient << endl;
	cout << remainder << endl;

	int array[] = { 0, 1, 2, 3, 4 };
	int* pointerToArray = nullptr; //oder NULL, eigentlich unn�tig da wert in der n�chsten zeile zugewiesen wird
	pointerToArray = array; // pointer zum ersten element des arrays
	cout << *pointerToArray << endl; // gleich wie pointerToArray = &array[0]
	pointerToArray++; //+=4//zeiger um eins erh�hen,zeigt aufs n�chste integer
	cout << *pointerToArray << endl;
	
	void (*funcPointer)(int*) = SetTo27; //erwartet ein integer zeiger
	funcPointer(&array[0]); //0. element des arrays �bergebn
	cout << array[0] << endl;

	//system("PAUSE");
	return 0;
}