#include <iostream>
#include <string>
#include <boost/regex.hpp>

void search(std::string s)
{
	boost::regex expr{"\\w+\\s\\w+"};
	std::cout << std::boolalpha << boost::regex_match(s, expr) << '\n';
}

void replace(std::string s)
{
	boost::regex expr{"(\\w+)\\s(\\w+)"};
	std::string fmt{"\\2 \\1"};
	std::cout << boost::regex_replace(s, expr, fmt) << '\n';
}

int main()
{

	std::string s = "Bo_ost Libraries";

	search(s);

	replace(s);


	return 0;

}
