// Creator: 陈照鹏 idk
#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T const &x) {
	std::cout << x << " ";
}

int main(void) {
	int int_array[] = { 1, 2, 3, 4, 5 };
	float float_array[] = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
	std::string string_array[] = { "one", "two", "three", "four", "five" };

	std::cout << "int_array: ";
	iter(int_array, static_cast<size_t> (5), print);
	std::cout << std::endl;

	std::cout << "float_array: ";
	iter(float_array, static_cast<size_t> (5), print);
	std::cout << std::endl;

	std::cout << "string_array: ";
	iter(string_array, static_cast<size_t> (5), print);
	std::cout << std::endl;

	return 0;
}