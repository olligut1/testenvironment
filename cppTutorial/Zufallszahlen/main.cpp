#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
	cout << "Maximale Groesse: " << RAND_MAX << endl;
	srand(time(NULL)); //seed (aktuelle Systemzeit)
	for (int i = 0; i < 10; i++)
	{
		cout << rand() % 17 + 2000 << endl; // modulo 2000-2016, zahlen werden durch 27 geteilt, rest wird ausgegeben linearer konkruenzgenerator
	}

	system("PAUSE");
	return 0;
}