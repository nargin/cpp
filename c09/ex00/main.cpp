#include "BitcoinExchange.hpp"

int	main(int ac, char *av[]){
	if (ac != 2){
		std::cout << "Error: Could not open file" << std::endl << "Usage: ./btc [file]" << std::endl;
		return (1);
	}
	BitcoinExchange exchange(av[1]);
	exchange.print();
	return (0);
}