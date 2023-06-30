#include "Span.hpp"

int main(void){
	Span<size_t> sp(10);
	size_t arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
	sp.addNumber(arr, arr + 10);
	// sp.addNumber(11);
	for (size_t i = 0; i < 10; i++)
		std::cout << sp[i] << std::endl;
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
}