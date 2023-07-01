#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>

int main(void){
	Span<size_t> sp(10000);
	srand(time(NULL));
	try {
		std::vector<size_t> vec;
		for (size_t i = 0; i < 10000; i++)
			vec.push_back(rand() % 10000);
		sp.addNumber(vec, 10000);
		std::cout << "count: " << sp.counting() << std::endl;
		for (size_t i = 0; i < 10; i++)
			std::cout << sp[i] << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}