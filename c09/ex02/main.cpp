#include "PmergeMe.hpp"

int main(int ac, char *av[]) {
	if (ac < 2) {
		std::cout << "Usage: ./a.out [int] [int] ..." << std::endl;
		return 1;
	}
	PmergeMe p(av);
	return 0;
}