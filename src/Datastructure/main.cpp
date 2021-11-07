#include "pch.h"
#include <iostream>
#include "list.h"

int main()
{
	std_study::list<int32_t> lst1;

	lst1.push_back(1);
	lst1.push_back(2);
	lst1.push_back(3);
	lst1.push_back(4);
	lst1.push_back(5);

	for (const auto& elem : lst1)
		std::cout << elem << ", ";
	std::cout << std::endl;

}