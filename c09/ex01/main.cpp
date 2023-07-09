#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./rpn \"expression\"" << std::endl;
		return 1;
	}
	try {
		RPN rpn(argv[1]);
	} catch (std::string e) {
		std::cout << e << std::endl;
	}
	return 0;
}