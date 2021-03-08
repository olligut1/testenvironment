# include <iostream>
# include "version.h"

//using namespace std;

namespace first
{
	int x = 1;
}

namespace second
{
	int x = 2;
}

namespace foo
{
	namespace bar
	{
		int y = 27; //kaskadierende namespaces
	}
}

int main()
{
	version::printVersion();

	std::cout << "Hello World\n"; //ohne namespace std::cout
	std::cout << first::x << std::endl;
	std::cout << foo::bar::y << std::endl;

	return 0;
}