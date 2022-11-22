#include <iostream>

int main()
{
#ifdef _WIN32
	std::cout << "Hello Windows";
#elif linux
	std::cout << "Hello Linux";
#endif
}
//we use the respective macros specific for windows ans linux in order to differentiate between them and print the message accordingly
