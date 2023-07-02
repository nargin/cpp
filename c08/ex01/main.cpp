#include "Span.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

int main(void){
	Span<size_t> sp(10000);
	srand(time(NULL));
	try {
		size_t tab[10000];
		size_t petit[50];
		for (size_t i = 0; i < 10000; i++) {
			tab[i] = rand();
			if (i < 50)
				petit[i] = rand() % 50;
		}
		(void)petit;
		sp.addNumber(tab, 10000);
		std::cout << "count: " << sp.counting() << std::endl;
		for (size_t i = 0; i < 50; i++)
			std::cout << sp[i] << std::endl;
		std::cout << "min: " << sp.shortestSpan() << std::endl;
		std::cout << "max: " << sp.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}