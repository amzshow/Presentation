#include <string>
#include <iostream>
#include <boost/foreach.hpp>

int main()
{
	std::string s = "Hello";
	
	BOOST_FOREACH(char ch, s)
	{
		std::cout << ch;
	}

	std::cout << std::endl;

	for(char ch: s)
	{
		std::cout << ch;
	}

	std::cout << std::endl;

	return 0;
	
}
