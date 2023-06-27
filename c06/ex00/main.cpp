#include "ScalarConverter.hpp"
#include <string>
#include <iostream>
#include <iomanip>

int 	main(int argc, char **argv) {
	if (argc != 3) {
		std::cout << "Usage: ./convert [input]" << std::endl;
		return 1;
	}
	// ScalarConverter converter(argv[1]);
	
	// converter.convert();
	// converter.printChar();
	// converter.printInt();
	// converter.printFloat();
	// converter.printDouble();
	double res = atof(argv[1]);
	double adding = atof(argv[2]);
	std::cout << res << " -> res : " << std::setprecision(32) << static_cast<double>(res + adding) << std::endl;

	return 0;
}