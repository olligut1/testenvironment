# include "version.h"

namespace version
{
	void printVersion()
	{
		// using namespace std; //sollte so nur in funktionen stehen
		std::cout << "Program version: " << VERSION_MAJOR << "." << VERSION_MINOR << std::endl;
	}
}