#include <iostream>
#include <string.h>

using namespace std;

int main() {
	char name[] = "Bla";
	const char *test = "Test";
	cout << name << endl;
	cout << test << endl;
	if (name[3] == '\0')
		cout << "Richtig" << endl;

	cout << strlen(name) << endl; //l�nge +1

	string teststring = "ich bin ein string";
	cout << teststring.length() << endl;
	const char* cstring = teststring.c_str();
	cout << cstring << endl;


	return 0;
}