#include <iostream>
#include "vector.hpp"

int main()
{
	OK::vector<int> vec(10, 69);
	for(const auto& elem: vec)
	{
		std::cout << elem << std::endl;
	}
	return 0;
}
