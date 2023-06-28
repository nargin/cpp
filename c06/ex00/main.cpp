#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <iomanip>

int 	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./convert [input]" << std::endl;
		return 1;
	}
	ScalarConverter converter(argv[1]);
	
	converter.convert();

	return 0;
}