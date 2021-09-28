#include <iostream>
#include "strutil.h"
int main()
{
	char first[100], second[100];

	std::cout << "INPUT:" << std::endl;
	std::cin >> first >> second;
	std::cout<<strConteins(first, second);
	return 0;
}
