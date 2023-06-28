#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	std::vector<int>::iterator it = easyfind(v, 5);
	std::cout << *it << std::endl;
	return 0;
}